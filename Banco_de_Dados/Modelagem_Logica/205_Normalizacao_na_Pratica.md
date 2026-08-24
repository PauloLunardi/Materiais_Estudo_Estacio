# Normalização na Prática: Sistema de Controle de Vendas

## 1. Estrutura Bruta e Análise do Arquivo de Notas Fiscais

O processo de normalização ocorre, em geral, após a execução da modelagem conceitual e lógica, funcionando como uma ferramenta de auditoria para validar e corrigir as estruturas das tabelas. O estudo de caso analisa um arquivo bruto de faturamento com a seguinte composição de dados: 

* **Dados de Cabeçalho e Cliente:** Número da Nota Fiscal (Num_NF), Série, Data de Emissão, Código do Cliente, Nome do Cliente, Endereço do Cliente e CNPJ do Cliente.
* **Grupo Repetitivo (Mercadorias):** Uma lista aninhada contendo Código da Mercadoria, Descrição da Mercadoria, Quantidade Vendida, Preço de Venda e Valor Total daquela mercadoria.
* **Indicador de Fechamento:** Total Geral da Nota.

### Esquema da Tabela Não Normalizada (TNN)

O emaranhado de dados brutos do faturamento é representado textualmente através de parênteses aninhados, explicitando o acoplamento do grupo repetitivo de mercadorias: 

```text

NOTA_FISCAL (Num_NF, Serie, Data_Emissao, Cod_Cliente, Nome_Cliente, Endereco_Cliente, CNPJ_Cliente, Total_Geral, (Cod_Mercadoria, Descricao_Mercadoria, Qtd_Vendida, Preco_Venda, Total_Item))

```

## 2. Processo para Obtenção da Primeira Forma Normal (1FN)

O estágio inicial da normalização visa eliminar completamente a presença de grupos repetitivos aninhados e transformar atributos compostos em estruturas atômicas e indivisíveis. 

* **Diretrizes do Roteiro de Prática (1FN):** 

  * Definir com clareza as chaves candidatas e eleger a chave primária oficial da tabela principal.
  * Transformar atributos compostos em múltiplos campos atômicos independentes.
  * Extrair os itens multivalorados e grupos repetitivos, movendo-os para novas tabelas dedicadas.
* **Aplicação no Cenário da Nota Fiscal:** 

  * O grupo repetitivo de mercadorias é extraído da tabela pai, dando origem à tabela intermediária ITEM_NOTA.
  * Como uma mesma nota possui várias mercadorias e uma mercadoria pode estar em várias notas, a tabela filha exige uma **Chave Primária Composta** formada pela combinação dos campos (Num_NF, Serie, Cod_Mercadoria).
  * *Eliminação de Atributo Redundante:* O campo Total_Item é omitido por ser um valor derivável (Qtd_Vendida * Preco_Venda), assim como o Total_Geral pode ser obtido pela somatória dos itens.

### Esquema Textual na 1FN

```text

NOTA_FISCAL (Num_NF, Serie, Data_Emissao, Cod_Cliente, Nome_Cliente, Endereco_Cliente, CNPJ_Cliente)

ITEM_NOTA (Num_NF, Serie, Cod_Mercadoria, Qtd_Vendida, Preco_Venda, Descricao_Mercadoria)
   (Num_NF, Serie) REFERENCIA NOTA_FISCAL

```

## 3. Processo para Obtenção da Segunda Forma Normal (2FN)

O segundo estágio concentra-se estritamente na análise de tabelas que possuem chaves primárias compostas, visando eliminar o que a literatura técnica chama de dependência funcional parcial. 

* **Diretrizes do Roteiro de Prática (2FN):** 

  * Isolar e mapear todas as colunas que não participam da chave primária da tabela em análise.
  * Para cada um desses atributos não chave, verificar se seu valor é determinado pela totalidade ou por apenas uma fração (parte) da chave composta.
  * *Ação Corretiva:* Para as colunas dependentes parciais, criar novas tabelas onde a chave primária será a coluna da chave original que determinou aquele valor de forma isolada. Em seguida, excluir essas colunas da tabela original.
* **Aplicação no Cenário da Nota Fiscal (Tabela ITEM_NOTA):** 

  * A tabela ITEM_NOTA possui chave composta. O campo Descricao_Mercadoria depende exclusivamente de Cod_Mercadoria (uma parte da chave), e não da Nota Fiscal em si. O nome de um produto não muda se ele for vendido na nota 10 ou na nota 20.
  * *Resultado:* Criamos a tabela MERCADORIA para isolar o catálogo de produtos e limpamos a tabela de itens, mantendo nela apenas os campos com dependência funcional total (Qtd_Vendida e Preco_Venda).

### Esquema Textual na 2FN

```text

NOTA_FISCAL (Num_NF, Serie, Data_Emissao, Cod_Cliente, Nome_Cliente, Endereco_Cliente, CNPJ_Cliente)

MERCADORIA (Cod_Mercadoria, Descricao_Mercadoria)

ITEM_NOTA (Num_NF, Serie, Cod_Mercadoria, Qtd_Vendida, Preco_Venda)
   (Num_NF, Serie) REFERENCIA NOTA_FISCAL
   Cod_Mercadoria REFERENCIA MERCADORIA

```

## 4. Processo para Obtenção da Terceira Forma Normal (3FN)

O estágio final do roteiro visa limpar as estruturas contra a dependência funcional transitiva, impedindo que uma coluna que não seja chave atue como determinante de outro atributo não chave. 

* **Diretrizes do Roteiro de Prática (3FN):** 

  * Identificar todas as colunas remanescentes que não integram a chave primária do arquivo.
  * Para cada um desses atributos comuns, analisar se o seu valor de negócio é determinado por alguma outra coluna que também não pertença à chave da tabela.
  * *Ação Corretiva:* Para as colunas que possuem dependência transitiva, criar tabelas independentes onde a chave primária será a coluna não chave que atuava como determinante. Agregar a essas novas estruturas as colunas dependentes e excluí-las permanentemente da tabela original.
* **Aplicação no Cenário da Nota Fiscal (Tabela NOTA_FISCAL):** 

  * Na tabela NOTA_FISCAL, a chave primária é a composição (Num_NF, Serie). No entanto, identificamos que Cod_Cliente determina diretamente o Nome_Cliente, o Endereco_Cliente e o CNPJ_Cliente. Existe aqui uma relação indireta de trânsito de dados (Chave → Cod_Cliente → Dados do Cliente).
  * *Resultado:* Extraímos todos os dados cadastrais do comprador para uma nova e exclusiva tabela chamada CLIENTE, utilizando Cod_Cliente como sua chave primária. Na tabela de origem NOTA_FISCAL, mantemos apenas o código do cliente atuando como Chave Estrangeira (FK).

### Esquema Textual Consolidado e Otimizado na 3FN

```text

CLIENTE (Cod_Cliente, Nome_Cliente, Endereco_Cliente, CNPJ_Cliente)

NOTA_FISCAL (Num_NF, Serie, Data_Emissao, Cod_Cliente)
   Cod_Cliente REFERENCIA CLIENTE

MERCADORIA (Cod_Mercadoria, Descricao_Mercadoria)

ITEM_NOTA (Num_NF, Serie, Cod_Mercadoria, Qtd_Vendida, Preco_Venda)
   (Num_NF, Serie) REFERENCIA NOTA_FISCAL
   Cod_Mercadoria REFERENCIA MERCADORIA

```
