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

#include "soma.h"

using namespace std;

//Class ExcecaoAcimaDeCem
char const* ExcecaoAcimaDeCem::what() const throw(){
    return "Exception: Soma atingiu valor maior que 100";
}


//Class Soma
Soma::Soma() = default;

void Soma::somar(float n){
    this->soma_ultima = this->soma_atual;
    this->soma_atual += n;

    if(this->soma_atual > 100)
        throw ExcecaoAcimaDeCem();
    
    this->qnt++;
}

int Soma::getQnt(){ return this->qnt; }

float Soma::getSoma_atual(){ return this->soma_atual; }

float Soma::getSoma_ultima(){ return this->soma_ultima; }