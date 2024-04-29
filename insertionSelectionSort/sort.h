#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

class List{
    public:
        List(){
            qtdAcessos = 0;
            tamanho = 0;
        }
        ~List(){}

        int vetor[N_MAX];
        unsigned qtdAcessos;
        unsigned tamanho;

        void armazenaValores(int v[], int n){
            for(int i=0; i<n; i++){
                vetor[i] = v[i];
                qtdAcessos++;
                tamanho++;
            }
        }

        void ordenaInsertion(int v[], int n){
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

        void ordenaInsertionListaAleatoria(int v[], int n){
            armazenaValores(v,n);
            for(int i=1; i<n; i++){
                int j = i-1;
                int aux = vetor[i];
                qtdAcessos++;
                while(j >= 0 && aux < vetor[j]){
                    vetor[j+1] = vetor[j];
                    j--;
                    qtdAcessos+=2;
                }
                vetor[j+1] = aux;
            }
        }

        void swap(int a, int b){
            int aux = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = aux;
            qtdAcessos+=4;
        }

        void ordenaSelection(int v[], int n){
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

        void ordenaSelectionListaAleatoria(int v[], int n){
            armazenaValores(v,n);
            for(int i=0; i<tamanho; i++){
                int menor = i;
                for(int j=i+1; j<tamanho; j++){
                    if(vetor[j] < vetor[menor])
                        menor = j;
                    qtdAcessos+=2;
                }
                swap(i,menor);
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