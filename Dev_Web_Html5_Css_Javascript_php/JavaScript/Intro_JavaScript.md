# JavaScript - Introdução

## Motivação

O JavaScript é uma das principais linguagens utilizadas no desenvolvimento web moderno.

Enquanto o HTML é responsável pela estrutura de uma página e o CSS pela apresentação visual, o JavaScript adiciona comportamento, interatividade e dinamismo às aplicações.

Com JavaScript é possível responder às ações do usuário, validar formulários, manipular conteúdos da página, realizar requisições para servidores e desenvolver aplicações completas tanto no navegador quanto no backend.

---

# O que é JavaScript?

JavaScript é uma linguagem de programação interpretada, orientada a objetos e baseada em eventos.

Sua principal finalidade é tornar páginas web interativas e dinâmicas.

Atualmente, além do navegador, também pode ser executado em ambientes externos através do Node.js.

---

# Onde o JavaScript pode ser utilizado?

## Front-end

Executado diretamente no navegador para manipulação da interface do usuário.

Exemplos:

* Validação de formulários
* Menus interativos
* Animações
* Atualização dinâmica de conteúdo
* Manipulação de elementos HTML

---

## Back-end

Utilizado através do Node.js para desenvolvimento de servidores e APIs.

Exemplos:

* APIs REST
* Sistemas web
* Integração com bancos de dados
* Microsserviços

---

## Aplicações Desktop

Por meio de frameworks específicos.

Exemplos:

* Electron
* Tauri

---

## Aplicações Mobile

Utilizando frameworks como:

* React Native
* Ionic

---

# Como inserir JavaScript em uma página?

## Código Interno

Inserido através da tag:

```html
<script>
  console.log("Olá Mundo");
</script>
```

---

## Arquivo Externo

Permite organizar melhor o projeto.

```html
<script src="script.js"></script>
```

---

# Variáveis

As variáveis são utilizadas para armazenar informações durante a execução do programa.

## let

Permite alterar o valor posteriormente.

```javascript
let nome = "Paulo";
```

---

## const

Cria uma constante.

```javascript
const PI = 3.14159;
```

---

## var

Forma antiga de declaração.

```javascript
var idade = 30;
```

Atualmente recomenda-se utilizar:

* let
* const

---

# Tipos de Dados

## String

Representa textos.

```javascript
let nome = "Paulo";
```

---

## Number

Representa números inteiros ou decimais.

```javascript
let idade = 25;
let altura = 1.80;
```

---

## Boolean

Representa valores lógicos.

```javascript
let ativo = true;
```

---

## Null

Representa ausência intencional de valor.

```javascript
let usuario = null;
```

---

## Undefined

Valor não definido.

```javascript
let resultado;
```

---

## Object

Estrutura composta por propriedades.

```javascript
let pessoa = {
  nome: "Paulo",
  idade: 25
};
```

---

## Array

Estrutura para armazenar múltiplos valores.

```javascript
let linguagens = ["HTML", "CSS", "JavaScript"];
```

---

# Operadores

## Aritméticos

```javascript
+
-
*
/
%
**
```

---

## Comparação

```javascript
==
===
!=
!==
>
<
>=
<=
```

---

## Lógicos

```javascript
&&
||
!
```

---

# Estruturas Condicionais

Permitem tomar decisões durante a execução.

## if

```javascript
if (idade >= 18) {
  console.log("Maior de idade");
}
```

---

## if / else

```javascript
if (idade >= 18) {
  console.log("Maior de idade");
} else {
  console.log("Menor de idade");
}
```

---

## switch

Utilizado para múltiplas condições.

```javascript
switch(dia) {
  case 1:
    console.log("Domingo");
    break;
}
```

---

# Estruturas de Repetição

## for

```javascript
for(let i = 0; i < 5; i++) {
  console.log(i);
}
```

---

## while

```javascript
while(contador < 5) {
  contador++;
}
```

---

## do...while

```javascript
do {
  contador++;
} while(contador < 5);
```

---

# Funções

Funções agrupam instruções reutilizáveis.

## Função Tradicional

```javascript
function saudacao() {
  console.log("Olá");
}
```

---

## Função com Parâmetros

```javascript
function soma(a, b) {
  return a + b;
}
```

---

## Arrow Function

Introduzida no ES6.

```javascript
const soma = (a, b) => {
  return a + b;
};
```

---

# Manipulação do DOM

DOM (Document Object Model) representa os elementos HTML da página.

Permite acessar e modificar conteúdos dinamicamente.

## Selecionar Elementos

```javascript
document.getElementById("titulo");
```

```javascript
document.querySelector(".classe");
```

---

## Alterar Conteúdo

```javascript
elemento.innerHTML = "Novo conteúdo";
```

---

## Alterar Estilos

```javascript
elemento.style.color = "blue";
```

---

# Eventos

Eventos permitem capturar ações do usuário.

Exemplos:

* Clique
* Teclado
* Mouse
* Envio de formulário

---

## Evento de Clique

```javascript
botao.addEventListener("click", function() {
  alert("Botão clicado");
});
```

---

# Arrays

Estruturas utilizadas para armazenar coleções de dados.

```javascript
let frutas = ["Maçã", "Banana", "Uva"];
```

Métodos importantes:

```javascript
push()
pop()
shift()
unshift()
length
```

---

# Objetos

Permitem representar entidades do mundo real.

```javascript
let pessoa = {
  nome: "Paulo",
  idade: 25,
  profissao: "Consultor SAP"
};
```

---

# JSON

Formato utilizado para troca de informações entre sistemas.

Exemplo:

```json
{
  "nome": "Paulo",
  "idade": 25
}
```

---

# Conceitos Modernos (ES6+)

## Template Strings

```javascript
let nome = "Paulo";

console.log(`Olá ${nome}`);
```

---

## Desestruturação

```javascript
const { nome, idade } = pessoa;
```

---

## Spread Operator

```javascript
const copia = [...array];
```

---

## Módulos

Permitem dividir aplicações em arquivos menores.

```javascript
export
import
```

---

# Assuntos Importantes para Estudos Futuros

* DOM
* Eventos
* Funções
* Arrays
* Objetos
* JSON
* ES6+
* Fetch API
* Promises
* Async/Await
* Local Storage
* Node.js
* APIs REST

---

# Conceitos Praticados

✔ JavaScript

✔ Variáveis

✔ Tipos de Dados

✔ Operadores

✔ Estruturas Condicionais

✔ Estruturas de Repetição

✔ Funções

✔ DOM

✔ Eventos

✔ Arrays

✔ Objetos

✔ JSON

✔ ES6+

✔ Front-end e Back-end
