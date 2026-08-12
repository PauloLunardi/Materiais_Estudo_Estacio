# Desafio: Comparaçao de Estruturas e Algoritmos de Busca no Inventario

Este documento apresenta a especificaçao tecnica e as diretrizes de arquitetura para o desenvolvimento das duas versoes do sistema de mochila de loot. O objetivo principal e contrastar o desempenho e a flexibilidade entre estruturas sequenciais (vetores) e estruturas dinamicas (listas encadeadas), mensurando a eficiencia de algoritmos de ordenaçao e busca em cenarios criticos de desempenho.

---

## 1. Visao Geral do Desafio

A tarefa consiste em criar duas engines de inventario que executam as mesmas operaçoes basicas em paralelo. Atraves dessa implementaçao, busca-se entender como o rearranjo de dados e o metodo de acesso influenciam o tempo de resposta e o processamento do jogo. 

A grande novidade deste nivel e a obrigatoriedade de ordenar os dados do vetor para habilitar a execuçao da busca binaria. O sistema tambem deve rastrear o custo de processamento computacional exibindo um contador com o numero exato de comparaçoes textuais feitas em cada busca.

---

## 2. Requisitos do Sistema

### Requisitos Funcionais
As rotinas obrigatorias para a construçao do motor de inventario sao:

1. **Criaçao de Structs Relacionadas:**
   * Struct `Item`: Contendo as propriedades `char nome[30]`, `char tipo[20]` e `int quantidade`.
   * Struct `No`: Unidade basica da lista encadeada, contendo um campo `Item dados` e um ponteiro de conexao `struct No* proximo`.
2. **Implementaçoes em Paralelo:** Criaçao de duas mochilas independentes rodando no mesmo programa: uma baseada em Alocaçao Sequencial Contigua (Vetor) e outra em Alocaçao Dinamica Encadeada (Lista Encadeada).
3. **Operaçoes Padrao das Estruturas:** Ambas as versoes devem ser capazes de inserir um novo item, remover um item buscando por nome, listar o conteudo completo e buscar um item pelo nome usando a Varredura Sequencial.
4. **Ordenaçao Estrutural:** O inventario por vetor deve possuir uma rotina de ordenaçao alfabetica crescente por nome utilizando os algoritmos `Bubble Sort` ou `Selection Sort`.
5. **Busca de Alta Performance:** Apos a ordenaçao do vetor, o sistema deve liberar a execuçao da Busca Binaria para localizar itens criticos de sobrevivencia com velocidade maxima.
6. **Métricas de Performance:** Implementaçao de contadores de comparaçoes. Toda busca (sequencial ou binaria) deve imprimir na tela quantas checagens de `strcmp()` foram executadas ate atingir o resultado.

### Requisitos Nao Funcionais
Criterios de qualidade, manutenibilidade e experiencia de uso:

* **Usabilidade Avançada:** O menu do terminal deve ser intuitivo, permitindo chavear de forma transparente entre o teste do vetor e o teste da lista ligada, exibindo tabelas de resultados claras.
* **Eficiencia Computacional:** O tempo total para o processamento e retorno de cada rotina nao deve ultrapassar o teto limite de 2 segundos.
* **Documentaçao e Clareza:** O codigo-fonte deve ser documentado com comentarios limpos sobre o papel de cada ponteiro, com nomenclatura de variaveis autoexplicativa.

---

## 3. Instruçoes Detalhadas de Implementaçao

Os modulos e dependencias do programa devem respeitar a seguinte estrutura de desenvolvimento:

### A. Dependencias e Diretivas
O arquivo de codigo deve ser guiado pelas inclusoes basicas:
```c
#include <stdio.h>   // Fluxos de entrada e saida de dados
#include <stdlib.h>  // Alocaçao dinamica e controle de memoria (malloc, free)
#include <string.h>  // Funcoes de cadeia de caracteres (strcmp, strcpy)
#include <time.h>    // Opcional para analise empirica de tempo de resposta
```

### B. Mapeamento das Funçoes Obrigatorias
O software deve ser totalmente modularizado atraves de funçoes especializadas com responsabilidades bem divididas:

* **Modulo do Vetor:** `inserirItemVetor()`, `removerItemVetor()`, `listarVetor()`, `ordenarVetor()`, `buscarSequencialVetor()`, `buscarBinariaVetor()`.
* **Modulo da Lista Encadeada:** `inserirItemLista()`, `removerItemLista()`, `listarLista()`, `buscarSequencialLista()`, `liberarLista()`.

### C. Logica de Metricas (Contadores)
As contagens de comparaçoes devem ser passadas por referencia atraves de ponteiros ou incrementadas em escopos controlados para isolar a contagem de cada clique de busca:
```c
// Exemplo de rastreamento dentro do laco da busca
int comparacoes = 0;
while (inicio <= fim) {
    comparacoes++;
    int comp = strcmp(vetor[meio].nome, alvo);
    // ... logica de corte da busca binaria
}
printf("Busca concluida. Total de comparacoes feitas: %d\n", comparacoes);
```

---

## 4. Guia de Versionamento e Entrega (Tutorial Git)

Para consolidar o projeto dentro do ambiente do GitHub Classroom, siga o roteiro operacional:

1. **Clonagem do Projeto:** Acesse o link oficial enviado pelo GitHub Classroom para aceitar a tarefa e gerar o seu repositorio privado do nivel aventureiro.
2. **Uso do CodeSpaces:** Ative o ambiente de desenvolvimento em nuvem do GitHub CodeSpaces acoplado ao seu repositorio para editar o codigo-fonte diretamente pelo navegador.
3. **Desenvolvimento Focado:** Codifique as duas versoes nos arquivos modelo preexistentes. Mantenha os arquivos organizados, respeitando os nomes de funçoes indicados.
4. **Comentarios de Codigo:** Antes de submeter, certifique-se de que todas as funçoes possuem comentarios explicativos sobre sua finalidade. Isolar e explicar o funcionamento do algoritmo de ordenaçao e o calculo do ponto medio da busca binaria e fundamental para a correçao.
5. **Sincronizaçao (Commit/Push):** Utilize o terminal integrado do CodeSpaces para rodar a sequencia de comandos `git add`, `git commit -m "Implementaçao do nivel aventureiro"` e `git push` para efetivar a entrega do desafio.
