//======================================================================
// Exemplo Pratico: Sistema de Biblioteca - Parte 2
//
// Objetivo desta etapa:
// Modularizar o código com funções especializadas, aplicando boas práticas.
//  - Passagem por valor (para exibição) e por referência (para modificação).
//  - Funções para cada funcionalidade principal do sistema.
//  - A função main() se torna um "orquestrado", chamando as outras.
//======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn

// -- Constantes Globais --
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

// -- Definição da estrutura(Struct) --
// Struct Livro agora tem um campo 'disponivel' para controlar o status.
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para não.
};

// -- Definição da estrutura para Emprestimos(Struct) --
struct Emprestimo {
  int indiceLivro; // Para saber qualo livro do array 'biblioteca' foi emprestado.
  char nomeUsuario[TAM_STRING];
};

// --- Protótipos das funções ---
// Declara as funções aqui permite que a 'main' as chame antes de suas definições.
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);



// -- Função Principal(main) --
int main() {
    // Mudança de arrays estáticos, agora usamos ponteiros.
    struct Livro *biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));
  
    // VERIFICAÇÂO:
    if (biblioteca == NULL || emprestimos == NULL) {
      printf("Erro: Falha ao alocar memória.\n");
      return 1; // Retorna 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

  // -- Laço Principal do Menu --
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf
    
        // -- Processamento da Opção --
        switch (opcao) {
            case 1: // Cadastro de Livro
              // Passamos o endereço de 'totalLivros' (&) para que a função possa MODIFICAR seu
              cadastrarLivro(biblioteca, &totalLivros);
              //printf("-- Cadastro de Novo Livro --\n\n");
              break;     
    
            case 2: // Listagem de Livros
              listarLivros(biblioteca, totalLivros);
              break;
              // printf("-- Lista de Livros Cadastrados --\n\n");
   
            case 3: // Realizar Emprestimo
              realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
              break;
              
            case 4: // Listar Emprestimos
              listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
              break;
              
            case 0: // Sair
    				printf("\nSaindo do Sistema...\n");
    				break;
    
    		default: // Opção invalida
    			printf("\nOpção Invalida! Tente Novamente.\n");
    			printf("\nOPressione Enter para continuar.\n");
    			getchar();
    			break;
    			
        }
    } while (opcao != 0);

    // Parte adicionada - Liberação da Memória
    free(biblioteca);
    free(emprestimos);
    
    return 0;
}

// Implementação das Funções

// -- Função para limpar o buffer de entrada--
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o menu de opções
void exibirMenu() {
        printf("=================================================\n");
        printf("---------------Biblioteca - Parte 1--------------\n");
        printf("1 - Cadastrar novo Livro   ----------------------\n");
        printf("2 - Listar Todos os Livros ----------------------\n");
        printf("3 - Realizar um Emprestimo ----------------------\n");
        printf("4 - Listar Empréstimo      ----------------------\n");
        printf("0 - Sair                   ----------------------\n");
        printf("-------------------------------------------------\n");
        printf("Escolha uma Opção   -----------------------------\n");
}

void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
  printf("---Cadastro de Novo Livro ---\n\n");

  if (*totalLivros < MAX_LIVROS) {
    int indice = *totalLivros; // Usa o valor apontado pelo ponteiro para o indice
   
    printf("Digite o nome do Livro: ");
    fgets(biblioteca[indice].nome, TAM_STRING, stdin);
        
    printf("Digite o Autor do Livro: ");
    fgets(biblioteca[indice].autor, TAM_STRING, stdin);
        
    printf("Digite a Editora: ");
    fgets(biblioteca[indice].editora, TAM_STRING, stdin);
        
    biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
    biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
    biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';
        
    printf("Digite a ediçao: ");
    scanf("%d", &biblioteca[indice].edicao);
    limparBufferEntrada();

    biblioteca[indice].disponivel = 1;
    
     (*totalLivros)++; // Incrementa o valor original na main        
     printf("\nLivro Cadastrado com Sucesso!\n");
  } else {
     printf("Biblioteca cheia! Não pe possivel cadastrar mais livros.\n");
  }
    
     printf("\nPressicone Enter para continuar...");
     getchar(); // Pausa para o usuário ler a msg antes de voltar ao menu
}

