
#include "Fitter.hh"
#include "NeutronFit_BC537.hh"
#include "vec.hh"
#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char * argv[])
{
    std::stringstream sVal;
    int time;
    sVal << argv[1];
    sVal >> time;

    Fitter fit;
    fit.LoadAll();
    fit.BuildEventTrees(double(time));

    return 0;
}
