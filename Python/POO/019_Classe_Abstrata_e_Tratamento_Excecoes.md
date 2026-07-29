# Documentação de Estudos: Classes Abstratas e Exceções Personalizadas

Este documento aborda a criação de modelos estruturais que não podem ser instanciados diretamente (Classes Abstratas) e o desenvolvimento de classes para o tratamento de erros específicos da lógica de negócios (Exceções Customizadas).

---

## 1. O Conceito de Classes Abstratas

Uma classe abstrata serve estritamente como um molde de categorias superiores para outras subclasses. Ela descreve um conceito abstrato do mundo real e, por essa razão, o sistema proíbe que ela seja instanciada diretamente na memória RAM.

### Cenário de Aplicação Bancária
Em um sistema de conta corrente, o banco não deseja criar objetos genéricos do tipo `ContaCliente`. O sistema exige apenas o processamento de contas concretas, como `ContaComum` ou `ContaVIP`. A classe `ContaCliente` atua apenas como uma superclasse abstrata para fornecer atributos e assinaturas comuns.

---

## 2. Implementação com o Módulo ABC e @abstractmethod

O Python não possui suporte nativo a classes abstratas em seu núcleo básico. Para converter uma classe comum em abstrata, importamos o módulo **`abc`** (Abstract Base Classes).

### Regras de Implementação
* A superclasse abstrata deve herdar obrigatoriamente da classe `ABC`.
* Para ser considerada abstrata, a classe deve possuir pelo menos um método decorado com `@abstractmethod`.
* **Subclasses Concretas:** As subclasses que herdam de uma classe abstrata são obrigadas a reescrever (implementar) todos os métodos abstratos da classe pai. Se esquecerem de implementar, o Python as considerará abstratas também e bloqueará sua instanciação.

```python
from abc import ABC, abstractmethod

class ContaCliente(ABC):
    def __init__(self, numero, saldo):
        self.numero = numero
        self.saldo = saldo

    # Assinatura obrigatória. As subclasses devem fornecer a lógica real.
    @abstractmethod
    def calculo_rendimento(self):
        pass

# --- Tentativa de Instanciação Direta ---
# Executar a linha abaixo gerará um erro do tipo TypeError:
# cc1 = ContaCliente(1, 1000)
```

---

## 3. Criação de Exceções Personalizadas

As exceções comuns da linguagem (`ValueError`, `ZeroDivisionError`, `IndexError`) tratam falhas técnicas do interpretador. Já as **Exceções Personalizadas** servem para capturar violações de regras de negócio específicas da sua aplicação.

### Como Criar uma Exceção Customizada
Toda exceção customizada deve herdar obrigatoriamente da classe base **`Exception`**. A utilização da instrução `pass` é suficiente, pois a diferenciação e identificação do erro ocorrem puramente pelo nome dado à classe.

```python
class SaldoInsuficienteError(Exception):
    # Classe vazia que serve apenas para rotular o erro de negócio
    pass
```

---

## 4. Disparando e Tratando Exceções com raise

Para acionar a sua exceção customizada em um momento específico do código quando uma regra for violada, utilizamos a instrução **`raise`** seguida da instância da sua classe de erro.

```python
import datetime

class ExcecaoCustomizada(Exception):
    pass

# Função que valida uma regra e dispara o erro se a condição for violada
def checa_valor(valor):
    if valor < 0:
        # A instrução raise interrompe a execução normal e lança o erro
        raise ExcecaoCustomizada("Erro: Não são permitidos valores negativos!")
    return valor

# --- Bloco de Captura com try...except ---
if __name__ == "__main__":
    try:
        # Força o disparo da exceção customizada enviando um valor inválido
        resultado = checa_valor(-50)
    except ExcecaoCustomizada as erro:
        # O bloco except captura a exceção e exibe a mensagem enviada pelo raise
        print(f"Tratamento de Erro Ativado: {erro}")
```

---

## 5. Exemplo Unificado: Classes Abstratas e Erros Customizados

O exemplo abaixo consolida todos os tópicos do módulo, unindo a estrutura abstrata da conta bancária com o disparo de uma exceção personalizada de segurança:

```python
from abc import ABC, abstractmethod

# 1. Definição da Exceção Customizada de Negócio
class ValorInvalidoError(Exception):
    pass

# 2. Definição da Classe Abstrata
class ContaCliente(ABC):
    def __init__(self, numero, saldo_inicial):
        self.numero = numero
        self.saldo = saldo_inicial

    @abstractmethod
    def calculo_rendimento(self):
        pass

# 3. Implementação da Subclasse Concreta obrigada a reescrever o método
class ContaComum(ContaCliente):
    def __init__(self, numero, saldo_inicial, taxa):
        super().__init__(numero, saldo_inicial)
        self.taxa = taxa

    def calculo_rendimento(self):
        # Implementação real do método abstrato
        self.saldo += self.saldo * self.taxa

    def depositar(self, valor):
        # Aplicação da Exceção Customizada com o comando raise
        if valor <= 0:
            raise ValorInvalidoError("O valor do depósito deve ser estritamente maior que zero.")
        self.saldo += valor

# --- Ambiente de Execução e Testes ---
if __name__ == "__main__":
    try:
        # Instanciando a classe concreta com sucesso
        minha_conta = ContaComum(numero=101, saldo_inicial=1000.0, taxa=0.05)
        
        # Tentativa de depósito inválido para forçar o acionamento do raise
        minha_conta.depositar(-500)
        
    except ValorInvalidoError as erro_negocio:
        print(f"Alerta de Negócio: {erro_negocio}")
        
    except Exception as erro_inesperado:
        print(f"Erro inesperado no sistema: {erro_inesperado}")
```
