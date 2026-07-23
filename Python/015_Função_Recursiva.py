# Função recursiva contagem regressiva

def regressiva(x):
  print(x)
  if x > 0:
    regressiva(x - 1)
  else:
    print('acabou a contagem recursiva')

regressiva(10)

# Modo não Recursiva
for y in range (10, -1, -1):
  print(y)
print('acabou a contagem não recursiva')

"""
10
9
8
7
6
5
4
3
2
1
0
acabou a contagem recursiva
10
9
8
7
6
5
4
3
2
1
0
acabou a contagem não recursiva
"""
