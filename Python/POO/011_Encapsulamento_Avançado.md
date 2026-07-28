# Documentação de Estudos: Encapsulamento Avançado e Atributos de Classe

O encapsulamento e o uso de atributos de classe são mecanismos fundamentais para garantir a integridade dos dados e o controle centralizado de informações dentro de um sistema orientado a objetos.

---

## 1. O Objetivo do Encapsulamento

O encapsulamento proíbe a alteração indevida dos atributos (estado) de um objeto por agentes externos. Em sistemas comerciais, permitir o acesso direto a variáveis críticas gera vulnerabilidades nas regras de negócio.

### Cenário de Violação
Em uma classe `Conta`, se o sistema permitir a instrução direta `conta1.saldo = -200`, a regra de negócio do método `sacar()` (que proíbe saques maiores que o saldo disponível) é completamente burlada, deixando o objeto em um estado inválido. O encapsulamento resolve isso reunindo dados e funções em uma única entidade protetora.

---

## 2. Atributos Privados e o Mecanismo Name Mangling

Por padrão, todos os atributos em Python são públicos. Para tornar um atributo privado, modificando sua visibilidade, o nome da variável deve ser iniciado com dois underscores (`__`).

### O Comportamento do Interpretador
Se um programa tentar acessar diretamente `print(conta1.__saldo)`, o interpretador disparará um erro informando que o atributo não existe. 

Na realidade, o Python não bloqueia o acesso de forma física e rígida, mas aplica um mecanismo chamado **Name Mangling** (Desfiguração de Nome). Internamente, o interpretador renomeia o atributo privado seguindo o padrão:
`_NomeDaClasse__NomeDoAtributo`

Portanto, a instrução abaixo funcionaria tecnicamente:
```python
print(conta1._Conta__saldo)
```

### Boa Prática de Mercado
Embora o acesso via Name Mangling seja possível, ele viola diretamente o princípio de encapsulamento. Deve haver disciplina por parte do desenvolvedor para que atributos iniciados com `__` ou `_` nunca sejam invocados fora do escopo da própria classe.

---

## 3. Controle de Acesso com o Decorador @property

As *properties* são a estratégia oficial do Python para ler e modificar atributos privados de forma controlada através de métodos acessores, sem perder a sintaxe limpa de acesso direto.

* **O Getter (`@property`):** Transforma um método de leitura em uma propriedade. Permite que o mundo exterior consulte o valor do atributo privado como se fosse uma variável comum.
* **O Setter (`@<nome_do_metodo>.setter`):** Intercepta qualquer tentativa de alteração de valor. É dentro do *setter* que injetamos as validações e regras de negócio.

### Regra de Ouro para Getters e Setters
De acordo com as boas práticas universais de POO, só devemos criar métodos *properties* (Getters/Setters) para um atributo se houver uma regra de negócio ou validação associada a ele. Caso o atributo não necessite de travas, ele deve permanecer público para poupar linhas de código e processamento desnecessários.

```python
class Conta:
    def __init__(self, titular, saldo_inicial):
        self.titular = titular
        self.__saldo = saldo_inicial  # Atributo privado

    # Método Getter: Permite ler o saldo de forma controlada
    @property
    def saldo(self):
        return self.__saldo

    # Método Setter: Valida a regra de negócio antes de alterar o estado
    @saldo.setter
    def saldo(self, novo_valor):
        if novo_valor >= 0:
            self.__saldo = novo_valor
        else:
            print("Erro: O saldo não pode receber valores negativos!")
```

---

## 4. Atributos de Classe (Variáveis Centrais)

Existem situações em que o sistema precisa rastrear e controlar valores que pertencem à **classe como um todo**, e não a cada objeto individualmente.

* **Atributo de Instância:** Cada objeto tem o seu próprio valor isolado (ex: cada conta tem o seu saldo).
* **Atributo de Classe:** Declarado diretamente no corpo da classe, antes do método `__init__`. Todas as instâncias criadas compartilham exatamente o mesmo endereço e valor desse atributo. Se uma instância alterar a variável de classe, a mudança se reflete instantaneamente em todas as outras.

### Aplicação Prática: Contador de Instâncias
Um exemplo clássico é um contador para monitorar quantos objetos foram criados na tela do sistema (como um aplicativo gráfico que conta o total de círculos desenhados).

```python
class Circulo:
    # Atributo de Classe: Inicializa o contador global na memória
    total_circulos = 0

    def __init__(self, raio):
        self.raio = raio  # Atributo de instância
        # Incrementa o contador central da classe a cada nova instanciação
        Circulo.total_circulos += 1
```

Se criarmos `circ1 = Circulo(5)` e `circ2 = Circulo(10)`:
* Acessar `circ1.total_circulos`, `circ2.total_circulos` ou `Circulo.total_circulos` retornará o valor **2**, pois todos apontam para o mesmo registro centralizado.

---

## 5. Encapsulamento de Atributos de Classe

Seguindo as convenções estritas de segurança, expor um atributo de classe de forma pública (`Circulo.total_circulos`) não é o ideal, pois qualquer parte do código poderia resetar o contador maliciosamente fazendo `Circulo.total_circulos = 0`.

Para proteger o registro centralizado, aplicamos o encapsulamento também na variável de classe, marcando-a como protegida ou privada através do uso de sublinhados (`_total_circulos`), restringindo sua manipulação direta fora do escopo da classe.
