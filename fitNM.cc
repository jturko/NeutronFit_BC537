
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    //Fitter fit(50,37,20,15,18,58,56,52);    
    Fitter fit(51, 46, 38, 2, 25, 4, 18, 58, 55 ,52);
    
    fit.SetMT(true);
   
    
    fit.SetOffset(4.81);
    fit.NelderMead(0.57791 , 1.71631 , 0.28050 , 0.99953 , -0.00002 , 0.24233 , 0.11107 , 0.00612, 200);
    
    //fit.SetOffset(5);
    //fit.NelderMead(0.87791 , 5.71631 , 0.22050 , 0.96953 , 0.00002 , 0,0,0, 200);

    //fit.MinimizeSimAn();

    return 0;

}
