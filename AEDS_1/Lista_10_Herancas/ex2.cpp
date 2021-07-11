#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Empregado{
    private:
    //{ } define um valor default caso o construtor nao inicialize a variavel em questao
    string nome {""};
    string sobrenome {""};
    float salario {0.0};
 
    public:
    Empregado() = default;
 
    Empregado(string nome, string sobrenome, float salario){
        this->nome = nome;
        this->sobrenome = sobrenome;
        this->salario = salario;
    }
 
    Empregado(string nome){
        this->nome = nome;
    }
 
    Empregado(float sal){
        this->salario = sal;
    }
 
    void setNome(string nome){
        this->nome = nome;
    }
 
    string getNome(){ return this->nome; }
 
    void setSobrenome(string sobrenome){
        this->sobrenome = sobrenome;
    }
 
    string getSobrenome(){ return this->sobrenome; }
 
    void setSalario(float salario){
        this->salario = salario;
    }
 
    float getSalario(){ return this->salario; }
 
    float calculaSalarioAnual(){
        return (this->salario * 12); //Nao considerei o decimo terceiro =/
    }
 
    //Aumenta o valor do salario mediante um aumento percentual como parametro
    void aumentaSalario(float aumento){
        this->salario += this->salario * (aumento/100);
    }
};
 
int main(){
    Empregado *em1 = new Empregado("Felipe", "Domingos da Cunha", 10000.00);
    Empregado *em2 = new Empregado("Max do Val");
    Empregado *em4 = new Empregado();
    Empregado *array[] = {em1, em2, em4};
 
    em4->setSalario(8500.10);
 
    for (int i = 0; i < 3; i++){
        cout << "Empregado \'" << i+1 << "\':\n";
        cout << "Nome = " << array[i]->getNome() << endl;
        cout << "Sobrenome = " << array[i]->getSobrenome() << endl;
        cout << "Salario = " << array[i]->getSalario() << endl;
        cout << "Salario Anual = " << array[i]->calculaSalarioAnual() << endl << endl;
    }
 
    em1->aumentaSalario(10);
    em4->aumentaSalario(10);
    cout << "Apos aumento de 10% nos salarios:\n";
    cout << "Salario novo do Empregado 1 = " << em1->getSalario() << endl;
    cout << "Salario novo do Empregado 2 = " << em4->getSalario() << endl << endl;
 
    cout << "Salario Anual do Empregado 1 = " << em1->calculaSalarioAnual() << endl;
    cout << "Salario Anual do Empregado 2 = " << em4->calculaSalarioAnual() << endl;
 
    return 0;
}
