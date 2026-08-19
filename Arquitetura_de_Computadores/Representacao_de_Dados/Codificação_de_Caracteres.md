# Tabelas de Representação de Dados: Codificação de Caracteres

Este documento apresenta os conceitos fundamentais sobre como os sistemas computacionais convertem símbolos legíveis em padrões codificados de bits. Compreender os padrões **ASCII** e **Unicode** é essencial para garantir a compatibilidade e a correta exibição de textos.

---

## 1. Tipos Primitivos de Dados

Os dados de entrada são classificados em categorias primitivas básicas:

*   **Caractere:** Representa símbolos não numéricos (letras, pontuações), sendo o meio primário para introduzir texto.
*   **Lógico:** Representa valores booleanos de verdadeiro ou falso.
*   **Numérico:** Representa os números para operações matemáticas.

---

## 2. O Padrão ASCII

O *American Standard Code for Information Interchange* (ASCII) utiliza 7 bits por caractere, permitindo um total de 128 símbolos. Os códigos de `0` a `1F` (hexadecimal) funcionam como caracteres de controle não imprimíveis, enquanto o restante abrange letras maiúsculas, minúsculas, pontuações e símbolos matemáticos.

*Nota: As tabelas completas com os 128 caracteres e seus respectivos códigos de controle e valores hexadecimais podem ser consultadas diretamente no documento original referenciado.*

---

## 3. O Padrão Unicode

O ASCII atende bem ao inglês, mas apresenta limitações para outros idiomas, motivando a criação do Unicode. Este padrão internacional utiliza 16 bits por caractere, permitindo representar até 65.536 símbolos diferentes. Além de alfabetos globais, ele inclui símbolos monetários, formas geométricas e emojis.

---

## 4. Exemplo Prático de Conversão

Ao digitar a palavra **SABER** em letras maiúsculas, os caracteres são convertidos para ASCII (em formato binário) e para Unicode (em notação hexadecimal) conforme demonstrado abaixo:

| Caractere | S | A | B | E | R |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **ASCII** | `01010011` | `01000001` | `01000010` | `01000101` | `01010010` |
| **Unicode** | `U+0053` | `U+0041` | `U+0042` | `U+0045` | `U+0052` |

---

## 5. Evolução e Compatibilidade

A ausência de padronizações no passado gerava incompatibilidades frequentes entre programas e idiomas distintos, prejudicando a acessibilidade e a usabilidade. Profissionais da área de tecnologia, como programadores e webdesigners, devem manter o foco na compatibilidade de caracteres para assegurar a correta integridade e exibição dos sistemas desenvolvidos.
