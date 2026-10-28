# Testes de Sistema: Validação do Ecossistema Completo

O **Teste de Sistema** ocorre quando o software está completamente integrado. O objetivo aqui não é encontrar pequenos bugs de lógica ou falhas em funções isoladas, mas sim validar se o sistema como um todo funciona corretamente quando submetido ao seu **ambiente real e completo de operação** (envolvendo hardware, redes, bancos de dados e usuários simultâneos).

Esta etapa foca predominantemente em requisitos não funcionais e na resiliência da infraestrutura. 

Abaixo estão detalhados os principais tipos de testes de sistema:

---

## Os Tipos de Testes de Sistema

* **Teste de Recuperação (*Recovery Testing*)**
  * **O que avalia:** A capacidade do software de se recuperar de falhas críticas de hardware, quedas de energia ou interrupções de rede sem perder dados e retornando a um estado operacional estável.
  * **Na prática:** Força-se uma queda repentina do servidor ou do banco de dados enquanto uma transação complexa está ocorrendo para checar se os mecanismos de *rollback* (estorno), *failover* (redirecionamento automático) e reoficialização do sistema operam de forma transparente e segura.

* **Teste de Segurança (*Security Testing*)**
  * **O que avalia:** A robustez dos mecanismos de proteção instalados no sistema para impedir acessos não autorizados, invasões, roubo ou vazamento de dados confidenciais.
  * **Na prática:** Envolve simulações de ataques cibernéticos (como *Pentests* ou testes de invasão), tentativas de injeção de código malicioso (SQL Injection, XSS) e quebra de criptografia em APIs. O objetivo é garantir que as barreiras do software e dos servidores estejam de acordo com as leis de proteção de dados (como a LGPD).

* **Teste por Esforço / Estresse (*Stress Testing*)**
  * **O que avalia:** O comportamento do software quando submetido a demandas, cargas ou volumes de dados que **ultrapassam os limites normais** de sua especificação operacional (ponto de ruptura).
  * **Na prática:** Se um sistema foi projetado para suportar até 1.000 usuários simultâneos, o teste de estresse joga 5.000 ou 10.000 conexões de uma só vez para ver como o sistema quebra. O foco é descobrir se ele "desliga graciosamente" bloqueando novas requisições com mensagens limpas, ou se ele corrompe o banco de dados e derruba o servidor inteiro.

* **Teste de Desempenho / Carga (*Performance & Load Testing*)**
  * **O que avalia:** O tempo de resposta, a velocidade de processamento e a taxa de transferência (*throughput*) do software sob condições normais e de pico de utilização planejadas.
  * **Na prática:** Mede-se em quantos milissegundos uma tela carrega ou quanto tempo o banco leva para gerar um relatório pesado quando há um fluxo regular de usuários trabalhando. Serve para validar se o consumo de memória RAM e processamento de CPU está dentro do aceitável na infraestrutura.

* **Teste de Disponibilização / Implantação (*Deployment/Installation Testing*)**
  * **O que avalia:** O processo de instalação, atualização e configuração do software nos servidores ou lojas de aplicativos onde os usuários finais terão acesso.
  * **Na prática:** Garante que os instaladores, scripts de banco de dados e pipelines de automação (CI/CD) funcionem perfeitamente. Valida se o sistema roda sem problemas em diferentes variações de sistemas operacionais de produção ou navegadores de internet.

## Complementos Técnicos Importantes

* **Teste de Regressão (*Regression Testing*)**
  * **Conceito:** Consiste em reexecutar testes antigos que já haviam passado, sempre que uma nova funcionalidade é adicionada ou um bug é corrigido.
  * **Por que importa:** Garante que uma alteração feita em um módulo do sistema não quebrou "sem querer" outras partes do software que já estavam funcionando perfeitamente há meses. Na engenharia moderna, é uma etapa 100% automatizada.
* **Teste de Volume (*Volume Testing*)**
  * **Conceito:** Foca em entupir o banco de dados com uma quantidade massiva de registros históricos (milhões de linhas) para avaliar o comportamento do software.
  * **Por que importa:** Muitas vezes o sistema responde rápido nos primeiros meses com poucos dados, mas fica extremamente lento após um ano de uso devido a buscas ineficientes no banco. O teste de volume descobre a necessidade de criar índices ou otimizar consultas SQL preventivamente.
