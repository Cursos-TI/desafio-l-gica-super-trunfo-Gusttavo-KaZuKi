#include <stdio.h>

int main() {
    // Cadastro das cartas
    char nome_cidade1[50], nome_cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;

    // Entrada da Carta 1
    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", nome_cidade1);

    printf("Digite a populacao da cidade da Carta 1: ");
    scanf("%lu", &populacao1);

    printf("Digite a area da cidade da Carta 1 em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade da Carta 1: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da cidade da Carta 1: ");
    scanf("%d", &pontos_turisticos1);

    // Entrada da Carta 2
    printf("\nDigite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", nome_cidade2);

    printf("Digite a populacao da cidade da Carta 2: ");
    scanf("%lu", &populacao2);

    printf("Digite a area da cidade da Carta 2 em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade da Carta 2: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da cidade da Carta 2: ");
    scanf("%d", &pontos_turisticos2);

    // Calcula densidade e PIB per capita
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;
    float pib_per_capita1 = pib1 / populacao1;
    float pib_per_capita2 = pib2 / populacao2;

    // Menu interativo para escolha de dois atributos
    int escolha1, escolha2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &escolha1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Populacional\n");
        printf("6 - PIB per Capita\n");
        printf("Opcao: ");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1);

    float valor1_at1, valor1_at2, valor2_at1, valor2_at2;

    // Atribui valores dos atributos escolhidos
    switch (escolha1) {
        case 1: valor1_at1 = populacao1; valor2_at1 = populacao2; break;
        case 2: valor1_at1 = area1; valor2_at1 = area2; break;
        case 3: valor1_at1 = pib1; valor2_at1 = pib2; break;
        case 4: valor1_at1 = pontos_turisticos1; valor2_at1 = pontos_turisticos2; break;
        case 5: valor1_at1 = densidade1; valor2_at1 = densidade2; break;
        case 6: valor1_at1 = pib_per_capita1; valor2_at1 = pib_per_capita2; break;
    }

    switch (escolha2) {
        case 1: valor1_at2 = populacao1; valor2_at2 = populacao2; break;
        case 2: valor1_at2 = area1; valor2_at2 = area2; break;
        case 3: valor1_at2 = pib1; valor2_at2 = pib2; break;
        case 4: valor1_at2 = pontos_turisticos1; valor2_at2 = pontos_turisticos2; break;
        case 5: valor1_at2 = densidade1; valor2_at2 = densidade2; break;
        case 6: valor1_at2 = pib_per_capita1; valor2_at2 = pib_per_capita2; break;
    }

    // Comparações individuais
    int resultado1, resultado2;

    // Para densidade, vence menor
    resultado1 = (escolha1 == 5) ? (valor1_at1 < valor2_at1 ? 1 : 0) : (valor1_at1 > valor2_at1 ? 1 : 0);
    resultado2 = (escolha2 == 5) ? (valor1_at2 < valor2_at2 ? 1 : 0) : (valor1_at2 > valor2_at2 ? 1 : 0);

    // Soma dos resultados para determinar vencedor
    int soma1 = resultado1 + resultado2;
    int soma2 = (resultado1 == 1 ? 0 : 1) + (resultado2 == 1 ? 0 : 1);

    // Exibição dos resultados
    printf("\nComparacao entre %s e %s:\n", nome_cidade1, nome_cidade2);

    printf("\nAtributo 1: ");
    switch (escolha1) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turisticos"); break;
        case 5: printf("Densidade Populacional"); break;
        case 6: printf("PIB per Capita"); break;
    }
    printf(" - %s venceu (resultado = %d)\n", resultado1 ? nome_cidade1 : nome_cidade2, resultado1);

    printf("Valores: %s = %.2f, %s = %.2f\n", nome_cidade1, valor1_at1, nome_cidade2, valor2_at1);

    printf("\nAtributo 2: ");
    switch (escolha2) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turisticos"); break;
        case 5: printf("Densidade Populacional"); break;
        case 6: printf("PIB per Capita"); break;
    }
    printf(" - %s venceu (resultado = %d)\n", resultado2 ? nome_cidade1 : nome_cidade2, resultado2);
    printf("Valores: %s = %.2f, %s = %.2f\n", nome_cidade1, valor1_at2, nome_cidade2, valor2_at2);

    // Resultado final pela soma
    printf("\nResultado Final:\n");
    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: %s\n", (soma1 > soma2) ? nome_cidade1 : nome_cidade2);
    }

    return 0;
}
