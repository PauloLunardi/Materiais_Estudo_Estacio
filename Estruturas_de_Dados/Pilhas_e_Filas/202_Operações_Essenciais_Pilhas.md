# Operações Essenciais em Pilhas

Este documento apresenta as diretrizes técnicas para o desenvolvimento e controle das quatro operações fundamentais que regem o ciclo de vida de uma pilha: inserir (*push*), remover (*pop*), consultar (*peek*) e liberar (*free*). A correta integração destas rotinas garante a estabilidade de sistemas que exigem controle de histórico e reversão de ordem (LIFO).

---

## 1. Inserir (Push): Adicionando Elementos

A operação de inserção consiste em posicionar um novo elemento estritamente no **topo da pilha**. Antes de realizar a gravação física do dado, o algoritmo deve verificar se a estrutura possui espaço disponível para evitar o estouro de capacidade (*overflow*).

### Mecanismo de Funcionamento
Em implementações estáticas (vetores), o topo é controlado por um índice numérico. A cada inserção, o índice avança e o elemento é sobreposto na nova posição.

> **Resumo:** O *push* adiciona um novo item no topo da pilha, respeitando o limite máximo e mantendo o controle da ordem inversa. Em softwares reais, cada ação feita pelo usuário gera um *push* para permitir que ela possa ser desfeita posteriormente.

```c
void push(Pilha *p, Elemento e) {
    // Validação obrigatória contra estouro de capacidade (overflow)
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o índice do topo
    p->itens[p->topo] = e;  // Grava o novo elemento na posição atualizada
}
```

> **Exemplo Prático (Digitação):** Para digitar a palavra "Pilha", o software executa 5 ações individuais. Uma pilha armazena cada caractere em sequência. O topo armazena a última letra digitada (`a`).

---

## 2. Remover (Pop): Retirando Elementos

A operação de remoção consiste em extrair o elemento localizado no **topo da pilha**, que corresponde ao dado mais recente inserido na estrutura. Antes de recuar os ponteiros, é obrigatório checar se a estrutura não está vazia (*underflow*).

### Mecanismo de Funcionamento
O algoritmo copia os dados do topo atual para uma variável de saída fornecida por referência e, logo em seguida, decrementa o índice de controle do topo.

> **Resumo:** O *pop* remove o item do topo da pilha e entrega o seu conteúdo para o programa por referência, desde que a estrutura não esteja vazia. Em softwares de edição, o comando "Desfazer" (Ctrl + Z) equivale a dar um *pop* no topo do histórico de ações.

```c
void pop(Pilha *p, Elemento *e) {
    // Validação obrigatória: impede o acesso a regiões inválidas da memória
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos para remover.\n");
        e->valor = -1;  // Define um valor padrão/flag para indicar falha
        return;
    }

    *e = p->itens[p->topo];  // Copia os dados contidos no topo atual
    p->topo--;               // Decrementa o índice para recuar o topo
}
```

> **Exemplo Prático (Reversão):** Para desfazer por completo a palavra "Pilha", o sistema executa o *pop* 5 vezes consecutivas. Seguindo a lógica LIFO, as letras saem na ordem inversa da digitação: `a`, `h`, `l`, `i`, `P`.

---

## 3. Consulta (Peek / Espiar)

A operação de consulta possibilita que o programa examine os dados armazenados no **topo da pilha** para fins de exibição ou tomada de decisão, mas **sem remover** o item da estrutura.

### Mecanismo de Funcionamento
A função apenas copia as informações da posição apontada pelo índice `topo` corrente. Os ponteiros e contadores permanecem intactos, agindo de forma previsível e segura em modo de leitura (*Const Correctness*).

> **Resumo:** O *peek* extrai as informações do topo da pilha sem alterar o seu conteúdo. Em aplicações reais, essa função serve para antecipar visualmente qual ação será desfeita caso o comando "Desfazer" seja acionado.

```c
void peek(Pilha *p, Elemento *e) {
    // Validação de segurança: não é possível espiar uma pilha vazia
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos no topo.\n");
        e->valor = -1;  // Valor padrão/flag para indicar erro
        return;
    }

    *e = p->itens[p->topo];  // Apenas copia o elemento do topo atual
}
```

---

## 4. Liberar (Free / Esvaziar)

A rotina de limpeza limpa a estrutura de dados e devolve os recursos para o sistema operacional. O método utilizado depende diretamente da arquitetura de alocação da pilha:

### A. Em Pilhas Estáticas (Tamanho Fixo com Vetores)
Os elementos antigos não são apagados fisicamente bit a bit da memória RAM, mas a pilha perde a referência lógica de onde o topo estava. Redefinir a variável de controle reinicia o ciclo do vetor.
```c
void liberarPilhaEstatica(Pilha *p) {
    p->topo = -1;  // Define a pilha como vazia novamente (índice base)
}
```

### B. Em Pilhas Dinâmicas (Tamanho Variável com Malloc)
Como cada elemento foi instanciado separadamente na memória *Heap*, o programa é obrigado a realizar uma varredura utilizando um laço `while` para aplicar a função `free()` individualmente em cada nó, eliminando vazamentos de memória (*memory leaks*).
```c
void liberarPilhaDinamica(PilhaDinamica *p) {
    // O laço percorre a corrente limpando cada nó dinâmico
    while (p->topo != NULL) {
        No *remover = p->topo;       // Guarda o endereço do nó atual
        p->topo = p->topo->proximo;  // Avança o topo para o próximo da fila
        free(remover);               // Desaloca fisicamente a caixinha da memória
    }
}
```

---

## 5. Matriz de Integração dos Estados da Pilha

| Operação Fundamental | Impacto no Índice `topo` | Impacto na Memória Física | Permissão de Execução |
| :--- | :---: | :---: | :--- |
| **Inserir (*Push*)** | Incrementa (`+1`) | Grava novo dado no índice atual | Permitida apenas se `pilhaCheia` for Falso. |
| **Remover (*Pop*)** | Decrementa (`-1`) | Mantém o dado residual (inacessível) | Permitida apenas se `pilhaVazia` for Falso. |
| **Consultar (*Peek*)** | Inalterado | Apenas leitura de dados | Permitida apenas se `pilhaVazia` for Falso. |
| **Liberar Estática** | Redefine para `-1`| Mantém dados residuais (inacessíveis) | Permitida a qualquer momento. |
| **Liberar Dinâmica** | Redefine para `NULL`| Apaga fisicamente via `free()` | Permitida a qualquer momento. |
