#include<iostream>
#include<string>
#define N_MAX 100
using namespace std;

class StaticList{
    public:
        int lista[N_MAX];
        int tamanho;
        int qtdAcessos;
        
    void armazenaValores();
    void geraListaAleatoria();
    void inserePosicaoEspecifica();
    void transposicao();
    void buscaValor();
    void buscaMenorValor();
    void imprime();
    void imprimeInverso();
    
};

int main(){
    StaticList list;
    int n;
    cin >> n;
    
    
    return 0;  
}