
CXX=g++
CXXFLAGS=-Wall
ROOTLIBS=-lMathMore -lProof
ROOTCONFIG=`root-config --cflags --glibs`
HEADERS = NeutronFit_BC537.hh Fitter.hh
SOURCES = NeutronFit_BC537.cc Fitter.cc

NeutronFit_BC537.o: NeutronFit_BC537.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) NeutronFit_BC537.cc $(ROOTCONFIG)                

Fitter.o: Fitter.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) Fitter.cc $(ROOTCONFIG)                

FitterDict.cxx: $(HEADERS) LinkDef.h
	rootcint -f $@ -c $(CXXFLAGS) -p $^

libFitter.so: FitterDict.cxx $(SOURCES)
	g++ -shared -o $@ $(ROOTCONFIG) $(CXXFLAGS) $(ROOTLIBS) -I$(ROOTSYS)/include $^

clean:
	rm -f *.o *.pcm FitterDict.cxx libFitter.so
