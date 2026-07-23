import math

# Função para calcular as raízes da equação de segundo grau
def calcular_raizes(a, b, c):
  # Calcula o discriminante
  delta = b ** 2 - 4 * a * c

  # Verifica se o discriminante é positivo, negativo ou zero
  if delta > 0:
    # duas raizes reais e distintas
    # math.sqrt(delta): Calcula a raiz quadrada exata do valor de delta
    raiz1 = (-b + math.sqrt(delta)) / (2 * a)
    raiz2 = (-b - math.sqrt(delta)) / (2 * a)
    return (raiz1, raiz2)
  elif delta == 0:
    # uma raiz real (duas raizes reais e iguais)
    raiz = -b / (2 * a)
    return (raiz,)
  else:
    # Raizes complexas (discriminante negativo)
    parte_real = -b / (2 * a)
    
    # math.sqrt(-delta): Como delta é negativo, usamos o sinal de menos (-delta) 
    # para torná-lo positivo antes de calcular a raiz, evitando que o Python quebre.
    parte_imaginaria = math.sqrt(-delta) / (2 * a)
    
    # complex(real, imaginaria): Função nativa do Python que une as duas partes 
    # e cria um número complexo legítimo, adicionando a letra 'j' automaticamente.
    raiz1 = complex(parte_real, parte_imaginaria)
    raiz2 = complex(parte_real, -parte_imaginaria)
    return (raiz1, raiz2)

# solicitando os coeficientes ao usuario
a = float(input("digite o coeficiente a: "))
b = float(input("digite o coeficiente b: "))
c = float(input("digite o coeficiente c: "))

# calculando as raizes
raizes = calcular_raizes(a, b, c)

# Imprimindo as raizes
if len(raizes) == 2:
  print(f"As raizes da equação são: {raizes[0]} e {raizes[1]}")
else:
  print(f"A raiz da equação é: {raizes[0]}")
