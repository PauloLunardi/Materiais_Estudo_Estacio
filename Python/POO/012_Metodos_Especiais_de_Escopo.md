# Documentação de Estudos: Métodos de Classe, Estáticos e Privados

Além dos métodos comuns de instância (que utilizam o parâmetro `self`), o Python oferece decoradores específicos para alterar o escopo de execução das funções e recursos para restringir o acesso a comportamentos internos.

---

## 1. Métodos de Classe (@classmethod)

Um método de classe é utilizado quando a operação precisa interagir com a classe como um todo (seus atributos de classe), e não com uma instância/objeto específico.

* **O parâmetro `cls`:** Em vez de receber `self`, ele recebe obrigatoriamente o parâmetro `cls` (abreviação de *Class*), que aponta diretamente para a classe contenedora.
* **Aplicação Prática:** É a melhor prática de mercado para criar métodos acessores (Getters) para variáveis de classe protegidas, mantendo o encapsulamento intacto.

```python
class Circulo:
    _total_circulos = 0  # Atributo de classe protegido

    def __init__(self, pontox, pontoy, raio):
        self.pontox = pontox
        self.pontoy = pontoy
        self.raio = raio
        # Usar type(self) obtém dinamicamente a referência da classe para incremento
        type(self)._total_circulos += 1

    # Método de Classe: Usado para ler o atributo protegido com segurança
    @classmethod
    def get_total_circulos(cls):
        return cls._total_circulos

# --- Uso no Sistema ---
circ1 = Circulo(1, 1, 10)
circ2 = Circulo(2, 2, 20)

# Chamamos o método direto pelo nome da Classe, sem precisar de um objeto
print(Circulo.get_total_circulos())  # Exibe: 2
```

---

## 2. Métodos Estáticos (@staticmethod)

Um método estático é uma função comum que não acessa e não modifica nenhuma propriedade da classe (`cls`) e nenhuma propriedade do objeto (`self`). 

* **Por que usá-lo?** Ele é colocado dentro da classe apenas por uma questão de organização lógica, agrupando funções utilitárias que possuem forte ligação conceitual com o tema daquela classe.
* **Exemplo Clássico:** Empacotamento de funções matemáticas puras.

```python
import math

class OperacoesMatematicas:
    # Método Estático: Não recebe self e nem cls. É uma função pura de processamento.
    @staticmethod
    def calcular_raiz(x):
        return math.sqrt(x)

# --- Uso no Sistema ---
# Não precisamos instanciar um objeto para usar uma função estática
resultado = OperacoesMatematicas.calcular_raiz(16)
print(resultado)  # Exibe: 4.0
```

---

## 3. Métodos Privados

Assim como aplicamos o encapsulamento em variáveis, podemos ocultar **comportamentos e funções auxiliares** que o mundo exterior não tem permissão para conhecer ou executar diretamente.

* **Sintaxe:** O nome do método deve ser iniciado com dois underscores (`__`).
* **Como funciona:** O interpretador aplica o Name Mangling na função. Ela só pode ser invocada por outros métodos de dentro da própria classe.

```python
class ContaEspecial:
    def __init__(self, numero, saldo):
        self.numero = numero
        self.saldo = saldo

    # Método Público: Pode ser chamado por qualquer arquivo do sistema
    def exibir_relatorio(self):
        # Chama internamente o método protegido
        self.__gerarsaldo()

    # Método Privado: Escondido do mundo exterior
    def __gerarsaldo(self):
        print(f"numero: {self.numero}\nsaldo: {self.saldo}")

# --- Uso no Sistema ---
conta = ContaEspecial(1001, 5000.0)

# O comando abaixo gerará um erro (AttributeError), pois o método está oculto
# conta.__gerarsaldo()

# O correto é acessar através da interface pública permitida
conta.exibir_relatorio()
```
