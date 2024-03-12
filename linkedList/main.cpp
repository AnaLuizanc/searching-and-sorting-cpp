#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

class SimpleNode{
    public:
        SimpleNode(int valor){
            this->valor = valor;
            this->prox = NULL;
        }
        ~SimpleNode(){}

        int valor;
        SimpleNode* prox;
};

class LinkedList{
    public:        
        LinkedList(){
            qtdAcessos = 0;
            tamanho = 0;
            cabeca = NULL;
        }
        ~LinkedList(){}

        int valor;
        int qtdAcessos;
        int tamanho;
        SimpleNode* cabeca;
};

int main(){

    return 0;  
}