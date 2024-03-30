#include<iostream>
using namespace std;
#define N 20
#define N_MAX 100
#include"sort.h"

int main(){
    InsertionSort l;
    int vetor[N_MAX] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};
    cout << "INSERTION SORT" << endl;
    l.armazenaValores(vetor);
    l.ordena();
    cout << "Numero de acessos: " << l.qtdAcessos << endl;

    cout << "SELECTION SORT" << endl;
    SelectionSort l2;
    l2.armazenaValores(vetor);
    l2.ordena();
    cout << "Numero de acessos: " << l2.qtdAcessos << endl;

    return 0;
}