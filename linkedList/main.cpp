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
    cabeca = NULL;
    *apLista = cabeca;
    (*apLista)->tamanho = 0;
    (*apLista)->qtdAcessos = 0;
}

void imprime(List lista){
    List aux = lista->prox;
    while(aux != NULL){
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

int main(){
    List lista;
    inicializaLista(&lista);
    int qtd, valor;
    cin >> qtd;
    for(int i=0; i<qtd; i++){
        cin >> valor;
    }
    imprime(lista);

    return 0;  
}