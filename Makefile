all: fit

fit: 
	g++ -Wall fit.cc -o fit `root-config --cflags --libs --glibs`

clean:
	rm -f fit



