# ⚔️ Desafio: Criação do Jogo WAR (Nível Novato)

## 🎥 Visão Geral do Desafio
Este desafio marca os seus primeiros passos na construção da base lógica do clássico jogo **WAR** em linguagem C. A missão consiste em implementar um sistema básico de banco de dados para o cadastro e exibição de territórios do jogo, consolidando os conceitos de **vetores de structs**, entrada de dados via terminal e organização lógica de programação estruturada.

---

## 🗺️ Missão: Construção dos Territórios

Sua tarefa é criar um programa que utilize uma estrutura de dados composta para gerenciar as informações geográficas e militares do jogo. O sistema permitirá o cadastro de **5 territórios** e exibirá seus dados consolidados logo após o preenchimento.

### 📋 Requisitos Funcionais

1.  **Criação da Struct:** Definir uma estrutura composta que agrupe as propriedades fundamentais de um território.
2.  **Cadastro de Dados:** Permitir que o usuário insira as informações de 5 territórios sequencialmente via terminal.
3.  **Exibição de Relatório:** Percorrer a estrutura de dados e listar na tela todas as informações registradas com formatação clara.

#### 🗂️ Modelagem da Estrutura (`Territorio`)
A `struct` deve conter exatamente os seguintes membros:

| Campo | Tipo de Dado | Tamanho / Descrição |
| :--- | :--- | :--- |
| `nome` | `char` (String) | `[30]` (Armazena o nome do território) |
| `cor` | `char` (String) | `[10]` (Armazena a cor do exército dominante) |
| `tropas` | `int` | Armazena a quantidade atual de exércitos no local |

### ⚡ Requisitos Não Funcionais e Técnicos

*   **Usabilidade:** A interface de entrada deve ser simples, exibindo mensagens claras que orientem o usuário sobre o que digitar.
*   **Desempenho:** O sistema deve processar e apresentar os dados imediatamente após o cadastro (tempo de resposta inferior a 2 segundos).
*   **Manutenibilidade:** Utilizar nomes de variáveis, membros e funções claros, representativos e em conformidade com as boas práticas de programação.
*   **Documentação Obrigatória:** O código-fonte **deve conter comentários explicativos** detalhando a criação da struct, o propósito das variáveis e a lógica dos laços de repetição (`for`).

---

## 🛠️ Instruções Detalhadas de Implementação

Siga o roteiro lógico abaixo para construir o arquivo de código-fonte:

1.  **Inclusão de Cabeçalhos:** Importe as bibliotecas essenciais: `<stdio.h>` e `<string.h>`.
2.  **Definição do Tipo:** Crie a `struct Territorio` conforme as especificações de campos.
3.  **Vetor de Estruturas:** Dentro da função `main`, declare um vetor (array estático) do tipo da sua struct com capacidade para **5 elementos**.
4.  **Laço de Entrada:** Implemente um laço `for` de 0 a 4 para capturar os dados do teclado (`scanf` ou `fgets`) e preencher o vetor.
5.  **Laço de Saída:** Implemente um segundo laço `for` para percorrer o vetor preenchido, imprimindo os dados formatados na tela.

---

## 🐙 Tutorial de Entrega: Fluxo do GitHub Classroom

Aplique os conceitos aprendidos e envie sua solução utilizando o ecossistema do GitHub seguindo as etapas abaixo:

### 1️⃣ Dar o Primeiro Passo
Acesse o link do **GitHub Classroom** fornecido pela sua disciplina para criar o seu repositório privado do desafio. Caso não possua uma conta no GitHub, crie uma gratuitamente (não é necessário registro de estudante).

### 2️⃣ Aceitar e Acessar o Desafio
Clique no botão para aceitar a tarefa. O GitHub gerará automaticamente um repositório com o seu nome de usuário. Clique no link gerado para abrir a página do projeto.

### 3️⃣ Explorar a Estrutura do Ambiente
Analise a árvore de arquivos fornecida. O repositório já possui a estrutura padrão de pastas e arquivos de modelo necessários. **Não crie novos arquivos**, trabalhe diretamente sobre os arquivos existentes.

### 4️⃣ Desenvolver no GitHub Codespaces
Instancie um ambiente de desenvolvimento virtual clicando em **Code -> Codespaces**. Utilize este editor online para programar, compilar e testar a sua solução.

### 5️⃣ Comentar e Enviar
Antes de finalizar o envio (Commit/Push), certifique-se de que todos os seus arquivos de código-fonte estejam devidamente comentados. Os comentários ajudam a banca de correção a validar seu entendimento sobre os algoritmos e a lógica aplicada.
