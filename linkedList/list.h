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

typedef struct node_aux{
    int valor;
    int qtdAcessos;
    int tamanho;
    struct node_aux* prox;
}SimpleNode;

typedef SimpleNode* List;

void inicializaLista(List* apLista){
    SimpleNode* cabeca = (SimpleNode*)malloc(sizeof(SimpleNode));
    cabeca->qtdAcessos = 0;
    cabeca->tamanho = 0;
    cabeca->valor = -1;
    cabeca->prox = NULL;
    *apLista = cabeca;      
}

void armazenaValores(List* apLista, int valor){
    SimpleNode* ultimo = (*apLista);
    while(ultimo->prox != NULL)
        ultimo = ultimo->prox;
    SimpleNode* novoNo = (SimpleNode*)malloc(sizeof(SimpleNode));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    ultimo->prox = novoNo;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
}

void inserePosicao(List* apLista, int valor, int posicao){
    SimpleNode* seguinte = (*apLista);
    SimpleNode* antec = (*apLista);
    SimpleNode* novoNo = (SimpleNode*)malloc(sizeof(SimpleNode));
    novoNo->valor = valor;
    int contador = 0;
    while(contador != posicao){
        seguinte = seguinte->prox;
        antec = antec->prox;
        contador++;
    }
    seguinte = seguinte->prox;
    antec->prox = novoNo;
    novoNo->prox = seguinte;
    (*apLista)->tamanho++;
    (*apLista)->qtdAcessos++;
}

void swap(List* apLista, int posicaoA, int posicaoB){
    SimpleNode* atualA = (*apLista)->prox;
    SimpleNode* atualB = (*apLista)->prox;
    int contadorA = 0, contadorB = 0;
    while(contadorA != posicaoA){
        atualA = atualA->prox;
        contadorA++;
    }
    while(contadorB != posicaoB){
        atualB = atualB->prox;
        contadorB++;
    }
    int auxiliar = atualA->valor;
    atualA->valor = atualB->valor;
    atualB->valor = auxiliar;
    (*apLista)->qtdAcessos++;
}

int buscaValor(List lista, int valor){
    SimpleNode* atual = lista->prox;
    for(int i=0; i<lista->tamanho; i++){
        if(atual->valor == valor)
            return i;
        atual = atual->prox;
    }
    lista->qtdAcessos++;
    return -1;
}

SimpleNode* buscaMenor(List lista){
    SimpleNode* menor = lista->prox;
    SimpleNode* atual = menor->prox;
    while(atual != NULL){
        if(atual->valor < menor->valor){
            menor = &(*atual);
            atual = atual->prox;
        }
        atual = atual->prox;
    }
    lista->qtdAcessos++;
    return menor;
}

void imprime(List lista){
    List aux = lista->prox; 
    while(aux != NULL){
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

#endif