#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;
#include "list.h"


int main(){
    StaticList lStatic;
    SimpleList lSimple;
    DoubleList lDouble;
    int opcao;
    do{
        cout << "Escolha um tipo de lista:" << endl;
        cout << "1. Lista por contiguidade fisica" << endl;
        cout << "2. Lista simplesmente encadeada" << endl;
        cout << "3. Lista duplamente encadeada" << endl;
        cout << "0. FINALIZAR" << endl;
        cin >> opcao;
        if(opcao == 1){
            cout << "Insercao de 10 numeros" << endl;
                lStatic.armazenaValores(8);
                lStatic.armazenaValores(1);
                lStatic.armazenaValores(3);
                lStatic.armazenaValores(4);
                lStatic.armazenaValores(3);
                lStatic.armazenaValores(6);
                lStatic.armazenaValores(10);
                lStatic.armazenaValores(8);
                lStatic.armazenaValores(9);
                lStatic.armazenaValores(1);
                cout << endl;
                lStatic.imprime();
                cout << "Insercao do 11 na posicao 10" << endl;
                lStatic.inserePosicao(11,10);
                cout << "Insercao do 2 na posicao 4" << endl;
                lStatic.inserePosicao(2,4);
                cout << "Insercao do 7 na posicao 0" << endl;
                lStatic.inserePosicao(7,0);
                cout << endl;
                lStatic.imprime();
                cout << "Numero 10 esta na posicao " << lStatic.buscaValor(10) << endl;
                cout << "Numero de acessos: " << lStatic.qtdAcessos << endl;
                cout << "Numero 8 esta na posicao " << lStatic.buscaValor(8) << endl;
                cout << "Numero de acessos: " << lStatic.qtdAcessos << endl;
                cout << "Numero 12 esta na posicao " << lStatic.buscaValor(12) << endl;
                cout << "Numero de acessos: " << lStatic.qtdAcessos << endl;
                lStatic.swap(3,4);
                lStatic.swap(0,6);
                lStatic.swap(6,12);
                lStatic.imprime();
                cout << "O menor valor da lista eh " << lStatic.vector[lStatic.buscaMenor()] << " na posicao " << lStatic.buscaMenor() << endl;
                cout << "Numero de acessos: " << lStatic.qtdAcessos << endl;
                lStatic.imprimeInverso();
                cout <<  endl;
        }else if(opcao == 2){
            cout << "Insercao de 10 numeros" << endl;
                lSimple.armazenaValores(8);
                lSimple.armazenaValores(1);
                lSimple.armazenaValores(3);
                lSimple.armazenaValores(4);
                lSimple.armazenaValores(3);
                lSimple.armazenaValores(6);
                lSimple.armazenaValores(10);
                lSimple.armazenaValores(8);
                lSimple.armazenaValores(9);
                lSimple.armazenaValores(1);
                cout << endl;
                lSimple.imprime();
                cout << "Insercao do 11 na posicao 10" << endl;
                lSimple.inserePosicao(11,10);
                cout << "Insercao do 2 na posicao 4" << endl;
                lSimple.inserePosicao(2,4);
                cout << "Insercao do 7 na posicao 0" << endl;
                lSimple.inserePosicao(7,0);
                cout << endl;
                lSimple.imprime();
                cout << "Numero 10 esta na posicao " << lSimple.buscaValor(10) << endl;
                cout << "Numero de acessos: " << lSimple.qtdAcessos << endl;
                cout << "Numero 8 esta na posicao " << lSimple.buscaValor(8) << endl;
                cout << "Numero de acessos: " << lSimple.qtdAcessos << endl;
                cout << "Numero 12 esta na posicao " << lSimple.buscaValor(12) << endl;
                cout << "Numero de acessos: " << lSimple.qtdAcessos << endl;
                lSimple.swap(3,4);
                lSimple.swap(0,6);
                lSimple.swap(6,12);
                lSimple.imprime();
                SimpleNode* menor = lSimple.buscaMenor();
                cout << "O menor valor da lista eh " << menor->valor << endl;
                cout << "Numero de acessos: " << lSimple.qtdAcessos << endl;
                lSimple.imprimeInverso();
                cout <<  endl;
        }else if(opcao == 3){
            cout << "Insercao de 10 numeros" << endl;
                lDouble.armazenaValores(8);
                lDouble.armazenaValores(1);
                lDouble.armazenaValores(3);
                lDouble.armazenaValores(4);
                lDouble.armazenaValores(3);
                lDouble.armazenaValores(6);
                lDouble.armazenaValores(10);
                lDouble.armazenaValores(8);
                lDouble.armazenaValores(9);
                lDouble.armazenaValores(1);
                cout << endl;
                lDouble.imprime();
                cout << "Insercao do 11 na posicao 10" << endl;
                lDouble.inserePosicao(11,10);
                cout << "Insercao do 2 na posicao 4" << endl;
                lDouble.inserePosicao(2,4);
                cout << "Insercao do 7 na posicao 0" << endl;
                lDouble.inserePosicao(7,0);
                cout << endl;
                lDouble.imprime();
                cout << "Numero 10 esta na posicao " << lDouble.buscaValor(10) << endl;
                cout << "Numero de acessos: " << lDouble.qtdAcessos << endl;
                cout << "Numero 8 esta na posicao " << lDouble.buscaValor(8) << endl;
                cout << "Numero de acessos: " << lDouble.qtdAcessos << endl;
                cout << "Numero 12 esta na posicao " << lDouble.buscaValor(12) << endl;
                cout << "Numero de acessos: " << lDouble.qtdAcessos << endl;
                lDouble.swap(3,4);
                lDouble.swap(0,6);
                lDouble.swap(6,12);
                lDouble.imprime();
                DoubleNode* menor = lDouble.buscaMenor();
                cout << "O menor valor da lista eh " << menor->valor << endl;
                cout << "Numero de acessos: " << lDouble.qtdAcessos << endl;
                lDouble.imprimeInverso();
                cout <<  endl;
        }else
            break;
    }while(opcao != 0);
    
    
    return 0;  
}