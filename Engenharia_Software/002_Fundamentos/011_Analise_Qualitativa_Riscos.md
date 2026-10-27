# Análise Qualitativa dos Riscos

Após identificar os riscos, o próximo passo essencial é qualificá-los. A **Análise Qualitativa dos Riscos** é o processo de priorizar os riscos do projeto para análise ou ação posterior, avaliando e combinando sua probabilidade de ocorrência e seu impacto. 

Essa etapa é crucial na Engenharia de Software porque permite que a equipe foque seus recursos limitados de gerenciamento e testes nas ameaças e oportunidades que realmente importam, evitando o desperdício de tempo com problemas insignificantes.

---

## Componentes Principais da Análise Qualitativa

Para qualificar um risco, os gerentes de projeto e os engenheiros de software utilizam duas variáveis fundamentais:

* **Probabilidade:** É a chance ou verossimilhança de um determinado evento de risco ocorrer durante o ciclo de vida do software. Geralmente é medida em uma escala qualitativa (ex: Baixa, Média, Alta) ou em termos percentuais (ex: 10%, 50%, 90%).
* **Graus de Impacto:** Refere-se à severidade do efeito que o risco causará nas restrições do projeto (Escopo, Cronograma, Custo e Qualidade) caso ele venha a se materializar. 

### Escala Clássica de Graus de Impacto no Software
* **Muito Baixo / Insignificante:** O bug ou evento afeta apenas elementos cosméticos da interface (UI) e não impede o uso do sistema. Não há impacto perceptível no prazo ou orçamento.
* **Baixo:** Causa pequenos desvios no cronograma técnico ou pequenas falhas contornáveis no software. O usuário final consegue realizar suas tarefas com uma solução alternativa simples (*workaround*).
* **Moderado / Médio:** Exige retrabalho na codificação ou infraestrutura, afetando uma entrega de sprint ou gerando um atraso gerenciável. Afeta funções secundárias do sistema.
* **Alto:** Impacta diretamente a arquitetura central do software ou atrasa a data de homologação/entrega final para o cliente. Causa falhas em módulos importantes de negócio.
* **Muito Alto / Catastrófico:** Torna o sistema completamente inoperante ou inseguro (ex: vazamento massivo de dados, queda total do servidor de produção). Pode causar o cancelamento do projeto ou prejuízos financeiros e jurídicos severos à organização.

---

## Aplicação Prática: A Matriz de Probabilidade e Impacto

A aplicação prática desse conceito ocorre por meio da montagem de uma **Matriz de Probabilidade e Impacto**. Cruzando os valores dessas duas variáveis, o risco recebe uma pontuação ou uma classificação de severidade que dita a urgência da resposta.

Abaixo está um modelo de classificação qualitativa que ajuda a priorizar os riscos em **Alto (Vermelho)**, **Médio (Amarelo)** ou **Baixo (Verde)**:

| Probabilidade | Impacto Muito Baixo | Impacto Baixo | Impacto Médio | Impacto Alto | Impacto Muito Alto |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Alta** | Médio | Médio | Alto | Alto | Alto |
| **Média** | Baixo | Médio | Médio | Alto | Alto |
| **Baixa** | Baixo | Baixo | Médio | Médio | Alto |

### Como aplicar essa priorização no dia a dia da Engenharia de Software?

* **Zona Alta (Prioridade Máxima):** Exige atenção imediata. Devem ser criadas ações proativas de mitigação (para reduzir a probabilidade) ou planos de contingência robustos. *Exemplo:* Um risco alto de que o banco de dados não aguente a concorrência exige testes de carga agressivos já nas primeiras iterações.
* **Zona Média (Monitoramento Ativo):** São incluídos em uma lista de observação e monitorados durante as reuniões de status ou encerramento de sprints. Ações preventivas podem ser tomadas se o orçamento permitir.
* **Zona Baixa (Apenas Acompanhamento):** São aceitos temporariamente pelo time. Ficam registrados caso a dinâmica do projeto mude, mas não gastam esforço ou recursos de gerenciamento imediatos.
