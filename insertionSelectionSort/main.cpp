#include<iostream>
using namespace std;
#define N_MAX 20
#include"sort.h"

int main(){
    InsertionSort l;
    int vetor[N_MAX] = {70,1,12,8,99,72,5,15,20,91,14,61,66,41,81,88,16,21,34,90};
    l.armazenaValores(vetor);
    l.ordena();
    cout << "Numero de acessos: " << l.qtdAcessos << endl;

    return 0;
}