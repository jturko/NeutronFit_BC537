
#include "NeutronFit_BC537.hh"

NeutronFit_BC537::NeutronFit_BC537(int run_num) :
    fFitFunc(NULL),
    fRunNum(run_num),
    fSimFile(NULL),
    fExpFile(NULL),
    fSimHist(NULL),
    fExpHist(NULL),
    fSimTree(NULL),
    fEdepBranch(NULL),
    fEkinBranch(NULL),
    fPtypeBranch(NULL),
    fTimingBranch(NULL),
    fEdepVector(NULL),
    fEkinVector(NULL),
    fPtypeVector(NULL),
    fTimingVector(NULL),
    fEventTree(NULL),
    fLongEventTree(NULL),
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

    double cutoff_low_vector[] =
    {   
        40,40,50,50,100,100,80,80,70,70,70,70,70,80,80,80,100,100,100,125,70,70,60,35,35,35,30,30,30,30,30,40,40,40,40,20,20,20,20,20,25,25,25,20,20,17,17,17,17,16,15,8,100,100,100,100,100,100,100,100,100,100,100,100
    };
    fCutoffLow = cutoff_low_vector[fRunNum];
    
    double cutoff_high_vector[] =
    {
        110,135,190,240,840,800,750,640,560,470,390,320,560,660,800,940,1050,1200,1300,1350,450,370,310,320,390,460,145,180,220,260,310,360,410,450,480,110,100,85,75,65,125,120,110,90,70,55,42,33,32,28,27,21,3200,3100,2800,2500,2200,1900,1600,1300,1050,850,700,600
    };
    fCutoffHigh = cutoff_high_vector[fRunNum];
 
    //fExpFile = TFile::Open("/tulkas/geant4/joey/smearing/deuteron/BC537_bkgsub.root"); 
    fExpFile = TFile::Open("/tulkas/geant4/joey/smearing/deuteron/BC537_bkgsub_mycal.root"); 

    std::string hist_name = "ScionixCal" + std::to_string(fRunNum);
    std::string title = std::to_string(fEnergy) + " MeV";
    fExpHist = (TH1F*)(fExpFile->Get(hist_name.c_str())->Clone());
    fExpHist->SetNameTitle(hist_name.c_str(),title.c_str());
    //fExpHist->Scale(10000./fExpHist->Integral());
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
    for(int i=0; i<fExpBinNum; i++) {
        if(fExpHist->GetBinContent(i)<0.) fExpHist->SetBinContent(i,0.);
    }    

    bool foundEventTree = false;
    std::string name = "/tulkas/geant4/joey/smearing/deuteron/G4_RAW_Timing/Sim" + std::to_string(fRunNum) + "/Sim" + std::to_string(fRunNum) + "EventTree.root";
    fSimFile = TFile::Open(name.c_str());
    if(!fSimFile) {
        name = "/tulkas/geant4/joey/smearing/deuteron/G4_RAW_Timing/Sim" + std::to_string(fRunNum) + "/g4out.root";
        fSimFile = TFile::Open(name.c_str());
        fSimTree = (TTree*)(fSimFile->Get("ntuple/ntuple")); 
    }
    else { 
        foundEventTree = true;
        fSimTree = (TTree*)(fSimFile->Get("EventTree2"));
        //fEventTree = (TTree*)(fSimFile->Get("EventTree"));
        //fLongEventTree = (TTree*)(fSimFile->Get("LongEventTree"));
    }
    fSimTree->SetBranchAddress("eDepVector",&fEdepVector,&fEdepBranch);
    fSimTree->SetBranchAddress("eKinVector",&fEkinVector,&fEkinBranch);
    fSimTree->SetBranchAddress("particleTypeVector",&fPtypeVector,&fPtypeBranch);
    fSimTree->SetBranchAddress("timingVector",&fTimingVector,&fTimingBranch);
    fNumEntries = fSimTree->GetEntries();
    if(!foundEventTree) {
        //BuildEventTree();
    }

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
    fParameters[5] = 0.1306;
    fParameters[6] = 0.1359;
    fParameters[7] = 1.21e-6;
    SetParameters(fParameters);
    
    fOffset = 0;

    //fSimSortMax = 200000;
    
    //if(fSimTree->GetEntries() > fExpHist->GetEntries()) fSimSortMax = fExpHist->GetEntries();
    
    if(fSimTree->GetEntries() >= 2e5) fSimSortMax = 2e5;
    else fSimSortMax = fSimTree->GetEntries();
    
    fSimSortMax = 1e5;

    //fSimSortMax = fSimTree->GetEntries();

    std::cout << "Run# = " << fRunNum << "\tEnergy = " << fEnergy << " MeV\tcutoff(low,high) = (" << fCutoffLow << ","; 
    std::cout << fCutoffHigh << ") " << "\t#evts ratio = " << double(fSimSortMax)/double(fExpHist->GetEntries()) << std::endl;

    //fExpHist->Rebin(5);
    //if(fExpBinNum == 50100) fExpHist->Rebin(10);

    fUsePolyLightYield = false;

    fEventTimeWindow = 200.; // this should be in nanoseconds

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
    
    TThread::Lock();
    if(fSimHist) { delete fSimHist; fSimHist = NULL; }
    //fSimHist = new TH1F("fSimHist","fSimHist",fExpBinNum,-10,5000); 
    fSimHist = new TH1F("fSimHist","fSimHist",fExpBinNum,fExpBinLow,fExpBinHigh); 
    TThread::UnLock();

    int nHits = 0;
    double light = 0.;
    double centroidEkin = 0.;    
    double centroidEres = 0.;    
    
    //clock_t overalstart = clock();
    //double resolutiontime = 0.;
    //double runningtime = 0.;
    
    int counter = 0;
    
    //std::cout << "starting run " << fRunNum << std::endl;
    for(int i=0; i<fSimSortMax; i++)
    {
        counter++;
        //if( counter%50000==0 ) std::cout << "sorting " << fEnergy << " MeV... " << "evt " << counter << "/" << fSimSortMax << "; " << double(counter)/double(fSimSortMax)*100 << "% complete \r"  << std::flush; 
     
        fEdepBranch->GetEntry(i);   
        fEkinBranch->GetEntry(i);   
        fPtypeBranch->GetEntry(i);   
        fTimingBranch->GetEntry(i);
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
                if(fUsePolyLightYield == true) {
                    centroidEkin = PolyLightOutput(fEkinVector->at(j), fDeuteronCoeff);
                    centroidEres = PolyLightOutputWall(fEkinVector->at(j)-fEdepVector->at(j), fDeuteronCoeff);
                }
                else {    
                    centroidEkin = LightOutput(fEkinVector->at(j), fDeuteronCoeff);
                    centroidEres = LightOutput(fEkinVector->at(j)-fEdepVector->at(j), fDeuteronCoeff);
                }
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
            light = light + centroidEkin - centroidEres; 
            //clock_t resolutionstart = clock();
            //if(centroidEkin>0.){
            //    light += 1000.*fRandom.Gaus(centroidEkin, Resolution(centroidEkin,fSmearingCoeff));
            //}
            //if(centroidEres>0.){
            //    light -= 1000.*fRandom.Gaus(centroidEres, Resolution(centroidEres,fSmearingCoeff));
            //} 
            //clock_t resolutionend = clock();
            //resolutiontime += (double)(resolutionend - resolutionstart);
        }//end scatters loop
        if( (light+(fOffset/1000.)) > 0. && light > 0.) {
            light = 1000.*fRandom.Gaus(light+(fOffset/1000.),Resolution(light+(fOffset/1000.),fSmearingCoeff));
            TThread::Lock();
            fSimHist->Fill(light);
            TThread::UnLock();
        }
        //if(light>0.) fSimHist->Fill(light);
    }//end event loop
    //std::cout << "finishing run " << fRunNum << std::endl;
    
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

