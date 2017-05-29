
#ifndef FITTER_H
#define FITTER_H
#endif

#include "NeutronFit_BC537.cc"
#include "vec.hh"

#include "Math/GSLMinimizer.h"
#include "Math/GSLSimAnMinimizer.h"
#include "Math/Functor.h"

#include <sstream>
#include <iostream>
#include <fstream>

class Fitter 
{

public:
    Fitter();
    ~Fitter();

    Fitter(int a);
    Fitter(int a, int b);
    Fitter(int a, int b, int c);
    Fitter(int a, int b, int c, int d);
    Fitter(int a, int b, int c, int d, int e, int f);
    Fitter(int a, int b, int c, int d, int e, int f, int g, int h);
    Fitter(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

    void Draw();
    void Run(double a1=0.639, double a2=1.462, double a3=0.373, double a4=0.968, double carbon=0, double A=0.123, double B=0.125, double C=0.0074);

    bool Check(int i) { if(i<=-1||i>=GetNumberOfNeutronFit_BC537s()) return false; else return true; }
    
    NeutronFit_BC537 * GetNeutronFit_BC537(int i) { if(Check(i)) return &fNeutronFit_BC537Vector[i]; else{ std::cout << "out of bounds!" << std::endl; return NULL;} }
    
    void SetNextNeutronFit_BC537(NeutronFit_BC537 hfit) { fNeutronFit_BC537Vector.push_back(hfit); fRunNumVector.push_back(hfit.GetRunNum());  }
    void SetNextNeutronFit_BC537(int i) {
        NeutronFit_BC537 * hfit = new NeutronFit_BC537(i);
        SetNextNeutronFit_BC537(*hfit);
    }    

    int GetNumberOfNeutronFit_BC537s() { return fNeutronFit_BC537Vector.size(); }
    
    void DrawNeutronFit_BC537(int i) { 
        if(!Check(i)) { std::cout << "out of bounds!" << std::endl; return; }
        if(fCanvas) delete fCanvas; 
        fNeutronFit_BC537Vector.at(i).Draw(); 
    }
    
    void SortRun(int num) { 
        if(Check(num)) { 
            fNeutronFit_BC537Vector.at(num).Sort(fParameters); 
        }
        else{ std::cout << "out of bounds!" << std::endl;} 
    }
    
    void SortAllRuns() { 
        //PrintParameters();
        for(int num=0; num<GetNumberOfNeutronFit_BC537s(); num++) SortRun(num); 
        DoChi2();
    }
    
    void Print() { for(int num=0; num<GetNumberOfNeutronFit_BC537s(); num++) std::cout << "Run# = " << fRunNumVector.at(num) << " ; Energy = " << fNeutronFit_BC537Vector.at(num).GetEnergy() << std::endl; } 

    void SetParameters(double a1, double a2, double a3, double a4, double carbon, double A, double B, double C) {
        fParameters[0]=a1;
        fParameters[1]=a2;
        fParameters[2]=a3;
        fParameters[3]=a4;
        fParameters[4]=carbon;
        fParameters[5]=A;
        fParameters[6]=B;
        fParameters[7]=C;
        for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) fNeutronFit_BC537Vector.at(i).SetParameters(fParameters);
    }
    void SetParameters(double * par) { // expects a par array w/ 8 elements
        for(int i=0; i<8; i++) fParameters[i] = par[i];
        for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) fNeutronFit_BC537Vector.at(i).SetParameters(fParameters);
    }
    void SetOffset(double offset) {
        for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) fNeutronFit_BC537Vector.at(i).SetOffset(offset);
    }    
    void SetSmearingCoeff(double A, double B, double C) {
        for(int i=0; i<GetNumberOfNeutronFit_BC537s(); i++) fNeutronFit_BC537Vector.at(i).SetSmearingCoeff(A,B,C);
    }
    double GetOffset() { return fNeutronFit_BC537Vector.at(0).GetOffset(); }
    double GetSmearingCoeff(int i) { return fNeutronFit_BC537Vector.at(0).GetSmearingCoeff(i); }

    void PrintParameters() { 
        std::cout << "     a1 = " << fParameters[0] << std::endl;
        std::cout << "     a2 = " << fParameters[1] << std::endl;
        std::cout << "     a3 = " << fParameters[2] << std::endl;
        std::cout << "     a4 = " << fParameters[3] << std::endl;
        std::cout << " carbon = " << fParameters[4] << std::endl;
        std::cout << "      A = " << fParameters[5] << std::endl;
        std::cout << "      B = " << fParameters[6] << std::endl;
        std::cout << "      C = " << fParameters[7] << std::endl;
        std::cout << " offset = " << fNeutronFit_BC537Vector.at(0).GetOffset() << std::endl;
    }

    void InitializeParameters();

    //void NelderMead(int itermax = 50);
    //vec NelderMead(vec initial_vec, int itermax = 50);
    //void NelderMead3(double a1=0.639, double a2=1.462, double a3=0.373, double a4=0.968, double carbon=0, int itermax=50);    
    vec NelderMead(double a1=0.639, double a2=1.462, double a3=0.373, double a4=0.968, double carbon=0, double A=0.123, double B=0.125, double C=0.0074, int itermax=50);
    vec NelderMead(vec input, int itermax=50);
    
    double DoChi2() { 
        fSum = 0.;
        fSum2 = 0.;
        for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum += fNeutronFit_BC537Vector.at(i).DoChi2();
        for(int i=0;i<GetNumberOfNeutronFit_BC537s();i++) fSum2 += fNeutronFit_BC537Vector.at(i).DoChi2() * fNeutronFit_BC537Vector.at(i).DoChi2();
        fSum /= double(GetNumberOfNeutronFit_BC537s());
        fSum2 /= double(GetNumberOfNeutronFit_BC537s());    
    
        return fSum; // CHANGE THIS TO SET WHAT WE WILL MINIMIZE [ chi2 or (chi2)^2 ]
    }
        
    double nm_val(double * par) {
        SetParameters(par);
        SortAllRuns();
        return DoChi2();
    }
    double nm_val(vec v) {
        SetParameters(v.par_array());
        SortAllRuns();
        return DoChi2();
    }
    
    double FitValue(const double * par) {
        double mypar[8];
        for(int i=0; i<8; i++) mypar[i]=par[i];
        SetParameters(mypar);
        //if(DidParametersChange(mypar)) SortAllRuns();
        SortAllRuns();
        
        double val = DoChi2();

        return val;
    }
    bool DidParametersChange(double * par) {
        for(int i=0; i<8; i++) {
            if(TMath::Abs(fParameters[i] - par[i] > 0.00001)) return true;
        }
        return false;
    }    
    int MinimizeGSL(std::string name="kVectorBFGS");
    int MinimizeSimAn();
    int MyMinimizeSimAn(double alpha = 0.9, double T_0 = 10000, double T_min = 1);   
 

    void DrawToFile(std::string name);


    std::vector<NeutronFit_BC537> fNeutronFit_BC537Vector;   
    std::vector<int> fRunNumVector;

    double fParameters[8];   
 
    TCanvas * fCanvas;
    
    int fMinimizeCounter;
    //ofstream fOutStream;    

    double fSum;
    double fSum2;

    int fNPar;
    TRandom3 fRandom;
    
    void SimAnStep(double * old_soln, double * new_soln);
    
    void SetSimAnHigh(int i, double val) {
        fXhigh[i] = val;
    }
    void SetSimAnLow(int i, double val) {
        fXlow[i] = val;
    }
    void SetSimAnStep(int i, double val) {
        fXstep[i] = val;
    }
    
    double * fXhigh;
    double * fXlow;
    double * fXstep;


};

