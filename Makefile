
CXX = g++
CXXFLAGS = -Wall -fPIC
ROOTLIBS = -lMathMore -lProof
ROOTCONFIG=`root-config --cflags --glibs`
HEADERS = NeutronFit_BC537.hh Fitter.hh vec.hh
SOURCES = NeutronFit_BC537.cc Fitter.cc
FITTERLIB = -L. -lFitter

libFitter.so: FitterDict.cxx $(SOURCES)
	g++ -shared -o $@ $(ROOTCONFIG) $(CXXFLAGS) $(ROOTLIBS) -I$(ROOTSYS)/include $^

FitterDict.cxx: $(HEADERS) LinkDef.h
	rootcint -f $@ -c $(CXXFLAGS) -p $^

NeutronFit_BC537.o: NeutronFit_BC537.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) NeutronFit_BC537.cc $(ROOTCONFIG)                

Fitter.o: Fitter.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) Fitter.cc $(ROOTCONFIG)                

fit: runSimAnRes.cc libFitter.so
	$(CXX) $(CXXFLAGS) -o fit $(FITTERLIB) $(ROOTLIBS) $(ROOTCONFIG) $^

clean:
	rm -f *.o *.pcm FitterDict.cxx libFitter.so fit
