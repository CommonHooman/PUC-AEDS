#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>
#include <limits>

using namespace std;

//Esse programa faz uso da biblioteca <limits>

int main(){
    int inteiro;
    bool erro;

    //Libera o lancamento de excecoes pela stream de input (cin)
    cin.exceptions(istream::failbit);

    do{
        try
        {
            cout << "Insira um numero inteiro qualquer:\n";
            cin >> inteiro;
            erro = false;
        }
        //ios::failure -> falha na stream de input/output
        catch(const ios::failure& e)
        {
            cerr << "\nERRO: " << e.what() << '\n';
            cout << "Insira um valor valido\n\n";
            //Libera o buffer de entrada (para que o mesmo possa ser manipulado de forma segura)
            cin.clear();
            //"reseta" (da um fflush()) em todo input falho (failbit) contido no buffer ate o \n
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erro = true;
        }   
    }while(erro == true);

    cout << "\nNumero inserido = " << inteiro << "\n";

    return 0;
}