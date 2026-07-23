# 📦 Importação de Funções e Módulos em Python

## 🔍 1. O Núcleo da Linguagem vs Biblioteca Padrão

* **Núcleo do Python:** Contém funções nativas básicas que funcionam sem precisar de nenhuma importação (ex: `print()`, `input()`, `len()`, `int()`, `str()`). O núcleo é mantido pequeno propositalmente para que a linguagem seja leve e eficiente.
* **Biblioteca Padrão (Standard Library):** É um conjunto de milhares de funções, métodos e classes extras que vêm instalados junto com o Python. Eles são organizados em componentes chamados **Módulos**. Existem mais de 200 módulos nativos prontos para uso.

---

## 🛠️ 2. Como Importar e Usar um Módulo

Para utilizar os recursos de qualquer módulo da biblioteca padrão, o processo sempre segue **dois passos**:

### Passo 1: Importar o módulo desejado
```python
import nome_modulo
```

### Passo 2: Chamar a função desejada (precedida pelo nome do módulo)
```python
nome_modulo.nome_funcao(parametros)
```

### 💻 Exemplo Prático: Módulo `math`
Para calcular a raiz quadrada de um número, utilizamos a função `sqrt()` que pertence ao módulo matemático `math`:

```python
import math

# Chamamos a função usando a sintaxe: modulo.funcao()
raiz = math.sqrt(5)

print(f"A raiz quadrada de 5 é: {raiz}")
```

---

## 🗂️ 3. Principais Módulos Nativos do Python

Estes são os módulos mais comuns abordados no conteúdo e suas respectivas finalidades:

| Ícone | Módulo | Finalidade Principal |
| :---: | :--- | :--- |
| 🧮 | `math` | Operações matemáticas avançadas (raízes, trigonometria, etc). |
| 🎲 | `random` | Geração de números pseudoaleatórios e embaralhamento. |
| ✉️ | `smtplib` | Protocolo para conexões e envio de e-mails. |
| ⏱️ | `time` | Implementação de contadores de tempo e pausas no código. |
| 🖼️ | `tkinter` | Desenvolvimento de interfaces gráficas com o usuário (GUI). |

---

## 💡 4. Dica de Conceito: Classes e Objetos

A biblioteca padrão também é baseada no paradigma de **Programação Orientada a Objetos (POO)**. 
* **Classe:** Funciona como uma fábrica ou um molde blueprint.
* **Objeto:** É a instância real criada por essa fábrica.

> **Exemplo:** Uma classe chamada `Pessoa` possui os atributos vazios `nome` e `CPF`. Quando criamos uma pessoa real baseada nesse molde (ex: João da Silva, CPF 000.000.000-00), essa pessoa passa a ser um **Objeto**.
