
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    Fitter fit;
    fit.LoadAll();
    
    fit.SetSimSortMax();    

    //fit.SetParameters( 0.63150 , 2.32135 , 0.22820 , 0.99025 , -0.00008 , 0.24276 , 0.12991 , 0.00166);
    //fit.SetOffset(5.20537);
    
    fit.SetParameters( 0.57791 , 1.71631 , 0.28050 , 0.99953 , -0.00002 , 0.24233 , 0.11107 , 0.00612);
    fit.SetParameters( 0.57783 , 1.70985 , 0.282788 , 1.00048 , -8.32195e-05 , 0.259175 , 0.110136 , 0.00615189);
    fit.SetOffset(4.81);
    
    fit.SortAllRunsMT();
    fit.DrawToFile("draw.pdf");

    return 0;

}
