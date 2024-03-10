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

};

int main(){
    StaticList list;
    int n;
    cin >> n;
    list.armazenaValores(n);
    list.imprime();

    return 0;  
}