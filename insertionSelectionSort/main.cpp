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
    InsertionSort insert;
    SelectionSort select;
    int lista[N] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};

    cout << "\t\tINSERTION SORT" << endl;
    insert.ordena(lista, N);
    cout << "Numero de acessos: " << insert.qtdAcessos << endl;
    
    cout << "\t\tSELECTION SORT" << endl;
    select.ordena(lista, N);
    cout << "Numero de acessos: " << select.qtdAcessos << endl;

    system("clear");

    ofstream arq;
    arq.open("geraGrafico.txt", ios::app);
    int listaAleatoria[N_MAX];
    unsigned tamanho;
    srand(time(0));
    // EXECUTA 100 VEZES
    for(int i = 0; i<N_MAX; i++){
        insert.tamanho = 0;
        insert.qtdAcessos = 0;
        select.tamanho = 0;
        select.qtdAcessos = 0;
        tamanho = rand() % 100 + 1;
        
        for(int j=0; j<tamanho; j++)
            listaAleatoria[j] = rand() % 1000 + 1;
        insert.ordenaListaAleatoria(listaAleatoria,tamanho);
        select.ordenaListaAleatoria(listaAleatoria,tamanho);
        cout << i+1 << "\t" << insert.tamanho << "\t" << insert.qtdAcessos << "\t" << select.qtdAcessos << endl;
        arq << i+1 << "\t" << insert.tamanho << "\t" << insert.qtdAcessos << "\t" << select.qtdAcessos << endl;
        //insert.imprime();
    }
    arq.close();

    return 0;
}