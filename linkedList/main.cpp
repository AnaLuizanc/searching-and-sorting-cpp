#include<iostream>
#include<string>
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
        }

        void imprime(){
            for(int i=0; i<tamanho; i++)
                cout << vector[i] << " ";
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
            }
            else{
                posicao = andaUm(posicao);
                vector[posicao] = valor;
                tamanho++;
            }
        }

        void trocaPosicoes(int posicaoA, int posicaoB){
            int auxiliar;
            auxiliar = vector[posicaoA];
            vector[posicaoA] = vector[posicaoB];
            vector[posicaoB] = auxiliar;
        }

        int menorValor(){
            int menor = vector[0];
            int posicao = 0;
            for(int i=1; i<tamanho; i++){
                if(menor > vector[i]){
                    menor = vector[i];
                    posicao = i;
                }     
            }
            return posicao;
        }

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

    return 0;  
}