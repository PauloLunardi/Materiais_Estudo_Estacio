"""
Este arquivo ilustra a interação avançada entre objetos, onde uma classe gerencia uma coleção (lista) preenchida por instâncias de outra classe.
"""

# Arquivo: CarrinhoDeCompras.py

# Importamos a classe do primeiro arquivo para usá-la como tipo de dado
from Produto import Produto

class CarrinhoDeCompras:
    def __init__(self, cliente_nome):
        self.cliente = cliente_nome
        # Atributo do tipo lista criado vazio, pronto para acumular objetos do tipo Produto
        self.itens = []

    # Método que recebe um objeto Produto inteiro como parâmetro de referência
    def adicionar_item(self, produto_objeto):
        # Adiciona a referência do objeto recebido diretamente na lista interna
        self.itens.append(produto_objeto)
        print(f"-> {produto_objeto.nome} adicionado ao carrinho de {self.cliente}.")

    # Método com retorno: varre a lista de objetos e calcula a soma total dos preços
    def calcular_total_carrinho(self):
        total_pago = 0.0
        # Percorre cada objeto armazenado dentro da nossa lista de itens
        for produto in self.itens:
            # Acessa o atributo público '.preco' de cada instância individualmente
            total_pago += produto.preco
        return total_pago


# --- Ambiente de Testes Isolado ---
def main():
    # 1. Criamos os objetos dos produtos individualmente
    prod1 = Produto("Mouse Gamer", 20, 150.00)
    prod2 = Produto("Monitor 24'", 5, 899.90)

    # 2. Criamos o objeto do carrinho de compras do cliente
    meu_carrinho = CarrinhoDeCompras("Marcos")

    # 3. Passamos as instâncias dos produtos para dentro do método do carrinho
    meu_carrinho.adicionar_item(prod1)
    meu_carrinho.adicionar_item(prod2)

    # 4. Exibimos o fechamento financeiro calculando os dados dos objetos inseridos
    valor_final = meu_carrinho.calcular_total_carrinho()
    print(f"Total a pagar pelo carrinho de {meu_carrinho.cliente}: R$ {valor_final:.2f}")

if __name__ == "__main__":
    main()
