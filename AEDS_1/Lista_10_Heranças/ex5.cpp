#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Veiculo{
    protected:
    float peso {0};
    int veloc {0};
    float preco {0};
 
    public:
    Veiculo() = default;
 
    Veiculo(float peso, int veloc, float preco){
        this->peso = peso;
        this->veloc = veloc;
        this->preco = preco;
    }
 
    void setPeso(float peso){ this->peso = peso; }
    float getPeso(){ return this->peso; }
 
    void setVeloc(int veloc){ this->veloc = veloc;}
    int getVeloc(){ return this->veloc; }
 
    void setPreco(float preco){ this->preco = preco;}
    float getPreco(){ return this->preco; }
 
    void printVeiculo(){
        cout << "Peso = " << this->peso << endl;
        cout << "Velocidade Maxima = " << this->veloc << endl;
        cout << "Preco = " << this->preco << endl;
    }
};
 
class Motor{
    protected:
    int cilindros {0};
    int potencia {0};
 
    public:
    Motor() = default;
 
    Motor(int cilindros, int potencia){
        this->cilindros = cilindros;
        this->potencia = potencia;
    }
 
    void setCilindros(int cilindros){ this->cilindros = cilindros; }
    int getCilindros(){ return this->cilindros; }
 
    void setPotencia(int potencia){ this->potencia = potencia;}
    int getPotencia(){ return this->potencia; }
 
    void printMotor(){
        cout << "Cilindros = " << this->cilindros << endl;
        cout << "Potencia = " << this->potencia << endl;
    }
};
 
class CarroPasseio : public Veiculo, public Motor{
    protected:
    string modelo {""};
    string cor {""};
 
    public:
    CarroPasseio() : Veiculo(), Motor() {}
 
    //Faz referencia aos construtores das classes Veiculo e Motor
    CarroPasseio(string modelo, string cor, int cilindros, int potencia, float peso, int veloc, float preco) : 
    Motor(cilindros, potencia), Veiculo(peso, veloc, preco){
        this->modelo = modelo;
        this->cor = cor;
    }
 
    void setModelo(string modelo){ this->modelo = modelo;}
    string getModelo(){ return this->modelo;}
 
    void setCor(string cor){ this->cor = cor;}
    string getCor(){ return this->cor;}
 
    void printCarroPasseio(){
        Veiculo::printVeiculo(); //Chama print de Veiculo
        Motor::printMotor(); //Chama print de Motor
 
        cout << "Modelo = " << this->modelo << endl;
        cout << "Cor = " << this->cor << endl;
    }
};
 
int main(){
    CarroPasseio *carro1 = new CarroPasseio("Honda", "Azul", 1000, 5000, 300.50, 200, 80000);
 
    cout << "Estado inicial do Carro de Passeio:\n\n";
    carro1->printCarroPasseio();
 
    carro1->setModelo("Volkswagen"); //CarroPasseio::setModelo()
    carro1->setCilindros(900); //Motor::setCilindros()
    carro1->setPreco(10000); //Veiculo::setPreco()
 
    getchar();
 
    cout << "Estado final do Carro de Passeio:\n\n";
    carro1->printCarroPasseio();
 
    return 0;
}
