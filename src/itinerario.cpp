#include "../include/itinerario.h"
#include <iostream>

using namespace std;

void inicializar(Itinerario& lista) {
    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.quantidade = 0;
}

bool listaVazia(const Itinerario& lista) {
    return lista.inicio == nullptr;
}

void inserirNoInicio(Itinerario& lista, const string& nome) {
    No* novo = new No;
    novo->nome = nome;
    novo->anterior = nullptr;
    novo->proximo = lista.inicio;

    if (listaVazia(lista)) {
        lista.fim = novo;
    } else {
        lista.inicio->anterior = novo;
    }

    lista.inicio = novo;
    lista.quantidade++;
}

void inserirNoFim(Itinerario& lista, const string& nome) {
    No* novo = new No;
    novo->nome = nome;
    novo->proximo = nullptr;
    novo->anterior = lista.fim;

    if (listaVazia(lista)) {
        lista.inicio = novo;
    } else {
        lista.fim->proximo = novo;
    }

    lista.fim = novo;
    lista.quantidade++;
}

bool inserirPorPosicao(Itinerario& lista, const string& nome, int posicao) {
    if (posicao < 1 || posicao > lista.quantidade + 1) {
        return false;
    }

    if (posicao == 1) {
        inserirNoInicio(lista, nome);
        return true;
    }

    if (posicao == lista.quantidade + 1) {
        inserirNoFim(lista, nome);
        return true;
    }

    No* atual = lista.inicio;
    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    No* novo = new No;
    novo->nome = nome;
    novo->anterior = atual;
    novo->proximo = atual->proximo;

    atual->proximo->anterior = novo;
    atual->proximo = novo;

    lista.quantidade++;
    return true;
}

bool removerPrimeiraParada(Itinerario& lista) {
    if (listaVazia(lista)) {
        return false;
    }

    No* apagar = lista.inicio;

    if (lista.inicio == lista.fim) {
        lista.inicio = nullptr;
        lista.fim = nullptr;
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = nullptr;
    }

    delete apagar;
    lista.quantidade--;
    return true;
}

bool removerUltimaParada(Itinerario& lista) {
    if (listaVazia(lista)) {
        return false;
    }

    No* apagar = lista.fim;

    if (lista.inicio == lista.fim) {
        lista.inicio = nullptr;
        lista.fim = nullptr;
    } else {
        lista.fim = lista.fim->anterior;
        lista.fim->proximo = nullptr;
    }

    delete apagar;
    lista.quantidade--;
    return true;
}

void buscarParadaPorNome(const Itinerario& lista, const string& trecho) {
    if (listaVazia(lista)) {
        cout << "Rota vazia.\n";
        return;
    }

    No* atual = lista.inicio;
    bool encontrou = false;
    int posicao = 1;

    while (atual != nullptr) {
        if (atual->nome.find(trecho) != string::npos) {
            cout << "Parada encontrada na posicao " << posicao
                 << ": " << atual->nome << endl;
            encontrou = true;
        }
        atual = atual->proximo;
        posicao++;
    }

    if (!encontrou) {
        cout << "Nenhuma parada encontrada com esse nome.\n";
    }
}

void listarRotaIda(const Itinerario& lista) {
    if (listaVazia(lista)) {
        cout << "Rota vazia.\n";
        return;
    }

    No* atual = lista.inicio;

    cout << "\nRota completa (ida):\n";
    while (atual != nullptr) {
        cout << "- " << atual->nome << endl;
        atual = atual->proximo;
    }
}

void listarRotaVolta(const Itinerario& lista) {
    if (listaVazia(lista)) {
        cout << "Rota vazia.\n";
        return;
    }

    No* atual = lista.fim;

    cout << "\nRota em ordem inversa:\n";
    while (atual != nullptr) {
        cout << "- " << atual->nome << endl;
        atual = atual->anterior;
    }
}

int contarParadas(const Itinerario& lista) {
    return lista.quantidade;
}

void liberarLista(Itinerario& lista) {
    No* atual = lista.inicio;

    while (atual != nullptr) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.quantidade = 0;
}