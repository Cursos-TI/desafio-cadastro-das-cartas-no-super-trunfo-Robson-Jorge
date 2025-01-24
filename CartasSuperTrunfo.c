#include <stdio.h>

// Desafio Super Trunfo - Países

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char estado;
    char codigo_da_carta[10];
    char nome_da_cidade[20];
    unsigned long int populacao;
    float area;
    double PIB;
    double PIB_per_capita;
    double densidade_populacional;
    int numero_de_pontos_turisticos;
} Cidade;

// Função para calcular quociente
float obterQuociente(float num1, float num2) {
    return num1 / num2;
}

// Função para calcular super poder
float calcular_super_poder(Cidade cidade) {
    float densidade_invertida = 1.0 / (cidade.populacao / cidade.area); // Invertendo a densidade populacional
    double super_poder = cidade.populacao 
                        + cidade.area 
                        + cidade.PIB 
                        + cidade.PIB_per_capita 
                        + densidade_invertida 
                        + cidade.numero_de_pontos_turisticos;
    return super_poder;
}

// Função para comparar duas cidades e determinar a vencedora com base nos critérios do jogo
void compararCartas(Cidade *cidade1, Cidade *cidade2) {
    float super_poder_cidade1 = calcular_super_poder(*cidade1);
    float super_poder_cidade2 = calcular_super_poder(*cidade2);
    int total_pontos_carta1 = 0, total_pontos_carta2 = 0;

    printf("\n--- Resultado da Comparação de Cartas ---\n");

    if(cidade1->densidade_populacional > cidade2->densidade_populacional) {
        printf("A cidade %s tem uma densidade populacional menor que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    } else if(cidade1->densidade_populacional < cidade2->densidade_populacional) {
        printf("A cidade %s tem uma densidade populacional menor que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    }

    if (cidade1->PIB > cidade2->PIB) {
        printf("A cidade %s tem um PIB maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if (cidade1->PIB < cidade2->PIB) {
        printf("A cidade %s tem um PIB maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if (cidade1->numero_de_pontos_turisticos > cidade2->numero_de_pontos_turisticos) {
        printf("A cidade %s tem um número de pontos turísticos maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if (cidade1->numero_de_pontos_turisticos < cidade2->numero_de_pontos_turisticos) {
        printf("A cidade %s tem um número de pontos turísticos maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if (cidade1->populacao > cidade2->populacao) {
        printf("A cidade %s tem uma população maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if (cidade1->populacao < cidade2->populacao) {
        printf("A cidade %s tem uma população maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if (cidade1->area > cidade2->area) {
        printf("A cidade %s tem uma área maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if (cidade1->area < cidade2->area) {
        printf("A cidade %s tem uma área maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if(cidade1->PIB_per_capita > cidade2->PIB_per_capita) {
        printf("A cidade %s tem um PIB per capita maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if(cidade1->PIB_per_capita < cidade2->PIB_per_capita) {
        printf("A cidade %s tem um PIB per capita maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if (super_poder_cidade1 > super_poder_cidade2) {
        printf("A cidade %s tem um super poder maior que %s.\n", cidade1->nome_da_cidade, cidade2->nome_da_cidade);
        total_pontos_carta1 += 1;
    } else if (super_poder_cidade1 < super_poder_cidade2) {
        printf("A cidade %s tem um super poder maior que %s.\n", cidade2->nome_da_cidade, cidade1->nome_da_cidade);
        total_pontos_carta2 += 1;
    }

    if (total_pontos_carta1 > total_pontos_carta2) {
        printf("A cidade %s venceu com %d pontos e a cidade %s teve %d pontos.\n", cidade1->nome_da_cidade, total_pontos_carta1, cidade2->nome_da_cidade, total_pontos_carta2);
    } else if (total_pontos_carta1 < total_pontos_carta2) {
        printf("A cidade %s venceu com %d pontos e a cidade %s teve %d pontos.\n", cidade2->nome_da_cidade, total_pontos_carta2, cidade1->nome_da_cidade, total_pontos_carta1);
    }
}

// Função para cadastro de uma cidade
void cadastrarCidade(Cidade *cidade) {
    // Cadastro das cartas com entrada de dados via scanf e printf, incluindo instruções claras para o usuário.
    printf("Digite o nome da cidade, substituindo espaços por '_' e sem acentos (ex.: Sao_Paulo): \n");
    scanf("%s", cidade->nome_da_cidade);

    printf("Digite a letra do estado: ");
    scanf(" %c", &cidade->estado);

    printf("Digite o código da carta: ");
    scanf("%s", cidade->codigo_da_carta);

    printf("Digite a população: ");
    scanf("%lu", &cidade->populacao);

    printf("Digite o numero de pontos turísticos: ");
    scanf("%d", &cidade->numero_de_pontos_turisticos);

    printf("Digite a area da cidade: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB da cidade: ");
    scanf("%lf", &cidade->PIB);

    // Cálculos de PIB per Capita e Densidade Populacional
    cidade->PIB_per_capita = obterQuociente(cidade->PIB, cidade->populacao);
    cidade->densidade_populacional = obterQuociente(cidade->populacao, cidade->area);
}

// Função para exibir os dados das cartas
void exibirCidade(Cidade cidade) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: %c\n", cidade.estado);
    printf("Código da Carta: %s\n", cidade.codigo_da_carta);
    printf("Nome da Cidade: %s\n", cidade.nome_da_cidade);
    printf("População: %lu habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB: R$ %.2f\n", cidade.PIB);
    printf("PIB Per Capita: R$ %.2f\n", cidade.PIB_per_capita);
    printf("Número de Pontos Turísticos: %d\n", cidade.numero_de_pontos_turisticos);
}

int main() {
    // Criando as cartas
    Cidade cidade1, cidade2;

    // Cadastrando as cartas
    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    // Exibindo as cartas
    printf("\n--- Dados das Cidades Cadastradas ---\n");
    exibirCidade(cidade1);
    exibirCidade(cidade2);

    // Comparando as cartas
    compararCartas(&cidade1, &cidade2);

    // Mensagem de conclusão
    printf("\n--- Obrigado por jogar! ---\n");
    
    return 0;
}