#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class ProdutoLoja{
    protected:
    string nome {""};
    float preco {0};

    public:
    ProdutoLoja() = default;

    ProdutoLoja(string nome, float preco){
        this->nome = nome;
        this->preco = preco;
    }

    void setNome(string nome){ this->nome = nome; }
    string getNome(){ return this->nome; }

    void setPreco(float preco){ this->preco = preco; }
    float getPreco(){ return this->preco; }

    /* Nao eh um virtual puro pois os elementos "nome" e "preco" sao compartilhados por todas subclasses
     * portanto o print dos mesmos ja pode ser realizado no metodo original (que sera herdado e sobreescrito)*/
    virtual void toString(){
        cout << "Nome = " << this->nome << endl;
        cout << "Preco = " << this->preco << endl;
    }
};

class Livro : public ProdutoLoja{
    private:
    string autor {""};

    public:
    //Chama explicitamente o construtor da classe base
    Livro(string nome, float preco, string autor) : ProdutoLoja(nome, preco){
        this->autor = autor;
    }

    void setAutor(string autor){ this->autor = autor; }
    string getAutor(){ return this->autor; }

    void toString() override{
        ProdutoLoja::toString();
        cout << "Autor = " << this->autor << endl;
    }
};

class CD : public ProdutoLoja{
    private:
    int num_faixas {0};

    public:
    //Chama explicitamente o construtor da classe base
    CD(string nome, float preco, int num_faixas) : ProdutoLoja(nome, preco){
        this->num_faixas = num_faixas;
    }

    void setNum_faixas(int num_faixas){ this->num_faixas = num_faixas; }
    int getNum_faixas(){ return this->num_faixas; }

    void toString() override{
        ProdutoLoja::toString();
        cout << "Numero de faixas do CD = " << this->num_faixas << endl;
    }
};

class DVD : public ProdutoLoja{
    private:
    float duracao {0}; //Em segundos

    public:
    //Chama explicitamente o construtor da classe base
    DVD(string nome, float preco, float duracao) : ProdutoLoja(nome, preco){
        this->duracao = duracao;
    }

    void setDuracao(int duracao){ this->duracao = duracao; }
    int getDuracao(){ return this->duracao; }

    void toString() override{
        ProdutoLoja::toString();
        cout << "Duracao do DVD = " << this->duracao << "s\n";
    }
};

class Loja{
    public:
    static int main(){
        ProdutoLoja* produtos[5];
        string aut = "Autor ";
        char caractere = 'A';

        //Instacia (new), inicializa (construtores), printa (toString()) e ja deleta os produtos
        for(int i = 0; i < 5; i++){
            if(i % 2 == 0){
                produtos[i] = new Livro("Livro " + to_string(i), (i+1) * 100, aut + caractere++);
            }else if(i == 1){
                produtos[i] = new CD("CD " + to_string(i), (i+1) * 100, i+10);
            }else{
                produtos[i] = new DVD("DVD " + to_string(i), (i+1) * 100, 180);
            }

            cout << "\nProduto \'" << i << "\':\n";
            produtos[i]->toString();
            delete produtos[i];
        }

        return 0;
    }
};

int main(){
    Loja::main();

    return 0;
}