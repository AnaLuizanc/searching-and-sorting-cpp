#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

class DoubleNode{
    public:
        int valor;
        DoubleNode* prox;
        DoubleNode* antec;
};

class DoubleList{
    public:
        DoubleList(){
            tamanho = 0;
            qtdAcessos = 0;
            cabeca->prox = cauda;
            cauda->antec = cabeca;
        }

        int tamanho;
        int qtdAcessos;
        DoubleNode* cabeca = new DoubleNode;
        DoubleNode* cauda = new DoubleNode;

        void armazenaValores(int valor){
            if(tamanho == 0){
                DoubleNode* novo = new DoubleNode;
                cabeca->prox = novo;
                cauda->antec = novo;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = cabeca;
                qtdAcessos+=2;
                tamanho++;
            }else{
                DoubleNode* ultimo = cauda->antec;
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = ultimo;
                cauda->antec = novo;
                ultimo->prox = novo;
                qtdAcessos+=5;
                tamanho++;
            }
        }

        
};

int main(){
    DoubleList l;
    l.armazenaValores(12);
    l.armazenaValores(45);
    l.armazenaValores(100);
    l.armazenaValores(147);
    cout << l.tamanho << endl;
    l.imprime();
    
    return 0;  
}