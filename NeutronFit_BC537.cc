
#include "NeutronFit_BC537.hh"

NeutronFit_BC537::NeutronFit_BC537(int run_num) :
    fRunNum(run_num),
    fSimFile(NULL),
    fExpFile(NULL),
    fSimHist(NULL),
    fExpHist(NULL),
    fSimTree(NULL),
    fEdepBranch(NULL),
    fEkinBranch(NULL),
    fPtypeBranch(NULL),
    fEdepVector(NULL),
    fEkinVector(NULL),
    fPtypeVector(NULL),
    fFitFunc(NULL),
    fRebin(false)
{
    
    double energy_vector[] = 
    {
        0.66201 ,0.80879    ,1.05264    ,1.21767    ,2.96445    ,2.86088    ,2.69813    ,2.48962    ,2.25152    ,
        2.00070 ,1.75268    ,1.52003    ,2.27882    ,2.60832    ,2.95748    ,3.30884    ,3.64108    ,3.93118    ,
        4.15713 ,4.30074    ,1.98127    ,1.72261    ,1.50509    ,1.50509    ,1.72261    ,1.98127    ,0.81657    ,
        0.95882 ,1.11930    ,1.29208    ,1.46825    ,1.63655    ,1.78465    ,1.90062    ,1.97458    ,0.69544    ,
        0.59575 ,0.51611    ,0.45421    ,0.38915    ,0.68765    ,0.65189    ,0.59641    ,0.48874    ,0.37184    ,
        0.26609 ,0.18371    ,0.12684    ,0.10089    ,0.07506    ,0.05996    ,0.05996    ,7.90894    ,7.64353    ,
        7.22603 ,6.69019    ,6.07682    ,5.42853    ,4.78473    ,4.17760    ,3.62976    ,3.15389    ,2.75400    ,
        2.42779 
    };
    fEnergy = energy_vector[fRunNum];

    //double cutoff_low_vector[] =
    //{
    //    40      ,40     ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,
    //    50      ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,
    //    50      ,50     ,50     ,50     ,50     ,

    //    17     ,17     ,20     ,8.5    ,
    //    8.5     ,15     ,15     ,15     ,15     ,15     ,15     ,15     ,8.5    ,
    //    8.5     ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,
    //    8.5     ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,8.5    ,500    ,500    ,  
    //    200     ,200    ,200    ,200    ,200    ,200    ,200    ,150    ,150    ,
    //    150 
    //};
    double cutoff_low_vector[] =
    {
        40      ,40     ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,
        50      ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,50     ,
        50      ,50     ,50     ,50     ,50     ,

        10      ,10     ,10     ,10     ,10     ,10     ,10     ,10     ,10     ,
        10      ,10     ,10     ,10     ,10     ,10     ,10     ,10     ,10     ,
        10      ,10     ,10     ,10     ,10     ,10     ,10     ,10     ,9      ,
        9   ,

        3    ,
        
        300,300,100,80,70,80,60,60,55,50,50,50
    };
    fCutoffLow = cutoff_low_vector[fRunNum];
    
    
    //double cutoff_high_vector[] =
    //{
    //    110     ,130    ,180 ,230 ,800     ,700    ,650     ,600     ,500   ,
    //    430     ,370    ,300 ,500 ,620     ,750    ,880     ,1000    ,1100  ,
    //    1200    ,1300   ,430 ,360 ,300     ,
    //    
    //    425    ,540     ,600     ,200   ,
    //    240     ,300    ,350 ,420 ,500     ,550    ,600     ,620     ,160   ,
    //    130     ,110    ,95  ,75  ,165     ,155    ,130     ,110     ,75    ,
    //    55      ,   45  ,35  ,30  ,25      ,25     ,25      ,4150    ,4000  ,
    //    3650    ,3200   ,2800,2500,2050    ,1750   ,1400    ,1100    ,900   ,
    //    750        
    //};
    double cutoff_high_vector[] =
    {
        110     ,130    ,180 ,230 ,800     ,700    ,650     ,600     ,500   ,
        430     ,370    ,300 ,500 ,620     ,750    ,880     ,1000    ,1100  ,
        1200    ,1300   ,430 ,360 ,300     ,

        320     ,400    ,480    ,160    ,180    ,220    ,260    ,310    ,360    ,
        410     ,440    ,480    ,110    ,100    ,90     ,80     ,70     ,130    ,
        120     ,110    ,90     ,70     ,55     ,44     ,34     ,32     ,26     ,
        26  ,
        
        22      ,

        3100,3000,2680,2500,2170,1850,1560,1250,1050,825,650,575
    };
    fCutoffHigh = cutoff_high_vector[fRunNum];
 
    fExpFile = TFile::Open("~/data/hists2012_resort.root"); 

    std::string hist_name = "ScionixCal" + std::to_string(fRunNum);
    std::string title = std::to_string(fEnergy) + " MeV";
    fExpHist = (TH1F*)(fExpFile->Get(hist_name.c_str())->Clone());
    fExpHist->SetNameTitle(hist_name.c_str(),title.c_str());
    fExpHist->Scale(10000./fExpHist->Integral());
    fExpHist->SetLineColor(kBlack);
    fExpHist->GetXaxis()->UnZoom(); 
    fExpHist->GetYaxis()->UnZoom();
    fExpHist->GetXaxis()->SetTitleOffset(0.75);
    fExpHist->GetXaxis()->SetTitleSize(0.05);
    fExpHist->SetStats(false);
    ApplyCutoffLow(fCutoffLow,"exp");
    fExpBinNum = fExpHist->GetNbinsX();
    fExpBinHigh = fExpHist->GetBinLowEdge(fExpBinNum+1);
    fExpBinLow = fExpHist->GetBinLowEdge(1);
    
    std::string name = "~/data/smearing/deuteron/G4_RAW/Sim" + std::to_string(fRunNum) + "/g4out.root";
    fSimFile = TFile::Open(name.c_str());     

    fSimTree = (TTree*)(fSimFile->Get("ntuple/ntuple")); 
    fNumEntries = fSimTree->GetEntries();
    
    fSimTree->SetBranchAddress("eDepVector",&fEdepVector,&fEdepBranch);
    fSimTree->SetBranchAddress("eKinVector",&fEkinVector,&fEkinBranch);
    fSimTree->SetBranchAddress("particleTypeVector",&fPtypeVector,&fPtypeBranch);
    
    fProtonCoeff[0] = 0.74; fProtonCoeff[1] = 3.2; fProtonCoeff[2] = 0.20; fProtonCoeff[3] = 0.97;
    fDeuteronCoeff[0] = 0.75; fDeuteronCoeff[1] = 2.80; fDeuteronCoeff[2] = 0.25; fDeuteronCoeff[3] = 0.93;
    fCarbonCoeff[0] = 0.05; fCarbonCoeff[1] = 0.0; fCarbonCoeff[2] = 0.0;fCarbonCoeff[3] = 0.0;
    fAlphaCoeff[0] = 0.14; fAlphaCoeff[1] = 0.59; fAlphaCoeff[2] = 0.065; fAlphaCoeff[3] = 1.01;
    fBeCoeff[0] = 0.0821; fBeCoeff[1] = 0.0; fBeCoeff[2] = 0.0; fBeCoeff[3] = 0.0;
    fBCoeff[0] = 0.0375; fBCoeff[1] = 0.0; fBCoeff[2] = 0.0; fBCoeff[3] = 0.0;
    
    fSmearingCoeff[0] = 0.123; fSmearingCoeff[1] = 0.125; fSmearingCoeff[2] = 0.0075;

    fParameters[0] = 0.639;
    fParameters[1] = 1.462;
    fParameters[2] = 0.373;
    fParameters[3] = 0.968;
    fParameters[4] = 0.0;
    fParameters[5] = 0.123;
    fParameters[6] = 0.125;
    fParameters[7] = 0.0074;
    SetParameters(fParameters);
   
    fOffset = 8.5;

    //fSimSortMax = 200000;
    
    //if(fSimTree->GetEntries() > fExpHist->GetEntries()) fSimSortMax = fExpHist->GetEntries();
    
    if(fSimTree->GetEntries() >= 2e5) fSimSortMax = 2e5;
    else fSimSortMax = fSimTree->GetEntries();
    
    //fSimSortMax = fSimTree->GetEntries();

    std::cout << "Run# = " << fRunNum << " ; Energy = " << fEnergy << " MeV ; cutoff(low,high) = (" << fCutoffLow << ","; 
    std::cout << fCutoffHigh << ") " << " ; #evts ratio = " << double(fSimSortMax)/double(fExpHist->GetEntries()) << std::endl;

    //fExpHist->Rebin(5);
    //if(fExpBinNum == 50100) fExpHist->Rebin(10);

}

