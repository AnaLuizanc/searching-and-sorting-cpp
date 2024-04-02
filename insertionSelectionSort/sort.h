#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

class InsertionSort{
    public:
        InsertionSort(){
            qtdAcessos = 0;
            tamanho = 0;
        }
        ~InsertionSort(){}

        int vetor[N];
        unsigned qtdAcessos;
        unsigned tamanho;

        void armazenaValores(int v[], int n){
            for(int i=0; i<n; i++){
                vetor[i] = v[i];
                qtdAcessos++;
                tamanho++;
            }
        }

        void ordena(int v[], int n){
            armazenaValores(v,n);
            imprime();
            for(int i=1; i<tamanho; i++){
                int j = i-1;
                int aux = vetor[i];
                qtdAcessos++;
                while(j >= 0 && aux < vetor[j]){
                    vetor[j+1] = vetor[j];
                    j--;
                    qtdAcessos+=2;
                    imprime();
                }
                vetor[j+1] = aux;
                imprime();
            }
        }


        void imprime(){
            for(int i=0; i<tamanho; i++){
                cout << vetor[i] << " ";
                qtdAcessos++;
            }   
            cout << endl;
        }
};

class SelectionSort{
    public:
        SelectionSort(){
            qtdAcessos = 0;
            tamanho = 0;   
        }
        ~SelectionSort(){}

        int vetor[N];
        unsigned qtdAcessos;
        unsigned tamanho;

        void armazenaValores(int v[], int n){
            for(int i=0; i<n; i++){
                vetor[i] = v[i];
                qtdAcessos++;
                tamanho++;
            }
        }

        void swap(int a, int b){
            int aux = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = aux;
            qtdAcessos+=4;
        }

        void ordena(int v[], int n){
            armazenaValores(v,n);
            imprime();
            for(int i=0; i<tamanho; i++){
                int menor = i;
                for(int j=i+1; j<tamanho; j++){
                    if(vetor[j] < vetor[menor])
                        menor = j;
                    qtdAcessos+=2;
                }
                swap(i,menor);
                imprime();
            }   
        }

        void imprime(){
            for(int i=0; i<tamanho; i++){
                cout << vetor[i] << " ";
                qtdAcessos++;
            }   
            cout << endl;
        }
};

#endif