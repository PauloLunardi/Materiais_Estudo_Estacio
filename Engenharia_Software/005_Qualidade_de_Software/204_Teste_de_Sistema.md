# Engenharia de Testes de Sistema: Abordagens Não Funcionais e Operacionais

O **Teste de Sistema** valida o software como um todo, em sua infraestrutura completa e integrada. Diferente dos testes unitários ou funcionais comuns (que buscam saber se um botão funciona), os testes de sistema concentram-se em atributos **não funcionais** e operacionais — avaliando resiliência, segurança, comportamento sob estresse e os processos de implantação.

```
                     [ MODELO DE TESTES DE SISTEMA ]
                                    |
     =================================================================

     |             |                |                |               |
     v             v                v                v               v
[RECUPERAÇÃO]  [SEGURANÇA]      [ESFORÇO]      [DESEMPENHO]  [DISPONIBILIZAÇÃO]
```

---

## 1. Teste de Recuperação (Recovery Testing)
Avalia a capacidade do sistema de se recuperar de falhas operacionais, quedas de energia, interrupções de rede ou travamentos de hardware sem perder a integridade dos dados. Ele força o software a falhar para medir o tempo e a eficácia do seu reestabelecimento.

* **Objetivo Principal:** Medir o *RTO* (Tempo Objetivo de Recuperação) e o *RPO* (Ponto Objetivo de Recuperação).
* **Exemplo Prático:** Derrubar intencionalmente o servidor de banco de dados principal no meio de uma transação financeira pesada e checar se o mecanismo de *failover* (comutação para o servidor reserva) e o *rollback* (estorno seguro de dados incompletos) funcionaram perfeitamente.

---

## 2. Teste de Segurança (Security Testing)
Verifica se as políticas de proteção de dados, integridade e privacidade do software são invioláveis. Ele busca vulnerabilidades na infraestrutura, nas APIs e no código que possam expor informações sigilosas a usuários mal-intencionados.

* **Objetivo Principal:** Mitigar brechas como injeção de código (SQL Injection), quebras de autenticação e vazamento de chaves privadas.
* **Exemplo Prático:** Executar testes de intrusão (*PenTests*), simulações de ataques cruzados (XSS) e análises estáticas/dinâmicas no código para garantir conformidade com regulamentações de proteção de dados (como a LGPD).

---

## 3. Teste de Esforço ou Estresse (Stress Testing)
Avalia o comportamento do software quando submetido a condições extremas que ultrapassam os limites planejados de infraestrutura ou capacidade operacional. O foco aqui não é a velocidade, mas descobrir o ponto de ruptura do sistema (*breaking point*) e garantir que ele quebre de forma graciosa, sem corromper dados.

* **Objetivo Principal:** Identificar gargalos e como o sistema se comporta quando faltam recursos de CPU, memória ou banco de dados.
* **Exemplo Prático:** Inundar o sistema de e-commerce com 10 vezes mais requisições por segundo do que o limite máximo de hardware suportado, garantindo que o software exiba uma mensagem amigável de erro em vez de congelar todo o servidor.

---

## 4. Teste de Desempenho (Performance Testing)
Mede o tempo de resposta, a taxa de transferência (*throughput*) e a utilização de recursos do software sob cargas de trabalho normais ou previsíveis. Garante que o software cumpra os requisitos acordados de velocidade e eficiência para o usuário.

* **Objetivo Principal:** Garantir a estabilidade e a rapidez das respostas em cenários cotidianos.
* **Exemplo Prático:** Avaliar se o tempo médio de carregamento da página principal ou de uma consulta de relatórios se mantém abaixo de 2 segundos quando há 1.000 usuários navegando simultaneamente na plataforma.

---

## 5. Teste de Disponibilização (Deployment Testing / Smoke Testing)
Também conhecido como teste de instalação ou implantação, ele valida o processo de mover o software de um ambiente para o outro (por exemplo, do ambiente de homologação para a produção). Ele certifica que os instaladores, scripts de migração de banco de dados e arquivos de configuração estejam perfeitamente alinhados para que o usuário final receba a nova versão sem indisponibilidade.

* **Objetivo Principal:** Garantir que o pipeline de deploy seja previsível e que a atualização ocorra sem quebrar o ambiente real.
* **Exemplo Prático:** Rodar scripts automáticos de verificação pós-deploy (frequentemente chamados de *Smoke Tests* ou Testes de Fumaça) logo após a publicação da nova versão em produção para validar se todos os serviços essenciais, caminhos de rede e banco de dados estão acessíveis e saudáveis.
```
