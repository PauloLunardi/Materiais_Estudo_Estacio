# Conceito e Sintaxe de Importação

O núcleo da linguagem Python é mantido enxuto de forma proposital para garantir eficiência e leveza. Recursos extras são organizados em componentes chamados de Módulos (arquivos .py contendo funções e classes prontas). O conjunto de módulos nativos que já vem instalados com o Python é chamado de Biblioteca Padrão (Python Standard Library).

---

## 1. Abordagem de Importação Global (import)

Nesta abordagem, trazemos o módulo inteiro para o código. Para usar qualquer função, somos obrigados a usar o prefixo com o nome do módulo seguido de um ponto.

```python
import math

# Sintaxe: modulo.funcao()
resultado = math.sqrt(16)
print(resultado)
```

* Vantagem: Evita conflito de nomes se você tiver uma função própria com o mesmo nome da biblioteca.
* Desvantagem: Carrega o arquivo inteiro na memória do script.

---

## 2. Abordagem de Importação Específica (from ... import)

Nesta abordagem, extraímos apenas a função ou classe exata que precisamos de dentro do módulo. O uso do prefixo deixa de ser necessário.

```python
from math import sqrt

# Sintaxe: funcao() direta
resultado = sqrt(16)
print(resultado)
```

* Vantagem: Código mais limpo e direto nas linhas de execução.
* Desvantagem: Risco de conflito. Se você criar uma função chamada `def sqrt():` no mesmo arquivo, ela substituirá a função que foi importada do módulo.

---

## 3. O Uso de Apelidos (as)

É utilizado para encurtar nomes de módulos grandes ou evitar conflitos de nomenclatura de forma explícita.

```python
import tkinter as tk

janela = tk.Tk()
```

---

## 4. Por que evitar o uso do Asterisco (import *)

A instrução `from nome_modulo import *` importa absolutamente todas as funções invisíveis da biblioteca de uma só vez para o escopo global. 

Isso é considerado uma má prática de mercado porque:
* Polui a memória do sistema desnecessariamente.
* Torna o código perigoso devido ao alto risco de mascarar ou substituir funções nativas sem que você perceba.
