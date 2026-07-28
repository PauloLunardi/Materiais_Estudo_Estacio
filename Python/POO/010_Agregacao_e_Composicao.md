# Documentação de Estudos: Associação Entre Objetos - Agregação e Composição

A associação entre objetos permite que instâncias de diferentes classes colaborem entre si. Em vez de criar classes gigantescas com todas as funções centralizadas, dividimos as responsabilidades em componentes menores e interconectados que conversam entre si na memória RAM.

---

## 1. O Conceito de Agregação (Relação Fraca)

A agregação é uma relação conceitual onde uma classe contém instâncias de outra classe, mas não possui a posse total delas. Os objetos agregados existem de forma independente e podem sobreviver mesmo se a classe principal (contenedora) for destruída.

No diagrama de classes, esse relacionamento é representado graficamente por um losango vazado.

### Características da Agregação
* **Independência:** O objeto contido existe antes e continua existindo depois da destruição do objeto contenedor.
* **Semântica:** Uma classe "tem um" ou "contém" uma lista de outros objetos independentes.
* **Exemplo Clássico:** Uma `Conta` conjunta agrega um ou vários objetos do tipo `Cliente`. Se a conta bancária for encerrada no sistema, as entidades físicas dos clientes continuam cadastradas no banco de dados independentemente.

---

## 2. O Conceito de Composição (Relação Forte)

A composição é uma relação de dependência existencial estrita e profunda. A classe contenedora é dona exclusiva das instâncias que ela carrega, controlando totalmente o ciclo de vida delas.

No diagrama de classes, esse relacionamento é representado graficamente por um losango preenchido (sólido).

### Características da Composição
* **Dependência de Vida:** Se o objeto pai for destruído, todos os objetos que o compõem são eliminados da memória simultaneamente. Eles não possuem vida útil isolada.
* **Sintaxe de Instanciação:** O objeto composto é criado obrigatoriamente dentro do próprio construtor (`__init__`) da classe pai, em vez de ser recebido pronto por parâmetro.
* **Exemplo Clássico:** Uma `Conta` é composta por um histórico de `Extrato`. O extrato não faz sentido e não pode existir no sistema se não estiver vinculado rigidamente a uma conta real. Se apagarmos a conta, o extrato some junto.

---

## 3. Implementação Prática: Agregação de Clientes

Neste cenário, a classe `Conta` recebe uma lista contendo instâncias de objetos `Cliente` criados previamente fora dela.

```python
# Arquivo: Cliente.py
class Cliente:
    def __init__(self, cpf, nome, endereco):
        self.cpf = cpf
        self.nome = nome
        self.endereco = endereco

# Arquivo: Conta.py
class Conta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes  # Recebe a lista de objetos Cliente (Agregação)
        self.numero = numero
        self.saldo = saldo

    def gerarsaldo(self):
        print(f"Número: {self.numero}\nSaldo: {self.saldo}")
```

### Análise de Execução e Resolução do Desafio da Aula
No script de teste abaixo, é instanciada uma conta iniciando com saldo `0` agregando dois clientes. Respondendo às perguntas do material:
* **Resultado da conta matemática:** O saldo inicia em 0, recebe um depósito de 1500 (saldo vai para 1500) e sofre um saque de 500. O valor final impresso em tela será de **1000**.
* **Resolução do Desafio (Varredura de Objetos Agregados):** Para acessar os dados de objetos guardados dentro de uma lista interna, usamos um laço `for` navegando pelo atributo `self.clientes` e acessando as propriedades de cada instância via notação de ponto (`.nome` e `.endereco`).

```python
# Arquivo: testecontas.py
from Cliente import Cliente
from Conta import Conta

cliente1 = Cliente(123, "Joao", "Rua 1")
cliente2 = Cliente(345, "Maria", "Rua 2")

# Os objetos cliente1 e cliente2 são criados fora e passados dentro de uma lista
conta1 = Conta([cliente1, cliente2], 1, 0)

conta1.gerarsaldo()   # Exibe: 0
conta1.depositar(1500)
conta1.sacar(500)
conta1.gerarsaldo()   # Exibe: 1000

# RESOLUÇÃO DO DESAFIO: Acessando atributos dos objetos agregados
print("\n--- Clientes Vinculados a esta Conta ---")
for c in conta1.clientes:
    print(f"Nome do Titular: {c.nome} | Endereço: {c.endereco}")
```

---

## 4. Implementação Prática: Composição com Extrato

Para registrar as transações, criamos a classe `Extrato` e embutimos o nascimento dela diretamente na criação da `Conta`.

```python
# Arquivo: Extrato.py
class Extrato:
    def __init__(self):
        self.transacoes = []  # Armazenará sublistas com os dados de cada operação

    def extrato(self, numeroconta):
        print(f"--- Extrato da Conta: {numeroconta} ---")
        for p in self.transacoes:
            # Imprime as informações formatando os espaços de exibição
            print(f"{p[0]:15s} {p[1]:10.2f} {p[2]:10s} {p[3].strftime('%d/%b/%y')}")
```

### Acoplamento na Classe Conta
Note como a linha do `self.extrato = Extrato()` cria a dependência de composição, e os métodos usam o caminho do atributo para empurrar dados para a lista interna do objeto composto.

```python
# Arquivo: ContaComposta.py
import datetime
from Extrato import Extrato

class ContaComposta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo
        self.dataabertura = datetime.datetime.today()
        # COMPOSIÇÃO: O objeto Extrato nasce aqui dentro. Se a conta morrer, ele morre.
        self.extrato = Extrato()

    def depositar(self, valor):
        self.saldo += valor
        # Alimenta a lista interna acessando o caminho do objeto composto
        self.extrato.transacoes.append(["DEPOSITO", valor, "Data", datetime.datetime.today()])

    def sacar(self, valor):
        if self.saldo < valor:
            return False
        else:
            self.saldo -= valor
            self.extrato.transacoes.append(["SAQUE", valor, "Data", datetime.datetime.today()])
            return True
```

---

## 5. Resumo Comparativo para Revisão

* **Na Agregação:** As partes (Clientes) são independentes do todo (Conta). A criação dos objetos acontece fora da classe receptora.
* **Na Composição:** As partes (Extrato) pertencem exclusivamente ao todo (Conta). A criação do objeto é interna e dependente, garantindo a integridade histórica de logs do sistema.
