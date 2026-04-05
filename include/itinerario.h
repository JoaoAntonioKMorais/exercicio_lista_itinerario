#ifndef ITINERARIO_H
#define ITINERARIO_H

#include <string>

using namespace std;

struct No {
    string nome;
    No* anterior;
    No* proximo;
};

struct Itinerario {
    No* inicio;
    No* fim;
    int quantidade;
};

void inicializar(Itinerario& lista);
bool listaVazia(const Itinerario& lista);

void inserirNoInicio(Itinerario& lista, const string& nome);
void inserirNoFim(Itinerario& lista, const string& nome);
bool inserirPorPosicao(Itinerario& lista, const string& nome, int posicao);

bool removerPrimeiraParada(Itinerario& lista);
bool removerUltimaParada(Itinerario& lista);

void buscarParadaPorNome(const Itinerario& lista, const string& trecho);

void listarRotaIda(const Itinerario& lista);
void listarRotaVolta(const Itinerario& lista);

int contarParadas(const Itinerario& lista);

void liberarLista(Itinerario& lista);

#endif