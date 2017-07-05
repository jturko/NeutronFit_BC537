
#include "Fitter.hh"

void Fitter::InitializeParameters()
{
    fParameters[0] = 0.639;
    fParameters[1] = 1.462;
    fParameters[2] = 0.373;
    fParameters[3] = 0.968;
    fParameters[4] = 0.;
    fParameters[5] = 0.123;
    fParameters[6] = 0.125;
    fParameters[7] = 0.0074;
    
    SetSmearingCoeff(0.130631,0.135853,1.20556e-6); 
   
    fMinimizeCounter = 0;
 
    fNPar = 9;
    //const int nPar = (const int)fNPar; 
    fXhigh = new double[fNPar];
    fXlow = new double[fNPar];
    fXstep = new double[fNPar];

    // a1
    SetSimAnHigh(0,1);
    SetSimAnLow(0,0.5);    
    SetSimAnStep(0,0.01);

    // a2
    SetSimAnHigh(1,10);
    SetSimAnLow(1,1);
    SetSimAnStep(1,0.5);
    
    // a3
    SetSimAnHigh(2,0.5);
    SetSimAnLow(2,0.1);
    SetSimAnStep(2,0.01);
    
    // a4
    SetSimAnHigh(3,1.2);
    SetSimAnLow(3,0.8);
    SetSimAnStep(3,0.01);
    
    // 12C
    SetSimAnHigh(4,0.02);
    SetSimAnLow(4,-0.0001);
    SetSimAnStep(4,0.0001);
    
    // A
    SetSimAnHigh(5,0.4);
    SetSimAnLow(5,0);
    SetSimAnStep(5,0.025);
    
    // B
    SetSimAnHigh(6,0.3);
    SetSimAnLow(6,0);
    SetSimAnStep(6,0.025);
    
    // C
    SetSimAnHigh(7,0.01);
    SetSimAnLow(7,0);
    SetSimAnStep(7,0.001);

    // Offset
    SetSimAnHighOffset(20);
    SetSimAnLowOffset(0);
    SetSimAnStepOffset(1);

    fInloopmax = 10;
    fStartChi2 = 10;

    fSum = 0;
    fSum2 = 0;

    fCurrentSortMT = 0;
    fRunMT = false;
}

void Fitter::Draw()
{
    if(!fCanvas) {
        fCanvas = new TCanvas();
        if(GetNumberOfNeutronFit_BC537s() == 1) fCanvas->Divide(1);
        else if(GetNumberOfNeutronFit_BC537s() == 2) fCanvas->Divide(2);
        else if(GetNumberOfNeutronFit_BC537s() == 3) fCanvas->Divide(3);
        else if(GetNumberOfNeutronFit_BC537s() == 4) fCanvas->Divide(2,2);
        else if(GetNumberOfNeutronFit_BC537s() == 6) fCanvas->Divide(2,3);
        else if(GetNumberOfNeutronFit_BC537s() == 8) fCanvas->Divide(2,4);
        else if(GetNumberOfNeutronFit_BC537s() == 10) fCanvas->Divide(2,5);
        else { std::cout << "more/less NeutronFit_BC537s that I know how to draw!" << std::endl; return; }
    }
    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
        fCanvas->cd(i+1);
        gPad->Clear();
        fNeutronFit_BC537Vector.at(i).Draw();
        gPad->Update();
    }
}

Fitter::Fitter() { InitializeParameters(); } 

Fitter::~Fitter() 
{
    //for(int i=0; i<(int)fThreadVector.size(); i++) {
    //    fThreadVector.at(i)->Delete();
    //    delete fThreadVector.at(i);
    //}
}

Fitter::Fitter(int one)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    InitializeParameters();
}

Fitter::Fitter(int one, int two)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    InitializeParameters();
}

Fitter::Fitter(int one, int two, int three)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    SetNextNeutronFit_BC537(three);
    InitializeParameters();
}

Fitter::Fitter(int one, int two, int three, int four)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    SetNextNeutronFit_BC537(three);
    SetNextNeutronFit_BC537(four);
    InitializeParameters();
}

Fitter::Fitter(int one, int two, int three, int four, int five, int six)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    SetNextNeutronFit_BC537(three);
    SetNextNeutronFit_BC537(four);
    SetNextNeutronFit_BC537(five);
    SetNextNeutronFit_BC537(six);
    InitializeParameters();
}

Fitter::Fitter(int one, int two, int three, int four, int five, int six, int seven, int eight)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    SetNextNeutronFit_BC537(three);
    SetNextNeutronFit_BC537(four);
    SetNextNeutronFit_BC537(five);
    SetNextNeutronFit_BC537(six);
    SetNextNeutronFit_BC537(seven);
    SetNextNeutronFit_BC537(eight);
    InitializeParameters();
}

Fitter::Fitter(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten)
{
    fCanvas = NULL;
    SetNextNeutronFit_BC537(one);
    SetNextNeutronFit_BC537(two);
    SetNextNeutronFit_BC537(three);
    SetNextNeutronFit_BC537(four);
    SetNextNeutronFit_BC537(five);
    SetNextNeutronFit_BC537(six);
    SetNextNeutronFit_BC537(seven);
    SetNextNeutronFit_BC537(eight);
    SetNextNeutronFit_BC537(nine);
    SetNextNeutronFit_BC537(ten);
    InitializeParameters();
}

