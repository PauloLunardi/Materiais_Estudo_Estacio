# Desafio: Sistema de Inventário Inicial (Mochila de Loot)

Este documento apresenta a especificação técnica e os requisitos para o desenvolvimento do sistema de inventário inicial, projetado para simular o gerenciamento de uma mochila de loot em um cenário de sobrevivência. A implementação utiliza estruturas de dados compostas (structs) e listas sequenciais contíguas (vetores) na linguagem C.

---

## 1. Visão Geral do Desafio

O objetivo é construir um minissistema capaz de gerenciar os recursos essenciais coletados por um jogador (como armas, munições, kits médicos e ferramentas) logo após o início da partida. O sistema servirá para organizar esses itens dentro de uma mochila virtual de espaço limitado, permitindo operações diretas de cadastro, exclusão, listagem e localização rápida de suprimentos por meio de uma varredura sequencial.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As funcionalidades obrigatórias que determinam o comportamento da mochila de loot são:

1. **Criação da Struct:** Definição de uma estrutura composta nomeada como `Item`, contendo exatamente os campos: `char nome[30]`, `char tipo[20]` e `int quantidade`.
2. **Cadastro de Itens:** O sistema deve suportar o armazenamento de até 10 itens simultâneos na mochila. O jogador deve fornecer o nome, o tipo do recurso (ex: arma, munição, cura) e a quantidade coletada.
3. **Remoção de Itens:** Permissão para excluir permanentemente um item específico da mochila realizando a busca pelo seu nome.
4. **Listagem dos Itens Registrados:** Exibição detalhada e formatada de todos os dados dos itens presentes no inventário. Esta operação de atualização deve ser chamada após cada alteração na estrutura.
5. **Busca Sequencial:** Implementação de uma função de busca linear que inspecione a lista de cima a baixo para localizar um item pelo nome e exibir seus dados na tela.

### Requisitos Não Funcionais
Critérios de qualidade e boas práticas para o desenvolvimento do software:

* **Usabilidade:** A interface de linha de comando no terminal deve ser clara, orientando o jogador com mensagens amigáveis sobre as ações e o que deve ser digitado.
* **Desempenho:** O tempo de resposta para o processamento de cada comando no terminal deve ser imediato, com tempo inferior a 2 segundos.
* **Documentação:** O código-fonte precisa conter comentários explicativos detalhados descrevendo a struct, o propósito de cada função e a lógica do fluxo de execução.
* **Manutenibilidade:** Uso obrigatório de identificadores representativos e claros para variáveis e funções, facilitando leituras e manutenções futuras.

---

## 3. Instruções Detalhadas de Implementação

A arquitetura do programa deve respeitar os seguintes blocos construtivos básicos:

### A. Dependências e Bibliotecas
O programa deve incluir as seguintes bibliotecas padrão:
* `<stdio.h>` (Operações de entrada e saída).
* `<stdlib.h>` (Funções utilitárias do sistema).
* `<string.h>` (Manipulação, comparação e cópia de strings).

### B. Vetor de Estruturas
A estrutura interna deve ser baseada em um array contíguo de tamanho fixo:
```c
#define CAPACIDADE_MAX 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Declaração do vetor e do contador de controle dentro da função main
Item mochila[CAPACIDADE_MAX];
int total_itens = 0;
```

### C. Funções Obrigatórias de Escopo
O código deve ser modularizado contendo as seguintes assinaturas obrigatórias:
* `inserirItem()`: Controla o limite de capacidade (máximo 10) e insere um novo registro na primeira posição livre do vetor.
* `removerItem()`: Localiza o elemento pelo nome, apaga o registro e desloca todos os itens subsequentes para a esquerda para fechar a lacuna na memória.
* `listarItens()`: Percorre o vetor de 0 até o limite do contador de controle, exibindo os dados na tela em formato de tabela.
* `buscarItem()`: Implementa o laço `for` ou `while` para comparar o nome buscado com os nomes salvos no vetor via `strcmp()`.

---

## 4. Guia de Desenvolvimento e Versionamento (Tutorial Git)

O ciclo de desenvolvimento e entrega do projeto deve seguir as diretrizes do ambiente do GitHub Classroom através dos seguintes passos:

1. **Acesso ao Desafio:** Acesse o link fornecido pelo GitHub Classroom utilizando uma conta ativa na plataforma para clonar o repositório padrão da tarefa.
2. **Exploração do Ambiente:** Abra o repositório gerado e examine a estrutura modelo de arquivos e pastas preexistentes. Não crie novos arquivos, trabalhe diretamente nos arquivos fornecidos.
3. **Uso do CodeSpaces:** Utilize o ambiente de desenvolvimento em nuvem do GitHub CodeSpaces para editar o código-fonte e implementar as funções do inventário de forma limpa e organizada.
4. **Comentários Obrigatórios:** Antes de finalizar, comente todas as seções principais do código-fonte. Explique a finalidade de cada algoritmo (como o deslocamento na remoção e a varredura na busca linear), detalhando o propósito das variáveis e parâmetros.
5. **Finalização e Commit:** Salve as alterações e execute os comandos de commit e push no terminal integrado para enviar o código finalizado de volta ao repositório do GitHub Classroom para correção.
