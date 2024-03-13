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
        }

        int tamanho;
        int qtdAcessos;
        DoubleNode* cabeca;
};

int main(){
    
    
    return 0;  
}