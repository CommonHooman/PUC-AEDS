#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Aluno{
    private:
    string nome {"none"};
    string curso {"none"};
    int grau {1}; //Periodo
    static int count;
 
    public:
 
    Aluno(){
        count++;
    }
 
    ~Aluno(){
        count--;
    }
 
    static int getCount(){ return count; }
 
    void setNome(string nome){ this->nome = nome;}
    string getNome(){ return this->nome;}
 
    void setCurso(string curso){ this->curso = curso;}
    string getCurso(){ return this->curso;}
 
    void setGrau(int grau){ this->grau = grau;}
    int getGrau(){ return this->grau;}
 
    void printAluno(){
        cout << "Aluno \'" << count << "\':\n";
        cout << "Nome = " << this->nome << endl;
        cout << "Curso = " << this->curso << endl;
        cout << "Grau = " << this->grau << endl << endl;
    }
};
 
int Aluno :: count = 0;
 
int main(){
    Aluno *turma[15];
    string nome_generico = "Fulano ", curso_generico = "Curso ";
    char c = 'A';
    int grau_generico = 0;
 
    //Instancia e atribui valores genericos a todos os objetos Aluno criados
    for(int i = 0, j = 64; i < 15; i++, j++){
        turma[i] = new Aluno();
 
        turma[i]->setNome(nome_generico + to_string(i+1));
        turma[i]->setCurso(curso_generico + c);
        turma[i]->setGrau(++grau_generico);
 
        turma[i]->printAluno();
        delete turma[i];
        c++;
    }
 
    cout << "Numero total de alunos = " << turma[0]->getCount() << endl;
 
    return 0;
}