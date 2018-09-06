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
		void Remove();
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
	if (vazia()) {
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
	Aluno* aux = mPrimeiro;
	bool achou = false;
	unsigned contador = 1;
	while (aux != NULL || achou == true) {
		if (mTamanho == 1) {
			// remove o mPrimeiro
			delete temporario;
		}
		if (contador == mTamanho) {
			// remove o mUltimo
			Aluno* temporario = aux;
			ultimo = aux->mAnterior;
			delete temporario;
			ultimo->mProximo = NULL;
		} 
		if  (aux->mMatricula == matricula) {
			// Faltou aqui
		} 
		aux = aux->mProximo;
		contador++;
		mTamanho--;
	}
}