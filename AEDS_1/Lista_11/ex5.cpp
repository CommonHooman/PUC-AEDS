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
    float preco {0};
    string marca {""};
    string modelo {""};
    bool sujo {false};
    int defeitos {0};

    public:
    Veiculo() = default;
    Veiculo(float preco, string modelo, string marca){
        this->preco = preco;
        this->modelo = modelo;
        this->marca = marca;
    };

    void setSujo(bool sujo){this->sujo = sujo; }
    bool getSujo(){return this->sujo; }

    void setDefeitos(int defeitos){this->defeitos = defeitos; }
    int getDefeitos(){return this->defeitos; }

    virtual void listarDados() = 0;
    virtual void ajustar() = 0;
    virtual void limpar() = 0;
};

class Automovel : public Veiculo{
    protected:
    string placa {""};
    bool oleo_antigo {false};

    public:
    Automovel() : Veiculo() {}

    void setPlaca(string placa){this->placa = placa; }
    string getPlaca(){return this->placa; }

    void setOleo_antigo(bool oleo){this->oleo_antigo = oleo; }
    bool getOleo_antigo(){return this->oleo_antigo; }

    void listarDados(){
        cout << "Marca = " << marca << endl;
        cout << "Modelo = " << modelo << endl;
        cout << "Placa = " << placa << endl;
    }

    void ajustar(){
        if(defeitos == 0){
            cout << "Nao ha defeitos para serem ajustados =)\n";
        }else{
            cout << "Ha " << defeitos << " para serem ajustados\n";
            defeitos = 0;
            cout << "Todos eles foram ajustados com sucesso =)\n";
        }
    }

    void limpar(){
        if(sujo){
            sujo = 0;
            cout << "O automovel foi limpo com sucesso =)\n";
        }else{
            cout << "O automovel ja esta limpo =)\n";
        }
    }

    void mudarOleo(){
        if(oleo_antigo){
            oleo_antigo = 0;
            cout << "O oleo foi trocado com sucesso =)\n";
        }else{
            cout << "O oleo ainda esta novo =)\n";
        }
    }
};

class Bicicleta : public Veiculo{
    protected:
    float aro {0};
    int marchas {0};

    public:
    Bicicleta() : Veiculo() {}
    
    void setAro(float aro){this->aro = aro; }
    float getAro(){return this->aro; }

    void setMarchas(int marchas){this->marchas = marchas; }
    int getMarchas(){return this->marchas; }

    void listarDados(){
        cout << "Marca = " << marca << endl;
        cout << "Modelo = " << modelo << endl;
        cout << "Aro = " << aro << endl;
        cout << "Quantidade de Marchas = " << marchas << endl;
    }

    void ajustar(){
        if(defeitos == 0){
            cout << "Nao ha defeitos para serem ajustados =)\n";
        }else{
            cout << "Ha " << defeitos << " para serem ajustados\n";
            defeitos = 0;
            cout << "Todos eles foram ajustados com sucesso =)\n";
        }
    }

    void limpar(){
        if(sujo){
            sujo = 0;
            cout << "A bicicleta foi limpa com sucesso =)\n";
        }else{
            cout << "A bicicleta ja esta limpa =)\n";
        }
    }
};