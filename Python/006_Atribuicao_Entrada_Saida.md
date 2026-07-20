# Atribuição, Entrada e Saída de Dados na Prática em Python

## Introdução

Ao desenvolver programas em Python, três conceitos são fundamentais:

- **Atribuição de variáveis**
- **Entrada de dados**
- **Saída de dados**

Esses conceitos permitem armazenar informações, interagir com o usuário e apresentar resultados, formando a base para o desenvolvimento de programas mais complexos.

Neste exemplo, será desenvolvido um programa que calcula o valor total de um pedido em um restaurante.

---

# Atribuição de Variáveis

A atribuição consiste em armazenar um valor em uma variável utilizando o operador `=`.

## Sintaxe

```python
variavel = valor
```

### Exemplo

```python
preco_hamburguer = 18.50
preco_batata = 10.00
preco_refrigerante = 6.50
```

Nesse exemplo:

- `preco_hamburguer` armazena o valor do hambúrguer.
- `preco_batata` armazena o valor da batata frita.
- `preco_refrigerante` armazena o valor do refrigerante.

Essas variáveis serão utilizadas posteriormente para calcular o valor total do pedido.

---

# Entrada de Dados

A entrada de dados permite que o usuário informe valores durante a execução do programa.

Para isso, utiliza-se a função `input()`.

## Exemplo

```python
quant_hamburguer = int(input("Quantidade de hambúrgueres: "))
quant_batata = int(input("Quantidade de batatas: "))
quant_refrigerante = int(input("Quantidade de refrigerantes: "))
```

Como o usuário digita números inteiros, utiliza-se a função `int()` para converter o texto digitado para o tipo inteiro.

---

# Cálculo do Preço Total

Após receber as quantidades informadas pelo usuário, basta multiplicar cada quantidade pelo respectivo preço.

## Exemplo

```python
total = (
    preco_hamburguer * quant_hamburguer +
    preco_batata * quant_batata +
    preco_refrigerante * quant_refrigerante
)
```

O resultado será armazenado na variável `total`.

---

# Saída de Dados

Depois de realizar os cálculos, utiliza-se a função `print()` para exibir o resultado.

## Exemplo

```python
print(f"Total do pedido: R$ {total:.2f}")
```

O especificador `.2f` exibe o valor com duas casas decimais.

### Exemplo de saída

```
Total do pedido: R$ 53.50
```

---

# Programa Completo

```python
# Preço dos produtos
preco_hamburguer = 18.50
preco_batata = 10.00
preco_refrigerante = 6.50

# Entrada de dados
quant_hamburguer = int(input("Quantidade de hambúrgueres: "))
quant_batata = int(input("Quantidade de batatas: "))
quant_refrigerante = int(input("Quantidade de refrigerantes: "))

# Cálculo do total
total = (
    preco_hamburguer * quant_hamburguer +
    preco_batata * quant_batata +
    preco_refrigerante * quant_refrigerante
)

# Saída de dados
print(f"Total do pedido: R$ {total:.2f}")
```

---

# Exemplo de Execução

```
Quantidade de hambúrgueres: 2
Quantidade de batatas: 1
Quantidade de refrigerantes: 3

Total do pedido: R$ 66.50
```

---

# Explicação do Programa

1. São definidos os preços dos produtos.
2. O usuário informa a quantidade desejada de cada item.
3. O programa multiplica cada quantidade pelo preço correspondente.
4. Os valores são somados para obter o total do pedido.
5. O resultado é exibido na tela de forma formatada.

---

# Conceitos Utilizados

| Conceito | Descrição | Exemplo |
|----------|-----------|----------|
| Atribuição | Armazena valores em variáveis | `preco = 18.50` |
| Entrada de dados | Recebe informações do usuário | `input()` |
| Conversão de tipos | Converte texto para número | `int()`, `float()` |
| Operações matemáticas | Realiza cálculos | `+`, `*` |
| Saída de dados | Exibe resultados | `print()` |
| Formatação | Exibe valores formatados | `f"R$ {total:.2f}"` |

---

# Fluxo do Programa

```
Início
   │
   ▼
Definir preços dos produtos
   │
   ▼
Solicitar quantidades ao usuário
   │
   ▼
Converter as entradas para inteiro
   │
   ▼
Calcular o valor total
   │
   ▼
Exibir o resultado
   │
   ▼
Fim
```

---

# Boas Práticas

- Utilize nomes de variáveis claros e descritivos.
- Converta corretamente os valores recebidos pelo `input()`.
- Use **f-strings** para facilitar a formatação da saída.
- Organize o código em etapas (atribuição, entrada, processamento e saída).
- Teste o programa com diferentes valores para garantir que os cálculos estejam corretos.
