
#include "Fitter.hh"

void Fitter::InitializeParameters()
{
    fParameters[0] = 0.639;
    fParameters[1] = 1.462;
    fParameters[2] = 0.373;
    fParameters[3] = 0.968;
    fParameters[4] = 0.;
    
    fMinimizeCounter = 0;

    fSum = 0;
    fSum2 = 0;
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

Fitter::~Fitter() {}

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

void Fitter::Run(double a1, double a2, double a3, double a4, double carbon) 
{
    SetParameters(a1,a2,a3,a4,carbon);
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

vec Fitter::NelderMead(vec initial_vec, int itermax)
{
    std::cout << "starting Nelder Mead method... " << std::endl;
    
    double inc0 = 0.01;   // a1
    double inc1 = 0.01;  // a2
    double inc2 = 0.01; // a3
    double inc3 = 0.01;  // a4
    double inc4 = 0.0001;  // carbon

    vec v0(initial_vec);
    vec v1(initial_vec); v1.set(0,v1.at(0)+inc0);
    vec v2(initial_vec); v2.set(1,v1.at(1)+inc1);
    vec v3(initial_vec); v3.set(2,v1.at(2)+inc2);
    vec v4(initial_vec); v4.set(3,v1.at(3)+inc3);
    vec v5(initial_vec); v5.set(4,v1.at(4)+inc4);

    std::vector<vec> nmvec;
    nmvec.push_back(v0);
    nmvec.push_back(v1);
    nmvec.push_back(v2);
    nmvec.push_back(v3);
    nmvec.push_back(v4);
    nmvec.push_back(v5);

    std::cout << "calculating chi2's for the initial simplex..." << std::endl;
    std::vector<double> chi2vec;
    for(int i=0; i<int(nmvec.size()); i++) {
        std::cout << "simplex " << i+1 << std::endl;
        SetParameters(nmvec.at(i).par_array());         
        SortAllRuns();
        chi2vec.push_back(DoChi2());
    } 
        
    std::cout << "starting the Nelder-Mead iterations..." << std::endl;
    //////////////////////////////////////////////////////////////////
    for(int iter=1; iter<=itermax; iter++) {

        std::vector<vec> temp_par;
        std::vector<double> temp_chi2;
        temp_par.resize(6);
        temp_chi2.resize(6);

        // reordering...
        double test = 1e100;
        int val = 0;
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
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
        for(int i=0; i<6; i++) {
            std::cout << " chi2 = " << chi2vec.at(i);
            std::cout << " pars = ";
            for(int j=0; j<4; j++) std::cout << nmvec.at(i).at(j) << " , "; std::cout << nmvec.at(i).at(4);
            std::cout << std::endl;
        }
        
    
        vec B(nmvec.at(0)); double B_chi2 = chi2vec.at(0);
        vec G(nmvec.at(1)); double G_chi2 = chi2vec.at(1);
        vec W(nmvec.at(5)); double W_chi2 = chi2vec.at(5);
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
        nmvec.at(5) = W; chi2vec.at(5) = W_chi2;
    
        std::cout << std::endl << "finished iteration # " << iter << "/" << itermax << std::endl << std::endl;
        
        // end of logical loop
    }

    std::vector<vec> temp_par;
    std::vector<double> temp_chi2;
    temp_par.resize(6);
    temp_chi2.resize(6);
    double test = 1e100;
    int val = 0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
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
    for(int i=0; i<6; i++) {
        std::cout << " chi2 = " << chi2vec.at(i);
        std::cout << " pars = ";
        for(int j=0; j<4; j++) std::cout << nmvec.at(i).at(j) << " , "; std::cout << nmvec.at(i).at(4);
        std::cout << std::endl;
    }
     
    Run(nmvec.at(0).at(0), nmvec.at(0).at(1), nmvec.at(0).at(2), nmvec.at(0).at(3), nmvec.at(0).at(4));
    return nmvec.at(0);

   //////////////////////////////////////////////////////////////////
}

vec Fitter::NelderMead(double a1, double a2, double a3, double a4, double carbon, int itermax) 
{
    vec v(a1,a2,a3,a4,carbon);
    return NelderMead(v,itermax);
}

int Fitter::MinimizeGSL(std::string name)
{
    SortAllRuns();

    if(name=="kVectorBFGS")             ROOT::Math::GSLMinimizer mini( ROOT::Math::kVectorBFGS );
    else if(name == "kConjugateFR")     ROOT::Math::GSLMinimizer mini( ROOT::Math::kConjugateFR );  
    else if(name == "kConjugatePR")     ROOT::Math::GSLMinimizer mini( ROOT::Math::kConjugatePR );  
    else if(name == "kVectorBFGS2")     ROOT::Math::GSLMinimizer mini( ROOT::Math::kVectorBFGS2 );  
    else if(name == "kSteepestDescent") ROOT::Math::GSLMinimizer mini( ROOT::Math::kSteepestDescent );  
    else {                              ROOT::Math::GSLMinimizer mini( ROOT::Math::kVectorBFGS ); std::cout << "using kVectorBFGS minimizer" << std::endl; }

    //ROOT::Math::GSLMinimizer mini( ROOT::Math::kVectorBFGS );
    ROOT::Math::GSLMinimizer mini( ROOT::Math::kConjugatePR );

    mini.SetMaxFunctionCalls(1000);
    mini.SetMaxIterations(100);
    mini.SetTolerance(0.0001);
    
    //ROOT::Math::Functor f((&Func)(&nm_val),5);
    ROOT::Math::Functor f(this,&Fitter::FitValue,5);
    double step[5] = { 0.1,0.2,0.1,0.1 ,0.01 };
    double variable[5] = { 0.639, 1.462, 0.373, 0.968, 0 };
    
    mini.SetFunction(f);
    mini.SetVariable(0,"a1",variable[0],step[0]);
    mini.SetVariable(1,"a2",variable[1],step[1]);
    mini.SetVariable(2,"a3",variable[2],step[2]);
    mini.SetVariable(3,"a4",variable[3],step[3]);
    mini.SetVariable(4,"carbon",variable[4],step[4]);

    mini.Minimize();

    return 0;
        
}

int Fitter::MinimizeSimAn()
{
    SortAllRuns();

    ROOT::Math::GSLSimAnMinimizer mini;

    mini.SetMaxFunctionCalls(1000);
    mini.SetMaxIterations(100);
    mini.SetTolerance(0.0001);

    ROOT::Math::Functor f(this,&Fitter::FitValue,5);
    double step[5] = { 0.1,0.2,0.1,0.1 ,0.01 };
    double variable[5] = { 0.639, 1.462, 0.373, 0.968, 0 };

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

    mini.SetPrintLevel(4);
    mini.Minimize();

    const double *xs = mini.X();
    std::cout << "Best fit: Chi2(" << xs[0] << "," << xs[1] << "," << xs[2] << "," << xs[3] << "," << xs[4] << ")" << std::endl;
    //std::cout << FitValue(xs);
    return 0;

}



