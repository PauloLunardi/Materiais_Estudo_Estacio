# O Padrão ISO/IEC 9126: Engenharia de Qualidade de Produto

A **ISO/IEC 9126** é uma das normas internacionais mais clássicas e influentes para a avaliação da qualidade do produto de software. Embora tenha sido posteriormente evoluída pela série ISO/IEC 25010 (SQuaRE), a sua estrutura original de **6 características fundamentais** ainda serve como a base conceitual para o design de testes e para a definição de requisitos não funcionais na engenharia moderna.

A norma divide a qualidade do produto no seguinte modelo estrutural:

```
                  [ ISO/IEC 9126: QUALIDADE DE PRODUTO ]
                                     |
     =================================================================

     |             |             |             |             |       |
     v             v             v             v             v       v
[FUNCIONAL.]  [CONFIABIL.]  [USABILID.]   [EFICIÊNC.]   [MANUTEN.]  [PORTABIL.]
```

---

## 1. Funcionalidade (Functionality)
Avalia se o software fornece as funções corretas para satisfazer as necessidades explícitas e implícitas do usuário quando utilizado sob condições especificadas. Responde à pergunta: **"O software faz o que é necessário?"**

* **Adequação:** Capacidade do software de realizar as tarefas propostas de forma apropriada ao objetivo do negócio.
* **Acurácia:** Capacidade de fornecer resultados ou efeitos corretos, precisos e com o grau de conformidade exigido.
* **Interoperabilidade:** Aptidão do sistema para interagir de forma segura e fluida com outros sistemas especificados.
* **Conformidade com a Funcionalidade:** Adesão a normas, convenções, leis ou regulamentações de mercado aplicáveis às funções.
* **Segurança de Acesso:** Habilidade de proteger informações e dados contra acessos, alterações ou destruições não autorizadas.

---

## 2. Confiabilidade (Reliability)
Mede a capacidade do software de manter seu nível de desempenho sob condições estabelecidas por um período de tempo determinado. Responde à pergunta: **"O software é estável e seguro contra falhas?"**

* **Maturidade:** Frequência com que o software manifesta falhas devido a defeitos ou bugs internos do código.
* **Tolerância a Falhas:** Habilidade do sistema de manter um nível especificado de desempenho mesmo em casos de falhas de hardware, infraestrutura ou erros de operação.
* **Recuperabilidade:** Capacidade do software de restabelecer seu nível de desempenho operacional e recuperar os dados afetados diretamente após uma falha de sistema.
* **Conformidade com a Confiabilidade:** Adesão do produto a normas e padrões técnicos voltados à estabilidade e resiliência de sistemas.

---

## 3. Usabilidade (Usability)
Avalia o esforço necessário que o usuário precisa despender para interagir, operar e compreender o sistema. Responde à pergunta: **"O software é fácil de usar e aprender?"**

* **Inteligibilidade:** Facilidade com que o usuário compreende a lógica do software, descobrindo se ele é adequado para sanar sua dor ou necessidade.
* **Apreensibilidade:** O nível de esforço técnico e cognitivo demandado para que os usuários aprendam a manusear as funcionalidades do sistema.
* **Operacionalidade:** O quão prático e fluido é o controle operacional diário do software pelo usuário (layouts intuitivos, mensagens claras, atalhos).
* **Atratividade:** O apelo estético da interface gráfica do usuário, tornando a navegação agradável.
* **Conformidade com a Usabilidade:** Alinhamento da interface e dos fluxos operacionais com os padrões internacionais e guias de acessibilidade da indústria.

---

## 4. Eficiência (Efficiency)
Analisa a relação entre o nível de desempenho do software e a quantidade de recursos de hardware ou rede utilizados sob condições estabelecidas. Responde à pergunta: **"O software é rápido e consome poucos recursos?"**

* **Comportamento em Relação ao Tempo:** Os tempos de resposta, processamento e taxas de transferência (*throughput*) na execução de tarefas específicas do sistema.
* **Utilização de Recursos:** A quantidade de memória, CPU, armazenamento de banco de dados e largura de banda que o software consome para operar.
* **Conformidade com a Eficiência:** Adesão a normas técnicas de otimização de performance e boas práticas de arquitetura computacional.

---

## 5. Facilidade de Manutenção (Maintainability)
Mede o esforço técnico necessário para executar modificações no software, incluindo correções de bugs, melhorias de desempenho ou adaptações de regras. Responde à pergunta: **"O código do software é fácil de modificar?"**

* **Analisabilidade:** A facilidade de diagnosticar deficiências, identificar causas raízes de falhas ou localizar partes do código que precisam ser alteradas.
* **Modificabilidade:** O nível de esforço requerido para alterar o código-fonte (uma alta modificabilidade significa que alterar uma parte não quebra outras aleatoriamente).
* **Estabilidade:** A probabilidade e o risco de surgirem efeitos inesperados ou novos bugs no sistema após a realização de modificações na estrutura de código.
* **Testabilidade:** A facilidade de validar as alterações realizadas no software através de testes rápidos, garantindo que o comportamento esperado se manteve estável.
* **Conformidade com a Manutenção:** Alinhamento do código com padrões de engenharia limpa (*Clean Code*, acoplamento fraco e alta coesão).

---

## 6. Portabilidade (Portability)
Avalia a capacidade do software de ser transferido de um ambiente tecnológico para outro (sejam sistemas operacionais, nuvens, navegadores ou hardwares diferentes). Responde à pergunta: **"O software roda em múltiplos ambientes?"**

* **Adaptabilidade:** A capacidade do sistema de se ajustar a diferentes ambientes de destino sem a necessidade de reescrever o código do zero (ex: design responsivo rodando em web e celular).
* **Capacidade de Instalação:** A facilidade e o esforço requeridos para instalar ou desinstalar o produto em um ambiente específico com sucesso.
* **Coexistência:** A habilidade do software de operar harmonicamente com outros sistemas independentes no mesmo ambiente compartilhado, sem conflito de recursos.
* **Capacidade de Substituição:** A viabilidade e a facilidade de usar este software no lugar de outro produto de software semelhante já existente no mesmo ecossistema.
* **Conformidade com a Portabilidade:** Alinhamento com padrões internacionais de empacotamento, containerização (como Docker) e arquitetura multiplataforma.
```
