#include <iostream>

using namespace std;

class Aluno {
	friend class Lista;
	public:
		Aluno(unsigned matricula, string nome) {
			mMatricula = matricula;
			mNome = nome;
			mProximo = NULL;
			mAnterior = NULL;
		}
	private:
		unsigned mMatricula;
		string mNome;
		Aluno* mProximo;
		Aluno* mAnterior;
};

class Lista {
	public:
		Lista();
		~Lista();
		inline bool Vazia();
		void InsereNoInicio(unsigned matricula, string nome);
		void Remove(unsigned matricula);
		void Imprime();
		void ImprimeReverso();
		bool ExisteMatricula(unsigned matricula);
	private:
		Aluno* mPrimeiro;
		Aluno* mUltimo;
		unsigned mTamanho;
		void RemoveTodos();
};

Lista::Lista() {
	mPrimeiro = NULL;
	mUltimo = NULL;
	mTamanho = 0;
}

Lista::~Lista() {
	RemoveTodos();
}

void Lista::RemoveTodos() {
	Aluno* aux = mPrimeiro;
	while (aux != NULL) {
		Aluno* temporario = aux;
		delete temporario;
		temporario = aux->mProximo;
		aux = aux->mProximo;
	}
	delete aux;
	mPrimeiro = NULL;
	mUltimo = NULL;
}

inline bool Lista::Vazia() {
	return (mPrimeiro == NULL);
}

void Lista::InsereNoInicio(unsigned matricula, string nome) {
	Aluno* novo = new Aluno(matricula, nome);
	if (Vazia()) {
		mPrimeiro = novo;
		mUltimo = novo;
	} else {
		novo->mProximo = mPrimeiro;
		mPrimeiro->mAnterior = novo;
		mPrimeiro = novo;
	}
	mTamanho++;
}

void Lista::Remove(unsigned matricula) {
	if (ExisteMatricula(matricula)) {
		Aluno* temporario = mPrimeiro;
		while (temporario->mMatricula != matricula) {
			temporario = temporario->mProximo;
		}
		if (temporario == mPrimeiro && temporario == mUltimo) {
			mPrimeiro = NULL;
			mUltimo = NULL;
		} else if (temporario == mPrimeiro) {
			mPrimeiro = temporario->mProximo;
			mPrimeiro->mAnterior = NULL;
		} else if (temporario == mUltimo) {
			mUltimo = temporario->mAnterior;
			mUltimo->mProximo = NULL;
		} else {
			temporario->mAnterior->mProximo = temporario->mProximo;
			temporario->mProximo->mAnterior = temporario->mAnterior;
		}
		
		delete temporario;
		mTamanho--;
	} else {
		cout << "ERRO" << endl;
	}
}

void Lista::Imprime() {
	Aluno* aux = mPrimeiro;
	while (aux != NULL) {
		cout << aux->mMatricula << " " << aux->mNome << " ";
		aux = aux->mProximo;
	}
}

void Lista::ImprimeReverso() {
	Aluno* aux = mUltimo;
	while (aux != NULL) {
		cout << aux->mMatricula << " " << aux->mNome << " ";
		aux = aux->mAnterior;
	}
}

bool Lista::ExisteMatricula(unsigned matricula) {
	Aluno* aux = mPrimeiro;
	while (aux != NULL) {
		if (aux->mMatricula == matricula) {
			return true;
		}
		aux = aux->mProximo;
	}
	return false;
}

int main() {
	Lista minhaLista;
	string opcao;
	unsigned matricula;
	string nome;
	 do {
        cin >> opcao;
        if (opcao == "i") {
            cin >> matricula >> nome;
            minhaLista.InsereNoInicio(matricula, nome);
		} else if (opcao == "r") {
			cin >> matricula;
			minhaLista.Remove(matricula);
		} else if (opcao == "ed") {
			minhaLista.Imprime();
            cout << endl;
        } else if (opcao == "er") {
            minhaLista.ImprimeReverso();
            cout << endl;
        }
    } while (opcao != "t");
    return 0;
}
