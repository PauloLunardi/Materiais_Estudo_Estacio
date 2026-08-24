# Chave Primária e Restrições de Integridade

## 1. O Conceito de Chave Primária e Suas Propriedades

Para que um SGBD funcione de forma confiável, ele precisa de um mecanismo interno capaz de diferenciar uma linha (tupla) de todas as outras dentro de uma mesma tabela. Isso é feito por meio de uma restrição de integridade chamada **Chave Primária (PK - Primary Key)**. 

* **A Escolha de Colunas:** O projetista escolhe um campo (ou um conjunto de campos) cujos valores serão obrigatoriamente exclusivos em todo o banco de dados.
* **Propriedades Absolutas da Chave Primária:** Toda chave primária deve cumprir rigorosamente três regras nativas do modelo relacional: 

  * *Unicidade:* O valor gravado na chave primária não permite repetição em nenhuma outra linha da tabela.
  * *Obrigatório:* O campo jamais aceita valores vazios ou nulos (NOT NULL).
  * *Monovalorado:* Cada célula da chave guarda um único elemento de informação por vez.
* **Mecanismo de Autoincremento:** Grande parte dos SGBDs modernos permite associar a propriedade de autoincremento a uma chave primária numérica simples. Com isso, o próprio motor do banco de dados gera e incrementa o próximo valor sequencial de forma automática a cada nova inserção, garantindo a singularidade do registro sem esforço do usuário.

## 2. Diferença entre Chaves Simples, Compostas e o Critério de Chave Mínima

A engenharia de banco de dados classifica as chaves primárias de acordo com a quantidade de colunas necessárias para consolidar a identificação exclusiva de um registro. 

* **Chave Primária Simples:** Ocorre quando uma única e exclusiva coluna isolada é suficiente para diferenciar uma linha das demais na tabela.
* **Chave Primária Composta:** Ocorre quando o sistema exige a combinação de duas ou mais colunas simultâneas para gerar um identificador único. Nenhuma das colunas participantes consegue individualizar o registro se for analisada isoladamente.
* **O Critério da Chave Mínima:** Toda chave primária deve ser, por definição, mínima. Isso significa que **todas** as colunas escolhidas para formá-la devem ser estritamente necessárias e suficientes para a identificação, sem nenhuma sobra ou redundância.

### Tabela Exemplo 1: ALUNO (Chave Primária Simples e Mínima)

A coluna CODIGOALUNO atua como uma chave simples e mínima. Se tentássemos criar uma chave composta unindo (CODIGOALUNO, CPF), o critério de chave mínima seria violado, pois o código sozinho já cumpre o papel de diferenciação de forma autossuficiente. 

CODIGOALUNO (PK) | NOME                   | NOMEMAE                 | CPF
-----------------|------------------------|-------------------------|------------
1                | Aline Goncalves Campos | NULL                    | 09320900022
2                | Pablo Goncalves Campos | Maria Augusta Goncalves | 08760900022
3                | Bruno da Silva         | Yvone Silva             | 99920900099
4                | Viviane da Silva       | Yvone Silva             | 00209000922
5                | Lucas Pontes Silva     | Daniele Pontes Maciel   | 11109000933


## Tabela Exemplo 2: DEPENDENTE (Chave Primária Composta e Mínima)

O par ordenado composto por (CODIGOFUNCIONARIO, NRDEPENDENTE) forma a chave primária desta tabela. Isolar apenas o código do funcionário falharia, pois um mesmo funcionário pode ter vários dependentes. Isolar apenas o número do dependente também falharia, pois o valor 1 repete-se para funcionários diferentes. A união de ambos é necessária e suficiente, respeitando o critério de chave mínima. 

CODIGOFUNCIONARIO (PK) | NRDEPENDENTE (PK) | NOME
-----------------------|-------------------|----------------
1                      | 1                 | Andrey Campos
1                      | 2                 | Manoel Oliveira
2                      | 1                 | Joao Silva
2                      | 2                 | Jose Maciel


## 3. Classificações de Chaves: Candidatas, Alternativas e Artificiais

Durante a fase de análise de uma tabela, o projetista frequentemente encontra múltiplos caminhos lógicos para estabelecer a integridade referencial do modelo. 

* **Chave Candidata:** Refere-se a qualquer coluna (ou conjunto de colunas) que cumpra com sucesso todos os requisitos de unicidade e obrigatoriedade para se tornar uma chave primária. Na tabela ALUNO, tanto a coluna CODIGOALUNO quanto a coluna CPF são consideradas chaves candidatas legítimas.
* **Chave Alternativa (ou Secundária):** É a chave candidata que sobrou após o projetista realizar a escolha da chave primária oficial da tabela. No momento em que CODIGOALUNO foi eleita como a PK do sistema, a coluna CPF foi automaticamente rebaixada e classificada como uma chave alternativa.
* **Chave Artificial (ou Subrogada):** É uma coluna criada artificialmente pelo desenvolvedor (geralmente um ID numérico sequencial autoincrementado) que não possui qualquer relação direta com as regras ou dados de negócio originais. Ela é inserida no modelo com o único propósito de servir como uma chave primária simples, limpa e de alto desempenho para indexação e consultas.
