// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h> // para strcspn

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define TOTAL_TERRITORIOS 5
#define TAM_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[30];      // Ex: "Argentina", "Egito"
    char cor[20]; // Cor do jogador que domina o território
    int tropas;     // Quantidade atual de exércitos no local
} Territorio;


// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // --- Requisito: Declaração de vetor de structs ---
    // Cria um vetor (array) com capacidade para armazenar exatamente 5 territórios
    Territorio lista_territorios[TOTAL_TERRITORIOS];

     // --- Requisito: Entrada dos dados ---
    // Laço 'for' para guiar o usuário no preenchimento de cada uma das 5 fichas
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        // Usabilidade: Mensagens claras orientando o usuário
        printf("=== CADASTRO DO %dº TERRITÓRIO ===\n", i + 1);
        
        printf("Digite o nome do territorio: ");
        // Requisito técnico: scanf para ler strings de palavra única sem bugar o buffer
        scanf("%29s", lista_territorios[i].nome);
        
        printf("Digite a cor do exercito: ");
        scanf("%9s", lista_territorios[i].cor);
        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &lista_territorios[i].tropas);
        
        printf("\n"); // Salta uma linha para organizar visualmente a entrada
    }

        printf("        TERRITÓRIOS REGISTRADOS NO JOGO      \n");
    // Percorre o vetor exibindo as informações de forma limpa e tabular
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  -> Nome:   %s\n", lista_territorios[i].nome);
        printf("  -> Cor:    %s\n", lista_territorios[i].cor);
        printf("  -> Tropas: %d\n", lista_territorios[i].tropas);
        printf("---------------------------------------------\n");
    }

    """
        
    
    return 0;

}

/* 
- Requisitos funcionais
    Veja os passos para criar e manipular uma estrutura que representa territórios em um sistema simples.

        Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
        Cadastro dos territórios: o sistema deve permitir que o usuário cadastre cinco territórios informando o nome, cor do exército e o número de tropas de cada um.
        Exibição dos dados: o sistema deve exibir as informações de todos os territórios registrados após o cadastro.

- Requisitos não funcionais
    Inclua também os seguintes critérios para ter um código funcional, eficiente e fácil de entender:

        Usabilidade: a interface de entrada deve ser simples e clara, com mensagens que orientem o usuário sobre o que digitar.
        Desempenho: o sistema deve apresentar os dados logo após o cadastro, com tempo de resposta inferior a 2 segundos.
        Documentação: o código deve conter comentários explicativos sobre a criação da struct, entrada e exibição de dados.
        Manutenibilidade: os nomes das variáveis e funções devem ser claros e representativos, facilitando a leitura e manutenção do código.
    
- Instruções detalhadas
    Siga os passos a seguir para implementar o programa de cadastro de territórios:

        Bibliotecas necessárias: inclua as bibliotecas stdio.h e string.h.
        Definição da struct: crie a struct Territorio com os campos mencionados.
        Declaração de vetor de structs: crie um vetor com capacidade para armazenar 5 estruturas do tipo Territorio.
        Entrada dos dados: utilize um laço for para preencher os dados dos 5 territórios.
        Exibição: percorra, após o cadastro, o vetor e exiba os dados de cada território com formatação clara.
*/
