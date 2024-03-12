#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

class SimpleNode{
    public:
        SimpleNode(){
            prox = NULL;
            
        }
        ~SimpleNode(){}

        int valor;
        SimpleNode* prox;
};

class LinkedList{
    public:        
        LinkedList(){
            qtdAcessos = 0;
            tamanho = 0;
            cabeca = NULL;
        }
        ~LinkedList(){}

        int valor;
        int qtdAcessos;
        int tamanho;
        SimpleNode* cabeca;
};

int main(){
    StaticList list;
    int n;
    cin >> n;
    //Operacao 1
    list.armazenaValores(n);
    list.imprime();
    //Operacao 3
    int valor, posicao;
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    list.imprime();
    //Operacao 5
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    //Operacao 4
    int pA, pB;
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    list.imprime();
    //Operacao 6
    int posicaoMenor = list.menorValor();
    cout << "Menor valor: " << list.vector[posicaoMenor] << endl;
    cout << "Posicao: " << posicaoMenor << endl;
    //Operacao 2
    int size, inicio, fim;
    cout << "Tamanho: ";
    cin >> size;
    cout << "Intervalo(50 150): ";
    cin >> inicio >> fim;
    list.geraListaAleatoria(size, inicio, fim);

    return 0;  
}