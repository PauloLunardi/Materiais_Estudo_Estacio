// ============================================================================
//         DETECTIVE QUEST - COLETA E ORGANIZAÇÃO DE PISTAS EM ARRANJOS
// ============================================================================

// ============================================================================
// PARTE 1: DEFINIÇÃO DE ESTRUTURAS, PROTÓTIPOS E MAPA DA MANSÃO (MAIN)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura 1: O Mapa da Mansão 
// Aqui nós criamos a struct para representar cada comodo física do jogo
typedef struct Sala {
    char nome[50];           // Guarda o nome do comodo (Ex: Sala de Estar)
    char pista[50];          // Guarda a pista escondida aqui (Vazia se nao houver)
    struct Sala* esquerda;   // Ponteiro para o proximo comodo do lado esquerdo
    struct Sala* direita;    // Ponteiro para o proximo comodo do lado direito
} Sala;

// Estrutura 2: O Inventário BST
// Aqui nós criamos a struct do no para a árvore binaria de busca que vai guardar as pistas
typedef struct PistaNode {
    char conteudo[50];          // Guarda o texto da pista coletada de forma isolada
    struct PistaNode* esquerda; // Ponteiro para pistas menores alfabeticamente
    struct PistaNode* direita;  // Ponteiro para pistas maiores alfabeticamente
} PistaNode;

// Variavel Global de Controle
// Criamos a raiz do nosso inventario comecando vazia (NULL)
PistaNode* inventario_pistas = NULL;

// Protótipos das Funções Modulares
void limparBuffer();
Sala* criarSala(char* nome, char* pista);
PistaNode* inserirPista(PistaNode* raiz, const char* texto_pista);
void explorarSalasComPistas(Sala* raiz_mansao);
void exibirPistas(PistaNode* raiz_bst);
void liberarMansao(Sala* raiz);
void liberarPistas(PistaNode* raiz);

// Função Principal (main)
int main() {
    printf("=================================================\n");
    printf("        ENIGMA STUDIOS - DETECTIVE QUEST v2      \n");
    printf("=================================================\n");

    // REQUISITO: O mapa da mansao e fixo e ja vem pre-definido automaticamente na main
    // Criamos a raiz do jogo com o nome e sem pista associada diretamente
    Sala* mansao = criarSala("Hall de Entrada", "Nenhuma");

    // Aqui nós conectamos os comodos do nivel 1 e colocamos as pistas neles
    mansao->esquerda = criarSala("Sala de Estar", "Pegadas de lama");
    mansao->direita = criarSala("Biblioteca", "Chave perdida");

    // Aqui nos descemos para o nivel 2 colocando as outras pistas conforme o diagrama
    mansao->esquerda->esquerda = criarSala("Gaveta perdida", "Lencol manchado");
    mansao->esquerda->direita = criarSala("Livro com pagina faltando", "Livro com pagina faltando");

    // Disparamos o motor do jogo passando o mapa inicializado
    explorarSalasComPistas(mansao);

    // --- Encerramento e Faxina de Memoria RAM ---
    printf("\n--- FIM DA INVESTIGAÇÃO ---\n");
    // Requisito final: Exibe todas as pistas coletadas em ordem alfabetica
    exibirPistas(inventario_pistas);

    // Liberamos as duas árvores do Heap para nao deixar vazamento de hardware
    liberarMansao(mansao);
    liberarPistas(inventario_pistas);
    mansao = NULL;
    inventario_pistas = NULL;

    printf("\n[Sistema] Memorias limpas com sucesso. Investigacao concluida!\n");
    return 0;
}

// Função para limpar o enter do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ============================================================================
// PARTE 2: LOGICA DA BST, COLETA AUTOMÁTICA E NAVEGAÇÃO INTERATIVA


