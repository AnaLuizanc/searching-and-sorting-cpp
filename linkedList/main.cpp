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

void armazenaValores(List* apLista, int valor){
    Node* atual = (*apLista);
    while(atual->prox != NULL)
        atual = atual->prox;
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    atual->prox = novoNo;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
}

void inserePosicao(List* apLista, int valor, int posicao){
    Node* seguinte = (*apLista);
    Node* antec = (*apLista);
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    int contador = 0;
    while(contador != posicao){
        seguinte = seguinte->prox;
        antec = antec->prox;
        contador++;
    }
    seguinte = seguinte->prox;
    antec->prox = novoNo;
    novoNo->prox = seguinte;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
}

void swap(List* apLista, int posicaoA, int posicaoB){
    Node* atualA = (*apLista)->prox;
    Node* atualB = (*apLista)->prox;
    int contadorA = 0, contadorB = 0;
    while(contadorA != posicaoA){
        atualA = atualA->prox;
        contadorA++;
    }
    while(contadorB != posicaoB){
        atualB = atualB->prox;
        contadorB++;
    }
    int auxiliar = atualA->valor;
    atualA->valor = atualB->valor;
    atualB->valor = auxiliar;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
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
    //cin >> valor;
    armazenaValores(&lista, 56);
    armazenaValores(&lista, 47);
    armazenaValores(&lista, 77);
    armazenaValores(&lista, 13);
    armazenaValores(&lista, 54);
    inserePosicao(&lista, 567, 3);
    imprime(lista);
    swap(&lista, 1, 3);
    imprime(lista);
    cout << lista->tamanho;

    return 0;  
}