void Fitter::RunOffset(double a1, double a2, double a3, double a4, double offset) 
{
    SetParameters(a1,a2,a3,a4, fParameters[4],fParameters[5],fParameters[6],fParameters[7]);   
    SetOffset(offset);
    PrintParameters();
    if(!fCanvas) {
        fCanvas = new TCanvas();
        if(GetNumberOfNeutronFit_BC537s() == 1) fCanvas->Divide(1);
        else if(GetNumberOfNeutronFit_BC537s() == 2) fCanvas->Divide(2);
        else if(GetNumberOfNeutronFit_BC537s() == 3) fCanvas->Divide(3);
        else if(GetNumberOfNeutronFit_BC537s() == 4) fCanvas->Divide(2,2);
        else if(GetNumberOfNeutronFit_BC537s() == 6) fCanvas->Divide(2,3);
        else if(GetNumberOfNeutronFit_BC537s() == 8) fCanvas->Divide(2,4);
        else if(GetNumberOfNeutronFit_BC537s() == 10) fCanvas->Divide(2,5);
        else { std::cout << "more/less NeutronFit_BC537s that I know how to draw!" << std::endl; return; }
    }
    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
        SortRun(i);
        fCanvas->cd(i+1);
        gPad->Clear();
        fNeutronFit_BC537Vector.at(i).Draw();
        gPad->Update();
    }
    fSum = 0.;
    fSum2 = 0.;
    for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum += fNeutronFit_BC537Vector.at(i).DoChi2();
    for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum2 += fNeutronFit_BC537Vector.at(i).DoChi2() * fNeutronFit_BC537Vector.at(i).DoChi2();
    fSum /= double(GetNumberOfNeutronFit_BC537s());
    fSum2 /= double(GetNumberOfNeutronFit_BC537s());
    std::cout << "sum(chi2)/nfits = " << fSum << " | sum((chi2)^2)/nfits = " << fSum2 << std::endl;
}
void Fitter::Run(double a1, double a2, double a3, double a4, double carbon, double A, double B, double C) 
{
    SetParameters(a1,a2,a3,a4,carbon,A,B,C);
    PrintParameters();
    if(!fCanvas) {
        fCanvas = new TCanvas();
        if(GetNumberOfNeutronFit_BC537s() == 1) fCanvas->Divide(1);
        else if(GetNumberOfNeutronFit_BC537s() == 2) fCanvas->Divide(2);
        else if(GetNumberOfNeutronFit_BC537s() == 3) fCanvas->Divide(3);
        else if(GetNumberOfNeutronFit_BC537s() == 4) fCanvas->Divide(2,2);
        else if(GetNumberOfNeutronFit_BC537s() == 6) fCanvas->Divide(2,3);
        else if(GetNumberOfNeutronFit_BC537s() == 8) fCanvas->Divide(2,4);
        else if(GetNumberOfNeutronFit_BC537s() == 10) fCanvas->Divide(2,5);
        else { std::cout << "more/less NeutronFit_BC537s that I know how to draw!" << std::endl; return; }
    }
    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
        SortRun(i);
        fCanvas->cd(i+1);
        gPad->Clear();
        fNeutronFit_BC537Vector.at(i).Draw();
        gPad->Update();
    }
    fSum = 0.;
    fSum2 = 0.;
    for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum += fNeutronFit_BC537Vector.at(i).DoChi2();
    for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum2 += fNeutronFit_BC537Vector.at(i).DoChi2() * fNeutronFit_BC537Vector.at(i).DoChi2();
    fSum /= double(GetNumberOfNeutronFit_BC537s());
    fSum2 /= double(GetNumberOfNeutronFit_BC537s());
    std::cout << "sum(chi2)/nfits = " << fSum << " | sum((chi2)^2)/nfits = " << fSum2 << std::endl;
}

void Fitter::DrawToFile(std::string input)
{
    std::cout << "drawing all NeutronFit_BC537s to output file \"" << input << "\" ... " << std::flush;
    TCanvas * out = new TCanvas();
    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) 
    {
        std::string name = input;
        fNeutronFit_BC537Vector.at(i).Draw();
        if(i==0) {
            name += "(";
            out->Print(name.c_str(),"pdf");
        }
        else if(i==GetNumberOfNeutronFit_BC537s()-1) {
            name += ")";
            out->Print(name.c_str(),"pdf");
        }
        else out->Print(name.c_str(),"pdf");
    }
    delete out;
    std::cout << " done!" << std::endl;

}

void Fitter::SortAllRunsMT() 
{
    //std::vector<TThread*> thvec;
    //for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
    //    thvec.push_back(new TThread(Form("Thread_%d",i), (TThread::VoidFunc_t)&Fitter::SortRunMT, (void*)this));
    //    thvec.at(i)->Run();
    //}
    
    //std::vector<TThread*> tList;
    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
        fThreadVector.at(i)->Run();
        //tList.push_back(fThreadVector.at(i));
    }
    
    //while(int(tList.size())>0) {
    //    std::cout << "completed " << (GetNumberOfNeutronFit_BC537s()-int(tList.size())) << "/" << GetNumberOfNeutronFit_BC537s() << "\r" << std::flush;
    //    for(int i=0; i<int(tList.size()); i++) {
    //        if(tList.at(i)->GetState() == TThread::kCanceledState) {
    //            tList.erase(std::remove(tList.begin(),tList.end(),tList.at(i)),tList.end());
    //            std::cout << "completed " << (GetNumberOfNeutronFit_BC537s()-int(tList.size())) << "/" << GetNumberOfNeutronFit_BC537s() << "\r" << std::flush;
    //        }
    //    }
    //    TThread::Sleep(0,1e6);
    //}    
    //std::cout << std::flush << std::endl;

    for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) {
        //std::cout << "trying to join thread " << i << std::endl;
        fThreadVector.at(i)->Join();
        //std::cout << "done! " << i << std::endl;
    }
    //while(fThreadVector.at(0)->Exists() > 1) {
    //    //std::cout << "threads running = " << fThreadVector.at(0)->Exists() << " ... sleeping..." << std::endl;
    //    TThread::Ps();
    //    std::cout << std::endl;
    //    TThread::Sleep(1,0);
    //}
    
    //TThread::CleanUp();

    //TThread::Ps();
    //TThread::Sleep(10,0);
    //TThread::Ps();
    
    DoChi2();
}

