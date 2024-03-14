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
                qtdAcessos+=4;
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

        void inserePosicao(int valor, int posicao){
            if(tamanho == 0){
                DoubleNode* novo = new DoubleNode;
                cabeca->prox = novo;
                cauda->antec = novo;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = cabeca;
                qtdAcessos+=4;
                tamanho++;
            }else if(posicao == 0){
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                cabeca->prox->antec = novo;
                novo->prox = cabeca->prox;
                cabeca->prox = novo;
                novo->antec = cabeca;
                qtdAcessos+=6;
                tamanho++;
            }else if(posicao >= tamanho){
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                cauda->antec->prox = novo;
                novo->antec = cauda->antec;
                novo->prox = cauda;
                cauda->antec = novo;
                qtdAcessos+=6;
                tamanho++;
            }else{
                DoubleNode* anterior = cabeca;
                DoubleNode* seguinte = cabeca->prox;
                qtdAcessos+=2;
                for(int i=0; i<=posicao; i++){
                    anterior = anterior->prox;
                    seguinte = seguinte->prox;
                    qtdAcessos+=2;
                }
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                seguinte->antec = novo;
                anterior->prox = novo;
                novo->antec = anterior;
                novo->prox = seguinte;
                qtdAcessos+=4;
                tamanho++;
            }
        }

        void imprime(){
            DoubleNode* atual = cabeca->prox;
            qtdAcessos++;
            while(atual != cauda){
                cout << atual->valor << " ";
                atual = atual->prox;
                qtdAcessos+=2;
            }
            cout << endl;
        }
};

int main(){
    DoubleList l;
    l.armazenaValores(12);
    l.armazenaValores(45);
    l.armazenaValores(100);
    l.armazenaValores(147);
    l.inserePosicao(10,2);

    cout << l.tamanho << endl;
    l.imprime();
    
    return 0;  
}