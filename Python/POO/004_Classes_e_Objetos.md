# Documentação de Estudos: Classes e Objetos em Programação Orientada a Objetos

As Classes e os Objetos formam a espinha dorsal do paradigma de Programação Orientada a Objetos (POO). Eles permitem agrupar dados e comportamentos em tipos de dados customizados e gerenciar como essas informações se relacionam diretamente na memória do computador.

---

## 1. Definição de Classe e Boas Práticas

Uma classe é uma declaração de tipo que encapsula constantes, variáveis (atributos) e métodos. Ela serve como o projeto ou molde estrutural para a criação de objetos.

### Regras de Organização do Sistema
* **Unicidade:** Cada classe deve ser única dentro de um sistema orientado a objetos.
* **Modularização:** Como boa prática de arquitetura, cada classe deve residir em seu próprio arquivo `.py`.
* **Nomenclatura:** O nome do arquivo deve ser idêntico ao nome da classe. Por exemplo, a classe `Conta` deve ser salva estritamente em um arquivo chamado `Conta.py`.

### A instrução `pass`
Quando queremos declarar a existência de uma classe ou método para definir seu corpo estrutural posteriormente, utilizamos a palavra reservada `pass`. Ela serve como um preenchedor de espaço (*placeholder*) que permite que o interpretador do Python execute o arquivo até o final sem disparar erros de indentação.

```python
# Arquivo: Conta.py
class Conta:
    pass  # Definição provisória da classe
```

---

## 2. O Processo de Construção: Construtores e o `self`

Embora o método `__init__` seja popularmente chamado de construtor por simplificação, o Python divide a criação de um objeto na memória RAM em duas etapas distintas:

1. **O Método `__new__`:** É o construtor real do ciclo de vida. Ele aloca o espaço físico na memória, cria a instância do objeto implicitamente e a devolve. É muito utilizado em cenários avançados, como frameworks e metaclasses.
2. **O Método `__init__`:** É o inicializador da classe. Ele recebe a instância recém-criada e atribui os valores iniciais aos atributos do objeto.

### O papel do parâmetro `self`
Como o objeto já foi instanciado pelo `__new__`, o `__init__` recebe automaticamente a referência desse espaço de memória através do parâmetro `self`. 

Usar `self.numero` ou `self.saldo` indica que estamos anexando essas variáveis diretamente ao corpo daquele objeto específico, definindo o seu **Estado**.

*Nota:* O método construtor não é obrigatório no Python. Ele só deve ser escrito se o objeto necessitar de inicialização ou atribuição de valores dinâmicos no momento do nascimento.

---

## 3. Métodos e Métodos com Retorno

Os métodos são as operações que manipulam os atributos e alteram o estado do objeto. Eles podem apenas executar uma ação ou retornar dados com base na análise do estado interno.

### Métodos de Manipulação de Estado (Sem Retorno)
```python
def depositar(self, valor):
    self.saldo += valor  # Modifica o estado somando o valor recebido
```

### Métodos de Validação de Regra de Negócio (Com Retorno)
É comum utilizar retornos booleanos (`True` ou `False`) para validar se uma operação é permitida pelo estado atual do objeto antes de efetivá-la.

```python
def sacar(self, valor):
    if self.saldo >= valor:
        self.saldo -= valor
        return True   # Saque permitido e executado
    else:
        return False  # Saldo insuficiente, operação rejeitada
```

> **Análise do Exercício da Aula:** Caso o objeto `c1` possua um saldo de 300 reais e o código execute o comando `c1.sacar(400)`, o teste da condição `if` falhará (300 não é maior ou igual a 400). O fluxo cairá no bloco `else`, fazendo com que o método retorne o valor booleano **`False`**, impedindo que a conta fique negativa.

---

## 4. Referências e Comportamento dos Objetos na Memória

Um sistema pode manter múltiplas instâncias de uma mesma classe coexistindo de forma independente na memória RAM.

### Comparação de Endereços vs Comparação de Valores
Quando criamos duas contas diferentes, elas recebem espaços físicos distintos na memória:
```python
conta1 = Conta(1, 123, 'Joao', 0)
conta2 = Conta(3, 456, 'Maria', 0)
```
* Os operadores de comparação `==` e `!=` analisam se as variáveis apontam para o **mesmo endereço de memória**, e não se os dados internos são parecidos.
* No cenário acima, a condição `if (conta1 !=2):` resultará em verdadeiro (`True`), pois elas residem em locais totalmente diferentes da memória.

### Atribuição de Referências
O operador de igualdade simples `=` realiza a cópia da posição da referência de memória, e não a cópia do objeto.

```python
conta1 = conta2
```
Ao fazer isso, a variável `conta1` deixa de apontar para o objeto original do João e passa a apontar exatamente para o mesmo endereço de memória da `conta2` (Maria). A partir desse momento, a expressão `if (conta1 == conta2):` retornará verdadeiro. Se você alterar o atributo de uma das variáveis (`conta1.cpf`), a mudança refletirá na outra (`conta2.cpf`), pois ambas manuseiam o mesmo objeto físico.

---

## 5. Implementação Completa da Classe `Conta`

O código abaixo consolida todas as frentes abordadas no material, incluindo o método de transferência, onde uma instância de um objeto é enviada diretamente como parâmetro para dentro do método de outra instância:

```python
# Arquivo: Conta.py

class Conta:
    # Método Inicializador (Tratado como o construtor do estado)
    # __init__ é o metodo construtor que cria o objeto da classe
    def __init__(self, numero, cpf, nome_titular, saldo_inicial=0.0):
        self.numero = numero
        self.cpf = cpf
        self.nome_titular = nome_titular
        self.saldo = saldo_inicial

    def depositar(self, valor):
        if valor > 0:
            self.saldo += valor
            print(f"Depósito de R\$ {valor} realizado na conta de {self.nome_titular}.")

    def sacar(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            return True
        else:
            return False

    # Interação entre objetos: Recebe outra instância de Conta no parâmetro 'destino'
    def transferir(self, conta_destino, valor):
        # Tenta realizar o saque da conta atual (self)
        if self.sacar(valor):
            # Se o saque der certo, deposita o valor na conta recebida por referência
            conta_destino.depositar(valor)
            print(f"Transferência de R\$ {valor} enviada com sucesso para {conta_destino.nome_titular}.")
            return True
        else:
            print("Transferência cancelada: Saldo insuficiente.")
            return False

    def exibir_extrato(self):
        print(f"Titular: {self.nome_titular} | Saldo Atual: R\$ {self.saldo}")


# --- Demonstração de Uso no Sistema ---
if __name__ == "__main__":
    # Instanciando dois objetos distintos em posições diferentes da memória
    conta1 = Conta(1, 123, 'Joao', 500.0)
    conta2 = Conta(3, 456, 'Maria', 100.0)

    # Executando a operação de transferência de um objeto para o outro
    conta1.transferir(conta2, 200.0)

    # Verificando os novos estados dos objetos
    conta1.exibir_extrato()  # Exibirá Saldo: 300.0
    conta2.exibir_extrato()  # Exibirá Saldo: 300.0
```
