#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 20
#define N_MAX 100
#include"sort.h"

int main(){
    List insert;
    List select;
    int lista[N] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};

    cout << "\t\t INSERTION SORT" << endl;
    insert.ordenaInsertion(lista, N);
    cout << "Quantidade de acessos: " << insert.qtdAcessos << endl;
    
    cout << "\t\t SELECTION SORT" << endl;
    select.ordenaSelection(lista, N);
    cout << "Quantidade de acessos: " << select.qtdAcessos << endl;

    fstream arq;
    arq.open("geraGrafico.txt", fstream::out | fstream::trunc);
    int listaAleatoria[N_MAX];
    unsigned tamanho;
    srand(time(0));
    cout << endl;
    
    // EXECUTA 100 VEZES
    for(int i = 0; i<N_MAX; i++){
        insert.tamanho = 0;
        insert.qtdAcessos = 0;
        select.tamanho = 0;
        select.qtdAcessos = 0;

        tamanho = rand() % 100 + 1;
        
        for(int j=0; j<tamanho; j++)
            listaAleatoria[j] = rand() % 1000 + 1;
        insert.ordenaInsertionListaAleatoria(listaAleatoria,tamanho);
        select.ordenaSelectionListaAleatoria(listaAleatoria,tamanho);
        cout << i+1 << "\t" << insert.tamanho << "\t" << insert.qtdAcessos << "\t" << select.qtdAcessos << endl;
        arq << i+1 << "\t" << insert.tamanho << "\t" << insert.qtdAcessos << "\t" << select.qtdAcessos << endl;
    }
    arq.close();

    return 0;
}