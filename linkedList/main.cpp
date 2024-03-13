#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"

int main(){
    SimpleList l;
    l.armazenaValores(7);
    l.armazenaValores(65);
    l.imprime();
    l.inserePosicao(4, 100);
    l.inserePosicao(0, 90);
    l.imprime();
    l.inserePosicao(3, 3);
    //l.swap(1, 2);
    l.imprime();

    SimpleNode* menor = l.buscaMenor();
    cout << "Menor: " << menor->valor << endl;

    cout << l.buscaValor(65) << " " << l.buscaValor(2) << endl;
    
    return 0;  
}