NeutronFit_BC537::~NeutronFit_BC537() {}

void NeutronFit_BC537::SetParameters(double * par)
{
    fDeuteronCoeff[0] = par[0];
    fDeuteronCoeff[1] = par[1];
    fDeuteronCoeff[2] = par[2];
    fDeuteronCoeff[3] = par[3];
    fCarbonCoeff[0] = par[4];
    fSmearingCoeff[0] = par[5]; 
    fSmearingCoeff[1] = par[6]; 
    fSmearingCoeff[2] = par[7]; 

    fParameters[0] = par[0];
    fParameters[1] = par[1];
    fParameters[2] = par[2];
    fParameters[3] = par[3];
    fParameters[4] = par[4];
    fParameters[5] = par[5];
    fParameters[6] = par[6];
    fParameters[7] = par[7];
}

void NeutronFit_BC537::Sort(double a1, double a2, double a3, double a4, double carbon, double A, double B, double C)
{
    double par[8];
    par[0] = a1;
    par[1] = a2;
    par[2] = a3;
    par[3] = a4;
    par[4] = carbon;
    par[5] = A;    
    par[6] = B;    
    par[7] = C;    

    Sort(par);
}

void NeutronFit_BC537::Sort(double * par)
{
    fRandom.SetSeed(1);
    gErrorIgnoreLevel = kError;    
    
    SetParameters(par);
    //PrintParameters();
    
    fExpBinNum = fExpHist->GetNbinsX();
    if(fSimHist) { delete fSimHist; fSimHist = NULL; }
    //fSimHist = new TH1F("fSimHist","fSimHist",fExpBinNum,-10,5000); 
    fSimHist = new TH1F("fSimHist","fSimHist",fExpBinNum,fExpBinLow,fExpBinHigh); 
    int nHits = 0;
    double light = 0.;
    double centroidEkin = 0.;    
    double centroidEres = 0.;    
    
    //clock_t overalstart = clock();
    //double resolutiontime = 0.;
    //double runningtime = 0.;
    
    int counter = 0;
    
    for(int i=0; i<fSimSortMax; i++)
    {
        counter++;
        //if( counter%50000==0 ) std::cout << "sorting " << fEnergy << " MeV... " << "evt " << counter << "/" << fSimSortMax << "; " << double(counter)/double(fSimSortMax)*100 << "% complete \r"  << std::flush; 
     
        fEdepBranch->GetEntry(i);   
        fEkinBranch->GetEntry(i);   
        fPtypeBranch->GetEntry(i);   
        nHits = fEdepVector->size();
        light = 0.;
        for(int j=0; j<nHits; j++)
        {
            if(fPtypeVector->at(j) == 2 || fPtypeVector->at(j) == 3) {
                centroidEkin = fEkinVector->at(j);
                centroidEres = fEkinVector->at(j)-fEdepVector->at(j);
            }
            else if(fPtypeVector->at(j) == 4) {
                centroidEkin = LightOutput(fEkinVector->at(j), fProtonCoeff);
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fProtonCoeff);
            }
            else if(fPtypeVector->at(j) == 6) {
                centroidEkin = LightOutput(fEkinVector->at(j), fDeuteronCoeff);
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fDeuteronCoeff);
            }
            else if(fPtypeVector->at(j) == 7) {
                centroidEkin = LightOutput(fEkinVector->at(j), fCarbonCoeff);
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fCarbonCoeff);
            }
            else if(fPtypeVector->at(j) == 8) {
                centroidEkin = LightOutput(fEkinVector->at(j), fAlphaCoeff);
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fAlphaCoeff);
            }
            else if(fPtypeVector->at(j) == 9) {
                centroidEkin = LightOutput(fEkinVector->at(j), fBeCoeff);
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fBeCoeff);
            }
            else if(fPtypeVector->at(j) == 10) {
                centroidEkin = LightOutput(fEkinVector->at(j), fBCoeff );
                centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fBCoeff);
            }
            else { 
                centroidEkin = 0.; 
                centroidEres = 0.; 
            } 
            //clock_t resolutionstart = clock();
            if(centroidEkin>0.){
                light += 1000.*fRandom.Gaus(centroidEkin, Resolution(centroidEkin,fSmearingCoeff));
            }
            if(centroidEres>0.){
                light -= 1000.*fRandom.Gaus(centroidEres, Resolution(centroidEres,fSmearingCoeff));
            } 
            //clock_t resolutionend = clock();
            //resolutiontime += (double)(resolutionend - resolutionstart);
        }//end scatters loop       
        if(light>0.) fSimHist->Fill(light+fOffset);
        //if(light>0.) fSimHist->Fill(light);
    }//end event loop
    
    //clock_t overalend = clock();
    //std::cout << "Overall time: " << (int)(overalend - overalstart) << std::endl;
    //std::cout << "Resolution time: " << (int)resolutiontime << std::endl;

    fExpHist->SetBinContent(fExpBinNum+1,0);

    ApplyCutoffLow(fCutoffLow,"sim");    
    fSimHist->Scale(fExpHist->Integral(fExpHist->FindBin(fCutoffLow),fExpHist->FindBin(fCutoffHigh),"width")/fSimHist->Integral(fSimHist->FindBin(fCutoffLow),fSimHist->FindBin(fCutoffHigh),"width"));
    fSimHist->SetStats(false);
    //std::cout << "sorting " << fEnergy << " MeV... done!                                                   " << std::endl;

    std::string title = std::to_string(fEnergy) + " MeV - Run " + std::to_string(fRunNum) + "; #chi^{2} = " + std::to_string(DoChi2());
    fExpHist->SetTitle(title.c_str());
    
    //if(fFitFunc) { delete fFitFunc; fFitFunc = NULL; }
    //fFitFunc = new TF1("fFitFunc",this,&NeutronFit_BC537::HistCompare,fCutoffLow,fCutoffHigh,8);
    //fFitFunc->SetNpx(100);
    //fFitFunc->SetParameters(fParameters[0],fParameters[1],fParameters[2],fParameters[3],fParameters[4],fParameters[5],fParameters[6],fParameters[7]);
    //fFitFunc->SetParLimits(0,0.2,1);
    //fFitFunc->SetParLimits(1,0.5,10);
    //fFitFunc->SetParLimits(2,0.05,0.4);
    //fFitFunc->SetParLimits(3,0.8,1.2);
    //fFitFunc->SetParLimits(4,0,0.1);
    //fFitFunc->SetParLimits(5,0,0.3);
    //fFitFunc->SetParLimits(6,0,0.3);
    //fFitFunc->SetParLimits(7,0,0.05);

}

double NeutronFit_BC537::HistCompare(double * x, double * par) 
{
    if(!fSimHist) Sort();
    if(DidParametersChange(par)) Sort(par);
    double xx = x[0];
    int bin = fSimHist->GetXaxis()->FindBin(xx);
    double content = fSimHist->GetBinContent(bin);
    return content;

}

TF1 * NeutronFit_BC537::Fit()
{
    //ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2","Combination");
    ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit","Simplex");
    TVirtualFitter::SetPrecision(1.0e-10);
    TVirtualFitter::SetMaxIterations(10000);
    TFitResultPtr res = fExpHist->Fit("fFitFunc","RSV");
    return fFitFunc;
}

bool NeutronFit_BC537::DidParametersChange(double * par)
{
    for(int i=0; i<8; i++) 
    {
        if(TMath::Abs(par[i] - fParameters[i]) > 1e-4) return true;
    }
    return false;
}


