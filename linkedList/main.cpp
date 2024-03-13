#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

typedef struct node_aux{
    int valor;
    int qtdAcessos;
    int tamanho;
    struct node_aux* prox;
}Node;

typedef Node* List;

void inicializaLista(List* apLista){
    Node* cabeca = (Node*)malloc(sizeof(Node));
    cabeca->qtdAcessos = 0;
    cabeca->tamanho = 0;
    cabeca->valor = -1;
    cabeca->prox = NULL;
    *apLista = cabeca;      
}



int main(){
    List lista;
    inicializaLista(&lista);
    int qtd, valor;

    return 0;  
}