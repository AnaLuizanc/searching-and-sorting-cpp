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

        void inserePosicao(int valor, int posicao){
            if(tamanho == 0){
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = NULL;
                cabeca = novo;
                tamanho++;
                qtdAcessos++;
            }else if(posicao == 0){
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = cabeca;
                cabeca = novo;
                qtdAcessos+=2;
                tamanho++;
            }else if(posicao >= tamanho){
                SimpleNode* ultimo = cabeca;qtdAcessos++;
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
            }else{
                SimpleNode* anterior = cabeca;
                SimpleNode* seguinte = cabeca->prox;
                qtdAcessos+=2;
                for(int i=0; i<posicao-1; i++){
                    anterior = anterior->prox;
                    seguinte = seguinte->prox;
                    qtdAcessos+=2;
                }
                SimpleNode* novo = new SimpleNode;
                novo->valor = valor;
                novo->prox = seguinte;
                anterior->prox = novo;
                qtdAcessos+=2;
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
            qtdAcessos+=4;
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

        void imprimeInverso_(SimpleNode* atual){
            if(atual == NULL)return;
            imprimeInverso_(atual->prox);
            cout << atual->valor << " ";
        }

        void imprimeInverso(){
            imprimeInverso_(cabeca);
            cout << endl;
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

class DoubleNode{
    public:
        int valor;
        DoubleNode* prox;
        DoubleNode* antec;
};

class DoubleList{
    public:
        DoubleList(){
            tamanho = 0;
            qtdAcessos = 0;
            cabeca->prox = cauda;
            cauda->antec = cabeca;
        }

        int tamanho;
        int qtdAcessos;
        DoubleNode* cabeca = new DoubleNode;
        DoubleNode* cauda = new DoubleNode;

        void armazenaValores(int valor){
            if(tamanho == 0){
                DoubleNode* novo = new DoubleNode;
                cabeca->prox = novo;
                cauda->antec = novo;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = cabeca;
                qtdAcessos+=4;
                tamanho++;
            }else{
                DoubleNode* ultimo = cauda->antec;
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = ultimo;
                cauda->antec = novo;
                ultimo->prox = novo;
                qtdAcessos+=5;
                tamanho++;
            }
        }

        void inserePosicao(int valor, int posicao){
            if(tamanho == 0){
                DoubleNode* novo = new DoubleNode;
                cabeca->prox = novo;
                cauda->antec = novo;
                novo->valor = valor;
                novo->prox = cauda;
                novo->antec = cabeca;
                qtdAcessos+=4;
                tamanho++;
            }else if(posicao == 0){
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                cabeca->prox->antec = novo;
                novo->prox = cabeca->prox;
                cabeca->prox = novo;
                novo->antec = cabeca;
                qtdAcessos+=6;
                tamanho++;
            }else if(posicao >= tamanho){
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                cauda->antec->prox = novo;
                novo->antec = cauda->antec;
                novo->prox = cauda;
                cauda->antec = novo;
                qtdAcessos+=6;
                tamanho++;
            }else{
                DoubleNode* anterior = cabeca;
                DoubleNode* seguinte = cabeca->prox;
                qtdAcessos+=2;
                for(int i=0; i<=posicao; i++){
                    anterior = anterior->prox;
                    seguinte = seguinte->prox;
                    qtdAcessos+=2;
                }
                DoubleNode* novo = new DoubleNode;
                novo->valor = valor;
                seguinte->antec = novo;
                anterior->prox = novo;
                novo->antec = anterior;
                novo->prox = seguinte;
                qtdAcessos+=4;
                tamanho++;
            }
        }

        void swap(int posicaoA, int posicaoB){
            DoubleNode* atualA = cabeca->prox;
            DoubleNode* atualB = cabeca->prox;
            qtdAcessos+=2;
            int contador = 0;
            while(contador != posicaoA){
                atualA = atualA->prox;
                qtdAcessos++;
                contador++;
            }
            contador = 0;
            while(contador != posicaoB){
                atualB = atualB->prox;
                qtdAcessos++;
                contador++;
            }
            int aux = atualA->valor;
            atualA->valor = atualB->valor;
            atualB->valor = aux;
            qtdAcessos+=4;
        }

        int buscaValor(int valor){
            DoubleNode* atual = cabeca->prox;
            qtdAcessos++;
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

        DoubleNode* buscaMenor(){
            DoubleNode* menor = cabeca->prox;
            DoubleNode* atual = cabeca->prox;
            qtdAcessos+=2;
            while(atual != cauda){
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

        void imprimeInverso(){
            DoubleNode* atual = cauda->antec;
            qtdAcessos++;
            while(atual != cabeca){
                cout << atual->valor << " ";
                atual = atual->antec;
                qtdAcessos+=2;
            }
            cout << endl;
        }

        void imprime(){
            DoubleNode* atual = cabeca->prox;
            qtdAcessos++;
            while(atual != cauda){
                cout << atual->valor << " ";
                atual = atual->prox;
                qtdAcessos+=2;
            }
            cout << endl;
        }
};

#endif