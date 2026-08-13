# Documentação Técnica: Implementação Prática de Árvore Binária em C

Este documento apresenta a especificação detalhada, a análise algorítmica e o guia de funcionamento do sistema de árvore binária de cômodos desenvolvido na linguagem C. O objetivo deste projeto é demonstrar de forma prática a aplicação de alocação dinâmica, manipulação de ponteiros estruturados e o impacto dos percursos recursivos clássicos na recuperação de dados hierárquicos.

---

## 1. Arquitetura do Código e Componentes

O software foi desenvolvido seguindo o paradigma da programação estruturada e divide-se em três pilares fundamentais: a modelagem do nó, os motores de busca/percurso e o gerenciador de memória.

### A. Anatomia do Nó (`struct No`)
Cada elemento da árvore (nó) funciona como uma célula autônoma na memória *Heap*. A struct possui três campos:
*   `valor`: Um array contíguo de caracteres (string) dimensionado para armazenar até 49 letras mais o caractere nulo terminal (`\0`).
*   `esquerda`: Ponteiro que guarda a coordenada do filho localizado na ramificação inferior esquerda.
*   `direita`: Ponteiro que guarda a coordenada do filho localizado na ramificação inferior direita.

### B. Módulo de Alocação (`criarNo`)
Para isolar a complexidade do gerenciamento de memória do usuário final, a função `criarNo` atua como um construtor automatizado:
1.  Solicita espaço em tempo de execução via `malloc(sizeof(struct No))`.
2.  Copia a string de texto recebida como parâmetro para dentro da struct utilizando `strcpy()`.
3.  **Aterra os ponteiros:** Define `esquerda = NULL` e `direita = NULL` obrigatoriamente. Isso cria um nó folha limpo e evita que o programa aponte para endereços de memória inválidos (ponteiros fantasmas).

---

## 2. Mapa Hierárquico do Sistema (Arte ASCII)

O código implementado dentro do bloco principal `main()` amarra os nós criando uma topologia idêntica ao layout arquitetônico residencial apresentado abaixo:

```text
               [ Hall de Entrada ]           <── (Nó Raiz / Nível 0)
                 /             \
                /               \
         [ Sala de Estar ]    [ Biblioteca ]  <── (Nós Internos / Nível 1)
           /           \
          /             \
      [ Quarto ]       [ NULL ]              <── (Nós Folhas / Nível 2)
```

### Detalhes das Amarrações de Ponteiros:
*   A **Raiz** aponta diretamente para a *Sala de Estar* (esquerda) e *Biblioteca* (direita).
*   A *Sala de Estar* estende a hierarquia para o nível 2 apontando para o *Quarto* (esquerda), enquanto o seu ponteiro da direita recebe `NULL`, indicando que não há ramificação naquele lado.
*   Os nós *Quarto* e *Biblioteca* são **Nós Folhas**, pois ambos os seus ponteiros (`esquerda` e `direita`) estão aterrados em `NULL`.

---

## 3. Análise Crítica dos Percursos Recursivos

A mudança no momento em que a função visita (imprime) o nó corrente altera por completo o fluxo de execução e a saída de texto no terminal:

### A. Pré-Ordem (Pai ➔ Esquerda ➔ Direita)
```c
void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
```
*   **Saída Obtida:** `Hall de Entrada ➔ Sala de Estar ➔ Quarto ➔ Biblioteca`
*   **Lógica Interna:** O processador lê a informação do pai imediatamente. De seguida, ele desce limpando todo o braço esquerdo até o final do galho antes de retornar e processar os elementos localizados à direita. 
*   **Aplicação:** Ideal para rotinas de **clonagem de árvores**, pois recria os nós exatamente na mesma hierarquia estrutural.

### B. Em Ordem (Esquerda ➔ Pai ➔ Direita)
```c
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
```
*   **Saída Obtida:** `Quarto ➔ Sala de Estar ➔ Hall de Entrada ➔ Biblioteca`
*   **Lógica Interna:** O programa ignora temporariamente o processamento do nó atual e desce de forma obstinada até encontrar o elemento mais profundo localizado à esquerda (`Quarto`). Só então ele imprime o dado e começa a subir em direção à raiz e à direita.
*   **Aplicação:** É o percurso mais importante para **Árvores Binárias de Busca (BST)**, pois recupera e lista os dados em ordem crescente perfeita.

### C. Pós-Ordem (Esquerda ➔ Direita ➔ Pai)
```c
void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}
```
*   **Saída Obtida:** `Quarto ➔ Sala de Estar ➔ Biblioteca ➔ Hall de Entrada`
*   **Lógica Interna:** O nó pai fica retido na pilha de execução e é o último a ser processado. O algoritmo garante a visita de todos os filhos e subárvores descendentes antes de validar o elemento central.
*   **Aplicação:** Essencial para avaliar árvores de expressões matemáticas e para rotinas de **exclusão/desalocação de estruturas**.

---

## 4. Gerenciamento de Memória e Proteção contra Vazamentos

Como os elementos foram criados individualmente utilizando alocação dinâmica com `malloc()`, o sistema operacional exige que o programa devolva explicitamente cada bloco de memória antes de encerrar sua execução.

A função `liberar()` adota obrigatoriamente a lógica do percurso em **Pós-Ordem**:

```c
void liberar(struct No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda); // 1. Desce limpando o galho esquerdo
        liberar(raiz->direita);  // 2. Desce limpando o galho direito
        free(raiz);              // 3. Libera o pai (Garante que os filhos já sumiram)
    }
}
```

### Por que usar Pós-Ordem na liberação?
Se utilizássemos a Pré-Ordem (dando `free(raiz)` primeiro), destruiríamos a caixinha do nó pai imediatamente. Com o pai apagado, perderíamos de forma irreversível os ponteiros `raiz->esquerda` e `raiz->direita`. Os nós filhos continuariam perdidos e isolados ocupando espaço na memória RAM do computador sem que ninguém conseguisse acessá-los ou apagá-los. Isso geraria um vazamento de memória crítico (*Memory Leak*). A Pós-Ordem garante que a base e as ramificações sejam apagadas primeiro, deixando a raiz para o final.
