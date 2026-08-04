# 📋 Nível Mestre: Passagem de Parâmetros por Valor em C

Este documento apresenta as regras de funcionamento, aplicação e vantagens da **Passagem de Parâmetros por Valor** na linguagem C. Compreender esta técnica é indispensável para criar códigos previsíveis, seguros e livres de efeitos colaterais, aplicando corretamente o princípio de isolamento de dados no seu projeto de War Estruturado (especialmente em funções de leitura e exibição).

---

## 1. O que é Passagem de Parâmetros?

Quando desenvolvemos um software estruturado, é comum dividirmos o código em funções menores e especializadas. Para que uma função consiga realizar o seu trabalho, frequentemente precisamos enviar dados para dentro dela. Esse ato de fornecer informações a uma função é chamado de **passagem de parâmetros**. 

Em suma, passar um parâmetro é como entregar um relatório ou uma informação para que a função trabalhe sobre ela de forma isolada.

---

## 2. O Mecanismo da Passagem por Valor

Na passagem por valor, a função **recebe uma cópia exata** do dado que foi enviado. Isso significa que a função ganha total liberdade para modificar, recalcular ou descartar essa cópia ao longo da sua execução, sem que isso interfira na variável original que gerou o envio.

> 📄 **Analogia 1: O Documento Escaneado**
> Pense em entregar a alguém uma cópia escaneada ou xerox de um documento seu. Essa pessoa pode riscar, dobrar, fazer anotações ou até jogar a folha no lixo. Independentemente do que ela faça com a cópia, o seu documento original guardado na sua pasta continua completamente seguro e intacto.

> 🍫 **Analogia 2: A Receita de Brigadeiro**
> Imagine que você tem uma receita clássica de brigadeiro anotada no seu caderno de receitas. Um amigo pede essa receita e você tira uma cópia em papel para entregar a ele. Na casa dele, seu amigo resolve alterar as instruções: risca alguns itens, adiciona canela e anota observações nas margens da folha. Apesar de todas as alterações feitas pelo seu amigo na cópia dele, a sua receita original no seu caderno de cozinha continua intocada, exatamente do jeito que você a escreveu.

---

## 3. Exemplo Prático Comentado

O código a seguir demonstra o comportamento padrão do C ao enviar dados por valor. Analisamos uma rotina que dobra o valor de uma variável e exibe os resultados dentro e fora do escopo da função:

```c
#include <stdio.h>

// Função que recebe uma cópia de um número inteiro e dobra o seu valor
void dobrar(int x) {
    // 'x' é uma variável local que armazena apenas uma CÓPIA do valor enviado
    x = x * 2;
    printf("Dentro da função: %d\n", x);
}

int main() {
    int numero = 5;
    
    // Passagem por Valor: enviamos apenas o conteúdo da variável (5)
    dobrar(numero);
    
    // Comprovação: a variável original não foi modificada
    printf("Fora da função: %d\n", numero);
    
    return 0;
}
```

### 💻 Saída Esperada no Terminal:
```text
Dentro da função: 10
Fora da função: 5
```

### 🔍 Análise Reta do Fluxo:
1. No `main()`, a variável `numero` é inicializada com o valor `5` e passada como argumento.
2. Ao invocar `dobrar(numero)`, o compilador cria uma nova variável chamada `x` na memória da função e joga o valor `5` lá dentro.
3. A linha `x = x * 2;` modifica exclusivamente a variável local `x`, alterando seu valor para `10`.
4. Assim que a função atinge a chave de fechamento `}`, a variável `x` é destruída da memória.
5. Quando o programa retorna ao `main()`, o `printf` comprova que `numero` permanece valendo `5`.

---

## 4. Quando e Por Que Utilizar?

A passagem por valor é o **comportamento padrão (default)** da linguagem C para tipos primitivos (`int`, `float`, `char`). Ela deve ser adotada sempre que os seguintes cenários ocorrerem no seu software:

* **Exibição de Informações:** Funções que servem apenas para imprimir dados na tela (como a listagem de territórios do War).
* **Consultas e Validações:** Funções que verificam condições de jogo (Ex: checar se um jogador tem tropas suficientes para atacar) sem a necessidade de alterar permanentemente o estado das variáveis.
* **Cálculos Temporários:** Funções que processam equações matemáticas e apenas retornam um resultado novo, sem corromper as entradas originais.

### 🛡️ Benefícios para o Design de Software:
* **Previsibilidade:** Garante que o fluxo de dados seja estável. Você sabe exatamente que a variável original não será alterada por acidente.
* **Segurança contra Efeitos Colaterais:** Elimina bugs gerados por funções secundárias que modificam ponteiros indevidamente, tornando o rastreamento de problemas muito mais confiável em sistemas grandes.

> **💡 Conexão com o War Estruturado:** Enquanto a função de **ataque** exige o uso de ponteiros (Passagem por Referência) para de fato alterar as tropas no mapa, a função de **exibição** (`exibirMapa`) utiliza o conceito de trabalhar com cópias ou referências de leitura para garantir que a simples listagem dos países nunca altere as tropas do jogo por erro de digitação.
