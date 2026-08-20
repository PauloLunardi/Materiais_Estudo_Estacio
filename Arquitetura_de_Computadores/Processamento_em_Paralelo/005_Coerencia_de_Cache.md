# Coerência de Cache em Arquiteturas Multiprocessadas (UMA e NUMA)

Este documento apresenta a especificação técnica e as propriedades de design para o gerenciamento de **Coerência de Cache** em sistemas com múltiplos processadores. O foco está na análise dos protocolos de consistência de dados em arquiteturas de acesso uniforme (UMA) e acesso não uniforme (NUMA) à memória.

---

## 1. O Problema da Coerência de Cache

A coerência de memória tornou-se uma consideração crítica de projeto a partir do momento em que os computadores passaram a adotar memórias **Cache privadas** para cada processador. Como o hardware oferece caminhos de acesso alternativos aos dados (pela cópia local no cache ou pela cópia global na memória principal), surge o risco de dessincronização.

Em sistemas multiprocessadores, se o *Processador 0* e o *Processador 1* possuem uma cópia do dado `X` em seus respectivos caches, e o *Processador 0* altera esse valor, o *Processador 1* passará a ler um dado desatualizado. Garantir que todos os núcleos enxerguem a versão mais recente e idêntica de um dado na memória é o objetivo dos protocolos de coerência.

---

## 2. Coerência de Cache em Arquiteturas UMA (*Snooping*)

Em sistemas **UMA (*Uniform Memory Access*)**, os processadores compartilham uma memória física central por meio de um barramento comum e rápido. A implementação da coerência neste cenário é direta e baseia-se na técnica de **Escuta de Barramento (*Snooping / Cache Sniffing*)**:

```text
 MECANISMO DE SNOOPING EM ARQUITETURA UMA

  [ Processador A ] ──➔ Grava Novo Dado no Barramento
                             │
  ┌──────────────────────────┴──────────────────────────┐ BARRAMENTO COMUM
  │  [ Processador B ] (Escutando/Snooping...)           │
  │  ➔ "Essa escrita é do dado que está no meu cache?"   │
  │  ➔ Se SIM: DESCARTA/INVALIDA o item local.          │
  └─────────────────────────────────────────────────────┘
```

*   **Funcionamento:** Cada cache privado monitora (escuta) continuamente o barramento compartilhado. Quando um processador requisita a escrita em um item de dado, os outros processadores determinam se possuem uma cópia daquele mesmo endereço em seus caches locais.
*   **Ação de Consistência:** Se houver correspondência, o processador ou atualiza sua cópia ou, de forma mais comum, **descarta (invalida)** o item de seu cache para forçar uma nova leitura da memória principal no futuro.
*   **Trade-off:** É um protocolo simples de implementar em hardware devido ao tamanho reduzido dos caches e à velocidade do barramento compartilhado, porém gera um tráfego de dados adicional (*overhead*) que pode limitar a escalabilidade do sistema.

---

## 3. Arquiteturas CC-NUMA (*Cache Coherent NUMA*)

Em sistemas **NUMA (*Non-Uniform Memory Access*)**, a memória física é distribuída entre os diferentes nós de processamento. Quando esse modelo impõe e gerencia rigidamente a coerência de cache por hardware, ele é denominado **CC-NUMA**.

Em uma arquitetura CC-NUMA típica, cada endereço de memória física está vinculado a um **Nó Nativo (*Home Node*)**, que age como o guardião ou o diretório central daquele dado (geralmente identificado pelos bits de ordem mais alta do endereço).

### A. Protocolo de Requisição de Leitura (Tratamento de Falha de Cache)
Quando ocorre uma falha de cache (*cache miss*) em um nó remoto, ele entra em contato com o Nó Nativo daquele endereço para solicitar o dado. O Nó Nativo avalia o estado do dado sob duas condições:

1.  **Item Limpo:** Se nenhum outro nó do sistema tiver modificado esse dado, o Nó Nativo envia a cópia da memória principal diretamente para o cache do processador requisitante.
2.  **Item Sujo:** Se outro nó escreveu e modificou o dado desde a última atualização da memória principal, o Nó Nativo encaminha a requisição para o nó que detém a cópia suja. Esse nó envia o dado atualizado ao requisitante e, simultaneamente, atualiza o Nó Nativo.

### B. Protocolo de Modificação de Dados (Escrita)
*   **Propriedade Exclusiva:** O nó que deseja alterar um dado em determinado endereço deve requisitar ao Nó Nativo a propriedade exclusiva daquela informação.
*   **Sincronização:** Se o modificador não tiver a versão mais recente, ele a obtém do mesmo modo que uma requisição de leitura. Após realizar a modificação, o Nó Nativo encarrega-se de notificar e invalidar as cópias idênticas contidas nos caches de todos os outros nós remotos do sistema.

### C. Vantagens e Limitações do CC-NUMA
*   **Vantagens:** Facilita a distribuição homogênea de carga por toda a rede de computadores, designando para cada nó físico aproximadamente o mesmo número de endereços nativos. Isso aumenta a tolerância a falhas e reduz os gargalos de contenção no barramento.
*   **Limitações:** O protocolo pode sofrer uma degradação severa de desempenho se a maior parte dos acessos e modificações de dados vier de nós remotos, já que exige um alto volume de comunicações de rede e tráfego de mensagens de diretório entre os nós.

---

## 4. Taxonomia de Múltiplos Processadores e Acesso à Memória

A árvore hierárquica abaixo consolida a classificação das máquinas multiprocessadas contemporâneas divididas pelas suas topologias de comunicação com o ecossistema de memória principal:

```text
                          MULTIPROCESSADORES (MIMD)
                                      │
           ┌──────────────────────────┴──────────────────────────┐
           ▼                                                     ▼
     Sistemas Fortemente Acoplados                     Sistemas Fracamente Acoplados
     (Memória Compartilhada)                           (Memória Distribuída / Redes)
           │                                                     │
     ┌─────┴──────────────────┐                                  ▼
     ▼                        ▼                               CLUSTERS
   UMA                      NUMA
 (Snooping)                   │
                              ▼
                           CC-NUMA
                         (Diretório)
```
