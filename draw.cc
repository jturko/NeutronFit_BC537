
#include "vec.hh"
#include "NeutronFit_BC537.hh"
#include "Fitter.hh"

int main()
{
    Fitter fit;
 
    fit.LoadAll(true);
    //for(int i=0; i<51; i++) fit.SetNextNeutronFit_BC537(i);
    //for(int i=52; i<64; i++) fit.SetNextNeutronFit_BC537(i);

    //fit.SetSimSortMax(-1);    
    fit.SetChi2Method(2);
    
    //fit.Print();

    //fit.SetParameters( 0.63150 , 2.32135 , 0.22820 , 0.99025 , -0.00008 , 0.24276 , 0.12991 , 0.00166);
    //fit.SetOffset(5.20537);
    
    //fit.SetParameters( 0.57791 , 1.71631 , 0.28050 , 0.99953 , -0.00002 , 0.24233 , 0.11107 , 0.00612);
    //fit.SetParameters( 0.57783 , 1.70985 , 0.282788 , 1.00048 , -8.32195e-05 , 0.259175 , 0.110136 , 0.00615189);
    //fit.SetOffset(4.81);
    
    //fit.SetParameters(0.67065 , 2.84380 , 0.19805 , 1.00051 , 0.00356 , 0.22379 , 0.19175 , 0.00019);
    //fit.SetOffset( 1.11618 );
    
    // these are the best parameters from fit_nessa.out
    //fit.SetParameters( 0.57791 , 1.71631 , 0.28050 , 0.99953 , -0.00002 , 0.24233 , 0.11107 , 0.00612 );
    //fit.SetOffset( 4.80967 );

    // from fit_nessa3_moreLowEnergyRuns.out 
    //fit.SetParameters( 0.56282 , 1.64118 , 0.28513 , 0.98436 , -0.00010 , 0.24314 , 0.10446 , 0.00141 );
    //fit.SetParameters( 0.56282 , 1.64118 , 0.28513 , 0.98436 , -0.00010 , 0, 0, 0);
    //fit.SetOffset( 8.20668 );

    // NelderMead output from best result in fit_nessa3_moreLowEnergyRuns.out
    //fit.SetParameters(0.571959 , 1.58203 , 0.307729 , 0.998759 , -4.90761e-05 , 0.251424 , 0.100439 , 0.00175765);
    //fit.SetOffset(7.61182);

    // fit parameters from plotEdgeFit script output + fit
    //fit.SetParameters(4.39550e-01 , 5.79582e-01 , 6.61679e-01 , 1.16190e+00 , 0 , 0 , 0 , 0);
    //fit.SetParameters(4.39550e-01 , 5.79582e-01 , 6.61679e-01 , 1.16190e+00 , 0, 0.284 , 0.064 , 0.00002);
    //fit.SetOffset(0);

    // massive negative overall chi2 results from fit_nessa3_try3...out
    //fit.SetParameters(0.55917 , 1.64428 , 0.29104 , 1.00054 , 0.00006 , 0.24106 , 0.12978 , 0.00912);
    //fit.SetOffset( 6.16387 );

    // from tulkas: /tulkas/geant4/joey/smearing/deuteron/NeutronFit_BC537/fit_nohup_out/fit_edgefit.out
    //fit.SetParameters(0.42209,0.52858,0.77273,1.08215,0,0.30943,0.21620,0.00358);
    //fit.SetOffset(0);

    // from tulkas: /tulkas/geant4/joey/smearing/deuteron/NeutronFit_BC537/fit.out
    //fit.SetParameters(0.431, 0.467, 0.894, 1.208, 0.00, 0.311, 0.114, 0.006);
    //fit.SetOffset(0);
    
    // published parameters in thesis
    //fit.SetParameters(0.418,0.470,0.849,1.168,0.017,0,0,0);
    fit.SetParameters(0.418,0.470,0.849,1.168,0,0.180,0.126,0.010);
    fit.SetOffset(0);

    fit.SortAllRunsMT();
    
    fit.PrintChi2();

    fit.DrawToFile("draw.pdf");
    fit.WriteToFile("draw.root");

    return 0;

}
