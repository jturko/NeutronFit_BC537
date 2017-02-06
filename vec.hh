
#ifndef VEC_H
#define VEC_H
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

class vec
{
public:
    vec() {
        set(0,0,0,0,0);
    }
    ~vec() {}

    vec(double e1, double e2, double e3, double e4, double e5) {
        set(e1,e2,e3,e4,e5);
    }

    double at(int i) {
        if(i<0||i>=int(fVector.size())) {
            std::cout << "out of range!" << std::endl;
            return 0.;
        }
        else return fVector.at(i);
    }

    int size() { return fVector.size(); }

    void set(double e1, double e2, double e3, double e4, double e5) {
        fVector.resize(0);
        fVector.push_back(e1); fArray[0] = e1;
        fVector.push_back(e2); fArray[1] = e2;
        fVector.push_back(e3); fArray[2] = e3;
        fVector.push_back(e4); fArray[3] = e4;
        fVector.push_back(e5); fArray[4] = e5;
    }
    void set(int i, double val) {
        if(i<0||i>=int(fVector.size())) {
            std::cout << "out of range!" << std::endl;
            return;
        }
        fVector.at(i) = val; fArray[i] = val;
    }

    void add(vec v) {
        if(v.size() != int(fVector.size())) { std::cout << "error, different vector sizes" << std::endl; return; }
        for(int i=0; i<int(fVector.size()); i++) fVector.at(i) = fVector.at(i) + v.at(i);
    }
    void subtract(vec v) {
        if(v.size() != int(fVector.size())) { std::cout << "error, different vector sizes" << std::endl; return; }
        for(int i=0; i<int(fVector.size()); i++) fVector.at(i) = fVector.at(i) - v.at(i);
    }

    vec scalar_multiply(double num) {
        vec return_vec;
        for(int i=0; i<int(fVector.size()); i++) return_vec.set(i,num*fVector.at(i));
        return return_vec;
    }

    vec midpoint(vec v) {
        vec return_vec;
        if(v.size() != int(fVector.size())) {
            std::cout << "error, different vector sizes" << std::endl;
            return return_vec;
        }
        for(int i=0; i<int(fVector.size()); i++) { return_vec.set(i,0.5*(fVector.at(i) + v.at(i))); }
        return return_vec;
    }
    double * par_array() {
        return fArray;
    }

private:
    std::vector<double> fVector;
    double fArray[5];
};

