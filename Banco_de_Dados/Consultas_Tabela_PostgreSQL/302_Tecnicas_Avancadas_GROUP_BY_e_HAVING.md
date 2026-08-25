# Tecnicas Avancadas de Filtragem e Agrupamento: GROUP BY e HAVING

Este documento aborda a aplicacao de tecnicas avancadas de analise de dados em bancos relacionais, detalhando o comportamento combinado de filtros agregados, regras de negocio restritivas e o uso da clausula HAVING para tomada de decisoes corporativas. 

## 1. Tecnicas e Casos de Aplicacao do HAVING

* O uso avancado do agrupamento resolve problemas onde os criterios de filtro dependem de informacoes estatisticas calculadas (como contagens, somatorios ou medias).
* Nao e possivel utilizar funcoes de agregacao dentro da clausula WHERE, pois ela atua antes do calculo dos grupos.
* A tecnica correta consiste em utilizar o GROUP BY para consolidar as dimensoes e o HAVING para cortar os grupos que nao atendem a regra de negocio.
* A combinacao de expressoes matematicas no SELECT permite projetar valores preditivos, como simulacoes de bonus, reajustes e impactos na folha.

## 2. Matriz de Comportamento dos Filtros em Cascata

```text

Estagio do Filtro      Clausula SQL   Objeto Analisado            Exemplo Pratico de Aplicacao
1. Pre-filtragem       WHERE          Registro bruto na tabela    Filtrar apenas funcionarios ativos
2. Consolidacao        GROUP BY       Colunas de agrupamento      Agrupar dados por codigo do departamento
3. Pos-filtragem       HAVING         Resultado da agregacao      Manter apenas grupos com mais de 10 pessoas

```

## 3. Consulta 05: Simulacao de Bonus Condicional com HAVING

* **Cenario:** Suponha que o departamento de recursos humanos esteja estudando a viabilidade de oferecer bônus de 5% aos funcionários por mês de nascimento, mas limitado somente aos casos em que há mais de um colaborador aniversariando. Assim, para cada mês em questão, deseja-se listar o mês, o número de colaboradores e o valor do bônus.

```sql

-- Execucao da query utilizando expressao de calculo e filtro HAVING
SELECT 
    EXTRACT(MONTH FROM dtnascimento) AS "Mês",
    COUNT(*) AS "Número de Colaboradores",
    SUM(salario * 0.05) AS "Valor do Bônus"
FROM colaboradores
GROUP BY EXTRACT(MONTH FROM dtnascimento)
HAVING COUNT(*) > 1
ORDER BY "Mês" ASC;

```

### Resultado da Consulta 05

```text

 Mês | Número de Colaboradores | Valor do Bônus 
-----+-------------------------+----------------
   3 |                       2 |         450.00
(1 row)

```

* **Analise do Resultado:** O motor do SGBD PostgreSQL processou todos os meses de nascimento do quadro de funcionarios, porem a clausula HAVING COUNT(*) > 1 descartou os meses 1, 7 e 10 da listagem final, pois estes possuiam apenas 1 aniversariante cadastrado, isolando exatamente o alvo do estudo do RH.
