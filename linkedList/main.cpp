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

};

int main(){
    StaticList list;
    int n;
    cin >> n;
    list.armazenaValores(n);
    list.imprime();
    int valor, posicao;
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    cin >> valor >> posicao;
    list.inserePosicao(valor, posicao);
    list.imprime();

    return 0;  
}