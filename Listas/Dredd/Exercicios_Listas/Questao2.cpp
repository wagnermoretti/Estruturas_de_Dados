#include <iostream>

using namespace std;

typedef string Texto;

class noh {
        friend class lista;
    private:
        const Texto palavra;
        noh* proximo;
    public:
        noh(Texto p);
};

noh::noh(Texto p) : palavra(p) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
        void removeTodos();
    public:
        lista();
        lista(const lista& umaLista);
        lista& operator=(const lista& umaLista);
        lista&
         operator+(const lista& umaLista);
        ~lista();
        void insere(Texto palavra);
        void imprime() const;
        void insereNoFim(Texto palavra);
        inline bool vazia();
};

// constrói uma lista inicialmente vazia
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

// insere no inicio da lista
void lista::insere(Texto palavra) {
    noh* novo = new noh(palavra);
    novo->proximo = primeiro;
    primeiro = novo;
    if (tamanho == 0)
        ultimo = novo;
    ++tamanho;
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() const {
    noh* iter = primeiro;
    while (iter != NULL) {
        cout << iter->palavra << " ";
        iter = iter->proximo;
    }
    cout << endl;
}

// construtor de cópia
lista::lista(const lista& umaLista) {
    // IMPLEMENTAR
    removeTodos();
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh* aux = umaLista.primeiro;
    while (aux != NULL) {
		insereNoFim(aux->palavra);
		aux = aux->proximo;
	}
}

// sobrecarga do operador de atribuição - retorna a própria lista
lista& lista::operator=(const lista& umaLista) {
    // IMPLEMENTAR
    removeTodos();
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
    noh* aux = umaLista.primeiro;
    while (aux != NULL) {
		insereNoFim(aux->palavra);
		aux = aux->proximo;
	}
	return *this;
}

// concatenacao de listas
lista& lista::operator+(const lista& umaLista) {
    // IMPLEMENTAR
    // IMPLEMENTAR
    noh* aux = umaLista.primeiro;
    while (aux != NULL) {
		insereNoFim(aux->palavra);
		aux = aux->proximo;
	}
	return *this;
}

void lista::insereNoFim(Texto palavra) {
	 if (vazia()) {
        noh* novo = new noh(palavra);
        primeiro = novo;
        ultimo = novo;
    } else {
        noh* novo = new noh(palavra);
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

inline bool lista::vazia() {
	return (primeiro == NULL);
}

void lista::removeTodos() {
	noh* aux = primeiro;
	noh* temporario;
	while (aux != NULL) {
		temporario = aux;
		delete temporario;
		aux = aux->proximo;
	}
	delete aux;
}

int main() { // NÃO MODIFIQUE!
    lista listaA;
    lista listaB;
    string opcao;
    string palavra;
    char idLista;
    do {
        cin >> opcao;
        if (opcao == "i") {
            cin >> idLista >> palavra;
            if (idLista == 'a')
                listaA.insere(palavra);
            else
                listaB.insere(palavra);
        }
        else if (opcao == "a=b") {
            listaA = listaB;
        }
        else if (opcao == "b=a") {
            listaB = listaA;
        }
        else if (opcao == "s") {
            lista soma = listaA + listaB;
            soma.imprime();
        }
        else if (opcao == "e") {
            cin >> idLista;
            if (idLista == 'a')
                listaA.imprime();
            else
                listaB.imprime();
        }
    } while (opcao != "t");
    return 0;
}
