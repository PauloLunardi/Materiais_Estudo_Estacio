# Documentação de Estudos: Encapsulamento em Programação Orientada a Objetos

O Encapsulamento é um dos pilares fundamentais da Programação Orientada a Objetos (POO). Ele consiste no isolamento de propriedades e comportamentos internos de um objeto, ocultando os detalhes de implementação do mundo exterior e protegendo a integridade dos dados.

---

## 1. Princípios do Encapsulamento

O encapsulamento baseia-se em fundamentos que ditam como as classes devem proteger e gerenciar seus próprios estados e comportamentos:

* **Privacidade dos Dados:** Restringe o acesso direto aos dados internos do objeto, impedindo que o estado de um componente seja modificado por agentes externos sem controle.
* **Métodos Acessores (Getters e Setters):** São os métodos públicos responsáveis por intermediar a leitura e a escrita dos atributos privados de forma controlada.
* **Ocultação da Implementação:** Esconde o funcionamento interno e os algoritmos da classe. O mundo exterior precisa saber apenas o que o objeto faz (sua interface pública), e não como ele faz internamente.
* **Facilidade de Manutenção:** Como as regras de negócio ficam centralizadas dentro da própria classe, qualquer alteração futura exige modificações apenas no código interno do objeto, sem quebrar o restante do sistema.
* **Segurança e Integridade dos Dados:** Garante que o objeto passe por validações rigorosas antes de aceitar novos valores, bloqueando estados inválidos ou corrupção de dados.

---

## 2. Modificadores de Acesso (Teoria Geral vs Python)

Na maioria das linguagens orientadas a objetos, existem três níveis de visibilidade para os atributos e métodos:

* Public (Público): Pode ser acessado de qualquer lugar do sistema.
* Protected (Protegido): Pode ser acessado apenas pela própria classe e por suas classes filhas (herança).
* Private (Privado): Pode ser acessado única e exclusivamente de dentro da própria classe.

No Python, esses modificadores não existem como palavras-chave rígidas do sistema. A linguagem adota uma convenção de nomenclatura baseada em sublinhados (_) no início dos nomes das variáveis para definir o nível de acesso.

---

## 3. Implementação do Encapsulamento em Python

### Atributos Públicos
Por padrão, qualquer atributo criado no construtor do Python é público.
```python
class ContaBancaria:
    def __init__(self, titular, saldo):
        self.titular = titular  # Público
        self.saldo = saldo      # Público
```
Qualquer parte do código pode fazer `conta.saldo = -500`, o que violaria a segurança e a integridade dos dados do sistema.

### Atributos Protegidos (Convenção)
Utiliza-se um único sublinhado `_` antes do nome do atributo. Isso avisa a outros programadores que o atributo não deve ser acessado diretamente fora da classe ou de suas subclasses, embora o Python tecnicamente ainda permita o acesso.
```python
class ContaBancaria:
    def __init__(self, titular, saldo):
        self._titular = titular  # Protegido
```

### Atributos Privados (Name Mangling)
Utiliza-se dois sublinhados `__` antes do nome do atributo para atingir a privacidade dos dados. O Python bloqueia o acesso direto externo alterando internamente o nome do atributo na memória (processo chamado de Name Mangling).
```python
class ContaBancaria:
    def __init__(self, titular, saldo):
        self.__saldo = saldo  # Privado
```
Se você tentar executar `print(conta.__saldo)` fora da classe, o programa disparará um erro de atributo (`AttributeError`), garantindo a ocultação da implementação.

---

## 4. Métodos Modificadores na Prática: Getters e Setters

Para permitir que o mundo exterior interaja com um atributo privado com segurança, criamos métodos específicos de leitura (Get) e escrita (Set). No Python moderno, isso é feito através do decorador `@property`.

```python
class ContaBancaria:
    def __init__(self, titular, saldo_inicial):
        self.titular = titular
        self.__saldo = saldo_inicial  # Atributo estritamente privado

    # Getter: Método acessor que permite ler o saldo com segurança
    @property
    def saldo(self):
        return self.__saldo

    # Setter: Método acessor que permite alterar o saldo validando sua integridade
    @saldo.setter
    def saldo(self, novo_valor):
        if novo_valor >= 0:
            self.__saldo = novo_valor
        else:
            print("Erro: O saldo não pode ser negativo!")

# --- Aplicação Prática ---
if __name__ == "__main__":
    conta = ContaBancaria("João", 1000.0)
    
    # Acesso via Getter (a leitura passa pela função protetora)
    print(f"Saldo atual: {conta.saldo}")
    
    # Tentativa de alteração inválida (será bloqueada pelo Setter para manter a integridade)
    conta.saldo = -200.0
    
    # Alteração válida (será aceita com sucesso)
    conta.saldo = 1200.0
    print(f"Novo saldo: {conta.saldo}")
```
