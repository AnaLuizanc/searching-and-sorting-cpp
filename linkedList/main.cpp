#include<iostream>
#include<string>
#define N_MAX 100
using namespace std;

class StaticList{
    public:
        StaticList(){
            qtdAccessos = 0;
            tamanho = 0;
        }
        ~StaticList(){

        }
    private:
        int qtdAccessos;
        int tamanho;
        int lista[N_MAX];
};

int main(){
    StaticList* list;
    int n;
    cin >> n;

    return 0;  
}