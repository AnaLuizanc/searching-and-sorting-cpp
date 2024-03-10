#include<iostream>
#include<string>
#define N_MAX 100
using namespace std;

class StaticList{
    public:
        int lista[N_MAX];
        int tamanho;
        int qtdAcessos;
        

    
};

int main(){
    StaticList list;
    list.qtdAcessos=0;
    int n;
    cin >> n;
    
    return 0;  
}