#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include<cstdio>
#define N_MAX 100
using namespace std;

class StaticList{
    public:
        StaticList(){
            qtdAcessos = 0;
            tamanho = 0;
        }
        ~StaticList(){}
        
        int vector[N_MAX];
        int qtdAcessos;
        int tamanho;

        void armazenaValores(int n){
            for(int i=0; i<n; i++)
                cin >> vector[i];
            tamanho+=n;
            qtdAcessos+=n;
        }

        void imprime(){
            for(int i=0; i<tamanho; i++){
                cout << vector[i] << " ";
                qtdAcessos++;
            }
            cout << endl;
        }

        void insereFim(int valor){
            vector[tamanho] = valor;
        }
        
        int andaUm(int posicao){
            int posicaoAux = tamanho;
            while(posicaoAux != posicao){
                vector[posicaoAux] = vector[posicaoAux-1];
                posicaoAux--;
            }
            return posicao;
        }

        void inserePosicao(int valor, int posicao){
            if(posicao == tamanho){
                insereFim(valor);
                tamanho++;
                qtdAcessos++;
            }
            else{
                posicao = andaUm(posicao);
                vector[posicao] = valor;
                tamanho++;
                qtdAcessos++;
            }
        }

        void trocaPosicoes(int posicaoA, int posicaoB){
            int auxiliar;
            auxiliar = vector[posicaoA];
            vector[posicaoA] = vector[posicaoB];
            vector[posicaoB] = auxiliar;
            qtdAcessos++;
        }

        int menorValor(){
            int menor = vector[0];
            int posicao = 0;
            for(int i=1; i<tamanho; i++){
                if(menor > vector[i]){
                    menor = vector[i];
                    posicao = i;
                    qtdAcessos++;
                }
                qtdAcessos++;    
            }
            return posicao;
        }

        void geraListaAleatoria(int size, int inicio, int fim){
            srand(time(0));
            for(int i=0; i<size; i++)
                vector[i] = rand() % (fim-inicio+1) + inicio;
            for(int i=0; i<size; i++)
                cout << vector[i] << " ";
            cout << endl;
        }

        int buscaValor(int valor){
            for(int i=0; i<tamanho; i++){
                if(vector[i] == valor){
                    qtdAcessos++;
                    return i;
                }
                qtdAcessos++;    
            }
            return -1;
        }
};

class No{
    public:
        No(){
            prox = NULL;
            antec = NULL;
            qtdAcessos = 0;
            tamanho = 0;
        }
        ~No(){}

        int valor;
        int qtdAcessos;
        int tamanho;
        No* prox;
        No* antec;
};

int main(){
    StaticList list;
    int n;
    cin >> n;
    //Operacao 1
    list.armazenaValores(n);
    list.imprime();
    //Operacao 3
    int valor, posicao;
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    list.imprime();
    //Operacao 5
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    cout << "Valor a ser procurado: ";
    cin >> valor;
    posicao = list.buscaValor(valor);
    cout << "Encontrou na posicao " << posicao << endl;
    //Operacao 4
    int pA, pB;
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    cin >> pA >> pB;
    list.trocaPosicoes(pA, pB);
    list.imprime();
    //Operacao 6
    int posicaoMenor = list.menorValor();
    cout << "Menor valor: " << list.vector[posicaoMenor] << endl;
    cout << "Posicao: " << posicaoMenor << endl;
    //Operacao 2
    int size, inicio, fim;
    cout << "Tamanho: ";
    cin >> size;
    cout << "Intervalo(50 150): ";
    cin >> inicio >> fim;
    list.geraListaAleatoria(size, inicio, fim);

    return 0;  
}