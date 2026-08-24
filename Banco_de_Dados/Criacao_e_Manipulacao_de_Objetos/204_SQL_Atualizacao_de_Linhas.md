# Comandos SQL para Atualizacao de Linhas em Tabela

Este documento apresenta as regras, sintaxes e boas praticas para a modificacao de registros existentes por meio do comando UPDATE, abordando desde alteracoes condicionais simples ate os impactos e tratativas de atualizacoes em colunas de chave primaria com integridade referencial. 

## 1. Atualizacao de Linhas em Tabela (UPDATE)

* O comando UPDATE modifica os valores das colunas de registros ja armazenados em uma tabela do SGBD.
* A utilizacao da clausula WHERE e fundamental para delimitar quais linhas sofrerao a alteracao de dados.
* A omissao intencional ou acidental da clausula WHERE faz com que a alteracao seja aplicada a todas as linhas da tabela.
* O operador = dentro da clausula SET atribui o novo valor, enquanto na clausula WHERE ele atua como comparador.

## 2. Matriz de Variacoes do Comando UPDATE

```text

Cenário de Uso         Sintaxe Aplicada            Alvo da Modificacao           Risco Operacional
Filtro por ID (PK)     UPDATE ... WHERE ID = valor Registro unico e especifico   Minimo (Controlado)
Filtro por Texto       UPDATE ... WHERE Nome = txt Linhas que casam com o texto  Moderado (Nomes duplicados)
Atualizacao Global     UPDATE ... SET Coluna = val Todas as linhas da tabela     Maximo (Altera o banco todo)

```

## 3. Exemplos Praticos de Atualizacao Coletiva e Condicional

```sql

-- Estruturacao basica da tabela para execucao dos exemplos
CREATE TABLE disciplina (
    codigodisciplina INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cargahoraria INT NOT NULL
);

INSERT INTO disciplina (codigodisciplina, nome, cargahoraria) VALUES
(1, 'Banco de Dados', 60),
(2, 'Redes de Computadores', 60),
(3, 'Programacao Web', 80);

-- Exemplo 1: Alteraremos para 70 a carga horaria da disciplina Redes de Computadores
UPDATE DISCIPLINA SET CARGAHORARIA=70 WHERE CODIGODISCIPLINA=2;

-- Abordagem alternativa utilizando o nome do registro como criterio de filtro
UPDATE DISCIPLINA SET CARGAHORARIA=70 WHERE NOME='Redes de Computadores';

-- Exemplo 2: Alterar em 20% a carga horaria de todas as disciplinas cadastradas
UPDATE DISCIPLINA SET CARGAHORARIA=CARGAHORARIA*1.2;

-- Verificacao do estado atual dos dados das disciplinas
SELECT * FROM disciplina;

```

## 4. Atualizacao de Coluna Chave Primaria e Restricoes

* Tentar alterar o valor de uma chave primaria referenciada por chaves estrangeiras (FOREIGN KEY) resulta em erro de restricao.
* Se tentarmos executar o comando abaixo antes de ajustar as constraints, o SGBD bloqueara a query para impedir registros orfaos:

```sql

-- Operacao direta bloqueada pelo mecanismo de integridade referencial nativo
UPDATE CURSO SET CODIGOCURSO=6 WHERE CODIGOCURSO=4;

```

* Para permitir essa atualizacao sem romper os vinculos relacionais, e necessario redefinir a chave estrangeira na tabela filha adicionando a propriedade de atualizacao em cascata (ON UPDATE CASCADE).

```sql

-- Ajuste estrutural da tabela filha para habilitar o comportamento em cascata
ALTER TABLE CURSODISCIPLINA
    DROP CONSTRAINT CURSODISCIPLINA_CURSO,
    ADD CONSTRAINT CURSODISCIPLINA_CURSO
    FOREIGN KEY (CODIGOCURSO) REFERENCES CURSO (CODIGOCURSO)
    ON UPDATE CASCADE;

```

## 5. Analise do Mecanismo ON UPDATE CASCADE

* O que fizemos? Usamos o comando ALTER TABLE para alterar a estrutura da tabela CURSODISCIPLINA, removemos a chave estrangeira (comando DROP CONSTRAINT) e, por ultimo, recriamos a chave (ADD CONSTRAINT), especificando a operacao de atualizacao (UPDATE) em cascata.
* Com a restricao configurada para propagacao automatica, a alteracao efetuada na tabela pai se reflete de forma imediata na tabela filha:

```sql

-- Execucao da alteracao da chave primaria na tabela pai
UPDATE CURSO SET CODIGOCURSO=10 WHERE CODIGOCURSO=1;

-- O PostgreSQL atualiza o codigo do curso para 10 de forma transparente em CURSODISCIPLINA
SELECT * FROM cursodisciplina;

```
