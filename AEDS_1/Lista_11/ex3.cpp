#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class ContaCorrente{
    protected:
    float saldo {0};

    public:
    ContaCorrente() = default;
    ContaCorrente(float init){
        this->saldo = init;
    };

    void setSaldo(float saldo){this->saldo = saldo; }
    float getSaldo(){return this->saldo; }

    void depositar(float depo){
        this->saldo += depo;
    }

    virtual void sacar(float saque){
        this->saldo -= saque + saque/200; //saque/200 = 0.5% do valor do saque
    }
};

class ContaEspecial : public ContaCorrente{
    public:
    ContaEspecial(float init){
        this->saldo = init;
    };

    void sacar(float saque){
        this->saldo -= saque + saque/1000; //saque/1000 = 0.1% do valor do saque
    }
};

int main(){
    ContaCorrente *conta = new ContaCorrente(1000);

    cout << "Classe ContaCorrente:\n";
    cout << "Saldo inicial = " << conta->getSaldo() << " R$"<< endl;
    conta->sacar(100);
    cout << "Apos saque de 100R$ = " << conta->getSaldo() << " R$"<< endl;

    conta = new ContaEspecial(1000);

    cout << "\nClasse ContaEspecial:\n";
    cout << "Saldo inicial = " << conta->getSaldo() << " R$"<< endl;
    conta->sacar(100);
    cout << "Apos saque de 100R$ = " << conta->getSaldo() << " R$"<< endl;

    delete conta;
}