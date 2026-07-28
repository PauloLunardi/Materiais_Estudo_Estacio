# Tabela Comparativa: Níveis de Visibilidade e Modificadores de Acesso em Python

Embora linguagens tradicionais como Java e C++ possuam palavras-chave rígidas (`public`, `protected`, `private`) para bloquear o acesso a códigos, o Python adota uma filosofia baseada em convenções de nomenclatura (prefixos de sublinhado) e desfiguração de nomes em tempo de execução.

---

## 1. Tabela Geral de Comparação

A tabela abaixo resume os quatro níveis de visibilidade existentes no ecossistema de desenvolvimento Python:

| Nível de Visibilidade | Prefixo no Nome | Exemplo de Sintaxe | Acesso Externo Direto? | Comportamento do Interpretador / Objetivo |
| :--- | :--- | :--- | :---: | :--- |
| **Público** | Nenhum | `def calcular()` | **Sim** | É o padrão da linguagem. Fica visível e disponível para qualquer arquivo do sistema. |
| **Protegido** | Um sublinhado (`_`) | `def _validar()` | **Sim** *(Por risco do dev)* | Funciona como um aviso visual de que o método é interno e só deve ser usado pela própria classe ou subclasses. O Python não bloqueia o acesso físico. |
| **Privado** (Fortemente Privado) | Dois underscores (`__`) | `def __processar()` | **Não** *(Bloqueio nativo)* | O Python aplica o *Name Mangling* (Desfiguração de Nome) na memória, impedindo que o método seja chamado diretamente pelo nome original fora da classe. |
| **Especial / Mágico** (Dunder) | Dois underscores no início e fim | `def __init__()` | **Sim** | São métodos do núcleo do Python (Double Underscore). Nunca crie métodos próprios com essa sintaxe; ela é exclusiva para recursos internos da linguagem. |

---

## 2. Detalhamento dos Comportamentos na Prática

### Métodos Públicos
Representam a interface de comunicação do seu objeto com o resto do sistema. Eles não possuem nenhuma marcação no nome.
```python
class Exemplo:
    def executar_operacao(self):
        print("Qualquer arquivo do sistema pode me chamar.")
```

### Métodos Protegidos
Seguem a filosofia Python de que *"somos todos adultos aqui"*. O interpretador não cria nenhuma trava técnica na memória. A proteção depende da disciplina da equipe de desenvolvimento em respeitar o sublinhado inicial.
```python
class Exemplo:
    def _limpar_dados_temporarios(self):
        print("Eu sou um método interno. Evite me chamar de fora desta classe.")
```

### Métodos Privados (Fortemente Privados)
Quando o Python encontra dois underscores iniciais (e nenhum no final), ele altera o endereço do método na tabela de símbolos da memória para `_NomeDaClasse__nome_do_metodo`. Isso quebra chamadas externas diretas e protege algoritmos críticos.
```python
class Exemplo:
    def __gerar_chave_criptografica(self):
        print("Método estritamente oculto do mundo exterior.")
```

---

## 3. Exemplo Prático de Execução

O script abaixo consolida a aplicação de todos os níveis e demonstra o erro gerado pelo interpretador ao tentar violar uma restrição fortemente privada:

```python
class CaixaEletronico:
    def __init__(self):
        self.ligado = True

    # 1. MÉTODO PÚBLICO: Interface que o usuário interage diretamente
    def solicitar_saque(self, valor):
        print(f"Iniciando solicitação de saque no valor de R\$ {valor}")
        # Métodos públicos gerenciam o fluxo chamando os métodos internos seguros
        if self._verificar_conexao_rede():
            self.__contar_cedulas(valor)

    # 2. MÉTODO PROTEGIDO: Operação interna compartilhada com sistemas parceiros
    def _verificar_conexao_rede(self):
        print("Checando sinal com o servidor central...")
        return True

    # 3. MÉTODO PRIVADO (FORTEMENTE PRIVADO): Mecanismo crítico de hardware
    def __contar_cedulas(self, valor):
        print(f"Dispensando R\$ {valor} físicos pelas engrenagens.")

# --- Cenário de Teste de Acesso ---
if __name__ == "__main__":
    caixa = CaixaEletronico()

    # Acesso Público: Funciona perfeitamente
    caixa.solicitar_saque(100)

    # Acesso Protegido: Funciona, mas o editor (IDE) emitirá um alerta de boa prática
    caixa._verificar_conexao_rede()

    # Acesso Privado Direto: Vai disparar um erro de atributo (AttributeError)
    # O Python dirá que '__contar_cedulas' não existe neste objeto
    try:
        caixa.__contar_cedulas(100)
    except AttributeError as erro:
        print(f"Bloqueio de segurança ativado com sucesso: {erro}")

    # Burlar o encapsulamento via Name Mangling (Prática proibida no mercado):
    caixa._CaixaEletronico__contar_cedulas(100)
```
