# Estudo de Caso: Integridade Referencial e Erros em Blocos Transacionais

Este documento apresenta o roteiro pratico sequencial para analise de comportamento do SGBD PostgreSQL diante de falhas de chaves estrangeiras dentro de blocos transacionais, demonstrando o impacto do desfazimento de dados e o comportamento de campos autoincrementais. 

## 1. Estruturacao do Modelo de Dados

* Acesse a ferramenta Query Tool no seu banco de dados local.
* Execute o script abaixo para criar as tabelas necessarias estabelecendo a integridade referencial.

```sql

-- Criacao da tabela pai de produtos
CREATE TABLE produtos (
    id_produto SERIAL PRIMARY KEY,
    nome_produto VARCHAR(50) NOT NULL,
    preco NUMERIC(10,2) NOT NULL
);

-- Criacao da tabela filha de vendas com vinculo de FK
CREATE TABLE vendas (
    id_venda SERIAL PRIMARY KEY,
    fk_produto INT NOT NULL,
    quantidade INT NOT NULL,
    CONSTRAINT fk_vendas_produtos FOREIGN KEY (fk_produto) REFERENCES produtos (id_produto)
);

-- Valide a criacao das tabelas
SELECT * FROM produtos;
SELECT * FROM vendas;

```

## 2. Matriz de Estados e Sequencia do Fluxo

```text

Etapa / Comando SQL    Acao Operacional no Banco   Comportamento do Motor        Estado dos Registros
1. BEGIN (Transacao 1) Inicia o primeiro bloco     Modo autocommit desativado    Tabelas vazias
2. INSERT (Produtos)   Insere Produto A e B        Gera IDs na sequencia serial  Visivel apenas na sessao
3. INSERT (Venda Falsa)Tenta vender fk_produto 999 Bloqueio por erro de FK ativa Bloco transacional abortado
4. ROLLBACK            Descarta a transacao 1      Limpa a memoria volatil       Tabelas voltam a ficar vazias
5. BEGIN (Transacao 2) Inicia o segundo bloco      Modo autocommit desativado    Tabelas vazias
6. INSERT (Produtos)   Reinsere Produto A e B      Ids saltam (Salto do Serial)  Visivel apenas na sessao
7. INSERT (Venda Ok)   Insere fk_produto e qtde    Sucesso na integridade        Visivel apenas na sessao
8. COMMIT              Consolida a transacao 2     Gravacao definitiva em disco  Dados salvos permanentemente

```

## 3. Simulacao de Falha e Reversao (Transacao 1)

```sql

-- Inicie explicitamente uma transacao
BEGIN;

-- Insira dois produtos na tabela produtos
INSERT INTO produtos (nome_produto, preco) VALUES ('Produto A', 10.00);
INSERT INTO produtos (nome_produto, preco) VALUES ('Produto B', 20.00);

-- Simule uma falha ao tentar inserir uma venda com um produto que nao existe
INSERT INTO vendas (fk_produto, quantidade) VALUES (999, 1);

```

* **Comportamento do PostgreSQL:** A inserção falhará porque o produto_id 999 não existe na tabela produtos, mas continue! Vamos lá! O SGBD exibirá o erro de chave estrangeira no console e invalidará o bloco transacional corrente:

```text

ERROR: insert or update on table "vendas" violates foreign key constraint "fk_vendas_produtos"
DETAIL: Key (fk_produto)=(999) is not present in table "produtos".

```

```sql

-- Desfaca a transacao invalida
ROLLBACK;

-- Verifique se as insercoes anteriores foram revertidas (Retornara zero registros)
SELECT COUNT(*) FROM produtos;

```

## 4. Execucao Correta e Analise de Serial (Transacao 2)

```sql

-- Inicie explicitamente uma nova transacao
BEGIN;

-- Insira dois produtos na tabela produtos com os mesmos dados anteriores
INSERT INTO produtos (nome_produto, preco) VALUES ('Produto A', 10.00);
INSERT INTO produtos (nome_produto, preco) VALUES ('Produto B', 20.00);

-- Verifique os IDs de produtos existentes
SELECT * FROM produtos;

```

* **Obs.:** os IDs podem variar, pois sendo o ID serial ao fazer rollback, os valores já utilizados são perdidos. Na listagem, os identificadores gerados serão 3 e 4, pois o contador da sequência (SEQUENCE) avança de forma global e não sofre rollback para evitar concorrência.

## 5. Vinculo de Venda e Confirmacao Final

* Supondo que o primeiro produto inserido nesta segunda transação tenha recebido o ID 3 (substitua o valor de fk_produto na query caso o seu ID seja diferente):

```sql

-- Insira uma venda corretamente utilizando o ID gerado e a quantidade
-- Exemplo adaptado para a sintaxe do cenario: fk_produto = 3, quantidade = 5
INSERT INTO vendas (fk_produto, quantidade) VALUES (3, 5);

-- Confirme a transacao
COMMIT;

-- Valide as insercoes realizadas de forma definitiva
SELECT * FROM produtos;
SELECT * FROM vendas;

```
