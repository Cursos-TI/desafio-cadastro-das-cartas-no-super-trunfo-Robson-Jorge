#include <stdio.h>

// Desafio Super Trunfo - Países
/* 
Resolução usando struct para cadastrar as cartas
While para que o usuário consiga escolher várias opção de comparação ou encerrar jogo
*/

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

// Função para obter entrada válida do usuário
int obterOpcaoValida() {
    int opcao;
    int resultado;

    do {
        printf("\n👉 Escolha uma opção (0 a 7): ");
        resultado = scanf("%d", &opcao);

        // Se o scanf falhar (não for número), tratamos o erro
        if (resultado != 1) {
            printf("❌ Entrada inválida! Digite apenas números.\n");
            while (getchar() != '\n'); // Limpa a entrada errada
        } else if (opcao < 0 || opcao > 7) {
            printf("⚠️ Opção fora do intervalo! Escolha entre 0 e 7.\n");
        }

    } while (resultado != 1 || (opcao < 0 || opcao > 7)); // Repete até obter um número válido

    return opcao;
}

// Função para comparar duas cidades e determinar a vencedora com base nos critérios do jogo
void compararCartas(Cidade *cidade1, Cidade *cidade2) {
    float super_poder1 = calcular_super_poder(*cidade1);
    float super_poder2 = calcular_super_poder(*cidade2);
    int opcao;
    
    do {
    printf("\n🔹 Escolha uma categoria para comparar ou 0 para encerrar o jogo:\n");
    printf("1 - População\n");
    printf("2 - PIB\n");
    printf("3 - Número de pontos turísticos\n");
    printf("4 - Densidade populacional (MENOR vence!)\n");
    printf("5 - Superpoder\n");
    printf("6 - Área\n");
    printf("7 - PIB per capita\n");
    printf("0 - Sair\n");

    opcao = obterOpcaoValida();

    switch (opcao) {
        case 1:
            if (cidade1->populacao > cidade2->populacao) {
                printf("🏆 Vitória! %s tem uma população maior que %s! (%d vs %d habitantes)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->populacao, cidade2->populacao);
            } else if (cidade1->populacao < cidade2->populacao) {
                printf("🏆 Vitória! %s tem uma população maior que %s! (%d vs %d habitantes)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->populacao, cidade1->populacao);
            } else {
                printf("🤝 Empate! Ambas as cidades têm a mesma população: %d habitantes.\n", cidade1->populacao);
            }
            break;

        case 2:
            if (cidade1->PIB > cidade2->PIB) {
                printf("💰 %s vence! Seu PIB é superior ao de %s! (%.2f vs %.2f bilhões)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->PIB, cidade2->PIB);
            } else if (cidade1->PIB < cidade2->PIB) {
                printf("💰 %s vence! Seu PIB é superior ao de %s! (%.2f vs %.2f bilhões)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->PIB, cidade1->PIB);
            } else {
                printf("🤝 Empate! Ambas as cidades têm o mesmo PIB: %.2f bilhões.\n", cidade1->PIB);
            }
            break;

        case 3:
            if (cidade1->numero_de_pontos_turisticos > cidade2->numero_de_pontos_turisticos) {
                printf("🏛️ %s é mais turística que %s! (%d vs %d pontos turísticos)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->numero_de_pontos_turisticos, cidade2->numero_de_pontos_turisticos);
            } else if (cidade1->numero_de_pontos_turisticos < cidade2->numero_de_pontos_turisticos) {
                printf("🏛️ %s é mais turística que %s! (%d vs %d pontos turísticos)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->numero_de_pontos_turisticos, cidade1->numero_de_pontos_turisticos);
            } else {
                printf("🤝 Empate! Ambas têm %d pontos turísticos.\n", cidade1->numero_de_pontos_turisticos);
            }
            break;

        case 4: 
            if (cidade1->densidade_populacional < cidade2->densidade_populacional) {
                printf("👥 Vitória! %s tem uma densidade populacional MENOR que %s! (%.2f vs %.2f hab/km²)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->densidade_populacional, cidade2->densidade_populacional);
            } else if (cidade1->densidade_populacional > cidade2->densidade_populacional) {
                printf("👥 Vitória! %s tem uma densidade populacional MENOR que %s! (%.2f vs %.2f hab/km²)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->densidade_populacional, cidade1->densidade_populacional);
            } else {
                printf("🤝 Empate! Ambas têm a mesma densidade populacional: %.2f hab/km².\n", cidade1->densidade_populacional);
            }
            break;

        case 5:
            if (super_poder1 > super_poder2) {
                printf("⚡ %s supera %s em superpoderes! (%.2f vs %.2f pontos de poder)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, super_poder1, super_poder2);
            } else if (super_poder1 < super_poder2) {
                printf("⚡ %s supera %s em superpoderes! (%.2f vs %.2f pontos de poder)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, super_poder2, super_poder1);
            } else {
                printf("🤝 Empate! Ambas as cidades têm o mesmo nível de superpoderes: %d pontos.\n", super_poder1);
            }
            break;

        case 6:
            if (cidade1->area > cidade2->area) {
                printf("🌎 %s vence! Sua área territorial é maior que a de %s! (%.2f vs %.2f km²)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->area, cidade2->area);
            } else if (cidade1->area < cidade2->area) {
                printf("🌎 %s vence! Sua área territorial é maior que a de %s! (%.2f vs %.2f km²)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->area, cidade1->area);
            } else {
                printf("🤝 Empate! Ambas têm a mesma área territorial: %.2f km².\n", cidade1->area);
            }
            break;

        case 7:
            if (cidade1->PIB_per_capita > cidade2->PIB_per_capita) {
                printf("📈 %s vence! Seu PIB per capita é maior que o de %s! (%.2f vs %.2f mil dólares)\n",
                        cidade1->nome_da_cidade, cidade2->nome_da_cidade, cidade1->PIB_per_capita, cidade2->PIB_per_capita);
            } else if (cidade1->PIB_per_capita < cidade2->PIB_per_capita) {
                printf("📈 %s vence! Seu PIB per capita é maior que o de %s! (%.2f vs %.2f mil dólares)\n",
                        cidade2->nome_da_cidade, cidade1->nome_da_cidade, cidade2->PIB_per_capita, cidade1->PIB_per_capita);
            } else {
                printf("🤝 Empate! Ambas têm o mesmo PIB per capita: %.2f mil dólares.\n", cidade1->PIB_per_capita);
            }
            break;

        case 0:
            printf("👋 Saindo do jogo...\n");
            break;

        default:
            printf("❌ Opção inválida. Escolha uma categoria correta!\n");
            break;
    }
} while (opcao != 0);

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

    // Mensagem de boas-vindas
    printf("--- Bem-vindo ao jogo Cartas Super Trunfo! ---\n");

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
