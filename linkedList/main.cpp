#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

typedef struct no_aux{
    int valor;
    int qtdAcessos; 
    int tamanho;
    struct no_aux* prox;
    struct no_aux* antec;
}DoubleNode;

typedef DoubleNode* ListD;

void inicializaLista(ListD* apLista){
    DoubleNode* cabeca = (DoubleNode*)malloc(sizeof(DoubleNode));
    cabeca->qtdAcessos = cabeca->tamanho = 0;
    cabeca->valor = -1;
    cabeca->prox = NULL;
    cabeca->antec = (*apLista);
    *apLista = cabeca;
}

void armazenaValores(ListD* apLista, int valor){
    DoubleNode* penultimo = (*apLista);
    while(penultimo->prox != NULL)
        penultimo = penultimo->prox;
    DoubleNode* novoNo = (DoubleNode*)malloc(sizeof(DoubleNode));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    novoNo->antec = penultimo;
    penultimo->prox = novoNo;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
}

int main(){
    
    return 0;  
}