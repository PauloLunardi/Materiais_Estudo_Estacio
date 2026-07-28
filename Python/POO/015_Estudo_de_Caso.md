# Documentação Prática: Laboratórios de Associação e Métodos de Escopo

Este documento registra o roteiro de desenvolvimento e as diretrizes estruturais para a execução de dois laboratórios práticos focados em conceitos comerciais de Programação Orientada a Objetos: Associação por Agregação e Métodos de Escopo Avançados (@classmethod e @staticmethod).

---

## 1. Cenário 1 - Gerenciamento de Biblioteca (Agregação)

O primeiro laboratório consiste em modelar um sistema básico de acervo literário. A relação entre as classes é de **Agregação**, o que significa que os livros existem de forma independente e podem ser transferidos ou mantidos no sistema mesmo se uma instância específica de biblioteca for desativada.

### Requisitos da Classe Livro
* **Atributos de Instância:** Deve registrar textualmente o título do livro, o nome do autor e o código identificador internacional ISBN.
* **Comportamento:** Atua como um objeto puramente de dados (*data object*) que será encapsulado e gerenciado pela classe contenedora.

### Requisitos da Classe Biblioteca
* **Atributos de Instância:** Deve registrar o nome da instituição e iniciar obrigatoriamente uma lista vazia dedicada a armazenar os objetos do tipo `Livro`.
* **Método `adicionar_livro`:** Deve receber uma instância pronta da classe `Livro` e inseri-la no array interno da biblioteca.
* **Método `remover_livro`:** Deve localizar e extrair um objeto específico da lista de acervo (geralmente validando pelo título ou código ISBN).
* **Método `listar_livros`:** Deve varrer a lista interna utilizando uma estrutura de repetição e exibir as propriedades de cada livro de forma organizada no terminal.

---

## 2. Cenário 2 - Gerenciamento de Pessoa (Métodos Especiais)

O segundo laboratório explora a manipulação de datas e fusos do sistema operacional através do módulo nativo `datetime`, aplicando a trindade de métodos do Python para isolar responsabilidades de cálculo e validação.

### Requisitos Estruturais da Classe Pessoa
* **Atributos de Instância:** O construtor básico da classe deve receber e registrar apenas o nome e a idade atual da pessoa.

### O Método de Classe (`@classmethod`) como Construtor Alternativo
O roteiro exige a criação de um método de classe capaz de receber o ano de nascimento de um indivíduo e o seu nome. 
* **Lógica Interna:** O método deve capturar o ano corrente do sistema operacional utilizando `datetime.date.today().year`, subtrair o ano de nascimento enviado para calcular a idade exata e, na linha de retorno, invocar o parâmetro `cls(nome, idade_calculada)`. Isso criará e devolverá uma instância legítima de `Pessoa` por uma rota alternativa de dados.

### O Método Estático (`@staticmethod`) de Validação Pura
O sistema exige uma função para validar a maioridade do indivíduo.
* **Lógica Interna:** Como avaliar se alguém é maior de idade necessita apenas de uma comparação matemática simples (idade maior ou igual a 18), a função não precisa acessar dados do objeto (`self`) e nem da classe (`cls`). O método deve ser decorado como `@staticmethod`, recebendo uma idade numérica por parâmetro e retornando um texto descritivo ou valor booleano indicando se a pessoa é maior ou menor de idade.

---

## 3. Direcionamento dos Arquivos do Repositório

Os códigos com as implementações práticas completas e funcionais descritas nestes laboratórios estão salvos nesta mesma pasta e podem ser acessados nos seguintes arquivos:

* [015__Caso_de_Estudo_1.py](./015__Caso_de_Estudo_1.py): Contém o desenvolvimento do Cenário 1 (Classes `Livro` e `Biblioteca`), demonstrando na prática as rotinas de adicionar, remover e varrer a lista de objetos agregados.
* [015__Caso_de_Estudo_2.py](./015__Caso_de_Estudo_2.py): Contém o desenvolvimento do Cenário 2 (Classe `Pessoa`), demonstrando o funcionamento integrado do módulo `datetime` com as chamadas de fábrica via `@classmethod` e validação pura via `@staticmethod`.
