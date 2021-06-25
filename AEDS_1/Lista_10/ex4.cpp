#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

//Armazena os valores de hora, minuto e segundo (como um relogio)
class Relogio{
    private:
    short hora {0};
    short minuto {0};
    short segundo {0};

    public:
    Relogio() = default;

    Relogio(short h, short m, short s){
        this->hora = h;
        this->minuto = m;
        this->segundo = s;
    }

    void setTempo(short h, short m, short s){
        this->hora = h;
        this->minuto = m;
        this->segundo = s;
    }

    short getHora() { return this->hora; }
    short getMinuto() { return this->minuto; }
    short getSegundo() { return this->segundo; }

    string getTempo(){
        string tempo = to_string(this->hora) + "H " + to_string(this->minuto) + "M " + to_string(this->segundo) + "S";
        return tempo;
    }
};

//Representa um unico carro em um estacionamento
class Estacionamento : private Relogio{
    protected:
    string placa {""};
    string modelo {""};
    Relogio *entrada = new Relogio(); 
    Relogio *saida = new Relogio();
    const float preco_hora = 1.5; //1,50 reais por hora

    public:
    Estacionamento() = default;
    
    //Inicializa placa e modelo do carro
    Estacionamento(string placa, string modelo){
        this->placa = placa;
        this->modelo = modelo;
    }

    //Inicializa placa, modelo e horario de entrada do carro
    Estacionamento(string placa, string modelo, short h, short m, short s){
        this->placa = placa;
        this->modelo = modelo;
        this->entrada = new Relogio(h, m, s);
    }

    void setPlaca(string placa){ this->placa = placa; }
    string getPlaca(){ return this->placa; }

    void setModelo(string modelo){ this->modelo = modelo; } 
    string getModelo(){ return this->modelo; }

    void setEntrada(short h, short m, short s){
        this->entrada->setTempo(h,m,s);
    }
    string getEntrada(){ return this->entrada->getTempo(); }

    void setSaida(short h, short m, short s){
        this->saida->setTempo(h,m,s);
    }
    string getSaida(){ return this->saida->getTempo(); }

    void printCarro(){
        cout << "Placa = " << this->placa << endl;
        cout << "Modelo = " << this->modelo << endl;
        cout << "Horario de Entrada = " << this->entrada->getTempo() << endl;
        cout << "Horario de Saida = " << this->saida->getTempo() << endl;
        cout << "Valor a ser pago = " << this->calculaValor() << " R$" << endl;
    }

    float calculaValor(){
        float horas_passadas, minutos_passados, segundos_passados;

        //O sistema conta apenas as horas, e nao os dias passados
        if(saida->getHora() < entrada->getHora()){
            cout << "Horario de saida invalido\n";
            return 0;
        }else{
            horas_passadas = saida->getHora() - entrada->getHora();
            minutos_passados = fabs(saida->getMinuto() - entrada->getMinuto());
            segundos_passados = fabs(saida->getSegundo() - entrada->getSegundo());
        }

        return (horas_passadas * this->preco_hora) + (minutos_passados * this->preco_hora/60) + (segundos_passados * this->preco_hora/360);
    }
};

int main(){
    Estacionamento *carro[5];
    int placa = 60;
    short h = 12, m = 0, s = 0; 

    //Inicializa e printa cada objeto Estacionamento (cada carro no estacionamento)
    for(int i = 0; i < 5; i++){
        //Inicializacao
        carro[i] = new Estacionamento("PLACA-" + to_string(placa++), "Model " + to_string(i+1), 12, 00, 00);
        carro[i]->setSaida(h, m, s);

        //Print
        cout << "\nCarro \'" << i+1 << "\':" << endl;
        carro[i]->printCarro();

        //Atualiza o horario de saida do proximo carro
        h++;
        m += 12;
        s += 12;
    }

    for(int i = 0; i < 5; i++)
        delete carro[i];

    return 0;
}