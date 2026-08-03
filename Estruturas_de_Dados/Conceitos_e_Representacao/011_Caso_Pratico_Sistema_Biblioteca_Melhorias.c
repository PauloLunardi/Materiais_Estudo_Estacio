//======================================================================
// Exemplo Pratico: Sistema de Biblioteca - Parte 2
//
// Objetivo desta etapa:
// Adicionar as funcionalidade de empréstimo e introduzir alocação dinâmica.
//  - Os arrays de livros e empréstimos são alocados com malloc/calloc.
//  - Nova struct apra Empréstimos.
//  - Liberação de memória com free.


//======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn

// -- Constantes Globais --
#define MAX_LIVROS 60
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 // Definimos uma capacidade de empéstimos

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
}

// -- Função para limpar o buffer de entrada--
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -- Função Principal(main) --
int main() {
    // Mudança de arrays estáticos, agora usamos ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;


    // Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    // Vantagem: inicializa toda a memória com zeros. Issi significa que 'disponivcel' ja começa
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro

    // Usamos malloc para o array de emprestimos. malloc(tamanho total em bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

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
        // Exibe o menu de opções
        printf("=================================================\n");
        printf("---------------Biblioteca - Parte 1--------------\n");
        printf("1 - Cadastrar novo Livro   ----------------------\n");
        printf("2 - Listar Todos os Livros ----------------------\n");
        printf("3 - Realizar um Emprestimo ----------------------\n");
        printf("4 - Listar Empréstimo      ----------------------\n");
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
      
            case 3: // Realizar Emprestimo
              printf("--- Realizar Emprestimo ---\n\n");
                if (totalEmprestimos >= MAX_EMPRESTIMOS){
                  printf("Limite de Emprestimos Atingidos!\n");
                } else {
                  printf("---*** Livros Disponiveis: ***---\n");
                  int disponiveis = 0;
                  for ( int i = 0; i < totalLivros; i++)
                    if (biblioteca[i].disponivel){
                      printf("%d - %s\n", i + 1, biblioteca[i].nome);
                      disponiveis++;
                    }
                }

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
                    fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING< stdin);
                    emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos]);

                    // Registra o Emprestimo
                    emprestimos[totalEmprestimos].inidceLivro = indice;

                    // Atualiza o status do livro para indisponivel.
                    biblioteca[indice].dispinivel = 0;

                    totalEmprestimos++;
                    printf("\nEmprestimo realizado com sucesso!\n");
                  } else {
                    printf("\nNumero de livro invalido ou Livro Indisponivel. \n");
                  }
      
                  case 4: // Listar Emprestimos
                  printf("---*** Lista de Emprestimos: ***---\n");
                    if(totalEmprestimos == 0) {
                      printf("Nenhum Emprestimo Ralizado. \n");
                    } else {
                      for ( int i = 0; i < totalEmprestimos; i++) {
                        // Usa o indice armazenado no emprestimo para buscar o nome do livro.
                        int indiceLivro = emprestimos[i].indicelivro;
                        printf("------------------------------------------------\n");
                        printf("Emprestimo %d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                      }
                      printf("------------------------------------------------\n");
                
                  
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
