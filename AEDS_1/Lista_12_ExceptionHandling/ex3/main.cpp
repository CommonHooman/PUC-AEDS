#include "soma.h"
 
using namespace std;
 
/* Pra compilar no g++ (Linux, no meu caso WSL):
 *
 * g++ main.cpp -o main soma.o -lm
 * ./main
 * 
 */

int main(){
    Soma *sum1 = new Soma;
    float num;
    bool input_valido;
 
    cin.exceptions(istream::failbit);
 
    for(int i = 0; 1; i++){
        while(input_valido == false){
            cout << "\nInsira o numero \'" << i << "\' para ser somado: ";
            try
            {
                input_valido = true;
                cin >> num;
            }
            catch(exception& e)
            {
                cerr << endl << "Exception: " << e.what() << endl;
                cout << "Insira um input valido\n";
                //usleep(1000);
                input_valido = false;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        try
        {
            sum1->somar(num);
        }
        catch(exception& e)
        {
            cerr << endl << e.what() << "\n";
            break;
        }
        input_valido = false;
    }
 
    cout << "\nValor Total Somado (antes de ultrapassar 100) = " << sum1->getSoma_ultima() << endl;
    cout << "Quantidade de elementos somados = " << sum1->getQnt() << endl;
    cout << "Media = " << sum1->getSoma_ultima()/sum1->getQnt() << endl;
 
    delete sum1;
 
    return 0;
}