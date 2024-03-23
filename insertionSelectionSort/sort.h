#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

class InsertionSort{
    public:
        InsertionSort(){
            qtdAcessos = 0;
        }
        ~InsertionSort(){}

        int vetor[N_MAX];
        unsigned qtdAcessos;

        void ordena(){
            for(int i=1; i<N_MAX-1; i++){
                int j = i-1;
                int aux = vetor[i];
                while(j >= 0 && aux < vetor[j]){
                    vetor[j+1] = vetor[j];
                    j--;
                }
                vetor[j+1] = aux;
            }
        }

        void imprime(){
            for(int i=0; i<N_MAX; i++){
                cout << vetor[i] << " ";
                qtdAcessos++;
            }
                
            cout << endl;
        }
};

#endif