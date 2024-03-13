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

int main(){
    
    return 0;  
}