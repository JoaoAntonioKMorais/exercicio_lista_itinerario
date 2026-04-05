#include <iostream>
#include "../include/itinerario.h"

using namespace std;

int main() {
    Itinerario rota;
    inicializar(rota);

    inserirNoInicio(rota, "Terminal Centro");
    inserirNoFim(rota, "Rua das Flores");
    inserirNoFim(rota, "Avenida Brasil");
    inserirPorPosicao(rota, "Praca Central", 2);

    cout << "=== TESTE LISTA IDA ===\n";
    listarRotaIda(rota);

    cout << "\n=== TESTE LISTA VOLTA ===\n";
    listarRotaVolta(rota);

    cout << "\n=== TESTE BUSCA ===\n";
    buscarParadaPorNome(rota, "Praca");

    cout << "\n=== TESTE CONTAGEM ===\n";
    cout << "Quantidade de paradas: " << contarParadas(rota) << endl;

    cout << "\n=== TESTE REMOCOES ===\n";
    removerPrimeiraParada(rota);
    removerUltimaParada(rota);
    listarRotaIda(rota);

    liberarLista(rota);
    return 0;
}