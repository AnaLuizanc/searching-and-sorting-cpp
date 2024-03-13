#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

        void imprimeInverso(){
            for(int i=tamanho-1; i>=0; i--){
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

        void swap(int posicaoA, int posicaoB){
            int auxiliar;
            auxiliar = vector[posicaoA];
            vector[posicaoA] = vector[posicaoB];
            vector[posicaoB] = auxiliar;
            qtdAcessos++;
        }

        int buscaMenor(){
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

class SimpleNode{
    public:
        int valor;
        SimpleNode* prox;
};

class SimpleList{
    public:
        SimpleList(){
            tamanho = 0;
            qtdAcessos = 0;
            cabeca = NULL;
        }
        int tamanho;
        int qtdAcessos;
        SimpleNode* cabeca;

        void armazenaValores(int valor){
            if(tamanho == 0){
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = NULL;
                cabeca = novo;
                tamanho++;
                qtdAcessos++;
            }else{
                SimpleNode* ultimo = cabeca;
                while(ultimo->prox != NULL){
                    ultimo = ultimo->prox;
                    qtdAcessos++;
                }
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = NULL;
                ultimo->prox = novo;
                tamanho++;
                qtdAcessos++;
            }
        }

        void inserePosicao(int posicao, int valor){
            if(posicao == 0){
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = cabeca;
                cabeca = novo;
                qtdAcessos+=2;
                tamanho++;

            }else if(posicao > tamanho){
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                SimpleNode* ultimo = cabeca;
                qtdAcessos++;
                while(ultimo->prox != NULL){
                    ultimo = ultimo->prox;
                    qtdAcessos++;
                }
                novo->prox = NULL;
                ultimo->prox = novo;
                qtdAcessos++;
                tamanho++;
            }else{
                SimpleNode* anterior = cabeca;
                SimpleNode* seguinte = cabeca;
                for(int i=0; i<posicao; i++){
                    anterior = anterior->prox;
                    seguinte = seguinte->prox;
                    qtdAcessos+=2;
                } 
                seguinte = seguinte->prox;qtdAcessos++;
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = seguinte;
                anterior->prox = novo;
                qtdAcessos++;
                tamanho++;
            }
        }

        void swap(int posicaoA, int posicaoB){
            SimpleNode* atualA = cabeca;qtdAcessos++;
            SimpleNode* atualB = cabeca;qtdAcessos++;
            int contador = 0;
            while(contador != posicaoA){
                atualA = atualA->prox;
                contador++;
                qtdAcessos++;
            }
            contador = 0;
            while(contador != posicaoB){
                atualB = atualB->prox;
                contador++;
                qtdAcessos++;
            }
            int aux = atualA->valor;
            atualA->valor = atualB->valor;
            atualB->valor = aux;
            qtdAcessos+=3;
        }

        int buscaValor(int valor){
            SimpleNode* atual = cabeca;qtdAcessos++;
            for(int i=0; i<tamanho; i++){
                if(atual->valor == valor){
                    qtdAcessos++;
                    return i;
                }
                qtdAcessos++;
                atual = atual->prox;
            }
            return -1;
        }

        SimpleNode* buscaMenor(){
            SimpleNode* menor = cabeca->prox;
            SimpleNode* atual = cabeca->prox;
            qtdAcessos+=2;
            while(atual != NULL){
                if(atual->valor < menor->valor){
                    menor = atual;
                    atual = atual->prox;
                    qtdAcessos+=2;
                }
                atual = atual->prox;
                qtdAcessos++;
            }
            return menor;
        }

        void imprime(){
            SimpleNode* atual = cabeca;
            qtdAcessos++;
            while(atual != NULL){
                cout << atual->valor << " ";
                atual = atual->prox;
                qtdAcessos++;
            }
            cout << endl;
        }
};

#endif