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

class ArrayIndexOutOfBoundsException : public exception{
    public:
    char const* what() const throw(){
        return "indice invalido";
    }
};
 
class Vetor{
    private:
    int array[10] {0};
 
    public:
    void insereValor(int valor, int index){
        //Caso o indice esteja fora das posicoes do vetor
        if(index < 0 || index > 9){
            throw ArrayIndexOutOfBoundsException();
        }
 
        array[index] = valor;
    }
 
    void printArray(){
        for(int i = 0; i < 10; i++)
            cout << "array[" << i << "] = " << array[i] << "\n";
    }
};
 
int main(){
    Vetor *v1 = new Vetor;
    bool erro_ocorreu = false, continuar;
    int index, val, inseridos = 10;
 
    cin.exceptions(istream::failbit);
 
    cout << "Insira os 10 valores do vetor na ordem que desejar:\n";
    for(int i = 0; i < 10; i++){
        cout << "\nPosicao do vetor: ";
 
        while(continuar == false){
        //1a possivel exception - iostream error (invalid_argument no cin, ou seja, algum valor q n eh int)
            try
            {
                cin >> index;
                continuar = true;
            }
            catch(exception& e)
            { 
                cerr << "\nException: " << e.what() << "\n";
                cout << "Insira um valor valido\n";
                continuar = false;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "array[" << index << "] = ";
 
        //2a possivel exception - NumberFormatException
        try{ 
            cin >> val;
        }catch(exception& e){ 
            cerr << "\nException: " << e.what() << "\n";
            erro_ocorreu = true;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
 
        //3a possivel exception - ArrayIndexOutOfBoundsException
        try{ 
            v1->insereValor(val, index);
        }catch(ArrayIndexOutOfBoundsException& e){ 
            cerr << "\nException: " << e.what() << "\n";
            erro_ocorreu = true;
        }
 
        //Caso alguma exception tenha ocorrido e o vetor nao tenha recebido um valor
        if(erro_ocorreu)
            inseridos--;
 
        //Atualiza a pergunta se alguma exception ocorreu
        erro_ocorreu = false;
        //Atualiza o argumento do while referente ao input do 'index'
        continuar = false;
    }
 
    cout << "\nForam inseridos " << inseridos << " valores corretamente\n";
    cout << "As posicoes do vetor que nao receberam valores permaneceram com o valor 0\n";
 
    cout << "Estado final do vetor:\n";
    v1->printArray();
 
    return 0;
}
