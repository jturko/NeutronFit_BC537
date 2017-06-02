
#include "Fitter.cc"

void runSimAn()
{
    //Fitter fit(50,37,20,15,18,58,56,52);    
    Fitter fit(50, 46, 38, 2, 25, 4, 18, 58, 55 ,52);
    
    fit.SetSimAnHigh(   0,  0.92);      // a1
    fit.SetSimAnLow(    0,  0.55);
    fit.SetSimAnStep(   0,  0.005);
    
    fit.SetSimAnHigh(   1,  6.2);       // a2 
    fit.SetSimAnLow(    1,  1.5);
    fit.SetSimAnStep(   1,  0.005);
    
    fit.SetSimAnHigh(   2,  0.34);      // a3
    fit.SetSimAnLow(    2,  0.13);
    fit.SetSimAnStep(   2,  0.005);
    
    fit.SetSimAnHigh(   3,  1.05);      // a4
    fit.SetSimAnLow(    3,  0.95);
    fit.SetSimAnStep(   3,  0.005);
    
    fit.SetSimAnHigh(   4,  0.02);      // 12C
    fit.SetSimAnLow(    4,  -0.0001);
    fit.SetSimAnStep(   4,  0.0001);
    
    fit.SetSimAnHigh(   5,  0.25);      // A
    fit.SetSimAnLow(    5,  0.10);
    fit.SetSimAnStep(   5,  0.01);
    
    fit.SetSimAnHigh(   6,  0.25);      // B
    fit.SetSimAnLow(    6,  0.10);
    fit.SetSimAnStep(   6,  0.01);
    
    fit.SetSimAnHigh(   7,  0.01);      // C
    fit.SetSimAnLow(    7,  0.0001);
    fit.SetSimAnStep(   7,  0.0001);

    fit.SetInLoopMax(100);
    fit.SetStartChi2(2);    

    double T_i = 10;
    double T_f = 0.01;
    double alpha = 0.99;

    fit.MyMinimizeSimAn(alpha,T_i,T_f);

}
