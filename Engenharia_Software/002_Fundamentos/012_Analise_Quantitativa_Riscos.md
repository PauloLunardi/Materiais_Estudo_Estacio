# Análise Quantitativa dos Riscos

Enquanto a análise qualitativa foca na priorização subjetiva e rápida (classificando os riscos em categorias como "Alto", "Médio" ou "Baixo"), a **Análise Quantitativa dos Riscos** traduz essas incertezas em **dados numéricos, estatísticos e financeiros**. 

No contexto da Engenharia de Software, essa etapa analisa matematicamente o efeito combinado de riscos identificados nas metas globais do projeto (como custo total e prazo final de entrega). Ela é aplicada principalmente em projetos de grande escala, alta complexidade ou que envolvem sistemas críticos, onde decisões intuitivas representam um risco financeiro muito alto.

---

## Métodos e Ferramentas Práticas de Aplicação

Para quantificar os riscos, os gerentes de projeto utilizam modelos matemáticos e simulações computacionais. As abordagens mais comuns na indústria de software são:

### 1. Análise do Valor Monetário Esperado (VME)
O VME (ou *Expected Monetary Value - EMV*) é uma técnica estatística que calcula o resultado médio ponderado de cenários que podem ou não acontecer no futuro. 

* **Como calcular:** Multiplica-se o valor monetário do impacto estimado pela probabilidade percentual de ocorrência do risco.
* **Cenário Negativo (Ameaça):** Resulta em um valor negativo (custo esperado).
* **Cenário Positivo (Oportunidade):** Resulta em um valor positivo (ganho/economia esperada).

```text
Exemplo Prático de Cálculo de VME no Software:

Risco Identificado: Perda de compatibilidade com uma API de pagamento terceirizada.
- Probabilidade de acontecer: 30% (0,30)
- Custo de reparo/atraso (Impacto): R\$ 50.000,00

Cálculo:
VME = Probabilidade x Impacto
VME = 0,30 x (-R\$ 50.000,00)
VME = -R\$ 15.000,00 (Este é o valor que deve ser provisionado no orçamento de reserva de risco)
```

### 2. Simulação de Monte Carlo
Trata-se de uma técnica computacional que realiza milhares de simulações do projeto combinando diferentes variáveis de tempo e custo baseadas em distribuições de probabilidade (como curvas normais ou triangulares).
* **No Software:** Em vez de dizer de forma simplista que o software "ficará pronto em 6 meses", a simulação de Monte Carlo analisa os riscos e gera um gráfico de probabilidade cumulativa (ex: "Há 85% de chance de o projeto ser concluído até o dia 15 de novembro, e apenas 15% de chance de terminar em outubro"). Ela ajuda a definir prazos realistas com base científica.

### 3. Análise de Árvore de Decisão
Um diagrama estruturado em forma de organograma que avalia diferentes caminhos e escolhas técnicas no projeto, considerando seus custos, probabilidades de sucesso/falha e impactos financeiros associados.
* **No Software:** Muito utilizada para decidir dilemas arquiteturais complexos, como a decisão de "Construir uma solução interna (*In-House*)" versus "Comprar/Contratar uma plataforma pronta (*SaaS/Third-Party*)".

---

## Análise Qualitativa vs. Análise Quantitativa

Para consolidar o conhecimento conceitual cobrado em exames e no mercado, é importante entender a distinção clara entre as duas abordagens:

| Característica | Análise Qualitativa | Análise Quantitativa |
| :--- | :--- | :--- |
| **Foco** | Subjetivo, rápido e focado em priorização. | Objetivo, matemático e focado em precisão. |
| **Métrica** | Escalas de percepção (Baixo, Médio, Alto). | Números brutos (R$, Dias, Probabilidade %). |
| **Complexidade** | Baixa. É obrigatória em todos os projetos. | Alta. Exige ferramentas e dados históricos confiáveis. |
| **Resultado** | Matriz de Probabilidade e Impacto / Lista prioritária. | Valor Monetário Esperado (VME) / Gráficos probabilísticos. |

---

## Benefícios para a Engenharia de Software

* **Reservas de Contingência Justificadas:** Permite calcular com precisão matemática o tamanho do fundo financeiro reserva e o tempo extra necessário para blindar o projeto contra imprevistos.
* **Apoio Crítico na Tomada de Decisão:** Fornece dados concretos para justificar à diretoria ou ao cliente a necessidade de investir em servidores redundantes, automação de testes ou contratação de especialistas técnicos.
* **Previsibilidade Comercial:** Reduz significativamente a taxa de fracasso em licitações e contratos corporativos de escopo fechado.