// DOCUMENTAÇÃO: criarSala() – cria dinamicamente um cômodo com ou sem pista
Sala* criarSala(char* nome, char* pista) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro Crítico: Falha de memória na criação da sala.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista); // Salva o nome da pista escondida
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// DOCUMENTAÇÃO: inserirPista() – insere uma nova pista na árvore de pistas (BST)
PistaNode* inserirPista(PistaNode* raiz, const char* texto_pista) {
    // Se achamos um espaço vago na BST, criamos o nó da pista aqui (Caso Base)
    if (raiz == NULL) {
        PistaNode* novoNo = (PistaNode*) malloc(sizeof(PistaNode));
        if (novoNo == NULL) {
            printf("Erro Crítico: Sem memória para catalogar pista.\n");
            exit(1);
        }
        strcpy(novoNo->conteudo, texto_pista);
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    // Regra da BST: Compara o texto usando strcmp() para ver para qual lado descer
    if (strcmp(texto_pista, raiz->conteudo) < 0) {
        raiz->esquerda = inserirPista(raiz->esquerda, texto_pista); // Menor vai para a esquerda
    } else if (strcmp(texto_pista, raiz->conteudo) > 0) {
        raiz->direita = inserirPista(raiz->direita, texto_pista);   // Maior vai para a direita
    }
    
    return raiz; // Devolve a raiz da BST atualizada
}

// DOCUMENTAÇÃO: explorarSalasComPistas() – controla a navegação entre salas e coleta de pistas
void explorarSalasComPistas(Sala* raiz_mansao) {
    Sala* atual = raiz_mansao;
    char escolha;

    if (atual == NULL) {
        printf("Erro: O mapa da mansão está quebrado ou vazio.\n");
        return;
    }

    printf("\n️ O detetive entrou na mansão Enigma. Vasculhe tudo!\n");

    // Lopo de turnos iterativo: roda até o usuário escolher sair voluntariamente ('s')
    while (atual != NULL) {
        printf("\n-------------------------------------------------\n");
        printf(" Você está em: [ %s ]\n", atual->nome);

        // Mecânica de Coleta Automática: Verifica se o cômodo atual esconde alguma pista válida
        if (strcmp(atual->pista, "Nenhuma") != 0 && strcmp(atual->pista, "") != 0) {
            printf(" [COLETA] Você encontrou uma pista: \"%s\"!\n", atual->pista);
            printf("️  Pista enviada automaticamente para o inventário BST.\n");
            
            // Aqui o motor do jogo alimenta a nossa árvore global de buscas
            inventario_pistas = inserirPista(inventario_pistas, atual->pista);
            
            // Para o detetive não coletar a mesma pista infinitas vezes se ficar preso na sala:
            strcpy(atual->pista, "Nenhuma"); 
        }

        // Exibe as portas e caminhos disponíveis na sala atual
        printf("\nPortas e caminhos descobertos:\n");
        if (atual->esquerda != NULL) {
            printf(" -> Esquerda (e): Abrir porta para a [ %s ]\n", atual->esquerda->nome);
        }
        if (atual->direita != NULL) {
            printf(" -> Direita (d): Abrir porta para a [ %s ]\n", atual->direita->nome);
        }
        printf(" -> Sair (s): Encerrar a investigação atual\n");

        printf("Escolha o seu caminho (e/d/s): ");
        scanf(" %c", &escolha);
        limparBuffer();

        // Operadores condicionais estruturados (if/else) para gerenciar o rumo do detetive
        if (escolha == 's' || escolha == 'S') {
            printf("\nVocê escolheu sair e analisar as evidências coletadas.\n");
            break;
        }
        else if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda; // Ponteiro avança para o filho esquerdo
            } else {
                printf("\n Bloqueado! Não há portas ou caminhos para a esquerda aqui.\n");
            }
        }
        else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL) {
                atual = atual->direita;  // Ponteiro avança para o filho direito
            } else {
                printf("\n Bloqueado! Não há portas ou caminhos para a direita aqui.\n");
            }
        }
        else {
            printf("\n Comando incorreto! Use 'e' (esquerda), 'd' (direita) ou 's' (sair).\n");
        }
    }
}

// DOCUMENTAÇÃO: exibirPistas() – imprime a árvore de pistas em ordem alfabética (In-Order)
void exibirPistas(PistaNode* raiz_bst) {
    if (raiz_bst == NULL) {
        // Se a raiz for nula no começo, avisa que nenhuma evidência foi recolhida
        if (inventario_pistas == NULL && raiz_bst == NULL) {
            printf("️  Inventário Vazio. Nenhuma pista foi coletada nesta rodada.\n");
            return;
        }
        return;
    }
    
    // Como a nossa BST organiza por ordem alfabética, o percurso em ordem lista de A a Z
    if (raiz_bst == inventario_pistas) {
        printf("\n=================================================\n");
        printf("   INVENTÁRIO DE EVIDÊNCIAS (Ordem Alfabética)   \n");
        printf("=================================================\n");
    }

    exibirPistas(raiz_bst->esquerda);   // 1º: Visita e processa tudo na esquerda (menores)
    printf("  • Evidência: %s\n", raiz_bst->conteudo); // 2º: Imprime o nó atual (Pai)
    exibirPistas(raiz_bst->direita);    // 3º: Visita e processa tudo na direita (maiores)

    if (raiz_bst == inventario_pistas) {
        printf("=================================================\n");
    }
}

// Funções Utilitárias para apagar as estruturas de baixo para cima (Pós-Ordem)
void liberarMansao(Sala* raiz) {
    if (raiz != NULL) {
        liberarMansao(raiz->esquerda);
        liberarMansao(raiz->direita);
        free(raiz);
    }
}

void liberarPistas(PistaNode* raiz) {
    if (raiz != NULL) {
        liberarPistas(raiz->esquerda);
        liberarPistas(raiz->direita);
        free(raiz);
    }
}
