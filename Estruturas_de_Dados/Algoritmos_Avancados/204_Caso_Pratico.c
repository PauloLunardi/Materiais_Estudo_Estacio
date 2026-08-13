// ============================================================================
//         ÁRVORES TRIE (ÁRVORE DE PREFIXOS) - CASO PRÁTICO COMPLETO
// ============================================================================
// OBJETIVOS CUMPRIDOS:
// - Definição da struct do nó da Trie com array de 26 ponteiros e booleano.
// - Função criarNo() com alocação dinâmica e inicialização com NULL.
// - Função inserir() convertendo caracteres em índices (0 a 25) via subtração.
// - Função buscar() fazendo a varredura e checando a flag ehFimDePalavra.
// - Função normalizar() limpando maiúsculas e caracteres inválidos.
// - Função listarPalavras() fazendo o percurso alfabético lexicográfico.
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definimos o tamanho do alfabeto como 26 (letras minúsculas de 'a' a 'z')
#define TAMANHO_ALFABETO 26

// --- Estrutura do Nó da Trie ---
// Aqui nós criamos a nossa struct para representar cada nó da árvore de prefixos
struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO]; // Array contendo 26 ponteiros para os próximos nós
    bool ehFimDePalavra;                     // Flag booleana que avisa se uma palavra termina aqui
};

// --- Protótipos das Funções ---
// Avisando o compilador quais funções nós criamos mais abaixo
struct NoTrie* criarNo();
void inserir(struct NoTrie* raiz, const char* palavra);
bool buscar(struct NoTrie* raiz, const char* palavra);
void listarPalavras(struct NoTrie* no, char* buffer, int nivel);
void normalizar(const char* entrada, char* saida);
void liberarTrie(struct NoTrie* raiz);

// --- Função Principal (main) ---
int main() {
    // Ao iniciarmos a Trie, precisaremos de um nó raiz vazio para dar o ponto de partida
    struct NoTrie* raiz = criarNo();
    char normalizada[100]; // Vetor para guardar o texto após passar pela limpeza
 
    // Aqui o programa limpa os textos e insere as pistas na árvore dinamicamente
    normalizar("Pegadas de Lama", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Chave perdida", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Livro com página faltando", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Lençol manchado", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Gaveta perdida", normalizada);
    inserir(raiz, normalizada);

    // Vetor buffer auxiliar para reconstruir as palavras na hora de exibir
    char buffer[100]; 
    
    printf("--- LISTAGEM DE PALAVRAS ORDENADAS NA TRIE ---\n");
    // Chamamos o percurso recursivo começando do nível zero
    listarPalavras(raiz, buffer, 0);
    printf("---------------------------------------------\n");

    // Testes de Busca de Palavras Completas
    printf("\n🔍 [Busca] 'chaveperdida': %s", buscar(raiz, "chaveperdida") ? "Encontrada" : "Não encontrada");
    printf("\n🔍 [Busca] 'chave': %s", buscar(raiz, "chave") ? "Encontrada" : "Não encontrada (Apenas prefixo)");
    printf("\n🔍 [Busca] 'oculos': %s\n", buscar(raiz, "oculos") ? "Encontrada" : "Não encontrada");

    // Limpeza obrigatória da memória antes de fechar o programa
    liberarTrie(raiz);
    raiz = NULL;

    return 0;
}

// ============================================================================
//                       IMPLEMENTAÇÃO DAS FUNÇÕES
// ============================================================================

// Função que faz a alocação dinâmica e aterra todos os 26 filhos com NULL
struct NoTrie* criarNo() { 
    // Aloca a memória para o novo nó da árvore
    struct NoTrie* novoNo = (struct NoTrie*) malloc(sizeof(struct NoTrie));
    
    if (novoNo == NULL) {
        printf("Erro Crítico: Falha ao alocar memória para o nó Trie.\n");
        exit(1);
    }

    novoNo->ehFimDePalavra = false; // Todo nó novo nasce sem ser um fim de palavra
    
    // Esse laço limpa o array de ponteiros para garantir que nasçam vazios, economizando espaço
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        novoNo->filhos[i] = NULL;
    }

    return novoNo; // Retorna a caixinha pronta para ser conectada
}

// Função de Inserção: percorre caractere por caractere criando os nós que faltam
void inserir(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    // O laço caminha pela string até achar o caractere nulo terminal '\0'
    for (int i = 0; palavra[i] != '\0'; i++) {
        // O uso de palavra[i] - 'a' transforma letras em índices numéricos de 0 a 25
        int indice = palavra[i] - 'a';

        // Se o caminho para essa letra ainda não existir, nós criamos o nó intermediário sob demanda
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        // O ponteiro avança e entra na caixinha da letra correspondente
        atual = atual->filhos[indice];
    }
    // Ao final da palavra, ativamos a marcação booleana para sabermos que a palavra terminou ali
    atual->ehFimDePalavra = true;
}

// Função de Busca: percorre os nós conforme a sequência das letras digitadas
bool buscar(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        // Se em algum momento o caminho não existir, significa que a palavra não está na árvore
        if (atual->filhos[indice] == NULL)
            return false;

        atual = atual->filhos[indice];
    }
    // Só retorna verdadeiro se a sequência inteira existir E estiver marcada como palavra completa
    return atual != NULL && atual->ehFimDePalavra;
}

// Função Recursiva que percorre a árvore em pré-ordem alfabética para ordenar e listar
void listarPalavras(struct NoTrie* no, char* buffer, int nivel) {
    // Se o nó atual for um fim de palavra, fechamos a string com '\0' e damos o printf
    if (no->ehFimDePalavra) {
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }

    // Passamos por todas as 26 opções do alfabeto na ordem certa (de 'a' até 'z')
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            // Converte o índice numérico de volta para o caractere original da letra
            buffer[nivel] = 'a' + i;
            // Chama a si mesma incrementando o nível para processar as letras de baixo
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

// Função que higieniza e normaliza o texto para não estourar os limites do array de 26 posições
void normalizar(const char* entrada, char* saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        
        // Se a letra for maiúscula, adicionamos +32 na tabela ASCII para virar minúscula
        if (c >= 'A' && c <= 'Z') c += 32; 
        
        // Ignora espaços e acentos, salvando apenas o que for estritamente de 'a' até 'z'
        if (c >= 'a' && c <= 'z') {
            saida[j++] = c; 
        }
    }
    saida[j] = '\0'; // Fecha a nova string normalizada com segurança
}

// Função de Limpeza Recursiva para desalocar fisicamente todos os nós da memória Heap
void liberarTrie(struct NoTrie* raiz) {
    if (raiz == NULL) return;

    // Passa varrendo todos os 26 caminhos possíveis recursivamente
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->filhos[i] != NULL) {
            liberarTrie(raiz->filhos[i]); // Deleta primeiro o que estiver embaixo
        }
    }
    free(raiz); // Por fim, apaga a si mesmo liberando o bloco de memória
}
