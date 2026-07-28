# Módulo Time (Controle de Tempo e Cronômetros)

O módulo `time` gerencia funções ligadas a contadores de tempo da máquina, formatação de carimbos de data e pausas estruturadas.

---

## 1. O Conceito de Unix Epoch (Era Unix)

O Python e a maioria dos sistemas operacionais contam o tempo baseando-se em segundos corridos desde o marco zero da computação moderna: **1º de janeiro de 1970 às 00:00:00 UTC**.
A função `time.time()` captura esse valor bruto (conhecido como *timestamp*).

```python
import time

print(time.time()) # Exibe um número gigante como: 1785113420.45
```

---

## 2. Pausas Estruturadas (time.sleep)

A função `time.sleep(segundos)` congela temporariamente a execução do thread atual do script pelo tempo determinado. É muito utilizada em loops, contadores visuais e rotinas de automação de testes.

```python
import time

print("Iniciando processo...")
time.sleep(2.5) # Pausa o programa por dois segundos e meio
print("Processo concluído.")
```

---

## 3. Medição de Performance (time.perf_counter)

Para descobrir de forma cirúrgica a velocidade de processamento de um algoritmo (como comparar busca iterativa versus recursiva), não devemos usar `time.time()`. O correto é usar o `time.perf_counter()`, que acessa o relógio de maior precisão disponível no hardware.

```python
import time

inicio = time.perf_counter()

# Bloco de código a ser testado
soma = sum(range(1000000))

fim = time.perf_counter()
print(f"Tempo total gasto: {fim - inicio} segundos.")
```
