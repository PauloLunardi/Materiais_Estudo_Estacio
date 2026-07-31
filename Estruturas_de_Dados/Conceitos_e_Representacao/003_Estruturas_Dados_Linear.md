# 🟡 Nível Novato: Estruturas de Dados Lineares

## 🎥 Visão Geral do Módulo
As **Estruturas de Dados Lineares** são modelos fundamentais que organizam os elementos de forma sequencial, isto é, um após o outro em uma única linha lógica. Elas são ideais para cenários onde a ordem de entrada, leitura ou remoção dos elementos é crucial para o funcionamento do sistema.

Neste módulo, você aprenderá o funcionamento mecânico dessas estruturas, suas regras de acesso à memória e como os conceitos de organização cronológica se aplicam a softwares do mundo real.

---

## 🧭 Características Fundamentais

Nas estruturas lineares, a disposição dos dados segue uma sequência linear estrita. Isso implica que:
*   Cada elemento possui exatamente **um antecessor** direto (exceto o primeiro).
*   Cada elemento possui exatamente **um sucessor** direto (exceto o último).
*   O acesso e o processamento dos dados seguem uma ordem sequencial bem definida.

> ⚠️ **Atenção:** Estas estruturas são a escolha perfeita para representar listas, pilhas, filas e qualquer coleção de dados onde o histórico ou a ordem de processamento das informações precise ser rigidamente preservado.

---

## 🗂️ Os 4 Principais Tipos de Estruturas Lineares

### 1. Vetores (`Arrays`)
Armazenam elementos do mesmo tipo em **posições consecutivas e contíguas de memória**. Funcionam como um conjunto de caixas numeradas (índices), onde cada caixa guarda um valor específico.

*   **Mecânica:** Permite acesso direto a qualquer elemento através do seu índice numérico, tornando a busca por posição extremamente rápida.
*   **Exemplo Prático:** Uma tabela de notas de alunos em um sistema acadêmico, onde o índice do vetor representa o ID ou a posição de um estudante específico.
*   **No Jogo WAR:** O vetor de `structs` usado para cadastrar e armazenar os dados estáticos dos jogadores (nome, cor, total de tropas).

### 2. Listas Lineares (`Listas Ligadas / Encadeadas`)
Ao contrário dos vetores, os elementos de uma lista ligada não precisam estar em posições consecutivas na memória. Cada elemento (chamado de **nó**) contém o seu dado e um **ponteiro** (referência) que aponta para o endereço do próximo elemento, como se fosse um colar de contas ou uma corrente.

*   **Mecânica:** Excelente para cenários onde o tamanho da lista muda constantemente, pois inserir ou remover elementos não exige reorganizar toda a estrutura na memória.
*   **Exemplo Prático:** O histórico de navegação de um browser de internet. Cada página visitada guarda um link para a página seguinte e para a anterior.

### 3. Pilhas (`Stacks`)
Uma estrutura linear baseada no princípio **LIFO** (*Last In, First Out*), onde o **último** elemento a entrar é obrigatoriamente o **primeiro** a sair. As operações de inserção (push) e remoção (pop) acontecem apenas em uma extremidade: o topo.

*   **Analogia:** Uma pilha de pratos limpos. O último prato lavado e colocado no topo será o primeiro a ser retirado para o uso.
*   **Exemplo Prático:** O mecanismo de **Desfazer/Refazer** (`Ctrl + Z` / `Ctrl + Y`) em editores de texto ou de imagem, onde a ação mais recente executada é a primeira a ser revertida.

### 4. Filas (`Queues`)
Uma estrutura linear baseada no princípio **FIFO** (*First In, First Out*), onde o **primeiro** elemento a entrar é obrigatoriamente o **primeiro** a ser removido. Os novos elementos entram pelo final (cauda) e as remoções acontecem no início (cabeça).

*   **Analogia:** Uma fila no caixa de um supermercado ou de um banco. Quem chegou primeiro é atendido e liberado primeiro.
*   **Exemplo Prático:** A gestão de chamadas telefônicas em um *call center* ou o gerenciamento de documentos enviados para uma impressora (*spooler de impressão*).

---

## 🔄 Comparativo Direto: LIFO vs. FIFO

Compreender a diferença entre essas duas filosofias de processamento é essencial para desenhar a arquitetura de qualquer software eficiente:

| Critério | LIFO (*Last In, First Out*) | FIFO (*First In, First Out*) |
| :--- | :--- | :--- |
| **Estrutura** | Pilha (`Stack`) | Fila (`Queue`) |
| **Regra de Ouro** | O último que entra é o primeiro que sai. | O primeiro que entra é o primeiro que sai. |
| **Ponto de Acesso** | Unidirecional (Apenas pelo **Topo**). | Bidirecional (Entra pelo **Fim**, sai pelo **Início**). |
| **Foco de Uso** | Retomar ações recentes ou históricos reversos. | Ordem estrita de chegada e processamento cronológico. |
| **Casos Reais** | Controle de chamadas de funções em execução no processador (*Call Stack*). | Escalonamento de tarefas em servidores e sistemas operacionais. |

---

## 🛠️ Próximos Passos no Projeto WAR
Para consolidar estes conceitos na prática da linguagem C:
1.  Utilizaremos o conceito de **Vetor** para alocar espaço fixo para os jogadores.
2.  Utilizaremos **Ponteiros** para fazer a manipulação direta desses endereços na memória.
3.  Entenderemos como a **Alocação Dinâmica** permite que estruturas lineares cresçam ou diminuam de tamanho enquanto o jogo está rodando.
