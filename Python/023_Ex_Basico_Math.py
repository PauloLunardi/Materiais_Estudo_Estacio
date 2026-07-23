# ===============================================================================
# 📊 CÓDIGO ORIGINAL DA AULA (COMENTADO)
# ===============================================================================
import math

# math.sqrt(x): Calcula a raiz quadrada exata do número informado
x = math.sqrt(4)
print(x)  # Vai exibir: 2.0

# math.cos(x): Calcula o cosseno. 
# ATENÇÃO: O Python calcula isso em RADIANOS e não em graus. 
# Por isso, math.cos(90) não dá 0, dá um número quebrado muito próximo de zero.
x = math.cos(90)
print(x)  # Vai exibir: -0.4480736161291701

# math.log(x, base): Calcula o logaritmo do primeiro número na base informada.
# Aqui estamos calculando o logaritmo de 100 na base 10 (ou seja, 10 elevado a quanto dá 100?)
x = math.log(100, 10)
print(x)  # Vai exibir: 2.0



# 1) TRABALHANDO COM GRAUS E RADIANOS (Corrigindo o cosseno)
# Se você quiser o cosseno de 90 GRAUS reais, precisa converter o 90 primeiro:
angulo_radianos = math.radians(90)
cosseno_90 = math.cos(angulo_radianos)
print(f"Cosseno real de 90 graus: {cosseno_90}")  # Vai dar praticamente 0 (6.12e-17)

# 2) ARREDONDAMENTOS (Muito útil para sistemas de vendas e finanças)
preco = 4.3

# math.ceil(x): Força o arredondamento para CIMA (teto), independente das casas decimais
print(f"Arredondado para cima: {math.ceil(preco)}")  # Vai exibir: 5

# math.floor(x): Força o arredondamento para BAIXO (chão), descartando as casas decimais
print(f"Arredondado para baixo: {math.floor(preco)}")  # Vai exibir: 4

# 3) CONSTANTES MATEMÁTICAS PRONTAS
# O módulo math já vem com valores famosos salvos na memória com precisão máxima
print(f"Valor exato de Pi: {math.pi}")  # Vai exibir: 3.141592653589793
print(f"Valor da constante de Euler (e): {math.e}")  # Vai exibir: 2.718281828459045

# 4) Seno
# Convertemos 45 graus para radianos e aplicamos o math.sin
angulo_radianos_sen = math.radians(45)
x = math.sin(angulo_radianos_sen)
print(x)  # Exibe: 0.7071067811865475

# 5) Tangente
# Convertemos 45 graus para radianos e aplicamos o math.tan
angulo_radianos_tan = math.radians(45)
x = math.tan(angulo_radianos_tan)
print(x)  # Exibe: 0.9999999999999999 (Aproximadamente 1.0)

