#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>
#include <limits>
#include <exception>

using namespace std;

//Exception de valores invalidos para a criacao de um triangulo
class triangulo_invalido : public exception{
    const char* what() const throw(){
        return "valores invalidos - triangulo inexistente";
    }
};
 
//Checa se o triangulo passado eh valido
bool possivelTriangulo(double a, double b, double c){
    if(fabs(a) > fabs(b + c))
        throw triangulo_invalido();
    else if(fabs(b) > fabs(a + c))
        throw triangulo_invalido();
    else if(fabs(c) > fabs(a + b))
        throw triangulo_invalido();
    
    return true;
}
 
int main(){
    double a, b, c;
 
    cout << "Insira os respectivos comprimentos dos lados de um triangulo:\n";
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    cout << "C = ";
    cin >> c;
 
    try
    {
        if(possivelTriangulo(a, b, c))
            cout << "O triangulo eh valido!\n";
            cout << "Area do Triangulo ABC = " << (a * c)/2 << "\n";
    }
    catch(exception& e)
    {
        cerr << "\nERROR: " << e.what() << '\n';
    }
 
    return 0;
}