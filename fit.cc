
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    //Fitter fit(50,37,20,15,18,58,56,52);    
    
    //Fitter fit(51, 46, 38, 2, 25, 4, 18, 58, 55 ,52);
    
    Fitter fit(50, 46, 38, 2, 25, 4, 18, 58, 55 ,52);
    //fit.SetNextNeutronFit_BC537(49);
    //fit.SetNextNeutronFit_BC537(48);
    //fit.SetNextNeutronFit_BC537(47);
   
    //Fitter fit;
    //fit.LoadAll();    

    fit.SetMT(true);
   
    fit.SetChi2Method(2);

    //fit.SetSimSortMax(1e5);
    fit.SetSimSortMax(1e5);
    fit.PrintSimSortMax();

    fit.SetSimAnHigh(   0,  0.92);      // a1
    fit.SetSimAnLow(    0,  0.15);
    fit.SetSimAnStep(   0,  0.005);
    
    fit.SetSimAnHigh(   1,  6.2);       // a2 
    fit.SetSimAnLow(    1,  0.1);
    fit.SetSimAnStep(   1,  0.02);
    
    fit.SetSimAnHigh(   2,  0.9);      // a3
    fit.SetSimAnLow(    2,  0.13);
    fit.SetSimAnStep(   2,  0.005);
    
    fit.SetSimAnHigh(   3,  1.3);      // a4
    fit.SetSimAnLow(    3,  0.95);
    fit.SetSimAnStep(   3,  0.005);
    
    fit.SetSimAnHigh(   4,  0.02);      // 12C
    fit.SetSimAnLow(    4,  -0.0001);
    fit.SetSimAnStep(   4,  0.0001);
    
    fit.SetSimAnHigh(   5,  0.4);      // A
    fit.SetSimAnLow(    5,  0);
    fit.SetSimAnStep(   5,  0.01);
    
    fit.SetSimAnHigh(   6,  0.4);      // B
    fit.SetSimAnLow(    6,  0);
    fit.SetSimAnStep(   6,  0.01);
    
    fit.SetSimAnHigh(   7,  0.01);      // C
    fit.SetSimAnLow(    7,  0);
    fit.SetSimAnStep(   7,  0.0001);

    fit.SetSimAnHighOffset(20);
    fit.SetSimAnLowOffset(0);
    fit.SetSimAnStepOffset(0.25);

    fit.SetInLoopMax(50);
    fit.SetStartChi2(15);    

    //fit.SetSmearingCoeff(0.130631,0.135853,1.20556e-6);

    double T_i = 5;
    double T_f = 0.01;
    double alpha = 0.999;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //fit.SetSimAnStart( 0.57381 , 1.58280 , 0.30884 , 0.99951 , -0.00006 , 0.24603 , 0.10532 , 0.00169 , 7.55915 );
    //fit.SetInLoopMax(50);
    //alpha = 0.999;
    //T_i = 0.1;    
    //fit.MyMinimizeSimAn9(alpha,T_i,T_f);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    fit.SetSimAnStart( 4.39550e-01 , 5.79582e-01 , 6.61679e-01 , 1.16190e+00 , 0, 0.284 , 0.064 , 0.00002 , 0); // values from fitting the 50%  edge PH
    fit.SetOffset(0);
    fit.SetInLoopMax(50);
    fit.MyMinimizeSimAn(alpha,T_i,T_f);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //fit.MyMinimizeSimAn9(alpha,T_i,T_f);
    
    //fit.SetOffset(4.81);
    //fit.NelderMead(0.57791 , 1.71631 , 0.28050 , 0.99953 , -0.00002 , 0.24233 , 0.11107 , 0.00612);

    return 0;

}
