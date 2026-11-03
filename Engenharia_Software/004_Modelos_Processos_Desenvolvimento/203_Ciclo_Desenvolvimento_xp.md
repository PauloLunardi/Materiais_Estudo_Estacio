# O Ciclo de Desenvolvimento no Extreme Programming (XP)

Dentro da metodologia do **Extreme Programming (XP)**, as atividades técnicas não ocorrem de forma isolada ou burocrática. O XP organiza seu ciclo de engenharia através de quatro fases altamente integradas e dinâmicas: **Planejamento, Projeto, Codificação e Teste**. 

Essas fases operam em ciclos muito curtos e repetitivos (iterações de 1 a 3 semanas), garantindo agilidade e feedback constante.

---

## As 4 Fases do Ciclo de Desenvolvimento XP

### 1. Planejamento (*Planning*)
O planejamento no XP foca em alinhar de forma rápida e colaborativa as expectativas de negócio do cliente com a capacidade de entrega técnica do time.
* **Histórias de Usuário (*User Stories*):** O processo começa com o cliente descrevendo as funcionalidades e regras de negócio desejadas em cartões simples, chamados de Histórias de Usuário.
* **Jogo do Planejamento (*Planning Game*):** O cliente prioriza os cartões por valor de negócio, e os desenvolvedores avaliam a complexidade técnica e atribuem uma estimativa de esforço (custo/tempo) para cada um.
* **Velocidade do Time:** O time determina quantas histórias consegue entregar na iteração atual com base no histórico de desempenho das semanas anteriores. O planejamento é revisado e adaptado a cada novo ciclo.

### 2. Projeto (*Design*)
O XP defende a filosofia do **Design Simples**. Em vez de passar semanas desenhando arquiteturas complexas no papel antes de programar, o time desenha estritamente o necessário para resolver o problema atual.
* **Metáfora do Sistema:** Utiliza-se uma analogia ou história simples e comum sobre o funcionamento do software para que clientes e programadores compartilhem do mesmo vocabulário técnico.
* **CRC Cards (Classe, Responsabilidade e Colaboração):** Para desenhar a arquitetura de objetos sem burocracia, o time usa cartões físicos para mapear as classes do sistema, determinando o que cada classe faz e com quem ela interage.
* **Combate à Complexidade:** Se um design começa a ficar confuso ou difícil de entender durante a evolução técnica, o XP dita que ele deve ser imediatamente reestruturado através da refatoração.

### 3. Codificação (*Coding*)
A codificação é a engrenagem central onde as ideias e designs simples são traduzidos em valor executável. No XP, nenhum programador trabalha sozinho ou isolado.
* **Programação em Par (*Pair Programming*):** Todo o código de produção é escrito por dois desenvolvedores dividindo o mesmo computador. Um escreve os comandos técnicos (piloto) e o outro revisa a lógica e pensa na arquitetura em tempo real (navegador). Os papéis mudam constantemente, o que eleva a qualidade do código e elimina erros de forma imediata.
* **Padrões de Codificação:** O time segue regras estritas de formatação visual do código para que qualquer membro consiga ler e dar manutenção em qualquer trecho do software.
* **Propriedade Coletiva:** Não existe dono do código. Qualquer par de programadores tem autonomia para alterar e refatorar qualquer módulo do sistema para melhorá-lo.

### 4. Teste (*Testing*)
Os testes não são uma fase final pós-desenvolvimento no XP; eles direcionam e validam todo o processo de escrita de código. O XP prega o **foco destrutivo em testes automatizados**.
* **Desenvolvimento Guiado por Testes (*TDD*):** Os desenvolvedores criam o teste de unidade automatizado **antes** de escrever o código da funcionalidade. O código só é considerado pronto quando passa no teste recém-criado, gerando um sistema com altíssima cobertura de testes e baixíssimo índice de bugs.
* **Testes de Aceitação (*Acceptance Tests*):** São criados e validados diretamente pelo **Cliente Presente** no time. Eles simulam o uso real do negócio para confirmar se a história de usuário foi implementada corretamente.
* **Integração Contínua:** Múltiplas vezes ao dia, os pares de desenvolvedores integram seus códigos ao repositório principal. A esteira de automação executa todos os testes imediatamente para dar feedback em minutos se algo quebrou.
