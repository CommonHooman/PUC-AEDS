#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Caminhao : public Motor, public Veiculo{
    protected:
    float toneladas {0};
    float altura_max {0};
    float comprimento {0};
 
    public:
    Caminhao(): Veiculo(), Motor() {} //Construtor default
 
    //Construtor especifico do caminhao (faz uso dos construtores default de Veiculo e Motor)
    Caminhao(float toneladas, float altura_max, float comprimento) : Veiculo(), Motor(){
        this->toneladas = toneladas;
        this->altura_max = altura_max;
        this->comprimento = comprimento;
    }
 
    //Construtor "completo", faz referencia aos construtores parametrizados de Veiculo e Motor
    Caminhao(float toneladas, float altura_max, float comprimento, float peso, int veloc, float preco, int cilindros, int potencia) : 
    Veiculo(peso, veloc, preco), Motor(cilindros, potencia){
        this->toneladas = toneladas;
        this->altura_max = altura_max;
        this->comprimento = comprimento;
    }
 
    //Getters e Setters
    void setToneladas(float toneladas){ this->toneladas = toneladas;}
    float getToneladas(){ return this->toneladas;}
 
    void setAltura(float altura){ this->altura_max = altura;}
    float getAltura(){ return this->altura_max;}
 
    void setComprimento(float comprimento){ this->comprimento = comprimento;}
    float getComprimento(){ return this->comprimento;}
 
    //Funcao de print de todos os dados do objeto
    void printCaminhao(){
        Veiculo::printVeiculo();
        Motor::printMotor();
 
        cout << "Toneladas = " << this->toneladas << "T" << endl;
        cout << "Altura Maxima = " << this->altura_max << " metros" << endl;
        cout << "Comprimento = " << this->comprimento << " metros" << endl;
    }
};
 
int main(){
    //Construtor vazio
    Caminhao *truck1 = new Caminhao();
    //Construtor apenas dos elementos de Caminhao
    Caminhao *truck2 = new Caminhao(500, 7, 16);
    //Construtor "completo", de todos os elementos de Caminhao, Veiculo e Motor
    Caminhao *truck3 = new Caminhao(350, 8, 22, 350000, 140, 110000, 800, 300);
 
    cout << "Caminhao 1:\n";
    truck1->printCaminhao();
    getchar();
 
    cout << "\nCaminhao 2:\n";
    truck2->printCaminhao();
    getchar();
 
    cout << "\nCaminhao 3:\n";
    truck3->printCaminhao();
    getchar();
 
    delete truck1;
    delete truck2;
    delete truck3;
 
    return 0;
}