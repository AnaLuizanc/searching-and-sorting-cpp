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

        void ordena(int vetor[N_MAX]){
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
};

#endif