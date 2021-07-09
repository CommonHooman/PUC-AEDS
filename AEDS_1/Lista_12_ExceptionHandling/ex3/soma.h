#ifndef SOMA_H
#define SOMA_H

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>
#include <cstddef>
#include <limits>
#include <exception>

using namespace std;

class ExcecaoAcimaDeCem : public exception{
    virtual char const* what() const throw();
};

class Soma : public ExcecaoAcimaDeCem{
    private:
    int qnt {0};
    float soma_atual {0};
    float soma_ultima {0};

    public:
    Soma();
    void somar(float n);
    int getQnt();
    float getSoma_atual();
    float getSoma_ultima();
};

#endif 