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
    Node* cabeca = new Node;
    cabeca->qtdAcessos = cabeca->tamanho = 0;
    cabeca->prox = NULL;
    *apLista = cabeca;      
}



int main(){
    List lista;
    inicializaLista(&lista);
    int qtd, valor;
    cin >> qtd;
   // for(int i=0; i<qtd; i++){
        cin >> valor;
        armazenaValores(&lista, valor);
    //}
    imprime(lista);

    return 0;  
}