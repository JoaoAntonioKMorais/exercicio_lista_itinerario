#include <iostream>
#include <string>
#include "include/itinerario.h"

using namespace std;

int main() {
    Itinerario rota;
    inicializar(rota);

    int opcao;
    string nome;
    int posicao;

    do {
        cout << "\n=========== MENU ITINERARIO ===========\n";
        cout << "1 - Inserir parada no inicio\n";
        cout << "2 - Inserir parada no fim\n";
        cout << "3 - Inserir parada por posicao\n";
        cout << "4 - Remover primeira parada\n";
        cout << "5 - Remover ultima parada\n";
        cout << "6 - Buscar parada por nome\n";
        cout << "7 - Listar rota completa (ida)\n";
        cout << "8 - Listar rota em ordem inversa\n";
        cout << "9 - Contar paradas\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Digite o nome da parada: ";
                getline(cin, nome);
                inserirNoInicio(rota, nome);
                cout << "Parada inserida no inicio com sucesso.\n";
                break;

            case 2:
                cout << "Digite o nome da parada: ";
                getline(cin, nome);
                inserirNoFim(rota, nome);
                cout << "Parada inserida no fim com sucesso.\n";
                break;

            case 3:
                cout << "Digite o nome da parada: ";
                getline(cin, nome);
                cout << "Digite a posicao desejada: ";
                cin >> posicao;
                cin.ignore();

                if (inserirPorPosicao(rota, nome, posicao)) {
                    cout << "Parada inserida com sucesso.\n";
                } else {
                    cout << "Posicao invalida.\n";
                }
                break;

            case 4:
                if (removerPrimeiraParada(rota)) {
                    cout << "Primeira parada removida com sucesso.\n";
                } else {
                    cout << "A rota esta vazia.\n";
                }
                break;

            case 5:
                if (removerUltimaParada(rota)) {
                    cout << "Ultima parada removida com sucesso.\n";
                } else {
                    cout << "A rota esta vazia.\n";
                }
                break;

            case 6:
                cout << "Digite parte do nome da parada: ";
                getline(cin, nome);
                buscarParadaPorNome(rota, nome);
                break;

            case 7:
                listarRotaIda(rota);
                break;

            case 8:
                listarRotaVolta(rota);
                break;

            case 9:
                cout << "Total de paradas cadastradas: "
                     << contarParadas(rota) << endl;
                break;

            case 0:
                cout << "Encerrando o sistema...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    liberarLista(rota);
    return 0;
}