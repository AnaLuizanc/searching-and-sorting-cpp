#include<stdio.h>
#include<stdlib.h>

typedef struct no_aux{
    int valor;
    struct no_aux* proximo;
    int qtd_acesso;
}List;

typedef List* Lista;

typedef struct no_aux{
    Lista lista;
    struct no_aux* antec;
}DoubleList;

int main(){


}