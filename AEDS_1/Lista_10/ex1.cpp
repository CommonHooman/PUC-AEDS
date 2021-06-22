#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

class Produto{ //(Peça)
    friend class NotaFiscal;
 
    private:
    string numProduto {"none"}; //Caso o construtor nao inicialize, o valor inicial sera "none"
    string descProduto {"none"};
    int qntd;
    float preco;
 
    public:
    Produto(string numProduto, string descProduto, int qntd, float preco){
        this->numProduto = numProduto;
        this->descProduto = descProduto;
        this->qntd = qntd;
        this->preco = preco;
    }
 
    Produto(int qntd, float preco){
        this->qntd = qntd;
        this->preco = preco;
    }
 
    void setProduto(string nome){
        this->numProduto = nome;
    }
    
    string getNumProduto(){ return this->numProduto; }
    
    void setDescProduto(string descricao){
        this->descProduto = descricao;
    }
 
    string getDescProduto(){ return this->descProduto; }
 
    void setQntd(int qntd){
        this->qntd = qntd;
    }
 
    int getQntd(){ return this->qntd; }
 
    void setPreco(float preco){
        this->preco = preco;
    }
 
    float getPreco(){ return this->preco; }
 
    //Retorna o valor total desta compra (unidades compradas * preco da unidade)
    float getTotalProduto(){
        return (this->qntd * this->preco);
    }
};
 
class NotaFiscal{
    private:
    Produto *itens[100]; //Limite de 100 produtos distintos por nota
    int count {0};
 
    public:
    //Adiciona um produto ja existente na Nota Fiscal
    void addProduto(Produto* prod){
        this->itens[count] = prod;
        count++;
    }
 
    //Adiciona um produto usando como parametro qntd e preco
    void addProduto(int qntd, float preco){
        this->itens[count] = new Produto(qntd, preco);
        count++;
    }
 
    //Adiciona um produto usando como parametro num do produto, descricao qntd e preco
    void addProduto(string num, string desc, int qntd, float preco){
        this->itens[count] = new Produto(num, desc, qntd, preco);
        count++;
    }
 
    //Remove um produto especifico usando de parametro o proprio objeto a ser removido
    void removeProduto(Produto* prod){
        bool achou = false; //Define se o produto foi achado (break no loop) ou nao (iterou pelo vetor inteiro)
 
        for(int i = 0; i < count; i++){ //Itera ate encontrar o produto ou acabar o vetor
            if(itens[i] == prod){
                delete itens[i]; //Encontrou o produto
                this->count--;
 
                for(int j = i; j < count; j++){ //Atualiza os ponteiros seguintes ao produto removido
                    itens[j] = itens[j+1];
                }
 
                itens[count] = NULL; //Atualiza o ultimo ponteiro
                achou = true;
                break;
            }
        }
 
        if(achou){
            cout << "Produto removido com sucesso\n";
        }else{
            cout << "Produto nao encontrado - O produto em questao nao se encontra nesta nota fiscal\n";
        }
    }
 
    //Remove o produto que se encontra na posicao [index] do vetor de itens
    void removeProduto(int index){
        delete itens[index];
        this->count--;
 
        for(int i = index; i < count; i++){
            itens[i] = itens[i+1];
        }
 
        itens[count] = NULL;
        cout << "Produto removido com sucesso\n";
    }
 
    //Retorna a soma total das quantidades e precos de todos produtos contidos na Nota
    float getTotalNota(){
        float total = 0;
 
        for(int i = 0; i < count; i++)
            total += itens[i]->getTotalProduto();
 
        return total;
    }
 
    //Printa todos os produtos contidos no vetor itens[]
    void printProdutos(){
        for(int i = 0; i < count; i++){
            cout << "Produto \'" << i+1 << "\':\n";
            cout << "Numero do produto = " << itens[i]->numProduto << endl;
            cout << "Descricao = " << itens[i]->descProduto << endl;
            cout << "Quantidade de unidades compradas = " << itens[i]->qntd << endl;
            cout << "Preco de cada unidade = " << itens[i]->preco << endl << endl;
        }
    }
};
 
int main(){
    NotaFiscal *nf = new NotaFiscal();
    Produto *p1 = new Produto("00-AA", "Peca de motor", 30, 5.50);
    Produto *p2 = new Produto(100, 2.10);
 
    nf->addProduto(p1);
    nf->addProduto(p2);
    nf->addProduto("10-BB", "Peca de ventilador caseiro", 20, 1.00);
    nf->addProduto(300, 0.50);
 
    nf->printProdutos();
    getchar();
 
    //Remove o produto p2
    nf->removeProduto(p2);
    cout << endl;
    nf->printProdutos();
    getchar();
 
    //Remove produto no indice [1], ou seja, o terceiro produto criado (p2 foi removido ja)
    nf->removeProduto(1);
    cout << endl;
    nf->printProdutos();
    getchar();
 
    return 0;
}
