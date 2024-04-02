#include<iostream>
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
    int lista[N_MAX] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};

    cout << "\t\tINSERTION SORT" << endl;
    insert.ordena(lista, N);
    cout << "Numero de acessos: " << insert.qtdAcessos << endl;
    
    cout << "\t\tSELECTION SORT" << endl;
    select.ordena(lista, N);
    cout << "Numero de acessos: " << select.qtdAcessos << endl;

    //system("clear");


    return 0;
}