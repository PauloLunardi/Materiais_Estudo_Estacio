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

## 4. Painel Completo de Conversão: Letras, Números e Controle

Abaixo está o mapeamento completo e detalhado de todos os caracteres alfanuméricos e comandos do sistema, contrastando a representação binária nativa do ASCII com o padrão internacional Unicode:

### 📁 A. Caracteres de Controle Não Imprimíveis (Hex 00 a 1F)

| Símbolo | Código ASCII (Binário) | Padrão Unicode | | Símbolo | Código ASCII (Binário) | Padrão Unicode |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **NUL** | `00000000` | `U+0000` | | **DLE** | `00010000` | `U+0010` |
| **SOH** | `00000001` | `U+0001` | | **DC1** | `00010001` | `U+0011` |
| **STX** | `00000010` | `U+0002` | | **DC2** | `00010010` | `U+0012` |
| **ETX** | `00000011` | `U+0003` | | **DC3** | `00010011` | `U+0013` |
| **EOT** | `00000010` | `U+0004` | | **DC4** | `00010100` | `U+0014` |
| **ENQ** | `00000101` | `U+0005` | | **NAK** | `00010101` | `U+0015` |
| **ACK** | `00000110` | `U+0006` | | **SYN** | `00010110` | `U+0016` |
| **BEL** | `00000111` | `U+0007` | | **ETB** | `00010111` | `U+0017` |
| **BS**  | `00001000` | `U+0008` | | **CAN** | `00011000` | `U+0018` |
| **HT**  | `00001001` | `U+0009` | | **EM**  | `00011001` | `U+0019` |
| **LF**  | `00001010` | `U+000A` | | **SUB** | `00011010` | `U+001A` |
| **VT**  | `00001011` | `U+000B` | | **ESC** | `00011011` | `U+001B` |
| **FF**  | `00001100` | `U+000C` | | **FS**  | `00011100` | `U+001C` |
| **CR**  | `00001101` | `U+000D` | | **GS**  | `00011101` | `U+001D` |
| **SO**  | `00001110` | `U+000E` | | **RS**  | `00011110` | `U+001E` |
| **SI**  | `00001111` | `U+000F` | | **US**  | `00011111` | `U+001F` |

---

### 📁 B. Algarismos Numéricos (0 a 9)

| Caractere | Código ASCII (Binário) | Padrão Unicode | | Caractere | Código ASCII (Binário) | Padrão Unicode |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | `00110000` | `U+0030` | | **5** | `00110101` | `U+0035` |
| **1** | `00110001` | `U+0031` | | **6** | `00110110` | `U+0036` |
| **2** | `00110010` | `U+0032` | | **7** | `00110111` | `U+0037` |
| **3** | `00110011` | `U+0033` | | **8** | `00111000` | `U+0038` |
| **4** | `00110100` | `U+0034` | | **9** | `00111001` | `U+0039` |

---

### 📁 C. Letras Maiúsculas (A a Z)

| Letra | Código ASCII (Binário) | Padrão Unicode | | Letra | Código ASCII (Binário) | Padrão Unicode |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **A** | `01000001` | `U+0041` | | **N** | `01001110` | `U+004E` |
| **B** | `01000010` | `U+0042` | | **O** | `01001111` | `U+004F` |
| **C** | `01000011` | `U+0043` | | **P** | `01010000` | `U+0050` |
| **D** | `01000100` | `U+0044` | | **Q** | `01010001` | `U+0051` |
| **E** | `01000101` | `U+0045` | | **R** | `01010010` | `U+0052` |
| **F** | `01000110` | `U+0046` | | **S** | `01010011` | `U+0053` |
| **G** | `01000111` | `U+0047` | | **T** | `01010100` | `U+0054` |
| **H** | `01001000` | `U+0048` | | **U** | `01010101` | `U+0055` |
| **I** | `01001001` | `U+0049` | | **V** | `01010110` | `U+0056` |
| **J** | `01001010` | `U+004A` | | **W** | `01010111` | `U+0057` |
| **K** | `01001011` | `U+004B` | | **X** | `01011000` | `U+0058` |
| **L** | `01001100` | `U+004C` | | **Y** | `01011001` | `U+0059` |
| **M** | `01001101` | `U+004D` | | **Z** | `01011010` | `U+005A` |

---

### 📁 D. Letras Minúsculas (a a z)

| Letra | Código ASCII (Binário) | Padrão Unicode | | Letra | Código ASCII (Binário) | Padrão Unicode |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **a** | `01100001` | `U+0061` | | **n** | `01101110` | `U+006E` |
| **b** | `01100010` | `U+0062` | | **o** | `01101111` | `U+006F` |
| **c** | `01100011` | `U+0063` | | **p** | `01110000` | `U+0070` |
| **d** | `01100100` | `U+0064` | | **q** | `01110001` | `U+0071` |
| **e** | `01100101` | `U+0065` | | **r** | `01110010` | `U+0072` |
| **f** | `01100110` | `U+0066` | | **s** | `01110011` | `U+0073` |
| **g** | `01100111` | `U+0067` | | **t** | `01110100` | `U+0074` |
| **h** | `01101000` | `U+0068` | | **u** | `01110101` | `U+0075` |
| **i** | `01101001` | `U+0069` | | **v** | `01110110` | `U+0076` |
| **j** | `01101010` | `U+007A` | | **w** | `01110111` | `U+0077` |
| **k** | `01101011` | `U+007B` | | **x** | `01111000` | `U+0078` |
| **l** | `01101100` | `U+007C` | | **y** | `01111001` | `U+0079` |
| **m** | `01101101` | `U+007D` | | **z** | `01111010` | `U+007A` |

> 💡 **Exemplo Prático de Codificação Completa:** 
> Ao processar a palavra **SABER**, a engine de hardware divide os caracteres gerando os seguintes pacotes de barramento de dados:
> *   `S` ➔ Binário: `01010011` | Unicode: `U+0053`
> *   `A` ➔ Binário: `01000001` | Unicode: `U+0041`
> *   `B` ➔ Binário: `01000010` | Unicode: `U+0042`
> *   `E` ➔ Binário: `01000101` | Unicode: `U+0045`
> *   `R` ➔ Binário: `01010010` | Unicode: `U+0052`


## 5. Evolução e Compatibilidade

A ausência de padronizações no passado gerava incompatibilidades frequentes entre programas e idiomas distintos, prejudicando a acessibilidade e a usabilidade. Profissionais da área de tecnologia, como programadores e webdesigners, devem manter o foco na compatibilidade de caracteres para assegurar a correta integridade e exibição dos sistemas desenvolvidos.
