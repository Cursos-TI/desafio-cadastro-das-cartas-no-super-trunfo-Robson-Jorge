#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int populacao, numero_de_pontos_turisticos;
    char nome[20], codigo_da_carta[10];
    float area, PIB;
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("Digite a populacao: ");
    scanf("%d", &populacao);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &numero_de_pontos_turisticos);

    printf("Digite a area da cidade: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB);
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    printf("\n--- Dados da Cidade ---\n");
    printf("População: %d\n", populacao);
    printf("Número de Pontos Turísticos: %d\n", numero_de_pontos_turisticos);
    printf("Área: %.2f km²\n", area);
    printf("PIB: R$ %.2f\n", PIB);

    return 0;
}