void Fitter::SetNextNeutronFit_BC537(int i) {
    NeutronFit_BC537 * hfit = new NeutronFit_BC537(i);
    SetNextNeutronFit_BC537(*hfit);
    //fThreadVector.push_back(new TThread(Form("Thread_%d",i), (void (*) (void *))&Fitter::SortRunMT, (void*)this));
    fThreadVector.push_back(new TThread(Form("Thread_%d",i), (TThread::VoidRtnFunc_t)&Fitter::SortRunMT, (void*)this));
    //fThreadVector.push_back(new TThread(Form("Thread_%d",i), (TThread::VoidFunc_t)&Fitter::SortRunMT, (void*)this));
} 

vec Fitter::NelderMead(vec initial_vec, int itermax)
{
    std::cout << "starting Nelder Mead method... " << std::endl;
    
    double inc0 = 0.01;   // a1
    double inc1 = 0.01;  // a2
    double inc2 = 0.01; // a3
    double inc3 = 0.01;  // a4
    double inc4 = 0.0001;  // carbon
    double inc5 = 0.05; // A
    double inc6 = 0.02; // B
    double inc7 = 0.0005; // C

    vec v0(initial_vec);
    vec v1(initial_vec); v1.set(0,v1.at(0)+inc0);
    vec v2(initial_vec); v2.set(1,v1.at(1)+inc1);
    vec v3(initial_vec); v3.set(2,v1.at(2)+inc2);
    vec v4(initial_vec); v4.set(3,v1.at(3)+inc3);
    vec v5(initial_vec); v5.set(4,v1.at(4)+inc4);
    vec v6(initial_vec); v6.set(5,v1.at(5)+inc5);
    vec v7(initial_vec); v7.set(6,v1.at(6)+inc6);
    vec v8(initial_vec); v8.set(7,v1.at(7)+inc7);

    std::vector<vec> nmvec;
    nmvec.push_back(v0);
    nmvec.push_back(v1);
    nmvec.push_back(v2);
    nmvec.push_back(v3);
    nmvec.push_back(v4);
    nmvec.push_back(v5);
    nmvec.push_back(v6);
    nmvec.push_back(v7);
    nmvec.push_back(v8);

    std::cout << "calculating chi2's for the initial simplex..." << std::endl;
    std::vector<double> chi2vec;
    for(int i=0; i<int(nmvec.size()); i++) {
        std::cout << "simplex " << i+1 << std::endl;
        SetParameters(nmvec.at(i).par_array());         
        if(fRunMT == true) SortAllRunsMT();
        else SortAllRuns();
        chi2vec.push_back(DoChi2());
    } 
    
    int nmvec_size = int(nmvec.size());
        
    std::cout << "starting the Nelder-Mead iterations..." << std::endl;
    //////////////////////////////////////////////////////////////////
    for(int iter=1; iter<=itermax; iter++) {

        
        std::vector<vec> temp_par;
        std::vector<double> temp_chi2;
        temp_par.resize(nmvec_size);
        temp_chi2.resize(nmvec_size);


        // reordering...
        double test = 1e100;
        int val = 0;
        for(int i=0; i<nmvec_size; i++) {
            for(int j=0; j<nmvec_size; j++) {
                if(chi2vec.at(j) < test) {
                    test = chi2vec.at(j);
                    temp_chi2.at(i) = test;
                    temp_par.at(i) = nmvec.at(j);
                    val = j;
                }
            }
            chi2vec.at(val) = 1e100;
            test = 1e100;
        }
        nmvec = temp_par;
        chi2vec = temp_chi2;
        
        std::cout << "printing the reordered variables..." << std::endl;
        for(int i=0; i<nmvec_size; i++) {
            std::cout << " chi2 = " << chi2vec.at(i);
            std::cout << " pars = ";
            for(int j=0; j<nmvec_size-2; j++) std::cout << nmvec.at(i).at(j) << " , "; std::cout << nmvec.at(i).at(nmvec_size-2);
            std::cout << std::endl;
        }
        
    
        vec B(nmvec.at(0)); double B_chi2 = chi2vec.at(0);
        vec G(nmvec.at(1)); double G_chi2 = chi2vec.at(1);
        vec W(nmvec.at(nmvec_size-1)); double W_chi2 = chi2vec.at(nmvec_size-1);
        vec M = B.midpoint(G); double M_chi2 = nm_val(M);
        vec R = M.scalar_multiply(2.); R.subtract(W); double R_chi2 = nm_val(R);
        vec E = R.scalar_multiply(2.); E.subtract(M); double E_chi2 = 0;
        vec C; double C_chi2 = 0;        
        vec S; double S_chi2 = 0;    

        // now with the logical decisions....
        if(R_chi2 < G_chi2) {  // case 1
            if(B_chi2 < R_chi2) {
                W = R; W_chi2 = R_chi2;
            }
            else {
                E_chi2 = nm_val(E);
                if(E_chi2 < B_chi2) {
                    W = E; W_chi2 = E_chi2;   
                }
                else {
                    W = R; W_chi2 = R_chi2;
                }        
            }
        }
        else {  // case 2
            if(R_chi2 < W_chi2) {
                W = R; W_chi2 = R_chi2;
            }
            vec C1 = W.midpoint(M); double C1_chi2 = nm_val(C1);
            vec C2 = M.midpoint(R); double C2_chi2 = nm_val(C2);
            if(C1_chi2 < C2_chi2) { C = C1; C_chi2 = C1_chi2; }
            else                  { C = C2; C_chi2 = C2_chi2; }
        
            if(C_chi2 < W_chi2) {
                W = C; W_chi2 = C_chi2;
            }
            else {
                S = B.midpoint(W); S_chi2 = nm_val(S);
                W = S; W_chi2 = S_chi2;
                G = M; G_chi2 = M_chi2;
            }
        }
        nmvec.at(0) = B; chi2vec.at(0) = B_chi2;
        nmvec.at(1) = G; chi2vec.at(1) = G_chi2;
        nmvec.at(nmvec_size-1) = W; chi2vec.at(nmvec_size-1) = W_chi2;
    
        std::cout << std::endl << "finished iteration # " << iter << "/" << itermax << std::endl << std::endl;
        
        // end of logical loop
    }

    std::vector<vec> temp_par;
    std::vector<double> temp_chi2;
    temp_par.resize(nmvec_size);
    temp_chi2.resize(nmvec_size);
    double test = 1e100;
    int val = 0;
    for(int i=0; i<nmvec_size; i++) {
        for(int j=0; j<nmvec_size; j++) {
            if(chi2vec.at(j) < test) {
                test = chi2vec.at(j);
                temp_chi2.at(i) = test;
                temp_par.at(i) = nmvec.at(j);
                val = j;
            }
        }
        chi2vec.at(val) = 1e100;
        test = 1e100;
    }
    nmvec = temp_par;
    chi2vec = temp_chi2;
    std::cout << "printing the reordered variables..." << std::endl;
    for(int i=0; i<nmvec_size; i++) {
        std::cout << " chi2 = " << chi2vec.at(i);
        std::cout << " pars = ";
        for(int j=0; j<nmvec_size-2; j++) std::cout << nmvec.at(i).at(j) << " , "; std::cout << nmvec.at(i).at(nmvec_size-2);
        std::cout << std::endl;
    }
     
    Run(nmvec.at(0).at(0), nmvec.at(0).at(1), nmvec.at(0).at(2), nmvec.at(0).at(3), nmvec.at(0).at(4), nmvec.at(0).at(5), nmvec.at(0).at(6), nmvec.at(0).at(7));
    return nmvec.at(0);

   //////////////////////////////////////////////////////////////////
}

