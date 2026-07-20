# Você foi designado para criar um programa em Python para um caixa de supermercado. 
# O programa deve solicitar ao cliente a quantidade de cada produto adquirido e calcular o total da compra com base nos preços unitários dos itens. 
# Utilize os conceitos de atribuição, entrada e saída de dados para implementar o programa.

# Preço dos produtos
preco_hamburguer = 18.50
preco_batata = 10.00
preco_refrigerante = 6.50

# Entrada de dados
quant_hamburguer = int(input("Quantidade de hambúrgueres: "))
quant_batata = int(input("Quantidade de batatas: "))
quant_refrigerante = int(input("Quantidade de refrigerantes: "))

# Cálculo do total
total = (
    preco_hamburguer * quant_hamburguer +
    preco_batata * quant_batata +
    preco_refrigerante * quant_refrigerante
)

# Saída de dados
print(f"Total do pedido: R$ {total:.2f}")
