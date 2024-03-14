#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"


int main(){
    DoubleList l;
    l.armazenaValores(12);
    l.armazenaValores(45);
    l.armazenaValores(100);
    l.armazenaValores(147);
    l.inserePosicao(10,2);
    l.imprime();
    l.swap(0,4);

    cout << l.tamanho << endl;
    l.imprime();
    l.imprimeInverso();

    cout << l.buscaValor(45) << l.buscaValor(24) << endl;

    DoubleNode* menor = l.buscaMenor();
    cout << "Menor: " << menor->valor << endl;
    
    return 0;  
}