/**
* @brief Lista todos os livros cadastrados.
* @param biblioteca .O array (ponteiro constante, apenas para leitura).
* @param totalLivros  .O número de livros (passagem de valor)
*/
void listarLivros(const struct Livro *biblioteca, int totalLivros) {
  printf("--- Lista de Livros Cadastrados ---\n\n");
  if (totalLivros == 0) {
    printf("Nenhum Livro Cadastrado Ainda.\n");
  } else {
    for (int i = 0; i < totalLivros; i++) {
      printf("-----------------------------------\n");
      printf("Livro %d\n", i + 1);
      printf("Nome: %s\n", biblioteca[i].nome);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("Editora: %s\n", biblioteca[i].editora);
      printf("Edição: %d\n", biblioteca[i].edicao);
      printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
    } // Fecha o laço for
    printf("-----------------------------------------\n");
  }     
      printf("\nPressione Enter para continuar...");
      getchar();
}

/**
* @brief realiza o emprestimos de um livro.
* @param biblioteca Array de livros (modificável, para alterar o status).
* @param totalLivros Total de livros cadastrados.
* @param emprestimos Array de empréstimos (modificavel).
* @param totalEmprestimos Ponteiro para o contador de emprestimos (para ser atualizado).
*/
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
  printf("--- Realizar Emprestimo ---\n\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
      printf("Limite de Emprestimos Atingidos!\n");
    } else {
      printf("---*** Livros Disponiveis: ***---\n");
      int disponiveis = 0;
      for ( int i = 0; i < totalLivros; i++) {
        if (biblioteca[i].disponivel) {
          printf("%d - %s\n", i + 1, biblioteca[i].nome);
          disponiveis++;
        }
      } // CORREÇÃO 1: Fechamento correto do laço 'for' aqui, mantendo 'disponiveis' visível abaixo

      if(disponiveis == 0) {
        printf("Nenhum livro disponivel para emprestimo.\n");
      } else {
        printf("\nDigite o numero do livro que deseja emprestar: ");
        int numLivro;
        scanf("%d", &numLivro);
        limparBufferEntrada();

        int indice = numLivro - 1; // Converte para o índice do array(0 a N-1)

        // Validacao da escolha do usuario.
        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
            printf("Digite o nome do usuario que esta pegando o livro: ");
            fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
            emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';

            // Salva o índice do livro emprestado e muda seu status
            emprestimos[*totalEmprestimos].indiceLivro = indice;
            biblioteca[indice].disponivel = 0; // Modifica o array original

            (*totalEmprestimos)++; // Incrementa o contador global de empréstimos
            printf("\nEmprestimo realizado com sucesso!\n");
        } else {
           printf("\nNumero de livro invalido ou Livro Indisponivel. \n");
        }
      }
    } // CORREÇÃO 2: Agora esta chave fecha o ELSE PRINCIPAL perfeitamente
    printf("\nPressione Enter para continuar...");
    getchar();
} // FECHA A FUNÇÃO REALIZAREMPRESTIMO

/**
* @brief lista todos emprestimos realizados
* @param biblioteca Array de livros (leitura).
* @param emprestimos Array de empréstimos (leitura).
* @param totalEmprestimos Total de emprestimos (valor).
*/
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos) {
  printf("---*** Lista de Empréstimos: ***---\n");
  if(totalEmprestimos == 0) {
    printf("Nenhum Empréstimo Realizado.\n"); 
  } else {
    for (int i = 0; i < totalEmprestimos; i++) {
        int idx = emprestimos[i].indiceLivro; 
        printf("------------------------------------------------\n");
        printf("Empréstimo %d\n", i + 1);
        printf("Livro: %s\n", biblioteca[idx].nome);
        printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
    }
    printf("------------------------------------------------\n");
  }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void liberarMemoria(struct Livro *biblioteca, struct Emprestimo * emprestimos) {
  free(biblioteca);
  free(emprestimos);
  printf("\nMemoria Liberada com Sucesso!...\n");
} // CORREÇÃO 3: Removida a chave que estava sobrando depois daqui
