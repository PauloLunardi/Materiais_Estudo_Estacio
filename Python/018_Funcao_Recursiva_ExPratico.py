# O problema das Torres de Hanói é um quebra-cabeça matemático e de lógica que envolve a movimentação de discos entre três pinos ou torres. 
# Escreva uma função em Python para resolver as Torres de Hanói de forma recursiva.

def mover_disco(origem, destino):
  # Remove o disco do topo da torre de origem e coloca no topo da torre de destino
  disco = origem.pop()
  destino.append(disco)

def imprimir_torres(torre_A, torre_B, torre_C):
  # Exibe o estado atual das três listas no terminal
  print("A: ", torre_A)
  print("B: ", torre_B)
  print("C: ", torre_C)
  print()

def torres_de_hanoi_recursivo(num_discos, origem, destino, auxiliar):
  # CASO BASE: Se restar apenas 1 disco, move direto da origem para o destino final
  if num_discos == 1:
    mover_disco(origem, destino)
    imprimir_torres(torre_A, torre_B, torre_C)
  else:
    # PASSO 1: Move a pilha de cima (num_discos - 1) para a torre auxiliar.
    # Note que aqui a torre 'destino' temporariamente vira a nossa 'auxiliar'.
    torres_de_hanoi_recursivo(num_discos - 1, origem, auxiliar, destino)
    
    # PASSO 2: Move o maior disco que sobrou na origem direto para o destino final.
    mover_disco(origem, destino)
    imprimir_torres(torre_A, torre_B, torre_C)
    
    # PASSO 3: Move a pilha que tínhamos deixado na torre auxiliar para cima do destino final.
    # Note que agora a torre 'auxiliar' vira a nossa 'origem'.
    torres_de_hanoi_recursivo(num_discos - 1, auxiliar, destino, origin_to_aux := origem)
    

# Resolvendo o problema recursivamente
num_disco = 3

# Inicializando as torres e os discos: cria a lista de trás para frente [3, 2, 1]
torre_A = list(range(num_disco, 0, -1))
torre_B = []
torre_C = []

# Mostrando o estado inicial antes de começar a mover
imprimir_torres(torre_A, torre_B, torre_C)

# Inicia a recursão dizendo que a torre A é a origem, C é o destino e B é a auxiliar
torres_de_hanoi_recursivo(num_disco, torre_A, torre_C, torre_B)
