"""
Este arquivo demonstra como um método pode alterar o estado de um atributo numérico de forma decrescente (controle de estoque) e valida a integridade antes de realizar a operação.
"""
# Arquivo: Produto.py

class Produto:
    # O inicializador define o estado inicial do produto com base nos dados fornecidos
    def __init__(self, nome, quantidade_estoque, preco_unitario):
        self.nome = nome
        self.estoque = quantidade_estoque
        self.preco = preco_unitario

    # Método modificador de estado: reduz a quantidade disponível caso haja saldo suficiente
    def dar_baixa_estoque(self, quantidade_venda):
        # Validação de segurança: o estoque não pode ficar negativo
        if self.estoque >= quantidade_venda:
            # Operador de atribuição cumulativa decrescente (-=)
            self.estoque -= quantidade_venda
            return True  # Retorna True confirmando que a baixa foi realizada
        else:
            return False # Retorna False se a quantidade solicitada for maior que o estoque

    # Método informativo: apenas exibe a situação atual da instância
    def exibir_status(self):
        print(f"Item: {self.nome} | Estoque Atual: {self.estoque} unidades | Preço: R$ {self.preco}")


# --- Ambiente de Testes Isolado ---
def main():
    # Instanciando um produto com 50 unidades no estoque inicial
    item_venda = Produto("Teclado Mecânico", 50, 250.00)
    item_venda.exibir_status()

    # Tentativa de venda válida: 10 unidades
    if item_venda.dar_baixa_estoque(10):
        print("Venda de 10 unidades aprovada!")
    else:
        print("Venda recusada: Estoque insuficiente.")
        
    item_venda.exibir_status()  # O estoque deve refletir 40 unidades agora

    # Tentativa de venda inválida: 100 unidades (maior que o estoque atual)
    if item_venda.dar_baixa_estoque(100):
        print("Venda de 100 unidades aprovada!")
    else:
        print("Venda recusada: Estoque insuficiente para 100 unidades.")

if __name__ == "__main__":
    main()

