// ============================================================================
//         DETECTIVE QUEST - VERSÃO COMPLETA E MELHORADA (NÍVEL MESTRE)
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 50
#define HASH_MAX 10
#define PILHA_NAV_MAX 20

// --- Estrutura 1: O Mapa da Mansão (Árvore Binária) ---
typedef struct Sala {
    char nome[TAM_STRING];      
    char pista[TAM_STRING];     
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// --- Estrutura 2: O Inventário de Evidências (Árvore BST) ---
typedef struct PistaNode {
    char conteudo[TAM_STRING];     
    struct PistaNode* esquerda;
    struct PistaNode* direita;
} PistaNode;

// --- Estrutura 3: Banco de Suspeitos (Tabela Hash) ---
typedef struct {
    char pista_chave[TAM_STRING]; 
    char suspeito_valor[TAM_STRING]; 
    int estado;                   
} SlotHash;

// --- Estrutura 4: Pilha Auxiliar para poder VOLTAR de sala ---
typedef struct {
    Sala* historico[PILHA_NAV_MAX];
    int topo;
} PilhaNavegacao;

// --- Variáveis Globais de Controle ---
PistaNode* inventario_bst = NULL;    
SlotHash tabela_hash[HASH_MAX];      
int total_provas_contra_acusado = 0; 
PilhaNavegacao pilha_nav; // Pilha que vai salvar o caminho para podermos voltar

// --- Protótipos das Funções ---
void limparBuffer();
int calcular_hash(const char* chave);
void inicializarTabelaHash();
Sala* criarSala(char* nome, char* pista);
PistaNode* inserirPista(PistaNode* raiz, const char* texto_pista);
void inserirNaHash(const char* pista, const char* suspeito);
const char* encontrarSuspeito(const char* pista);
void explorarSalas(Sala* raiz_mansao);
void verificarSuspeitoFinal(PistaNode* raiz_bst, const char* acusado);
void exibirPistasInventario(PistaNode* raiz_bst);
void listarSuspeitosCatalogo();
void liberarMansao(Sala* raiz);
void liberarPistas(PistaNode* raiz);

// Funções extras da Pilha de Navegação
void pushNav(Sala* s) { if (pilha_nav.topo < PILHA_NAV_MAX - 1) pilha_nav.historico[++pilha_nav.topo] = s; }
Sala* popNav() { if (pilha_nav.topo >= 0) return pilha_nav.historico[pilha_nav.topo--]; return NULL; }

int main() {
    inicializarTabelaHash();
    pilha_nav.topo = -1; // Inicializa a pilha de navegação como vazia

    printf("=================================================\n");
    printf("        DETECTIVE QUEST - CAPÍTULO FINAL (MESTRE) \n");
    printf("=================================================\n");

    // Cadastrando pistas e suspeitos na Hash
    inserirNaHash("Pegadas de lama", "Mordomo Charles");
    inserirNaHash("Lencol manchado", "Mordomo Charles");
    inserirNaHash("Chave perdida", "Cozinheira Ana");
    inserirNaHash("Livro com pagina faltando", "Governanta Julia");

    // mapa da mansão
    Sala* mansao = criarSala("Hall de Entrada", "Nenhuma");
    mansao->esquerda = criarSala("Sala de Estar", "Pegadas de lama");
    mansao->direita = criarSala("Biblioteca", "Chave perdida");
    mansao->esquerda->esquerda = criarSala("Quarto de Hospedes", "Lencol manchado");
    mansao->esquerda->direita = criarSala("Escritorio Velho", "Livro com pagina faltando");

    // Roda o jogo
    explorarSalas(mansao);

    printf("\n=================================================\n");
    printf("             TRIBUNAL DE JUSTIÇA                 \n");
    printf("=================================================\n");
    
    exibirPistasInventario(inventario_bst);

    if (inventario_bst == NULL) {
        printf("\n️ Você foi ao tribunal sem nenhuma prova! O caso foi arquivado.\n");
    } else {
        // Exibe os suspeitos cadastrados para o jogador saber quem acusar
        listarSuspeitosCatalogo();

        char suspeito_acusado[TAM_STRING];
        printf("\nDetetive, quem e o grande culpado pelo crime?\n");
        printf("Digite o nome exato do suspeito: ");
        fgets(suspeito_acusado, TAM_STRING, stdin);
        suspeito_acusado[strcspn(suspeito_acusado, "\n")] = '\0'; 

        total_provas_contra_acusado = 0;
        verificarSuspeitoFinal(inventario_bst, suspeito_acusado);

        printf("\n=================================================\n");
        printf("               VEREDITO DO JUIZ                  \n");
        printf("=================================================\n");
        printf(">> Total de provas válidas encontradas contra o réu: %d\n", total_provas_contra_acusado);

        if (total_provas_contra_acusado >= 2) {
            printf("\n PARABÉNS! O réu \"%s\" foi condenado com provas robustas! \n", suspeito_acusado);
        } else {
            printf("\n CASO PERDIDO! Provas insuficientes contra \"%s\". O culpado continua solto!\n", suspeito_acusado);
        }
        printf("=================================================\n");
    }

    liberarMansao(mansao);
    liberarPistas(inventario_bst);
    return 0;
}

int calcular_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) soma += chave[i];
    return soma % HASH_MAX;
}

