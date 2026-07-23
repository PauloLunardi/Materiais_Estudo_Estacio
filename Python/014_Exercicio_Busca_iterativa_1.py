# Neste exemplo não utilizamos o LEN apenas o for

def buscar_maior_elemento(lista):
  #Se a lista estiver vazia retorna None
  if not lista:
    return None

  # Define o primeiro elemento como maior(inicialmente apenas)
  maior = lista[0]

  # Percorre cada numero da lista a partir do segundo elemento(ja definimos o 1 elemento acima como maior)
  for numero in lista[1:]:
    # ao incontrar numero maior, atualiza variavel
    if numero > maior:
      maior = numero

  return maior

# --- Exemplos de teste ---
print(buscar_maior_elemento([3, 15, 7, 22, 9]))  # Retorna 22
print(buscar_maior_elemento([-5, -2, -18, -1])) # Retorna -1
print(buscar_maior_elemento([]))                # Retorna None
