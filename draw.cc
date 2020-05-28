
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    Fitter fit;
 
    fit.LoadAll(true);

    fit.SetSimSortMax(-1);    
    fit.SetChi2Method(2);
    
    fit.SetParameters(4.39550e-01 , 5.79582e-01 , 6.61679e-01 , 1.16190e+00 , 0 , 0 , 0 , 0);
    fit.SetOffset(0);
    fit.SortAllRunsMT();
    fit.WriteToFile("sorted_forpaper_nr.root");

    fit.SetParameters(4.39550e-01 , 5.79582e-01 , 6.61679e-01 , 1.16190e+00 , 0, 0.284 , 0.064 , 0.00002);
    fit.SetOffset(0);
    fit.SortAllRunsMT();
    fit.WriteToFile("sorted_forpaper.root");
    return 0;

}