vec Fitter::NelderMead(double a1, double a2, double a3, double a4, double carbon, double A, double B, double C, int itermax) 
{
    vec v(a1,a2,a3,a4,carbon,A,B,C);
    return NelderMead(v,itermax);
}

int Fitter::MinimizeGSL(std::string name)
{
    if(fRunMT == true) SortAllRunsMT();
    else SortAllRuns();

    ROOT::Math::GSLMinimizer * mini;

    if(name=="kVectorBFGS")             mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kVectorBFGS );
    else if(name == "kConjugateFR")     mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kConjugateFR );  
    else if(name == "kConjugatePR")     mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kConjugatePR );  
    else if(name == "kVectorBFGS2")     mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kVectorBFGS2 );  
    else if(name == "kSteepestDescent") mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kSteepestDescent );  
    else {                              mini = new ROOT::Math::GSLMinimizer( ROOT::Math::kVectorBFGS ); std::cout << "using kVectorBFGS minimizer" << std::endl; }

    //ROOT::Math::GSLMinimizer mini( ROOT::Math::kVectorBFGS );
    //ROOT::Math::GSLMinimizer mini( ROOT::Math::kConjugatePR );

    mini->SetMaxFunctionCalls(1000);
    mini->SetMaxIterations(100);
    mini->SetTolerance(0.0001);
    
    const int nPar = 8;

    //ROOT::Math::Functor f((&Func)(&nm_val),5);
    ROOT::Math::Functor f(this,&Fitter::FitValue,nPar);
    double step[nPar] = { 0.1,0.2,0.1,0.1 ,0.01, 0.05, 0.02, 0.0005 };
    double variable[nPar] = { 0.639, 1.462, 0.373, 0.968, 0 , 0.123,0.125,0.0075};
    
    mini->SetFunction(f);
    mini->SetVariable(0,"a1",variable[0],step[0]);
    mini->SetVariable(1,"a2",variable[1],step[1]);
    mini->SetVariable(2,"a3",variable[2],step[2]);
    mini->SetVariable(3,"a4",variable[3],step[3]);
    mini->SetVariable(4,"carbon",variable[4],step[4]);
    mini->SetVariable(5,"A",variable[5],step[5]);
    mini->SetVariable(6,"B",variable[6],step[6]);
    mini->SetVariable(7,"C",variable[7],step[7]);

    mini->SetPrintLevel(4);
    mini->Minimize();

    return 0;
        
}

int Fitter::MinimizeSimAn()
{
    if(fRunMT == true) SortAllRunsMT();
    else SortAllRuns();

    ROOT::Math::GSLSimAnMinimizer mini;

    mini.SetMaxFunctionCalls(1000);
    mini.SetMaxIterations(100);
    mini.SetTolerance(0.0001);

    const int nPar = 8;

    ROOT::Math::Functor f(this,&Fitter::FitValue,nPar);
    double step[nPar] = { 0.1,0.2,0.1,0.1 ,0.01, 0.05, 0.02, 0.0005 };
    double variable[nPar] = { 0.639, 1.462, 0.373, 0.968, 0 , 0.123,0.125,0.0075};

    mini.SetFunction(f);
    
    mini.SetVariable(0,"a1",variable[0],step[0]);
    mini.SetVariableLimits(0,0.5,1);
    
    mini.SetVariable(1,"a2",variable[1],step[1]);
    mini.SetVariableLimits(1,1,10);
    
    mini.SetVariable(2,"a3",variable[2],step[2]);
    mini.SetVariableLimits(2,0.1,0.5);
    
    mini.SetVariable(3,"a4",variable[3],step[3]);
    mini.SetVariableLimits(3,0.8,1.2);
    
    mini.SetVariable(4,"carbon",variable[4],step[4]);
    mini.SetVariableLimits(4,0,0.2);

    mini.SetVariable(5,"A",variable[5],step[5]);
    mini.SetVariableLimits(5,0,0.4);
    
    mini.SetVariable(6,"B",variable[6],step[6]);
    mini.SetVariableLimits(6,0,0.3);
    
    mini.SetVariable(7,"C",variable[7],step[6]);
    mini.SetVariableLimits(7,0,0.01);

    mini.SetPrintLevel(4);
    mini.Minimize();

    const double *xs = mini.X();
    std::cout << "Best fit: Chi2(" << xs[0] << "," << xs[1] << "," << xs[2] << "," << xs[3] << "," << xs[4] << "," << xs[5] << "," << xs[6] << "," << xs[7] << ")" << std::endl;
    //std::cout << FitValue(xs);
    return 0;

}

