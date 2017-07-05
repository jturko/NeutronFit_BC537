
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    Fitter fit;
    fit.LoadAll();
    fit.SetParameters( 0.63150 , 2.32135 , 0.22820 , 0.99025 , -0.00008 , 0.24276 , 0.12991 , 0.00166);
    fit.SetOffset(5.20537);
    
    fit.SortAllRunsMT();
    fit.DrawToFile("draw.pdf");

    return 0;

}
