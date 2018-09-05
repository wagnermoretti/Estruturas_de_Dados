#include <iostream>

using namespace std;

typedef string Texto;

class noh {
    friend class Aluno;
		private:
			const Texto nome;
			noh* mProximo;
			noh* mAnterior;
		public:
			noh();
};

noh::noh() {
    mProximo = NULL;
    mAnterior = NULL;
}

class Aluno {
    private:
        noh* mPrimeiro;
        noh* mUltimo;
        char* mNome;
        unsigned mMatricula;
        int mTamanho;
    public:
        Aluno();
        ~Aluno();
        void InsereNoInicio(unsigned matricula, Texto nome);
        inline bool vazia();
};
	
Aluno::Aluno() {
    mTamanho = 0;
    mPrimeiro = NULL;
    mUltimo = NULL;
}

Aluno::~Aluno() {
    noh* temporario = mPrimeiro;
    while (temporario != NULL) {
        delete temporario;
        temporario = temporario->mProximo;
    }
}

inline bool Aluno::vazia() {
	return (mPrimeiro == NULL);
} 

void Aluno::InsereNoInicio(unsigned matricula, Texto nome) {
	if (vazia()) {
		noh* novo = new noh(matricula, nome);
		mPrimeiro = novo;
		mUltimo = novo;
	} else {
		noh* novo = new noh(matricula, nome);
		novo->mProximo = mPrimeiro;
		mPrimeiro = novo;
	}
	tamanho++;
}

void Aluno::imprime() {
	noh* aux = mPrimeiro;
	while (aux != NULL) {
		cout << aux->mMatricula << " " << aux->mNome << " ";
		aux = aux->mProximo;
	}
}

int main() {
    Aluno cadastroAluno;
    string opcao;
    Texto nome;
    unsigned matricula;
    cin >> opcao;
    while (opcao != "t") {
        switch(opcao) {
            case "i":
                cin >> matricula >> nome;
                cadastroAluno.InsereNoInicio(matricula, nome);
                break;
            case "r":
                cin >> matricula;
                cadastroAluno.remove(matricula);
                break;
            case "ed":
                cout << cadastroAluno.imprime() << endl;
                break;
            case "er":
                cout << cadastroAluno.imprimeReverso() << endl;
                break;
        }
        cin >> opcao;
    }
    cadastroAluno.imprime();
    return 0;
}
