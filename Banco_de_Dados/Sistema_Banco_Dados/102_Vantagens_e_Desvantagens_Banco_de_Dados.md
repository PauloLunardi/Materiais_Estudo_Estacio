# Funcionalidades, Propriedades ACID, Vantagens e Desvantagens da Abordagem de Banco de Dados

## 1. Funcionalidades Estruturais de um SBD

Os Sistemas de Gerenciamento de Bancos de Dados (SGBDs) estendem a capacidade de manipulação através de funcionalidades nativas que mitigam os riscos do gerenciamento direto de arquivos: 

* **Controle de Redundância de Dados:** Previne a ocorrência de inconsistências, elimina a duplicação de esforços para atualização e evita o desperdício de armazenamento. O SGBD equilibra o *trade-off* técnico entre manter o dado em local único (normalização) versus permitir redundâncias controladas para ganho de performance em consultas complexas.
* **Controle de Acesso a Dados:** Implementa subsistemas de segurança, criptografia e autorização. Gerencia autenticações por credenciais individuais ou em grupos; restringe permissões a visões e frações específicas da base; bloqueia o uso de comandos e utilitários administrativos privilegiados para contas comuns.
* **Múltiplas Interfaces de Usuários e Aplicações:** Fornece linguagens de consulta declarativas para acessos casuais; APIs de comunicação para linguagens de programação; interfaces visuais com formulários e menus para usuários finais; ferramentas de gerenciamento para administradores (DBAs); e conectores para processamento em linguagem natural.
* **Representação de Relacionamentos:** Mapeia conexões lógicas complexas entre registros de forma nativa e transparente.
* **Cumprimento de Restrições de Integridade:** Valida chaves, tipos e domínios de dados em tempo real, impedindo a inserção de registros inválidos.
* **Capacidade de Backup e Recuperação (Recovery):** Garante mecanismos automáticos para salvaguardar os dados e restaurar o estado do sistema após falhas de hardware ou software.

## 2. Propriedades das Transações (O Modelo ACID)

Para sustentar o compartilhamento de dados concorrente entre múltiplos usuários sem corromper as informações, o SGBD deve assegurar estritamente quatro propriedades fundamentais: 

* **Atomicidade (Atomicity):** Garante que a transação seja tratada como uma unidade lógica indivisível. Todas as operações internas da transação devem ser executadas com sucesso absoluto; caso ocorra uma falha em qualquer etapa, a transação inteira é abortada e o banco retorna ao estado original (*rollback*).
* **Consistência (Consistency):** Assegura que uma transação movimente o banco de dados exclusivamente de um estado válido para outro estado igualmente válido. Nenhuma regra de integridade, restrição ou chave declarada pode ser violada ao término da operação.
* **Isolamento (Isolation):** Certifica que transações executadas simultaneamente operem de forma independente, sem que uma interfira no estado temporário da outra. O resultado final deve ser idêntico ao cenário em que todas as transações fossem processadas sequencialmente, uma após a outra.
* **Durabilidade (Durability):** Determina que, uma vez que a transação receba a confirmação de sucesso (*commit*), seus efeitos tornam-se permanentes no armazenamento não volátil (disco). As modificações persistem e não podem ser perdidas, mesmo diante de uma queda total de energia ou colapso do sistema operacional logo após o registro.

## 3. Análise de Viabilidade: Vantagens vs. Desvantagens

        [Abordagem SBD]
               │
      ┌────────┴────────┐
      ▼                 ▼
[Vantagens]       [Desvantagens]
• Padronização    • Overhead / Desempenho
• Produtividade   • Custos de Licença
• Integridade     • Complexidade Técnica
• Flexibilidade   • Inviável para Tempo Real

### Vantagens Corporativas

* Estabelece padrões rígidos de governança e uso de dados em toda a instituição.
* Reduz sensivelmente o tempo de desenvolvimento de novas aplicações, pois a infraestrutura de dados já está pronta.
* Oferece flexibilidade e agilidade na manutenção evolutiva das estruturas.
* Garante a disponibilidade imediata de informações íntegras e atualizadas globalmente.
* Gera economia de escala ao centralizar os recursos de TI.

### Desvantagens e Fatores de Sobrecarga

* **Overhead de Desempenho:** A presença do SGBD como camada intermediária consome poder de processamento, memória e operações de I/O, tornando o fluxo de dados global mais pesado do que o acesso direto ao sistema de arquivos.
* **Custos:** Demanda investimentos em licenças de software sofisticadas, infraestrutura de hardware robusta e constante capacitação de pessoal técnico especializado.

## 4. Cenários de Inaplicabilidade dos SBDs Tradicionais

A adoção de um SBD tradicional torna-se prejudicial ou desnecessária nos seguintes contextos específicos: 

1. **Sistemas Monousuários:** Aplicações simples operadas por apenas um usuário, onde não há necessidade de controle de concorrência ou segurança complexa.
2. **Dados Estáticos:** Repositórios de dados fixos que nunca ou raramente sofrem modificações estruturais ou inserções.
3. **Sistemas de Tempo Real Estrito (Real-Time Systems):** Aplicações com requisitos de tempo rígidos e milimétricos (ex: software de piloto automático aeronáutico, controle industrial crítico). O *overhead* e a latência causados pelo processamento do SGBD comprometem a janela temporal de resposta exigida pelo hardware.
4. **Sistemas Embarcados Limitados:** Dispositivos com restrição extrema de memória, armazenamento e energia física, que processam pouca massa de dados.

*Nota de Evolução Tecnológica:* Cenários de alto volume e velocidade massiva, como a Internet das Coisas (IoT) e Big Data, eram historicamente incompatíveis com os SGBDs relacionais tradicionais. Contudo, essa lacuna técnica motivou o desenvolvimento dos bancos de dados NoSQL, cujos modelos específicos absorvem essa dinâmica de dados escalável.
