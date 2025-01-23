#include <stdio.h>

// Desafio Super Trunfo - Países

// função de divisão para cálculo do PIB Per Capita e Densidade Populacional
float obterQuociente(float num1, float num2) {
    return num1 / num2;
}

int main() {
    // Declaração das Variáveis:
    int populacao, numero_de_pontos_turisticos;
    char nome_da_cidade[20], codigo_da_carta[10], estado;
    float area, Densidade_populacional;
    double PIB, PIB_per_capita;
    
    // Cadastro das cartas com entrada de dados via scanf e printf, incluindo instruções claras para o usuário.
    printf("Digite o nome da cidade, substituindo espaços por '_' e sem acentos (ex.: Sao_Paulo): \n");
    scanf("%s", &nome_da_cidade);

    printf("Digite a letra do estado: ");
    scanf(" %c", &estado);

    printf("Digite o código da carta: ");
    scanf("%s", codigo_da_carta);

    printf("Digite a população: ");
    scanf("%d", &populacao);

    printf("Digite o numero de pontos turísticos: ");
    scanf("%d", &numero_de_pontos_turisticos);

    printf("Digite a area da cidade: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: ");
    scanf("%lf", &PIB);

    // Cálculo do PIB Per Capita:
    PIB_per_capita = obterQuociente(PIB, populacao);

    // Cálculo da Densidade Populacional:
    Densidade_populacional = obterQuociente(populacao, area);
    
    // Exibição dos Dados das Cartas:
    // Mostra os dados das cartas cadastradas.

    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: B%c\n", estado);
    printf("Código da Carta: %s\n", codigo_da_carta);
    printf("Nome da Cidade: %s\n", nome_da_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("Densidade Populacional: %.2f hab/km²\n", Densidade_populacional);
    printf("PIB: R$ %.2f\n", PIB);
    printf("PIB Per Capita: R$ %.2f\n", PIB_per_capita);
    printf("Número de Pontos Turísticos: %d\n", numero_de_pontos_turisticos);

    return 0;
}