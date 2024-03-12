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
    *apLista = NULL;
}

void armazenaValores(List* apLista, int valor){
    Node* cabeca = *apLista;
    Node* novoNo = new Node;
    novoNo->valor = valor;
    if(cabeca == NULL){
        cabeca->prox = novoNo;
        cabeca->tamanho++;
    }else{
        novoNo->prox = NULL;
        Node* apAtual = *apLista;
        while(apAtual->prox != NULL)
            apAtual = apAtual->prox;
        apAtual->prox = novoNo;
        cabeca->tamanho++;
    }
}

int main(){
    List lista;
    lista->tamanho = 0;
    inicializaLista(&lista);
    int qtd, valor;
    cin >> qtd;
    for(int i=0; i<qtd; i++){
        cin >> valor;
        armazenaValores(&lista, valor);
    }

    return 0;  
}