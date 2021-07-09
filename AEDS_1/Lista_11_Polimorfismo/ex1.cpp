#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Funcionario{
    protected:
    string nome {""};
    string cpf {""};
    float salario {0};

    public:
    void setNome(string nome){ this->nome = nome; }
    string getNome(){ return this->nome; }

    void setCpf(string cpf){ this->cpf = cpf; }
    string getCpf(){ return this->cpf; }

    void setSalario(float salario){ this->salario = salario; }
    float getSalario(){ return this->salario; }

    void virtual exibeDados(){
        cout << "Nome = " << this->nome << endl;
        cout << "CPF = " << this->cpf << endl;
        cout << "Salario = " << this->salario << " R$" << endl;
    }
};

class Assistente : protected Funcionario{
    protected:
    string num_matricula {""};

    public:
    void setMatricula(string matricula){ this->num_matricula = matricula; }
    string getMatricula(){ return this->num_matricula; }

    void virtual exibeDados(){
        Funcionario::exibeDados();
        cout << "Matricula = " << this->num_matricula << endl;
    }
};

class Tecnico : protected Assistente{
    protected:   
    float bonus_salario {0};

    public:
    void exibeDados(){
        Assistente::exibeDados();
        cout << "Bonus Salarial = " << this->bonus_salario << " R$" << endl;
    }
};

class Administrativo : protected Assistente{
    protected:
    bool turno_manha {true}; //true = turno da manha, false = turno da noite
    float bonus_noturno {0};

    public:
    void exibeDados(){
        Assistente::exibeDados();
        if(turno_manha){
            cout << "Turno = dia\n";
        }else{
            cout << "Turno = noite\n";
            cout << "Bonus Noturno = " << this->bonus_noturno << " R$" << endl;
        }
    }
};

int main(){
    Funcionario func1;
    Assistente assi1;
    Tecnico tec1;
    Administrativo adm1;

    func1.exibeDados();
    cout << endl;

    assi1.exibeDados();
    cout << endl;

    tec1.exibeDados();
    cout << endl;

    adm1.exibeDados();
    cout << endl;
}