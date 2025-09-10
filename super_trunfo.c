#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char nome[50];
    float populacao;
    float area;
    float densidade;
    float idh;
} Carta;

// Função para exibir os detalhes da carta e o resultado da rodada
void exibirResultado(const char* resultado, const Carta* carta1, const Carta* carta2, int atributo1, int atributo2) {
    printf("\n--- RESULTADO DA RODADA ---\n");
    printf("Comparando %s com %s\n", carta1->nome, carta2->nome);

    // Array de nomes dos atributos para exibicao
    const char* atributosNomes[] = {"Populacao", "Area", "Densidade Demografica", "IDH"};

    // Exibindo os valores de cada atributo para cada carta
    printf("\nAtributo 1: %s\n", atributosNomes[atributo1 - 1]);
    printf("  %s: %.2f\n", carta1->nome, (atributo1 == 1) ? carta1->populacao : (atributo1 == 2) ? carta1->area : (atributo1 == 3) ? carta1->densidade : carta1->idh);
    printf("  %s: %.2f\n", carta2->nome, (atributo1 == 1) ? carta2->populacao : (atributo1 == 2) ? carta2->area : (atributo1 == 3) ? carta2->densidade : carta2->idh);

    printf("\nAtributo 2: %s\n", atributosNomes[atributo2 - 1]);
    printf("  %s: %.2f\n", carta1->nome, (atributo2 == 1) ? carta1->populacao : (atributo2 == 2) ? carta1->area : (atributo2 == 3) ? carta1->densidade : carta1->idh);
    printf("  %s: %.2f\n", carta2->nome, (atributo2 == 1) ? carta2->populacao : (atributo2 == 2) ? carta2->area : (atributo2 == 3) ? carta2->densidade : carta2->idh);

    // Calculando a soma dos atributos
    float soma1 = ((atributo1 == 1) ? carta1->populacao : (atributo1 == 2) ? carta1->area : (atributo1 == 3) ? carta1->densidade : carta1->idh) +
                  ((atributo2 == 1) ? carta1->populacao : (atributo2 == 2) ? carta1->area : (atributo2 == 3) ? carta1->densidade : carta1->idh);
    
    float soma2 = ((atributo1 == 1) ? carta2->populacao : (atributo1 == 2) ? carta2->area : (atributo1 == 3) ? carta2->densidade : carta2->idh) +
                  ((atributo2 == 1) ? carta2->populacao : (atributo2 == 2) ? carta2->area : (atributo2 == 3) ? carta2->densidade : carta2->idh);

    printf("\nSoma dos atributos de %s: %.2f\n", carta1->nome, soma1);
    printf("Soma dos atributos de %s: %.2f\n", carta2->nome, soma2);

    printf("\n%s\n", resultado);
}

