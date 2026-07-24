# 🧩 Documentação de Estudos: Introdução à Programação Orientada a Objetos (POO)

A **Programação Orientada a Objetos (POO)** é um paradigma de desenvolvimento (uma forma de pensar e estruturar softwares) focado em organizar o código em torno de elementos do mundo real, aproximando a computação da nossa realidade concreta.

---

## 🌎 1. O Pensamento Orientado a Objetos

A grande revolução da POO foi mudar a forma como estruturamos os programas. 

* **Programação Convencional (Procedural):** Trata os dados e o comportamento (as funções) de forma separada e pouco vinculada.
* **Programação Orientada a Objetos (POO):** Une os dados e os comportamentos no mesmo lugar. Ela funciona como um reflexo do mundo real através da interação de componentes independentes.

> 🗣️ *"A tecnologia baseada em objetos é mais do que apenas uma forma de programar. Ela é mais importante como um modo de pensar em um problema de forma abstrata, utilizando conceitos do mundo real, e não ideias computacionais."* (Rumbaugh, 1994)

---

## 🕸️ 2. O Processo de Abstração

Não precisamos trazer todos os detalhes de um objeto do mundo real para o computador. **Abstrair** significa isolar e capturar apenas as características e comportamentos que são **relevantes para o problema atual**.

* **Cenário A:** Em um **Sistema Acadêmico**, o objeto `Pessoa` precisa registrar a *formação acadêmica*, *nome do pai* e *nome da mãe*.
* **Cenário B:** Em um **Sistema de Academia de Ginástica**, o mesmo objeto `Pessoa` precisa registrar a *altura*, *peso* e *frequência cardíaca*.

---

## 🔲 3. O Mapeamento do Mundo Real para o Computador

O desenvolvimento de um sistema baseado em POO consiste em mapear os elementos da realidade em estruturas computacionais:

```text
  OBJETO NO MUNDO REAL                    OBJETO COMPUTACIONAL
┌──────────────────────┐                ┌──────────────────────┐
│  • Características   │ ─────────────> │  • Atributos         │
│  • Comportamento     │                │  • Operações         │
└──────────────────────┘                └──────────────────────┘
```

---

## 💎 4. Os Três Pilares Iniciais da Modelagem

### 📦 A. Objetos
Um objeto é a representation computacional de um elemento ou processo real. Ele é uma entidade independente que armazena informações e interage com outros objetos do sistema.
* **Exemplos de Objetos:** `aluno`, `professor`, `livro`, `empresa`, `janela`, `pedido_de_compra`.

### 📑 B. Atributos
Atributos são as **propriedades ou características** que descrevem um objeto. O conjunto de valores guardados nos atributos em um determinado momento determina o **estado atual** daquele objeto.

* **Exemplo Prático (Comparando Estados):**
  * **Objeto Pessoa 1:** `Nome: Maria`, `Idade: 25`, `Peso: 63kg`, `Altura: 1.60m`
  * **Objeto Pessoa 2:** `Nome: Joana`, `Idade: 30`, `Peso: 60kg`, `Altura: 1.68m`

### ⚙️ C. Operações (Métodos)
Uma operação é uma **função, ação ou transformação** que pode ser aplicada aos dados de um objeto. As operações servem para alterar o estado (mudar os atributos) ou fazer com que diferentes objetos colaborem entre si.

O conjunto de operações que um objeto expõe para o sistema é chamado de **Interface**. A única forma de um objeto conversar com o outro é por meio de suas interfaces.

* **Exemplos de Operações por Escopo:**
  * **Classe `Empresa`:** `Contratar_Funcionario()`, `Despedir_Funcionario()`, `Dar_Ferias()`
  * **Classe `Janela`:** `Abrir()`, `Fechar()`, `Ocultar()`, `Minimizar()`

---

## 💻 5. Visualizando a Estrutura (Conceito Inicial)

Embora você vá estudar a sintaxe detalhadamente mais à frente, veja como a união de Atributos (dados) e Operações (funções) se parece de forma genérica:

```text
OBJETO: ContaBancaria
│
├── ATRIBUTOS (Dados/Características)
│   ├── titular = "João da Silva"
│   └── saldo = 1000.0
│
└── OPERAÇÕES (Ações/Comportamentos)
    ├── depositar(valor)
    └── exibir_extrato()
```
