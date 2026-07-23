# modulo random
import random

# Cria um laço de repetição que vai rodar exatamente 10 vezes (de 0 a 9)
for i in range(10):
    
    # Gera um número decimal aleatório (float) entre 0.0 e 1.0 e guarda na variável 'vnr'
    vnr = random.random()
    
    # NOTA DE ESTUDO: O 'random.seed()' define a semente inicial do gerador aleatório.
    # Como ele foi colocado vazio DENTRO do laço 'for', ele fica reiniciando a semente 
    # usando o relógio do sistema a cada volta. O retorno dele é sempre vazio ('None').
    vnr1 = random.seed()
    
    # Imprime o número decimal aleatório gerado nesta volta do laço
    print(vnr)
    
    # Imprime o valor da variável 'vnr1' (que sempre exibirá 'None' na tela)
    print(vnr1)
