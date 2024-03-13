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
            tamanho = qtdAcessos = 0;
            cabeca = NULL;
            cauda = NULL;
        }

        int tamanho;
        int qtdAcessos;
        DoubleNode* cabeca;
        DoubleNode* cauda;

        void armazenaValores(int valor){
            if(tamanho == 0){
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = cabeca;
                cabeca = novo;
                cauda->antec = novo;
                qtdAcessos+=2;
                tamanho++;
            }else{
                DoubleNode* ultimo = cauda->antec;
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                novo->prox = cauda;
                cauda->antec = novo;
                novo->antec = ultimo;
                ultimo->prox = novo;
                qtdAcessos+=5;
                tamanho++;
            }
        }
};

int main(){
    
    
    return 0;  
}