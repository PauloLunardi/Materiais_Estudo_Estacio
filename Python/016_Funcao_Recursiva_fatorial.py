# Função recursiva Fatorial

def fatorial(f):
  if f == 0 or f == 1:
    return 1
  else:
    return f*fatorial(f-1)

vfat = fatorial(5)
print(f'resultado recursiva fatorial: {vfat}')

# Função Fatorial NÂO Recursiva

def fatorial_nr(n):
  fat = 1
  if n ==0 or n == 1:
    return fat
  else:
    for x in range(2, n + 1):
      fat = fat*x
    return fat

vfat = fatorial_nr(5)
print(f'Reultado Iterativa Não Recursiva: {vfat}')