// Funcao principal que contem a logica do jogo
int main() {
    // Cartas pre-cadastradas
    Carta cartas[3];

    strcpy(cartas[0].nome, "Brasil");
    cartas[0].populacao = 215.3;
    cartas[0].area = 8.51;
    cartas[0].densidade = 25.3;
    cartas[0].idh = 0.76;

    strcpy(cartas[1].nome, "India");
    cartas[1].populacao = 1417.0;
    cartas[1].area = 3.28;
    cartas[1].densidade = 431.0;
    cartas[1].idh = 0.63;

    strcpy(cartas[2].nome, "EUA");
    cartas[2].populacao = 333.3;
    cartas[2].area = 9.83;
    cartas[2].densidade = 33.7;
    cartas[2].idh = 0.92;

    int escolha_carta1, escolha_carta2;
    int escolha_atributo1, escolha_atributo2;
    int validade = 0;

    // Menu para escolha das cartas
    printf("--- SUPER TRUNFO ---\n");
    printf("Escolha a primeira carta:\n");
    printf("1. Brasil\n");
    printf("2. India\n");
    printf("3. EUA\n");
    printf("Opcao: ");
    scanf("%d", &escolha_carta1);

    printf("\nEscolha a segunda carta:\n");
    printf("1. Brasil\n");
    printf("2. India\n");
    printf("3. EUA\n");
    printf("Opcao: ");
    scanf("%d", &escolha_carta2);

    // Lógica para garantir que cartas diferentes sejam escolhidas
    while (escolha_carta1 == escolha_carta2 || escolha_carta1 < 1 || escolha_carta1 > 3 || escolha_carta2 < 1 || escolha_carta2 > 3) {
        printf("\nEscolha de cartas invalida. As cartas devem ser diferentes e validas.\n");
        printf("Escolha a primeira carta: ");
        scanf("%d", &escolha_carta1);
        printf("Escolha a segunda carta: ");
        scanf("%d", &escolha_carta2);
    }
    
    // Menu para escolha dos atributos (dinamico)
    printf("\n--- ESCOLHA DE ATRIBUTOS ---\n");
    do {
        printf("\nEscolha o primeiro atributo para comparacao:\n");
        printf("1. Populacao\n");
        printf("2. Area\n");
        printf("3. Densidade Demografica\n");
        printf("4. IDH\n");
        printf("Opcao: ");
        scanf("%d", &escolha_atributo1);

        switch (escolha_atributo1) {
            case 1:
            case 2:
            case 3:
            case 4:
                validade = 1;
                break;
            default:
                printf("\nOpcao invalida. Por favor, escolha um numero entre 1 e 4.\n");
                validade = 0;
        }
    } while (!validade);

    // Segundo menu, excluindo a primeira opcao
    do {
        printf("\nEscolha o segundo atributo para comparacao:\n");
        printf("1. Populacao\n");
        if (escolha_atributo1 != 1) printf("1. Populacao\n");
        if (escolha_atributo1 != 2) printf("2. Area\n");
        if (escolha_atributo1 != 3) printf("3. Densidade Demografica\n");
        if (escolha_atributo1 != 4) printf("4. IDH\n");
        printf("Opcao: ");
        scanf("%d", &escolha_atributo2);

        if (escolha_atributo2 == escolha_atributo1 || escolha_atributo2 < 1 || escolha_atributo2 > 4) {
            printf("\nOpcao invalida. Escolha um atributo diferente do primeiro.\n");
            validade = 0;
        } else {
            validade = 1;
        }
    } while (!validade);

    // Lógica de comparação dos atributos
    Carta* carta1 = &cartas[escolha_carta1 - 1];
    Carta* carta2 = &cartas[escolha_carta2 - 1];

    int vitorias_carta1 = 0;
    int vitorias_carta2 = 0;

    // Comparacao do primeiro atributo
    float valor1_a1, valor2_a1;
    // Operador ternario para selecionar o valor correto do atributo
    valor1_a1 = (escolha_atributo1 == 1) ? carta1->populacao : (escolha_atributo1 == 2) ? carta1->area : (escolha_atributo1 == 3) ? carta1->densidade : carta1->idh;
    valor2_a1 = (escolha_atributo1 == 1) ? carta2->populacao : (escolha_atributo1 == 2) ? carta2->area : (escolha_atributo1 == 3) ? carta2->densidade : carta2->idh;

    // Condicional para a regra de Densidade Demografica
    if (escolha_atributo1 == 3) {
        if (valor1_a1 < valor2_a1) {
            vitorias_carta1++;
        } else if (valor2_a1 < valor1_a1) {
            vitorias_carta2++;
        }
    } else {
        if (valor1_a1 > valor2_a1) {
            vitorias_carta1++;
        } else if (valor2_a1 > valor1_a1) {
            vitorias_carta2++;
        }
    }

    // Comparacao do segundo atributo
    float valor1_a2, valor2_a2;
    valor1_a2 = (escolha_atributo2 == 1) ? carta1->populacao : (escolha_atributo2 == 2) ? carta1->area : (escolha_atributo2 == 3) ? carta1->densidade : carta1->idh;
    valor2_a2 = (escolha_atributo2 == 1) ? carta2->populacao : (escolha_atributo2 == 2) ? carta2->area : (escolha_atributo2 == 3) ? carta2->densidade : carta2->idh;

    if (escolha_atributo2 == 3) {
        if (valor1_a2 < valor2_a2) {
            vitorias_carta1++;
        } else if (valor2_a2 < valor1_a2) {
            vitorias_carta2++;
        }
    } else {
        if (valor1_a2 > valor2_a2) {
            vitorias_carta1++;
        } else if (valor2_a2 > valor1_a2) {
            vitorias_carta2++;
        }
    }

    // Determinando o vencedor
    if (vitorias_carta1 > vitorias_carta2) {
        exibirResultado("Vencedor: " + (char*)carta1->nome, carta1, carta2, escolha_atributo1, escolha_atributo2);
    } else if (vitorias_carta2 > vitorias_carta1) {
        exibirResultado("Vencedor: " + (char*)carta2->nome, carta1, carta2, escolha_atributo1, escolha_atributo2);
    } else {
        // Logica de desempate por soma
        float soma_carta1 = valor1_a1 + valor1_a2;
        float soma_carta2 = valor2_a1 + valor2_a2;

        if (soma_carta1 > soma_carta2) {
            exibirResultado("Empate de atributos! Vencedor (maior soma): " + (char*)carta1->nome, carta1, carta2, escolha_atributo1, escolha_atributo2);
        } else if (soma_carta2 > soma_carta1) {
            exibirResultado("Empate de atributos! Vencedor (maior soma): " + (char*)carta22->nome, carta1, carta2, escolha_atributo1, escolha_atributo2);
        } else {
            exibirResultado("Empate!", carta1, carta2, escolha_atributo1, escolha_atributo2);
        }
    }
    
    return 0;
}