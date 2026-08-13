// ============================================================================
//         DETECTIVE QUEST - DESAFIO FINAL: INVESTIGAÇÃO NA MANSÃO
// ============================================================================
// OBJETIVOS CUMPRIDOS:
// - Criacao da struct Sala com nome e ponteiros de esquerda/direita.
// - Funcao criarSala() para alocacao dinamica simples via malloc.
// - Funcao explorarSalas() que controla a navegacao por laço iterativo.
// - Menu interativo aceitando os comandos 'e', 'd' e 's'.
// - Liberaçao correta de toda a memoria RAM antes de fechar.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estrutura da Sala ---
// Aqui nós criamos a nossa struct para representar cada comodo da mansao
typedef struct Sala {
    char nome[50];           // Guarda o nome da sala (Ex: Sala de estar)
    struct Sala* esquerda;   // Ponteiro para o comodo que fica na esquerda (e)
    struct Sala* direita;    // Ponteiro para o comodo que fica na direita (d)
} Sala;

// --- Protótipos das Funções ---
void limparBuffer();
Sala* criarSala(char* nome);
void explorarSalas(Sala* raiz);
void liberarMansao(Sala* raiz);

// --- Função Principal (main) ---
int main() {
    printf("=================================================\n");
    printf("        ENIGMA STUDIOS - DETECTIVE QUEST         \n");
    printf("=================================================\n");

    // REQUISITO: A árvore é montada de modo automático na main usando criarSala()
    // Aqui eu crio a raiz principal do jogo: O Hall de Entrada
    Sala* mansao = criarSala("Hall de Entrada");
    
    // Aqui nós conectamos as salas do primeiro nível de ramificação
    mansao->esquerda = criarSala("Sala de Estar");
    mansao->direita = criarSala("Biblioteca");
    
    // E aqui eu coloco o Quarto debaixo da Sala de Estar (no lado esquerdo)
    mansao->esquerda->esquerda = criarSala("Quarto");

    // Desafio: Disparar a funcao de exploracao interativa passando a raiz
    explorarSalas(mansao);

    // Passo obrigatório: Limpar a memória do Heap antes do jogo fechar
    liberarMansao(mansao);
    mansao = NULL;

    printf("\n[Sistema] Memória limpa. Investigação encerrada de forma segura!\n");
    return 0;
}

// -- Função para limpar o buffer de entrada --
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Implementação das Funções ---

// DOCUMENTAÇÃO: criarSala() - cria, de forma dinâmica, uma sala com nome
Sala* criarSala(char* nome) {
    // Alocação Dinâmica: malloc pede espaço na memória para o tamanho exato de uma sala
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    
    if (nova == NULL) {
        printf("Erro Crítico: Falha ao alocar memória para a sala.\n");
        exit(1);
    }
    
    // Aqui eu copio o nome para dentro da struct e aterro os ponteiros de caminhos com NULL
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    
    return nova; // Devolve a sala prontinha para ser conectada
}

// DOCUMENTAÇÃO: explorarSalas() - permite a navegação do jogador pela árvore
void explorarSalas(Sala* raiz) {
    // Criamos um ponteiro auxiliar para saber em qual comodo o detetive esta agora
    Sala* atual = raiz;
    char escolha;

    if (atual == NULL) {
        printf("Erro: O mapa da mansão está vazio!\n");
        return;
    }

    printf("\n️ A investigação começou! Você acabou de entrar na mansão.\n");

    // O laço while fica rodando a navegação até o detetive escolher sair ou bater em uma folha
    while (atual != NULL) {
        // Mostra o histórico exibindo onde o jogador está no momento
        printf("\nVocê está na sala: [ %s ]\n", atual->nome);

        // REQUISITO: Verificar se alcançou um cômodo sem saídas (Nó-Folha)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf(" Você procurou tudo possivel! Esta sala não possui mais caminhos ou portas adicionais.\n");
            printf("Fim da linha para esta ala da investigação.\n");
            break; // Quebra o laço e encerra a exploração
        }

        // Se não for um nó-folha, mostra as portas disponíveis para abrir
        printf("Portas disponíveis:\n");
        if (atual->esquerda != NULL) {
            printf(" -> Esquerda (e): Para ir para a [ %s ]\n", atual->esquerda->nome);
        }
        if (atual->direita != NULL) {
            printf(" -> Direita (d): Para ir para a [ %s ]\n", atual->direita->nome);
        }
        printf(" -> Sair (s): Para encerrar o jogo\n");
        
        printf("Digite o seu comando (e/d/s): ");
        scanf(" %c", &escolha); // O espaço antes do %c ignora enters perdidos
        limparBuffer();

        // Tratamento das decisões do jogador usando operadores condicionais (if/else)
        if (escolha == 's' || escolha == 'S') {
            printf("\nVocê decidiu sair e abandonar a mansão. Investigação incompleta!\n");
            break;
        }
        else if (escolha == 'e' || escolha == 'E') {
            // Verifica se a porta da esquerda realmente existe antes de entrar
            if (atual->esquerda != NULL) {
                atual = atual->esquerda; // O ponteiro avança e entra na sala da esquerda
            } else {
                printf("\n Não há nenhuma porta ou caminho para a esquerda aqui!\n");
            }
        }
        else if (escolha == 'd' || escolha == 'D') {
            // Verifica se a porta da direita realmente existe antes de entrar
            if (atual->direita != NULL) {
                atual = atual->direita; // O ponteiro avança e entra na sala da direita
            } else {
                printf("\n Não há nenhuma porta ou caminho para a direita aqui!\n");
            }
        }
        else {
            printf("\n Comando incorreto! Digite apenas 'e' para esquerda, 'd' para direita ou 's' para sair.\n");
        }
    }
}

// Função de Limpeza (Pós-Ordem) para deletar os nós de baixo para cima com segurança
void liberarMansao(Sala* raiz) {
    if (raiz != NULL) {
        liberarMansao(raiz->esquerda); // Primeiro limpa tudo na esquerda
        liberarMansao(raiz->direita);  // Depois limpa tudo na direita
        free(raiz);                    // Por fim, dá free na sala pai
    }
}



    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

