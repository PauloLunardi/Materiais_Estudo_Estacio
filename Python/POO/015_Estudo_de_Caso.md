# Documentação Prática: Laboratórios de Associação e Métodos de Escopo

Este documento organiza as especificações e o passo a passo para a implementação dos exercícios práticos de programação orientada a objetos.

---

## Bloco 1: Gerenciamento de Biblioteca (Agregação)

### Cenário 1
Criar um sistema simples de gerenciamento de uma biblioteca que contém vários livros usando o conceito de agregação. Você deve criar duas classes: Livro e Biblioteca.

A classe Livro deve ter os seguintes atributos:
* título (str);
* autor (str);
* isbn (str).

A classe Biblioteca deve ter:
* Um nome (str);
* Uma lista de livros.

A classe Biblioteca deve ter métodos para:
* Adicionar um livro à biblioteca;
* Remover um livro da biblioteca;
* Listar todos os livros na biblioteca.

### Roteiro para o Cenário 1
1. Defina a classe Livro: Construtor que inicializa os atributos título, autor e isbn.
2. Defina a classe Biblioteca: Construtor que inicializa o nome da biblioteca e uma lista vazia de livros.
3. Crie o método para adicionar um livro (`adicionar_livro`).
4. Crie o método para remover um livro (`remover_livro`).
5. Crie o método para listar todos os livros (`listar_livros`).
6. Testar o funcionamento.

---

## Bloco 2: Gerenciamento de Pessoa (Métodos Especiais)

### Cenário 2
Criar uma classe Pessoa que recebe parâmetro para o construtor.

A classe Pessoa deve ter:
* Nome;
* Idade;
* Método de classe para receber o ano de nascimento, o nome da pessoa e calcular sua idade;
* Método estático que informe se a pessoa é maior ou menor de idade.

### Roteiro para o Cenário 2
1. Faça o import para o projeto do módulo `datetime`.
2. Defina a classe Pessoa: Construtor que inicializa os atributos nome e idade.
3. Crie o método de classe para instanciar um objeto pessoa a partir do ano de seu nascimento.
4. Crie o método estático para definir se a pessoa instanciada é maior ou menor de idade.
5. Crie instâncias de pessoas e teste o funcionamento.

---

## 3. Direcionamento dos Arquivos do Repositório

Os códigos funcionais baseados nas diretrizes acima estão disponíveis nos seguintes arquivos clicáveis:

* [015__Caso_de_Estudo_1.py](./015__Caso_de_Estudo_1.py): Contém o desenvolvimento completo do Bloco 1 (Classes Livro e Biblioteca), aplicando as rotinas de manipulação do acervo.
* [015__Caso_de_Estudo_2.py](./015__Caso_de_Estudo_2.py): Contém o desenvolvimento completo do Bloco 2 (Classe Pessoa), demonstrando o cálculo dinâmico de datas, chamadas com `@classmethod` e validação com `@staticmethod`.
