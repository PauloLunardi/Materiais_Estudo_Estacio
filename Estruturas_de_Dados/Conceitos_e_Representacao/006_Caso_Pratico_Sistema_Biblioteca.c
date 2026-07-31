//======================================================================
// Exemplo Pratico: Sistema de Biblioteca - Parte 1
//
// Objetivo desta etapa
// Implementar o cadastro e alistagem de livros usando array estático.
// Foco em structs, entrada/saida de dados e organização basica.
//
//======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn

// -- Constantes Globais --
#define MAX_LIVROS 60
#define TAM_STRING 100

// -- Definição da estrutura(Struct) --
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// -- Função para limpar o buffer de entrada--
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -- Função Principal(main) --
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

  // -- Laço Principal do Menu --
    do {
        // Exibe o menu de opções
        printf("=================================================\n");
        printf("---------------Biblioteca - Parte 1--------------\n");
        printf("1 - Cadastrar novo Livro   ----------------------\n");
        printf("2 - Listar Todos os Livros ----------------------\n");
        printf("0 - Sair                   ----------------------\n");
        printf("-------------------------------------------------\n");
        printf("Escolha uma Opção   -----------------------------\n");
    
        // Lê a opção do usuario.
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf
    
        // -- Processamento da Opção --
        switch (opcao) {
            case 1: // Cadastro de Livro
            printf("-- Cadastro de Novo Livro --\n\n");
    
                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do Livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
        
                    printf("Digite o Autor do Livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
        
                    printf("Digite a Editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
        
        			biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
        			biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
        			biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';
        
                    printf("Digite a ediçao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();
        
                    totalLivros++;
        
                    printf("\nLivro Cadastrado com Sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Não pe possivel cadastrar mais livros.\n");
                }
    
            printf("\nPressicone Enter para continuar...");
            getchar(); // Pausa para o usuário ler a msg antes de voltar ao menu
            break;
    
            case 2: // Listagem de Livros
            printf("-- Lista de Livros Cadastrados --\n\n");
    
                if(totalLivros == 0) {
                  printf("Nenhum livro cadastrado ainda.\n");
        
                } else {
                  for (int i = 0; i < totalLivros; i++) {
                    printf("-----------------------------------\n");
                    printf("Livro %d\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n", biblioteca[i].edicao);
                  }
                   printf("-----------------------------------------\n");
                }
        
        				// A pausa é crucial apra que o usuário veja a lista antes do proximo loop limpar a tela.
        				printf("\nPressione Enter para continuar...");
        				getchar();
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
    
    return 0;
}