void Fitter::SimAnStep(double * old_soln, double * new_soln) 
{
    fRandom = TRandom3(0);
    //fRandom.RndmArray(fNPar,new_soln);

    for(int i=0; i<8; i++) {
        bool go = true;
        while(go) {
            //std::cout << "par " << i << " randomization ... " << std::endl;
            new_soln[i] = fRandom.Rndm();
            //std::cout << " value from [0,1] = " << new_soln[i] << std::endl;
            new_soln[i] = (old_soln[i]-fXstep[i]) + new_soln[i]*2*fXstep[i];
            //std::cout << " value from [" << old_soln[i]-fXstep[i] << "," << old_soln[i]+fXstep[i] << "] = " << new_soln[i] << std::endl;
            if(new_soln[i] > fXlow[i] && new_soln[i] < fXhigh[i]) go = false;    
        }
    } 
    
}

void Fitter::SimAnStep4(double * old_soln, double * new_soln) 
{
    fRandom = TRandom3(0);

    for(int i=0; i<4; i++) {
        bool go = true;
        while(go) {
            //std::cout << "par " << i << " randomization ... " << std::endl;
            new_soln[i] = fRandom.Rndm();
            //std::cout << " value from [0,1] = " << new_soln[i] << std::endl;
            new_soln[i] = (old_soln[i]-fXstep[i]) + new_soln[i]*2*fXstep[i];
            //std::cout << " value from [" << old_soln[i]-fXstep[i] << "," << old_soln[i]+fXstep[i] << "] = " << new_soln[i] << std::endl;
            if(new_soln[i] > fXlow[i] && new_soln[i] < fXhigh[i]) go = false;    
        }
    } 
}
void Fitter::SimAnStep5(double * old_soln, double * new_soln) 
{
    fRandom = TRandom3(0);

    SimAnStep4(old_soln,new_soln);
    bool go = true;
    while(go) { // 4th element is the offset parameter
        new_soln[4] = fRandom.Rndm();
        new_soln[4] = (old_soln[4]-fXstepOffset) + new_soln[4]*2*fXstepOffset;        
        if(new_soln[4] > fXlowOffset && new_soln[4] < fXhighOffset) go = false;
    }
}
void Fitter::SimAnStep9(double * old_soln, double * new_soln) 
{
    fRandom = TRandom3(0);
    for(int i=0; i<9; i++) {
        bool go = true;
        while(go) {
            new_soln[i] = fRandom.Rndm();
            new_soln[i] = (old_soln[i]-fXstep[i]) + new_soln[i]*2*fXstep[i];
            if(new_soln[i] > fXlow[i] && new_soln[i] < fXhigh[i]) go = false;    
        }
    } 
}

