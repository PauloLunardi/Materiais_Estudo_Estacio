# Controle de Transacao em Banco de Dados

Este documento aborda os fundamentos do controle transacional em sistemas gerenciadores de banco de dados, detalhando o comportamento das requisicoes, os tipos de falhas, as propriedades fundamentais ACID e o ciclo de estados de uma transacao. 

## 1. Transacoes em Banco de Dados e Concorrencia

* Uma transacao e uma unidade logica de processamento que encapsula uma ou mais requisicoes das aplicacoes.
* Uma transacao de Leitura executa exclusivamente operacoes de busca de dados sem alterar o estado do banco.
* Uma transacao de Leitura-gravacao realiza alteracoes estruturais ou de registros no armazenamento fisico.
* A Atualizacao perdida ocorre quando duas transacoes alteram o mesmo dado simultaneamente e uma sobrescreve a outra.
* A Atualizacao temporaria (Leitura suja) acontece quando uma transacao le um dado modificado por outra que ainda nao foi confirmada.
* O Resumo incorreto surge quando uma transacao calcula funcoes de agregacao enquanto outra modifica os registros envolvidos.
* A Leitura nao repetitiva ocorre quando uma transacao le o mesmo registro duas vezes e obtem valores diferentes devido a outra confirmacao.
* Se uma transacao for cancelada, o SGBD executa o rollback, revertendo todas as alteracoes para manter o estado anterior.
* Se uma transacao for executada com sucesso, o SGBD realiza o commit, tornando as modificacoes permanentes em disco.

## 2. Tipos de Falhas em Sistemas de Banco de Dados

* **Falha do computador:** Queda de energia ou travamento de hardware que limpa a memoria volatil (RAM) repentinamente.
* **Erro de transacao ou sistema:** Erros logicos no codigo (como divisao por zero) ou estouro de memoria do SGBD.
* **Condicoes de excecao:** Situacoes detectadas pela transacao que interrompem o fluxo (como saldo insuficiente em conta).
* **Falha de disco e catastrofes:** Danos fisicos nos HDs/SSDs, incendios ou inundacoes que destroem o armazenamento.

## 3. Matriz de Propriedades Fundamentais (ACID)

```text

Propriedade            Conceito e Comportamento Tecnico No Motor do SGBD
Atomicidade            Tudo ou nada. A transacao executa por completo ou nenhuma alteracao e mantida.
Consistencia           Preservacao de regras. A transacao leva o banco de um estado valido para outro estado valido.
Isolamento             Invisibilidade concorrente. Operacoes simultaneas nao interferem no resultado umas das outras.
Durabilidade           Persistencia garantida. Os dados gravados apos o commit nao sao perdidos mesmo em quedas de energia.

```

### 4. Estados de uma Transacao no Ciclo de Vida

* **Ativo:** O estado inicial onde a transacao comeca sua execucao e continua processando os comandos lidos.
* **Parcialmente confirmado:** O ponto atingido apos a execucao do ultimo comando, mas antes da gravacao fisica final no disco.
* **Falha:** O estado assumido quando o SGBD detecta que a execucao normal nao pode mais prosseguir devido a erros.
* **Cancelado (Aborted):** O estado definitivo apos o banco reverter todas as alteracoes (completando o rollback).
* **Confirmado (Committed):** O estado definitivo de sucesso onde as alteracoes sao persistidas permanentemente nos arquivos.

## 5. Exemplo Pratico de Gerenciamento Transacional

```sql

-- Estruturacao de cenario para teste de atomicidade
CREATE TABLE conta_corrente (
    id_conta INT PRIMARY KEY,
    titular VARCHAR(50) NOT NULL,
    saldo NUMERIC(12,2) CHECK (saldo >= 0)
);

INSERT INTO conta_corrente (id_conta, titular, saldo) VALUES 
(1, 'Carlos Eduardo', 1000.00),
(2, 'Beatriz Souza', 200.00);

-- 1. Simulacao de transacao bem-sucedida (Estado: Confirmado)
BEGIN;

UPDATE conta_corrente SET saldo = saldo - 100 WHERE id_conta = 1;
UPDATE conta_corrente SET saldo = saldo + 100 WHERE id_conta = 2;

COMMIT;

-- 2. Simulacao de condicao de excecao e falha (Estado: Cancelado)
BEGIN;

UPDATE conta_corrente SET saldo = saldo - 1500 WHERE id_conta = 1; 
-- O comando acima falhara devido a restricao CHECK (saldo >= 0)

-- O SGBD assume o estado de Falha e exige o desfazimento completo
ROLLBACK;

```
