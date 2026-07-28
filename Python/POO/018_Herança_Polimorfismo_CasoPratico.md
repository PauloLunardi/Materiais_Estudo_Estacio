# Documentação Prática: Laboratório de Herança e Polimorfismo Avançado

Este documento apresenta as especificações técnicas, a hierarquia de herança (simples e múltipla) e a dinâmica de polimorfismo para a criação do sistema de simulação de animais.

---

## Bloco 1: Estrutura das Classes (Herança Simples e Múltipla)

### Cenário do Exercício
Desenvolver um ecossistema de classes que modele diferentes tipos de animais e suas respectivas habilidades de movimentação e vocalização, exercitando o reaproveitamento de código e as assinaturas comuns de métodos.

### Classe Base: Animal
* **Atributo do Construtor:** `nome` (str).
* **Método `falar(self)`:** Assinatura abstrata que deve ser obrigatoriamente sobrescrita pelas subclasses.
* **Método `mover(self)`:** Assinatura abstrata que deve ser obrigatoriamente sobrescrita pelas subclasses.

### Subclasses de Herança Simples
As seguintes classes devem herdar diretamente de `Animal` e implementar seus próprios comportamentos para `falar` e `mover`:
* **Classe Cachorro**
* **Classe Gato**
* **Classe Vaca**

### Classes de Habilidades (Mixins)
Classes independentes criadas para injetar capacidades de movimentação específicas em outras estruturas:
* **Classe Voador:** Deve conter comportamentos ligados ao voo.
* **Classe Nadador:** Deve conter comportamentos ligados ao nado.

### Subclasse de Herança Múltipla: Pato
A classe `Pato` deve possuir uma estrutura de herança múltipla, herdando simultaneamente das seguintes classes:
* `Animal`, `Voador` e `Nadador`.
* **Comportamentos:** Deve implementar suas versões de `falar()` e `mover()`, além de possuir um método exclusivo chamado `andar()`.

---

## Bloco 2: Funções Polimórficas (Mecanismo de Teste)

Para validar o polimorfismo do sistema em tempo de execução, devem ser criadas duas funções globais isoladas (fora de qualquer classe):

* **Função `fazer_som(animal_objeto)`:** Aceita qualquer objeto que herde de `Animal` e invoca o método `.falar()`.
* **Função `fazer_movimento(animal_objeto)`:** Aceita qualquer objeto que herde de `Animal` e invoca o método `.mover()`.

O polimorfismo garantirá que o Python chame a ação correta dependendo da instância (Cachorro, Gato, Vaca ou Pato) que for passada como argumento para essas funções.

---

## Roteiro de Prática para Implementação

1. Defina a classe base `Animal` configurando o construtor com o nome.
2. Crie as subclasses `Cachorro`, `Gato` e `Vaca` sobrescrevendo as funções de som e movimento de cada um.
3. Desenvolva as classes de habilidade `Voador` e `Nadador`.
4. Monte a classe `Pato` herdando das três frentes (Animal, Voador, Nadador) e adicione o método `andar`.
5. Escreva as funções globais `fazer_som` e `fazer_movimento`.
6. Isole a área de testes com a trava de segurança comercial.
7. Instancie um objeto de cada bicho e passe as referências para as duas funções globais para verificar as respostas no terminal.

---

## Direcionamento dos Arquivos do Repositório

O código funcional baseado nas diretrizes e no roteiro deste laboratório está disponível no seguinte link clicável:

* [016__Caso_de_Estudo_Animais.py](./016__Caso_de_Estudo_Animais.py): Implementação prática completa contendo a árvore de herança simples, herança múltipla do Pato e os testes polimórficos de simulação.