int Fitter::MyMinimizeSimAn(double alpha, double T_0, double T_min)
{
    
    fRandom = TRandom3(0);
    
    const int nPar = 8;
    double old_soln[nPar];
    double new_soln[nPar];
    double best_soln[nPar];
    
    double itermax = TMath::Log(T_min/T_0)/TMath::Log(alpha);
    double T = T_0;
    int iter = 1;
    double old_chi2, new_chi2, best_chi2, delta;   

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(3);

    //  generate x(0) - the initial random solution
    bool badStart = true;
    std::cout << "\t--->>> Looking for a start w/ chi2 < " << fStartChi2 << std::endl << std::endl;
    std::cout << "\ta1\ta2\ta3\ta4\t12C\tA\tB\tC" << std::endl;
    while(badStart) {
        fRandom.RndmArray(nPar,old_soln);
        for(int i=0; i<nPar; i++) old_soln[i] = fXlow[i] + old_soln[i]*(fXhigh[i]-fXlow[i]);
        for(int i=0; i<nPar; i++) std::cout << "\t" << old_soln[i];
        old_chi2 = FitValue((const double *)old_soln); // evaluate initial guess x(0) chi2
        if(old_chi2 < fStartChi2) {
            std::cout << " \tgood start! chi2 = " << old_chi2 << std::endl;
            badStart = false;
        }
        else {
            std::cout << " \tbad start! chi2 = " << old_chi2 << std::endl;
        }
   
    }    
    
     
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::endl;
    std::cout << "\tT_i = " << T_0 << " \tT_f = " << T_min << " \talpha = " << alpha << " \t# of iterations = " << (int(itermax)+1) << " \t# of sub-iterations / T = " << fInloopmax << std::endl;
    std::cout << "\tOffset = " << fNeutronFit_BC537Vector.at(0).fOffset << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\t\ta1\t\ta2\t\ta3\t\ta4\t\t12C\t\tA\t\tB\t\tC" << std::endl;
    std::cout << "\tHigh\t";
    for(int i=0; i<nPar; i++) std::cout << fXhigh[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tLow\t";
    for(int i=0; i<nPar; i++) std::cout << fXlow[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tStep\t";
    for(int i=0; i<nPar; i++) std::cout << fXstep[i] << "\t";
    std::cout << std::endl << std::endl;
   

    //double itermax = 1000;
    //double alpha = 0.98; // factor to reduce the temperature
    //double T = 10000;
    //double T_min = T*TMath::Power(alpha,itermax); // define final temperature based on number of iterations
    
    std::cout << std::fixed << std::setprecision(5);
    
    best_chi2 = old_chi2;
    for(int i=0; i<nPar; i++) best_soln[i] = old_soln[i];
    
    while(T > T_min) {
        for(int inloop = 0; inloop<fInloopmax; inloop++) {        
            SimAnStep(old_soln,new_soln);
            new_chi2 = FitValue((const double *)new_soln);
            if(new_chi2 < best_chi2) {
                best_chi2 = new_chi2;
                std::cout << "\t--->>> new best fit! - chi2 = " << best_chi2 << "\t ( ";
                for(int i=0; i<nPar; i++) {
                    best_soln[i] = new_soln[i];
                    std::cout << best_soln[i] << " , "; 
                }
                std::cout << "\b\b)" << std::endl;
            }
            delta = TMath::Abs(old_chi2 - new_chi2);
            double chance;
            if(new_chi2 < old_chi2) chance = 1;
            else chance = TMath::Exp(-delta/T);
            double rando = fRandom.Rndm();
            
            if(inloop==0) std::cout << "Iter " << iter << "/" << (int(itermax)+1) << "\t T = " << T << "\t old = " << old_chi2 << "\t new = " << new_chi2 << "\t chance = " << chance << std::endl;
            
            if(chance>rando) {     // deciding whether to take the new point or not ( if new chi2 is better than old, chance=1 and we take the new point for sure)
                for(int i=0; i<nPar; i++) old_soln[i] = new_soln[i];
                old_chi2 = new_chi2;
            }       
        }
        //for(int i=0; i<nPar; i++) std::cout << "x(" << iter << ")_" << i << " = " << new_soln[i] << "  ";
        //std::cout << std::endl;
    
        T *= alpha;
        iter++;
    }

    //std::cout << "best chi2 = " << best_chi2 << " w/ parameters ";
    //for(int i=0; i<nPar; i++) std::cout << best_soln[i] << " , ";
    //std::cout << std::endl;
    
    Run(best_soln[0],best_soln[1],best_soln[2],best_soln[3],best_soln[4],best_soln[5],best_soln[6],best_soln[7]);

    return 1;
}



int Fitter::MyMinimizeSimAn4(double alpha, double T_0, double T_min)
{
    
    fRandom = TRandom3(0);
    
    const int nPar = 4;
    double old_soln[nPar];
    double new_soln[nPar];
    double best_soln[nPar];
    
    double itermax = TMath::Log(T_min/T_0)/TMath::Log(alpha);
    double T = T_0;
    int iter = 1;
    double old_chi2, new_chi2, best_chi2, delta;   

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(3);

    //  generate x(0) - the initial random solution
    bool badStart = true;
    std::cout << "\t--->>> Looking for a start w/ chi2 < " << fStartChi2 << std::endl << std::endl;
    std::cout << "\ta1\ta2\ta3\ta4" << std::endl;
    while(badStart) {
        fRandom.RndmArray(nPar,old_soln);
        for(int i=0; i<nPar; i++) old_soln[i] = fXlow[i] + old_soln[i]*(fXhigh[i]-fXlow[i]);
        for(int i=0; i<nPar; i++) std::cout << "\t" << old_soln[i];
        old_chi2 = FitValue4((const double *)old_soln); // evaluate initial guess x(0) chi2
        if(old_chi2 < fStartChi2) {
            std::cout << " \tgood start! chi2 = " << old_chi2 << std::endl;
            badStart = false;
        }
        else {
            std::cout << "  \tbad start! chi2 = " << old_chi2 << std::endl;
        }
   
    }    
    
     
    std::cout << std::fixed << std::setprecision(5);
    std::cout << std::endl;
    std::cout << "\tT_i = " << T_0 << " \tT_f = " << T_min << " \talpha = " << alpha << " \t# of iterations = " << (int(itermax)+1) << " \t# of sub-iterations / T = " << fInloopmax << std::endl;
    std::cout << "\tOffset = " << fNeutronFit_BC537Vector.at(0).fOffset << std::endl;
    std::cout << "\tA = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[0] << "\tB = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[1] 
              << "\tC = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[2] << std::endl;
    std::cout << "\t12C = " << fNeutronFit_BC537Vector.at(0).fCarbonCoeff[0] << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\t\ta1\t\ta2\t\ta3\t\ta4" << std::endl;
    std::cout << "\tHigh\t";
    for(int i=0; i<nPar; i++) std::cout << fXhigh[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tLow\t";
    for(int i=0; i<nPar; i++) std::cout << fXlow[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tStep\t";
    for(int i=0; i<nPar; i++) std::cout << fXstep[i] << "\t";
    std::cout << std::endl << std::endl;
   

    //double itermax = 1000;
    //double alpha = 0.98; // factor to reduce the temperature
    //double T = 10000;
    //double T_min = T*TMath::Power(alpha,itermax); // define final temperature based on number of iterations
    
    std::cout << std::fixed << std::setprecision(5);
    
    best_chi2 = old_chi2;
    for(int i=0; i<nPar; i++) best_soln[i] = old_soln[i];
    
    while(T > T_min) {
        for(int inloop = 0; inloop<fInloopmax; inloop++) {        
            SimAnStep4(old_soln,new_soln);
            new_chi2 = FitValue4((const double *)new_soln);
            if(new_chi2 < best_chi2) {
                best_chi2 = new_chi2;
                std::cout << "\t--->>> new best fit! - chi2 = " << best_chi2 << "\t ( ";
                for(int i=0; i<nPar; i++) {
                    best_soln[i] = new_soln[i];
                    std::cout << best_soln[i] << " , "; 
                }
                std::cout << "\b\b)" << std::endl;
            }
            delta = TMath::Abs(old_chi2 - new_chi2);
            double chance;
            if(new_chi2 < old_chi2) chance = 1;
            else chance = TMath::Exp(-delta/T);
            double rando = fRandom.Rndm();
            
            if(inloop==0) std::cout << "Iter " << iter << "/" << (int(itermax)+1) << "\t T = " << T << "\t old = " << old_chi2 << "\t new = " << new_chi2 << "\t chance = " << chance << std::endl;
            
            if(chance>rando) {     // deciding whether to take the new point or not ( if new chi2 is better than old, chance=1 and we take the new point for sure)
                for(int i=0; i<nPar; i++) old_soln[i] = new_soln[i];
                old_chi2 = new_chi2;
            }       
        }
        //for(int i=0; i<nPar; i++) std::cout << "x(" << iter << ")_" << i << " = " << new_soln[i] << "  ";
        //std::cout << std::endl;
    
        T *= alpha;
        iter++;
    }

    //std::cout << "best chi2 = " << best_chi2 << " w/ parameters ";
    //for(int i=0; i<nPar; i++) std::cout << best_soln[i] << " , ";
    //std::cout << std::endl;
    
    Run(best_soln[0],best_soln[1],best_soln[2],best_soln[3],fNeutronFit_BC537Vector.at(0).fCarbonCoeff[0],
        fNeutronFit_BC537Vector.at(0).fSmearingCoeff[0],fNeutronFit_BC537Vector.at(0).fSmearingCoeff[1],fNeutronFit_BC537Vector.at(0).fSmearingCoeff[2]);

    if(GetNumberOfNeutronFit_BC537s() == 1) {
        std::ofstream outfile;
        std::string filename = "fit_carbon_" + std::to_string(fNeutronFit_BC537Vector.at(0).fCarbonCoeff[0]) + "_smearing_" + std::to_string(fNeutronFit_BC537Vector.at(0).fSmearingCoeff[0]) + "_" + 
                                               std::to_string(fNeutronFit_BC537Vector.at(0).fSmearingCoeff[1]) + "_" + std::to_string(fNeutronFit_BC537Vector.at(0).fSmearingCoeff[2]) + ".out";
        outfile.open(filename.c_str(), std::ios::out | std::ios::app);
        outfile << fRunNumVector.at(0) << "\t";
        outfile << best_soln[0] << "\t" << best_soln[1] << "\t" << best_soln[2] << "\t" << best_soln[3] << "\n";
        outfile.close();
    }

    return 1;
}

int Fitter::MyMinimizeSimAn5(double alpha, double T_0, double T_min)
{
    
    fRandom = TRandom3(0);
    
    const int nPar = 5;
    double old_soln[nPar];
    double new_soln[nPar];
    double best_soln[nPar];
    
    double itermax = TMath::Log(T_min/T_0)/TMath::Log(alpha);
    double T = T_0;
    int iter = 1;
    double old_chi2, new_chi2, best_chi2, delta;   

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(3);

    //  generate x(0) - the initial random solution
    bool badStart = true;
    std::cout << "\t--->>> Looking for a start w/ chi2 < " << fStartChi2 << std::endl << std::endl;
    std::cout << "\ta1\ta2\ta3\ta4\tOffset" << std::endl;
    while(badStart) {
        fRandom.RndmArray(nPar,old_soln);
        for(int i=0; i<nPar-1; i++) old_soln[i] = fXlow[i] + old_soln[i]*(fXhigh[i]-fXlow[i]);
        old_soln[4] = fXlowOffset + old_soln[4]*(fXhighOffset-fXlowOffset);
        for(int i=0; i<nPar; i++) std::cout << "\t" << old_soln[i];
        SetOffset(old_soln[4]);
        old_chi2 = FitValue4((const double *)old_soln); // evaluate initial guess x(0) chi2
        if(old_chi2 < fStartChi2) {
            std::cout << " \t\tgood start! chi2 = " << old_chi2 << std::endl;
            badStart = false;
        }
        else {
            std::cout << " \t\tbad start! chi2 = " << old_chi2 << std::endl;
        }
   
    }    
    
     
    std::cout << std::fixed << std::setprecision(5);
    std::cout << std::endl;
    std::cout << "\tT_i = " << T_0 << " \tT_f = " << T_min << " \talpha = " << alpha << " \t# of iterations = " << (int(itermax)+1) << " \t# of sub-iterations / T = " << fInloopmax << std::endl;
    std::cout << "\tA = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[0] << "\tB = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[1] 
              << "\tC = " << fNeutronFit_BC537Vector.at(0).fSmearingCoeff[2] << std::endl;
    std::cout << "\t12C = " << fNeutronFit_BC537Vector.at(0).fCarbonCoeff[0] << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\t\ta1\t\ta2\t\ta3\t\ta4\t\tOffset" << std::endl;
    std::cout << "\tHigh\t";
    for(int i=0; i<nPar-1; i++) std::cout << fXhigh[i] << "\t";
    std::cout << fXhighOffset << std::endl;
    std::cout << "\tLow\t";
    for(int i=0; i<nPar-1; i++) std::cout << fXlow[i] << "\t";
    std::cout << fXlowOffset << std::endl;
    std::cout << "\tStep\t";
    for(int i=0; i<nPar-1; i++) std::cout << fXstep[i] << "\t";
    std::cout << fXstepOffset << std::endl << std::endl;
   

    //double itermax = 1000;
    //double alpha = 0.98; // factor to reduce the temperature
    //double T = 10000;
    //double T_min = T*TMath::Power(alpha,itermax); // define final temperature based on number of iterations
    
    std::cout << std::fixed << std::setprecision(5);
    
    best_chi2 = old_chi2;
    for(int i=0; i<nPar; i++) best_soln[i] = old_soln[i];
    
    while(T > T_min) {
        for(int inloop = 0; inloop<fInloopmax; inloop++) {        
            SimAnStep5(old_soln,new_soln);
            SetOffset(new_soln[4]);
            new_chi2 = FitValue4((const double *)new_soln);
            if(new_chi2 < best_chi2) {
                best_chi2 = new_chi2;
                std::cout << "\t--->>> new best fit! - chi2 = " << best_chi2 << "\t ( ";
                for(int i=0; i<nPar; i++) {
                    best_soln[i] = new_soln[i];
                    std::cout << best_soln[i] << " , "; 
                }
                std::cout << "\b\b)" << std::endl;
            }
            delta = TMath::Abs(old_chi2 - new_chi2);
            double chance;
            if(new_chi2 < old_chi2) chance = 1;
            else chance = TMath::Exp(-delta/T);
            double rando = fRandom.Rndm();
            
            if(inloop==0) std::cout << "Iter " << iter << "/" << (int(itermax)+1) << "\t T = " << T << "\t old = " << old_chi2 << "\t new = " << new_chi2 << "\t chance = " << chance << std::endl;
            
            if(chance>rando) {     // deciding whether to take the new point or not ( if new chi2 is better than old, chance=1 and we take the new point for sure)
                for(int i=0; i<nPar; i++) old_soln[i] = new_soln[i];
                old_chi2 = new_chi2;
            }       
        }
        //for(int i=0; i<nPar; i++) std::cout << "x(" << iter << ")_" << i << " = " << new_soln[i] << "  ";
        //std::cout << std::endl;
    
        T *= alpha;
        iter++;
    }

    //std::cout << "best chi2 = " << best_chi2 << " w/ parameters ";
    //for(int i=0; i<nPar; i++) std::cout << best_soln[i] << " , ";
    //std::cout << std::endl;
        
    //SetOffset(best_soln[4]);
    //Run(best_soln[0],best_soln[1],best_soln[2],best_soln[3],fNeutronFit_BC537Vector.at(0).fCarbonCoeff[0],
    //    fNeutronFit_BC537Vector.at(0).fSmearingCoeff[0],fNeutronFit_BC537Vector.at(0).fSmearingCoeff[1],fNeutronFit_BC537Vector.at(0).fSmearingCoeff[2]);

    return 1;
}


int Fitter::MyMinimizeSimAn9(double alpha, double T_0, double T_min)
{
    
    fRandom = TRandom3(0);
    
    const int nPar = 9;
    double old_soln[nPar];
    double new_soln[nPar];
    double best_soln[nPar];
    
    double itermax = TMath::Log(T_min/T_0)/TMath::Log(alpha);
    double T = T_0;
    int iter = 1;
    double old_chi2, new_chi2, best_chi2, delta;   

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(3);

    //  generate x(0) - the initial random solution
    bool badStart = true;
    std::cout << "\t--->>> Looking for a start w/ chi2 < " << fStartChi2 << std::endl << std::endl;
    std::cout << "\ta1\ta2\ta3\ta4\t12C\tA\tB\tC\tOffset" << std::endl;
    while(badStart) {
        fRandom.RndmArray(nPar,old_soln);
        for(int i=0; i<nPar; i++) old_soln[i] = fXlow[i] + old_soln[i]*(fXhigh[i]-fXlow[i]);
        for(int i=0; i<nPar; i++) std::cout << "\t" << old_soln[i];
        SetOffset(old_soln[8]);
        old_chi2 = FitValue((const double *)old_soln); // evaluate initial guess x(0) chi2
        if(old_chi2 < fStartChi2) {
            std::cout << " \tgood start! chi2 = " << old_chi2 << std::endl;
            badStart = false;
        }
        else {
            std::cout << " \tbad start! chi2 = " << old_chi2 << std::endl;
        }
   
    }    
    
     
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::endl;
    std::cout << "\tT_i = " << T_0 << " \tT_f = " << T_min << " \talpha = " << alpha << " \t# of iterations = " << (int(itermax)+1) << " \t# of sub-iterations / T = " << fInloopmax << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\t\ta1\t\ta2\t\ta3\t\ta4\t\t12C\t\tA\t\tB\t\tC\t\tOffset" << std::endl;
    std::cout << "\tHigh\t";
    for(int i=0; i<nPar; i++) std::cout << fXhigh[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tLow\t";
    for(int i=0; i<nPar; i++) std::cout << fXlow[i] << "\t";
    std::cout << std::endl;
    std::cout << "\tStep\t";
    for(int i=0; i<nPar; i++) std::cout << fXstep[i] << "\t";
    std::cout << std::endl << std::endl;
   

    //double itermax = 1000;
    //double alpha = 0.98; // factor to reduce the temperature
    //double T = 10000;
    //double T_min = T*TMath::Power(alpha,itermax); // define final temperature based on number of iterations
    
    std::cout << std::fixed << std::setprecision(5);
    
    best_chi2 = old_chi2;
    for(int i=0; i<nPar; i++) best_soln[i] = old_soln[i];
    
    while(T > T_min) {
        for(int inloop = 0; inloop<fInloopmax; inloop++) {        
            SimAnStep9(old_soln,new_soln);
            SetOffset(new_soln[8]);
            new_chi2 = FitValue((const double *)new_soln);
            if(new_chi2 < best_chi2) {
                best_chi2 = new_chi2;
                std::cout << "\t--->>> new best fit! - chi2 = " << best_chi2 << "\t ( ";
                for(int i=0; i<nPar; i++) {
                    best_soln[i] = new_soln[i];
                    std::cout << best_soln[i] << " , "; 
                }
                std::cout << "\b\b)" << std::endl;
            }
            delta = TMath::Abs(old_chi2 - new_chi2);
            double chance;
            if(new_chi2 < old_chi2) chance = 1;
            else chance = TMath::Exp(-delta/T);
            double rando = fRandom.Rndm();
            
            if(inloop==0) std::cout << "Iter " << iter << "/" << (int(itermax)+1) << "\t T = " << T << "\t old = " << old_chi2 << "\t new = " << new_chi2 << "\t chance = " << chance << std::endl;
            
            if(chance>rando) {     // deciding whether to take the new point or not ( if new chi2 is better than old, chance=1 and we take the new point for sure)
                for(int i=0; i<nPar; i++) old_soln[i] = new_soln[i];
                old_chi2 = new_chi2;
            }       
        }
        //for(int i=0; i<nPar; i++) std::cout << "x(" << iter << ")_" << i << " = " << new_soln[i] << "  ";
        //std::cout << std::endl;
    
        T *= alpha;
        iter++;
    }

    //std::cout << "best chi2 = " << best_chi2 << " w/ parameters ";
    //for(int i=0; i<nPar; i++) std::cout << best_soln[i] << " , ";
    //std::cout << std::endl;
        
    SetOffset(best_soln[8]);
    Run(best_soln[0],best_soln[1],best_soln[2],best_soln[3],best_soln[4],best_soln[5],best_soln[6],best_soln[7]);

    return 1;
}