Sala* criarSala(char* nome, char* pista) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

PistaNode* inserirPista(PistaNode* raiz, const char* texto_pista) {
    if (raiz == NULL) {
        PistaNode* novo = (PistaNode*) malloc(sizeof(PistaNode));
        strcpy(novo->conteudo, texto_pista);
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if (strcmp(texto_pista, raiz->conteudo) < 0) raiz->esquerda = inserirPista(raiz->esquerda, texto_pista);
    else if (strcmp(texto_pista, raiz->conteudo) > 0) raiz->direita = inserirPista(raiz->direita, texto_pista);
    return raiz;
}

void inserirNaHash(const char* pista, const char* suspeito) {
    int indice = calcular_hash(pista);
    for (int i = 0; i < HASH_MAX; i++) {
        int pos = (indice + i) % HASH_MAX;
        if (tabela_hash[pos].estado == 0) {
            strcpy(tabela_hash[pos].pista_chave, pista);
            strcpy(tabela_hash[pos].suspeito_valor, suspeito);
            tabela_hash[pos].estado = 1;
            return;
        }
    }
}

const char* encontrarSuspeito(const char* pista) {
    int indice = calcular_hash(pista);
    for (int i = 0; i < HASH_MAX; i++) {
        int pos = (indice + i) % HASH_MAX;
        if (tabela_hash[pos].estado == 0) return "Desconhecido";
        if (tabela_hash[pos].estado == 1 && strcmp(tabela_hash[pos].pista_chave, pista) == 0) return tabela_hash[pos].suspeito_valor;
    }
    return "Desconhecido";
}

// lógica de Pilha (push e pop) para poder VOLTAR de sala
void explorarSalas(Sala* raiz_mansao) {
    Sala* atual = raiz_mansao;
    char escolha;

    while (atual != NULL) {
        printf("\n-------------------------------------------------\n");
        printf(" Você está em: [ %s ]\n", atual->nome);

        if (strcmp(atual->pista, "Nenhuma") != 0 && strcmp(atual->pista, "") != 0) {
            printf("[EVIDÊNCIA] Pista localizada: \"%s\"!\n", atual->pista);
            inventario_bst = inserirPista(inventario_bst, atual->pista);
            strcpy(atual->pista, "Nenhuma");
        }

        printf("\nRotas disponíveis:\n");
        if (atual->esquerda != NULL) printf(" -> Esquerda (e): [ %s ]\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf(" -> Direita (d): [ %s ]\n", atual->direita->nome);
        if (pilha_nav.topo >= 0) printf(" -> Voltar (v): Retornar para a sala anterior\n");
        printf(" -> Sair (s): Ir para o Tribunal\n");

        printf("Digite seu comando (e/d/v/s): ");
        scanf(" %c", &escolha);
        limparBuffer();

        if (escolha == 's' || escolha == 'S') break;
        else if (escolha == 'v' || escolha == 'V') {
            Sala* anterior = popNav();
            if (anterior != NULL) atual = anterior;
            else printf("\n Você já está no Hall de Entrada, não há como voltar atrás!\n");
        }
        else if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL) {
                pushNav(atual); // Salva a sala atual na pilha antes de descer
                atual = atual->esquerda;
            } else printf("\n Caminho bloqueado à esquerda!\n");
        }
        else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL) {
                pushNav(atual); // Salva a sala atual na pilha antes de descer
                atual = atual->direita;
            } else printf("\n Caminho bloqueado à direita!\n");
        }
    }
}

void verificarSuspeitoFinal(PistaNode* raiz_bst, const char* acusado) {
    if (raiz_bst == NULL) return;
    verificarSuspeitoFinal(raiz_bst->esquerda, acusado);
    const char* suspeito_vinculado = encontrarSuspeito(raiz_bst->conteudo);
    if (strcmp(suspeito_vinculado, acusado) == 0) {
        total_provas_contra_acusado++;
        printf("  [PROVA] A pista \"%s\" aponta para %s!\n", raiz_bst->conteudo, acusado);
    } else {
        printf("  [INFO] A pista \"%s\" aponta para %s.\n", raiz_bst->conteudo, suspeito_vinculado);
    }
    verificarSuspeitoFinal(raiz_bst->direita, acusado);
}

void exibirPistasInventario(PistaNode* raiz_bst) {
    if (raiz_bst == NULL) return;
    exibirPistasInventario(raiz_bst->esquerda);
    printf(" Evidência Coletada: %s\n", raiz_bst->conteudo);
    exibirPistasInventario(raiz_bst->direita);
}

//  limpa a tabela de suspeitos e define os estados iniciais como vazios (0)
void inicializarTabelaHash() {
    for (int i = 0; i < HASH_MAX; i++) {
        tabela_hash[i].estado = 0; // 0 significa Vazio/Disponível
        strcpy(tabela_hash[i].pista_chave, "");
        strcpy(tabela_hash[i].suspeito_valor, "");
    }
}

void listarSuspeitosCatalogo() {
    printf("\n SUSPEITOS REGISTRADOS NO CASO:\n");
    printf("  - Mordomo Charles\n");
    printf("  - Cozinheira Ana\n");
    printf("  - Governanta Julia\n");
}

void limparBuffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF);
}

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
