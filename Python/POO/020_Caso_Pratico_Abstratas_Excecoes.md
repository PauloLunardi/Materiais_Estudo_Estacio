# Documentação Prática: Laboratórios de Classes Abstratas e Tratamento de Exceções

Este documento organiza as especificações técnicas e o passo a passo para a execução dos exercícios práticos envolvendo o uso de contratos estruturais abstratos e blindagem de código contra erros de entrada de dados.

---

## Bloco 1: Modelagem de Veículos (Classes Abstratas)

### Cenário 1
Criar um sistema de classes para modelar diferentes tipos de veículos, utilizando uma classe abstrata como base para definir a interface comum. Chamar os métodos mover() e ligar() em cada instância.

### Roteiro para o Cenário 1
1. Importe o módulo `abc` para o projeto (Abstract Base Classes).
2. Defina la classe abstrata Veiculo: Crie uma classe abstrata chamada Veiculo com os métodos abstratos `mover()` e `ligar()`.
3. Crie subclasses de Veículo: Implemente duas subclasses de Veículo chamadas `Carro` e `Bicicleta`. Cada subclasse deve fornecer implementações concretas para os métodos abstratos de acordo com o comportamento de cada veículo.
4. Teste as implementações: Crie instâncias de Carro e Bicicleta, chame os métodos `mover()` e `ligar()` em cada instância e verifique as saídas para garantir que funcionem conforme o esperado.

---

## Bloco 2: Operações Matemáticas Seguras (Tratamento de Exceções)

### Cenário 2
Criar uma classe chamada Calculadora que tenha métodos para realizar operações matemáticas básicas: adição, subtração, multiplicação e divisão. Implementar tratamento de exceções para evitar tipos de dados incorretos.

### Roteiro para o Cenário 2
1. Defina a classe Calculadora: Crie métodos para as operações de adição, subtração, multiplicação e divisão. Cada método deve conter o tratamento de exceções adequado para identificar tipos de dados incorretos enviados pelo usuário.
2. Teste as implementações: Crie instâncias da Classe Calculadora e chame os métodos para realizar as operações aritméticas comuns.
3. Forçar o erro de tipo: Passe valores inválidos (como strings contendo letras no lugar de números) para os métodos e valide se o tratamento de exceções impede que o programa trave.

---

## 3. Direcionamento dos Arquivos do Repositório

Os códigos funcionais baseados nas diretrizes e nos roteiros destes laboratórios estão disponíveis nos seguintes arquivos clicáveis:

* [020__Caso_de_Estudo_Veiculos.py](./020__Caso_de_Estudo_Veiculos.py): Contém o desenvolvimento completo do Bloco 1, demonstrando a herança a partir de uma classe base herdeira de `ABC` com decoradores de métodos abstratos.
* [020__Caso_de_Estudo_Calculadora.py](./020__Caso_de_Estudo_Calculadora.py): Contém o desenvolvimento completo do Bloco 2, aplicando blocos de captura de erro do tipo `TypeError` e `ZeroDivisionError` no processamento aritmético.