void NeutronFit_BC537::BuildEventTree()
{
    //if(fSimTree) { 
    //    std::cout << "deleting fSimTree ... ";
    //    delete fSimTree; 
    //    fSimTree = NULL; 
    //    std::cout << "done!\n" << std::flush;
    //}
    //if(fEventTree) { 
    //    std::cout << "deleting fEventTree ... ";
    //    delete fEventTree;
    //    fEventTree = NULL;
    //    std::cout << "done!\n" << std::flush;
    //}
    //if(fLongEventTree) { 
    //    std::cout << "deleting fLongEventTree ... ";
    //    delete fLongEventTree;
    //    fLongEventTree = NULL;
    //    std::cout << "done!\n" << std::flush;
    //}
    //if(fSimFile) { 
    //    std::cout << "deleting fSimFile ... ";
    //    delete fSimFile; 
    //    fSimFile = NULL; 
    //    std::cout << "done!\n" << std::flush;
    //}
    std::string name = "/tulkas/geant4/joey/smearing/deuteron/G4_RAW_Timing/Sim" + std::to_string(fRunNum) + "/g4out.root";
    fSimFile = TFile::Open(name.c_str());
    fSimTree = (TTree*)(fSimFile->Get("ntuple/ntuple")); 
    fSimTree->SetBranchAddress("eDepVector",&fEdepVector,&fEdepBranch);
    fSimTree->SetBranchAddress("eKinVector",&fEkinVector,&fEkinBranch);
    fSimTree->SetBranchAddress("particleTypeVector",&fPtypeVector,&fPtypeBranch);
    fSimTree->SetBranchAddress("timingVector",&fTimingVector,&fTimingBranch);
    
    std::vector<double> ekin;
    std::vector<double> edep;
    std::vector<int> ptype;
    std::vector<double> time;
    
    TFile * outfile = TFile::Open(Form("/tulkas/geant4/joey/smearing/deuteron/G4_RAW_Timing/Sim%d/Sim%dEventTree.root",fRunNum,fRunNum),"RECREATE"); 
    outfile->cd();
    
    fEventTree = new TTree("EventTree","EventTree");
    fEventTree->Branch("eKinVector",&ekin);
    fEventTree->Branch("eDepVector",&edep);
    fEventTree->Branch("particleTypeVector",&ptype);
    fEventTree->Branch("timingVector",&time);
    fNumEvents = 0;
    //fEventTree->SetDirectory(outfile);
    
    fLongEventTree = new TTree("LongEventTree","LongEventTree");
    fLongEventTree->Branch("eKinVector",&ekin);
    fLongEventTree->Branch("eDepVector",&edep);
    fLongEventTree->Branch("particleTypeVector",&ptype);
    fLongEventTree->Branch("timingVector",&time);
    //fLongEventTree->SetDirectory(outfile);

    int vSize;
    for(int i=0; i<GetSimEntries(); i++) {
        if(i%10000==0 || i==fNumEntries-1) std::cout << "\rRun " << fRunNum << " - building from evt " << i << " / " << fNumEntries-1 
                                                    << " ( " << Form("%.1f",double(i)/double(fNumEntries-1)*100.) << " % ) ..." << std::flush;
        GetEntry(i);
        vSize = (int)fTimingVector->size();
        //if(vSize == 1) continue;
 
        std::vector<std::pair<size_t,std::vector<double>::const_iterator>> order(fTimingVector->size());
        size_t n = 0;
        for(std::vector<double>::const_iterator it = fTimingVector->begin(); it != fTimingVector->end(); it++, n++) {
            order[n] = std::make_pair(n,it);
        }
        struct ordering {
            bool operator ()(std::pair<size_t, std::vector<double>::const_iterator> const& a, std::pair<size_t, std::vector<double>::const_iterator> const& b) {
                return *(a.second) < *(b.second);
            }
        };
        std::sort(order.begin(), order.end(), ordering());
        *fEdepVector = sort_from_ref(*fEdepVector,order);
        *fEkinVector = sort_from_ref(*fEkinVector,order);
        *fPtypeVector = sort_from_ref(*fPtypeVector,order);
        *fTimingVector = sort_from_ref(*fTimingVector,order);

        double t = 0, delta = 0;
        double t0 = fTimingVector->at(0);
        ekin.clear();
        edep.clear();
        ptype.clear();
        time.clear();
        ekin.push_back(fEkinVector->at(0));
        edep.push_back(fEdepVector->at(0));
        ptype.push_back(fPtypeVector->at(0));
        time.push_back(fTimingVector->at(0));
        
        bool longEvent = false;
        for(int j=1; j<vSize; j++) {
            t = fTimingVector->at(j);
            delta = t - t0;
            if(delta > fEventTimeWindow) {
                fEventTree->Fill();
                if(longEvent) fLongEventTree->Fill();
                longEvent = true;
                ekin.clear();
                edep.clear();
                ptype.clear();
                time.clear();
            }
            ekin.push_back(fEkinVector->at(j));
            edep.push_back(fEdepVector->at(j));
            ptype.push_back(fPtypeVector->at(j));
            time.push_back(fTimingVector->at(j));
            t0 = t;
        }
        fEventTree->Fill();
        if(longEvent) fLongEventTree->Fill();
        
        //fEventTree->FlushBaskets();
        //fLongEventTree->FlushBaskets();
    }
    fNumEvents = fEventTree->GetEntries();
    std::cout << " done! writing trees ..." << std::flush;

    fEventTree->Write("EventTree2");
    fLongEventTree->Write("LongEventTree2");
    
    std::cout << " done! sim evts: " << fSimTree->GetEntries() << " built evts: " << fEventTree->GetEntries() << " long evts: " << fLongEventTree->GetEntries() << std::endl;
    
    if(fSimTree) delete fSimTree; fSimTree = NULL;
    if(fSimFile) delete fSimFile; fSimFile = NULL;
    if(fEventTree) delete fEventTree; fEventTree = NULL;
    if(fLongEventTree) delete fLongEventTree; fLongEventTree = NULL;
    
    //fSimFile = TFile::Open(Form("~/data/smearing/deuteron/G4_RAW_Timing/Sim%d/Sim%dEventTree.root",fRunNum,fRunNum));
    //fSimFile->cd();
    //fSimTree = (TTree*)fSimFile->Get("EventTree");
    //fEventTree = (TTree*)fSimFile->Get("EventTree");
    //fLongEventTree = (TTree*)fSimFile->Get("LongEventTree");
    //fNumEntries = fSimTree->GetEntries();
    //fSimTree->SetBranchAddress("eDepVector",&fEdepVector,&fEdepBranch);
    //fSimTree->SetBranchAddress("eKinVector",&fEkinVector,&fEkinBranch);
    //fSimTree->SetBranchAddress("particleTypeVector",&fPtypeVector,&fPtypeBranch);
    //fSimTree->SetBranchAddress("timingVector",&fTimingVector,&fTimingBranch);
    
    outfile->Write();
    outfile->Close();
}

void NeutronFit_BC537::BuildEventTree(double time)
{
    SetEventTimeWindow(time);
    BuildEventTree();
}



