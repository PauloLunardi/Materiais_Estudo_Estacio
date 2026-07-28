# Documentação Prática: Caso de Estudo - Classe Televisão

Este documento registra a resolução e a modelagem do exercício prático de fixação sobre a criação de classes, inicialização de atributos dinâmicos e manipulação de estados por meio de métodos de controle em Python.

---

## 1. Requisitos do Sistema e Regras de Negócio

O exercício propõe a modelagem de um objeto que simula o comportamento de um aparelho de televisão real, obedecendo aos seguintes critérios:

* **Parâmetros do Construtor:** A classe deve receber obrigatoriamente três valores inteiros no momento da sua criação: o canal inicial que a TV ligará, o número do menor canal disponível no aparelho e o número do maior canal disponível.
* **Atributos de Instância:** O objeto deve registrar e manter em seu estado o canal atualmente sintonizado, o limite mínimo (canal mínimo) e o limite máximo (canal máximo).
* **Operações/Métodos de Controle:** Devem existir dois métodos públicos de alteração de estado: um responsável por avançar para o canal superior e outro por retornar ao canal inferior.
* **Validação de Limites:** Como regra implícita de segurança de dados, os métodos de troca de canal devem respeitar os limites mínimo e máximo configurados no construtor, impedindo que o aparelho sintonize um canal inexistente.

---

## 2. Lógica dos Métodos de Troca de Canal

Para garantir a integridade dos dados guardados no estado do objeto, a lógica dos comportamentos deve ser estruturada da seguinte forma:

### Avançar Canal
Antes de incrementar o canal atual (`self.canal += 1`), o sistema deve verificar se o canal atual já não atingiu o valor limite armazenado em `self.canal_maximo`. Se já estiver no máximo, o método impede o incremento ou realiza a rotação para retornar ao canal mínimo.

### Retroceder Canal
Antes de decrementar o canal atual (`self.canal -= 1`), o sistema deve verificar se o valor atual já é igual ao limite configurado em `self.canal_minimo`. Se a condição for verdadeira, o decremento é bloqueado para proteger a integridade do estado.

---

## 3. Guia de Implementação e Fluxo de Execução

Ao traduzir este roteiro para o seu arquivo de código, a estrutura lógica deve seguir os seguintes passos sequenciais:

1. **Declaração da Classe:** Definição da assinatura utilizando o comando `class Televisao:`.
2. **Método Inicializador:** Escrita do método especial `__init__` recebendo `self`, `canal_inicial`, `minimo` e `maximo`.
3. **Mapeamento de Atributos:** Associação dos parâmetros às variáveis internas do objeto utilizando o prefixo `self.`.
4. **Construção dos Métodos:** Desenvolvimento das funções de incremento e decremento com as estruturas condicionais de validação (`if/else`).
5. **Cenário de Teste:** Instanciação de pelo menos dois objetos de televisão com configurações de limites diferentes (ex: uma TV de sala com limites de 2 a 99, e uma TV de quarto com limites de 1 a 15) para certificar a independência das referências de memória RAM e validar a subida e descida dos canais no terminal.
