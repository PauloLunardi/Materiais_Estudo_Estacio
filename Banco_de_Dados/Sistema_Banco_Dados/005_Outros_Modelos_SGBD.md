# ASSUNTO: Outros Modelos de SGBD - SGBDs Multimodelos, Movimento NoSQL e Classificações

## 1. O Conceito de SGBDs Multimodelos

O mercado moderno de banco de dados evoluiu para permitir que um único sistema gerencie dados utilizando diferentes paradigmas estruturais. 

### Mapeamento de Recursos dos Líderes Relacionais

Os grandes líderes do mercado relacional expandiram suas capacidades originais para suportar novos formatos de dados, sendo formalmente classificados como **SGBDs Multimodelos**: 

* **Oracle:** Suporta os modelos Relacional, Documentos, Grafos e RDF.
* **IBM DB2:** Suporta os modelos Relacional, Documentos e RDF.
* **Microsoft SQL Server:** Suporta os modelos Relacional, Documentos e Grafos.
* **MySQL:** Suporta os modelos Relacional e Documentos.
* **PostgreSQL:** Suporta os modelos Relacional e Documentos.

*Nota de Monitoramento:* Essa evolução e o nível de adoção dessas tecnologias são monitorados e atualizados mensalmente por meio do ranking global da plataforma **DB-Engines** (db-engines.com). 

## 2. O Movimento NoSQL e Novas Demandas de TI

Embora o modelo relacional permaneça consolidado no ambiente corporativo devido à maturidade dos produtos e à padronização da linguagem SQL, ele enfrenta limitações frente às novas tecnologias de dados. 

### Fatores de Impulsão do NoSQL

* **Aplicações Alvo:** Sistemas Web de alta escala, aplicações científicas, ecossistemas de *Big Data*, Internet das Coisas (IoT) e Ciência de Dados (*Data Science*).
* **Demanda Técnica:** Necessidade de armazenar e processar volumes massivos de informação em alta velocidade e formatos altamente heterogêneos, indo além da rigidez das tabelas relacionais.

### Definição e Características do NoSQL

* **Significado da Sigla:** Traduzido como "Não SQL" ou, mais precisamente, **"Não Somente SQL"** (*Not Only SQL*).
* **Modelo Operacional:** Não adotam a estrutura puramente relacional como base nativa de armazenamento.
* **Abstração da Linguagem:** Não utilizam a linguagem SQL padrão, embora alguns motores NoSQL implementem variações do comando SELECT para facilitar a compatibilidade e a curva de aprendizado de profissionais da área.

## 3. Classificação dos Modelos de Bancos de Dados NoSQL e Seus Produtos

A diversidade de tecnologias NoSQL e multimodelos divide-se em categorias especializadas de acordo com a forma de estruturação do dado: 

* **Chave-Valor:** Armazenamento focado em alto desempenho via dicionário simples. 

  * *Produtos:* Redis, Amazon DynamoDB, Microsoft Azure CosmosDB.
* **Documentos:** Dados estruturados de forma flexível (comumente JSON ou BSON). 

  * *Produtos:* MongoDB, Amazon DynamoDB, Microsoft Azure CosmosDB.
* **Motores de Busca (Search Engines):** Otimizados para indexação e pesquisa textual complexa. 

  * *Produtos:* Elasticsearch, Splunk, Solr.
* **Séries Temporais (Time Series):** Especializados em registrar fluxos de dados cronológicos (como sensores IoT). 

  * *Produtos:* InfluxDB, KDB+, Prometheus.
* **Grafos:** Focados em redes de relacionamentos complexas entre nós e arestas. 

  * *Produtos:* Neo4J, Microsoft Azure CosmosDB, ArangoDB.
* **Colunar (Wide-Column):** Dados armazenados e indexados em colunas dinâmicas em vez de linhas físicas. 

  * *Produtos:* Cassandra, HBase, Microsoft Azure CosmosDB.
* **RDF (Resource Description Framework):** Bancos voltados para dados semânticos e web inteligente. 

  * *Produtos:* Marklogic, Apache Jena, Virtuoso.
* **Orientado a Objetos:** Armazenam objetos diretamente, integrando-se nativamente a linguagens OOP. 

  * *Produtos:* InterSystems Caché, Versant Object Database, ObjectStore.
* **XML Nativo:** Motores otimizados para documentos hierárquicos XML. 

  * *Produtos:* Marklogic, Oracle Berkeley DB, Virtuoso.
* **Eventos:** Registram fluxos de modificações de estados (padrão *Event Sourcing*). 

  * *Produtos:* Event Store, IBM DB2 Event Store, NEventStore.
* **Multivalores:** Suportam dados não normalizados com múltiplos valores por campo. 

  * *Produtos:* Adabas, UniData/UniVerse, jBASE.
* **Conteúdos:** Gerenciadores específicos para repositórios e sistemas de arquivos de conteúdo. 

  * *Produtos:* JackRabbit, ModeShape.
* **Navegacional:** O modelo pioneiro da década de 1960 (Hierárquico e em Rede) que persiste ativo em sistemas legados. 

  * *Produtos:* IMS, IDMS.
