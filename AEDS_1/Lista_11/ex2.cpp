#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Animal{
    protected:
    string nome {"Animal"};

    public:
    virtual void fala() = 0;

    Animal() = default;

    Animal(string nome){
        this->nome = nome;
    }
};

class Humano : public Animal{
    public:
    void fala(){
        cout << "Oi!\n";
    }

    Humano() : Animal("Humano"){};
};

class Cachorro : public Animal{
    public:
    void fala(){
        cout << "Au au!\n";
    }

    Cachorro() : Animal("Cachorro"){};
};

class Gato : public Animal{
    public:
    void fala(){
        cout << "Miau!\n";
    }

    Gato() : Animal("Gato"){};
};

int main(){
    Animal* animais[10];

    for(int i = 0; i < 10; i++){
        if(i < 3){
            animais[i] = new Cachorro;
        }else if(i >= 3 && i < 7){
            animais[i] = new Gato;
        }else{
            animais[i] = new Humano;
        }

        cout << "animais[" << i << "]:";
        animais[i]->fala();
    }
}