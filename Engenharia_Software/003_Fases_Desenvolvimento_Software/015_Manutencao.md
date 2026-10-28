# A Etapa de Manutenção de Software

Muitas pessoas acreditam que o ciclo de vida da Engenharia de Software termina com a implantação do sistema. No entanto, a literatura clássica deixa claro que a maior parte do tempo e do custo financeiro de um produto de software ocorre após a sua entrega, na fase de **Manutenção de Software**.

Como destaca **Ian Sommerville (2007)**, a manutenção é o processo geral de modificar um sistema de software após ele ter sido entregue ao cliente. O software é um produto dinâmico: à medida que o mundo real muda, as leis evoluem e novas tecnologias surgem, o sistema precisa obrigatoriamente se adaptar para não se tornar obsoleto.

---

## Os 4 Tipos de Manutenção de Software

De acordo com as normas internacionais e os autores clássicos como **Roger Pressman (2016)**, as atividades de manutenção são divididas em quatro categorias fundamentais baseadas no motivo que gerou a alteração:

* **1. Manutenção Corretiva**
  * **O que é:** O ato de corrigir falhas, erros ou comportamentos inesperados (*bugs*) descobertos pelos usuários em ambiente de produção.
  * **Na prática:** O sistema gera um erro técnico inesperado ao tentar emitir uma nota fiscal específica. A equipe atua diretamente na correção do código para reestabelecer o funcionamento correto.

* **2. Manutenção Adaptativa**
  * **O que é:** Modificações realizadas para fazer o software funcionar corretamente em um ambiente operacional que mudou ou está mudando.
  * **Na prática:** O banco de dados do servidor foi atualizado para uma versão mais recente, uma nova lei fiscal entrou em vigor mudando as alíquotas de imposto, ou o sistema precisa passar a rodar em um novo sistema operacional corporativo.

* **3. Manutenção Perfectiva (ou Evolutiva)**
  * **O que é:** Alterações solicitadas pelos usuários para adicionar novas funcionalidades, recursos ou melhorar o desempenho do sistema, mesmo que ele não apresente nenhuma falha técnica.
  * **Na prática:** O cliente solicita a criação de uma nova tela de relatório gráfico ou pede para otimizar uma consulta ao banco que está demorando muito para carregar, visando melhorar a experiência do usuário.

* **4. Manutenção Preventiva**
  * **O que é:** Atividades voltadas para encontrar e corrigir defeitos latentes antes que eles se transformem em problemas reais para o usuário final, aumentando a manutenibilidade futura do sistema.
  * **Na prática:** Realizar a refatoração de um trecho de código confuso (*código espaguete*), atualizar bibliotecas antigas que possuem vulnerabilidades de segurança descobertas recentemente, ou melhorar a documentação técnica das classes centrais.

---

## A Lei da Evolução do Software (Leis de Lehman)

Para entender a dinâmica da manutenção, a engenharia de software estuda as **Leis de Lehman**, formuladas por Manny Lehman. Duas delas são cruciais para a ementa técnica:

* **Mudança Contínua:** Um software utilizado em um ambiente real deve passar por mudanças contínuas, ou se tornará progressivamente menos útil para a organização.
* **Complexidade Crescente:** À medida que um software evolui por meio de manutenções sucessivas, sua estrutura interna tende a se tornar cada vez mais complexas, a menos que a equipe invista esforço ativo (manutenção preventiva/refatoração) para simplificá-la.

---

## Reengenharia de Software vs. Manutenção Tradicional

Quando o custo de manter um software antigo (sistema legado) se torna proibitivo devido à sua alta complexidade estrutural, a engenharia de software adota o conceito de **Reengenharia de Software**.

* **Manutenção Tradicional:** Modifica pequenas partes do código para corrigir bugs ou adicionar funções pontuais, mantendo a arquitetura original intacta.
* **Reengenharia:** É um processo radical de longo prazo. Envolve a análise detalhada do sistema antigo (Engenharia Reversa) para compreender suas regras de negócio ocultas, seguida pela reestruturação completa do código e da arquitetura do software utilizando tecnologias modernas (Engenharia Avante) para torná-lo fácil de manter novamente.
