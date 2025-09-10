#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char nome[50];
    char estado[3];
    char codigo_carta[10];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função principal do programa
int main() {
    // Cartas pre-cadastradas
    Carta carta1;
    strcpy(carta1.nome, "Brasil");
    strcpy(carta1.estado, "BR");
    carta1.populacao = 215300000;
    carta1.area = 8510000;
    carta1.pib = 1600.0;
    carta1.pontos_turisticos = 50;

    Carta carta2;
    strcpy(carta2.nome, "Estados Unidos");
    strcpy(carta2.estado, "EUA");
    carta2.populacao = 333000000;
    carta2.area = 9834000;
    carta2.pib = 23320.0;
    carta2.pontos_turisticos = 70;

    // Calculo de atributos derivados
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;
    
    int escolha;

    // Menu Interativo
    printf("--- SUPER TRUNFO ---\n");
    printf("Escolha o atributo para a comparacao entre %s e %s:\n", carta1.nome, carta2.nome);
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    
    printf("\n--- RESULTADO DA RODADA ---\n");
    
    // Logica da comparacao com base na escolha do usuario
    switch(escolha) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", carta1.nome, carta1.populacao);
            printf("%s: %d\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("\nResultado: %s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\nResultado: %s venceu!\n", carta2.nome);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
            
        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f km2\n", carta1.nome, carta1.area);
            printf("%s: %.2f km2\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("\nResultado: %s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("\nResultado: %s venceu!\n", carta2.nome);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
            
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhoes\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhoes\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("\nResultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("\nResultado: %s venceu!\n", carta2.nome);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
            
        case 4:
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("\nResultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("\nResultado: %s venceu!\n", carta2.nome);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km2\n", carta1.nome, carta1.densidade_populacional);
            printf("%s: %.2f hab/km2\n", carta2.nome, carta2.densidade_populacional);
            
            // Regra especial: menor valor vence
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("\nResultado: %s venceu!\n", carta1.nome);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("\nResultado: %s venceu!\n", carta2.nome);
            } else {
                printf("\nResultado: Empate!\n");
            }
            break;
            
        default:
            printf("Opcao invalida. Por favor, escolha um numero de 1 a 5.\n");
            break;
    }

    return 0;
}