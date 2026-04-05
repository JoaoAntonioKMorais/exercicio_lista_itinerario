# Exercício Lista - Itinerário

## Descrição
Este projeto implementa um sistema de itinerário de ônibus em C++, utilizando listas encadeadas como estrutura principal de dados. O sistema permite cadastrar, remover, buscar e listar paradas da rota por meio de um menu interativo.

## Funcionalidades
- Inserir parada no início
- Inserir parada no fim
- Inserir parada por posição
- Remover primeira parada
- Remover última parada
- Buscar parada por nome
- Listar rota completa (ida)
- Listar rota em ordem inversa
- Contar paradas

## Estrutura escolhida
Foi utilizada uma **lista duplamente encadeada**.

## Justificativa
A lista duplamente encadeada foi escolhida porque atende melhor às operações exigidas pelo problema.

Ela permite:
- inserção no início da rota;
- inserção no fim da rota;
- inserção em uma posição específica;
- remoção da primeira parada;
- remoção da última parada;
- navegação da rota em ordem normal e em ordem inversa.

A principal vantagem dessa estrutura é a facilidade para percorrer os elementos tanto do início para o fim quanto do fim para o início. Isso torna a operação de listar a rota em ordem inversa mais simples e eficiente.

Se fosse utilizada uma lista simplesmente encadeada, a listagem inversa seria mais trabalhosa, exigindo outras estratégias. A lista circular também não foi a melhor escolha para este caso, pois o problema não exige que a última parada se conecte automaticamente à primeira.

## Cenário em que outra estrutura seria mais vantajosa
Em uma linha circular de ônibus, uma **lista circular** poderia ser mais vantajosa, pois a última parada se conecta novamente à primeira, representando melhor um trajeto contínuo.

## Organização do projeto
- `include/itinerario.h` -> definições das estruturas e protótipos das funções
- `src/itinerario.cpp` -> implementação das funções
- `main.cpp` -> menu interativo do sistema
- `tests/teste.cpp` -> testes simples das operações
- `README.md` -> descrição e justificativas do projeto

## Compilação

### Testes
```bash
 g++ -o teste tests/teste.cpp src/itinerario.cpp -Iinclude
./teste
```

### Programa principal
```bash
g++ -o main main.cpp src/itinerario.cpp -Iinclude
./main
