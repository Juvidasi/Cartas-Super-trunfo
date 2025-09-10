#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[3];
    char codigo_carta[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para realizar os calculos e exibir a carta
void exibirCarta(Carta *c) {
    c->densidade_populacional = (float)c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
    
    printf("\n--- Detalhes da Carta ---\n");
    printf("Cidade: %s (%s)\n", c->nome_cidade, c->estado);
    printf("Populacao: %d habitantes\n", c->populacao);
    printf("Area: %.2f km2\n", c->area);
    printf("PIB: %.2f bilhoes\n", c->pib);
    printf("Pontos Turisticos: %d\n", c->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", c->densidade_populacional);
    printf("PIB per capita: %.2f bilhoes/hab\n", c->pib_per_capita);
}

// Funcao principal do programa
int main() {

    // --- CADASTRO DAS DUAS CARTAS ---
    Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo_carta, "SP-01");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11;
    carta1.pib = 763.8;
    carta1.pontos_turisticos = 25;

    Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo_carta, "RJ-01");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6775561;
    carta2.area = 1200.2;
    carta2.pib = 364.0;
    carta2.pontos_turisticos = 50;

    // --- EXIBICAO DOS DETALHES DAS CARTAS ---
    exibirCarta(&carta1);
    exibirCarta(&carta2);
    
    // --- COMPARACAO DE ATRIBUTOS ---
    
    // Escolha do atributo para comparacao (1 = Populacao, 2 = Area, 3 = PIB, 4 = Densidade, 5 = PIB per capita)
    int atributo_comparacao = 4; // Exemplo: comparando a Densidade Populacional
    
    printf("\n\n--- COMPARACAO DE CARTAS ---\n");

    // Lógica para a comparação
    if (atributo_comparacao == 1) { // Populacao
        printf("Atributo: Populacao\n");
        printf("Carta 1 (%s): %d\n", carta1.nome_cidade, carta1.populacao);
        printf("Carta 2 (%s): %d\n", carta2.nome_cidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributo_comparacao == 2) { // Area
        printf("Atributo: Area\n");
        printf("Carta 1 (%s): %.2f\n", carta1.nome_cidade, carta1.area);
        printf("Carta 2 (%s): %.2f\n", carta2.nome_cidade, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributo_comparacao == 3) { // PIB
        printf("Atributo: PIB\n");
        printf("Carta 1 (%s): %.2f\n", carta1.nome_cidade, carta1.pib);
        printf("Carta 2 (%s): %.2f\n", carta2.nome_cidade, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributo_comparacao == 4) { // Densidade Populacional (menor valor vence)
        printf("Atributo: Densidade Populacional\n");
        printf("Carta 1 (%s): %.2f\n", carta1.nome_cidade, carta1.densidade_populacional);
        printf("Carta 2 (%s): %.2f\n", carta2.nome_cidade, carta2.densidade_populacional);
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributo_comparacao == 5) { // PIB per capita
        printf("Atributo: PIB per capita\n");
        printf("Carta 1 (%s): %.2f\n", carta1.nome_cidade, carta1.pib_per_capita);
        printf("Carta 2 (%s): %.2f\n", carta2.nome_cidade, carta2.pib_per_capita);
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Atributo de comparacao invalido. Por favor, escolha um numero entre 1 e 5.\n");
    }

    return 0;
}