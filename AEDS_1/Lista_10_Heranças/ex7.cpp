#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Utils{
    public:
    double static toCelsius(double fahren){
        if(fahren < -459.67){
            cerr << "Erro - Valor invalido\n";
            return -500; //Nao existe o valor -500 Celsius
        }else{
            return ((fahren - 32) / 1.8);
        }
    }
};