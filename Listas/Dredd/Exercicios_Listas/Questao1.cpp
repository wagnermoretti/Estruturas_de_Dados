#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constroi uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// metodo basico que percorre a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrao no final da lista
void lista::insere(Dado dado) {
    // Implemente aqui
    if (vazia()) {
        noh* novo = new noh(dado);
        primeiro = novo;
        ultimo = novo;
    } else {
        noh* novo = new noh(dado);
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

// insere um dado em uma determinada posicao da lista
void lista::insere(Dado dado, int posicao) {
    // Implemente aqui
    if (posicao >= 0 && posicao <= tamanho) {
        if (vazia()) {
             noh* novo = new noh(dado);
            primeiro = novo;
            ultimo = novo;
        } else if (posicao == 0) {
            noh* novo = new noh(dado);
            novo->proximo = primeiro;
            primeiro = novo;
        } else if (posicao == tamanho && tamanho != 0) {
            noh* novo = new noh(dado);
            ultimo->proximo = novo;
            ultimo = novo;
        } else {
            int contador = 0;
            noh* aux = primeiro;
            while (contador < posicao-1) {
                aux = aux->proximo;
                contador++;
            }
            noh* novo = new noh(dado);
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        tamanho++;
    }
}

// remove o item da posicao passada por parametro
// Atencao - o codigo deve tratar de posicoes invalidas
void lista::remove(int posicao) {
    // Implemente aqui
    if (posicao >= 0 && posicao < tamanho) {
        if (posicao == 0) {
            noh* temporario = primeiro;
            primeiro = primeiro->proximo;
            delete temporario;
        } else if (posicao == tamanho-1) {
            noh* aux = primeiro;
            noh* temporario;
            for (int i = 0; i < tamanho-2; i++) {
                aux = aux->proximo;
            }
            temporario = aux->proximo;
            ultimo = aux;
            ultimo->proximo = NULL;
            delete temporario;
        } else {
            noh* aux = primeiro;
            noh* temporario;
            for (int i = 0; i < posicao-1; i++) {
                aux = aux->proximo;
            }
            temporario = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            delete temporario;
        }
        tamanho--;
    }
}

// procura por um elemento e retorna a posicao ou -1 se nao encontrado
int lista::procura(Dado valor) {
    // Implemente aqui
    int posicao = 0;
    noh* aux = primeiro;
    while (aux != NULL) {
        if (aux->dado == valor) {
            return posicao;
        }
        aux = aux->proximo;
        posicao++;
    }
    return -1;
}

// verifica se a lista esta vazia
inline bool lista::vazia() {
    // Implemente aqui
    return (primeiro == NULL);
}

int main() { // NÃO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
