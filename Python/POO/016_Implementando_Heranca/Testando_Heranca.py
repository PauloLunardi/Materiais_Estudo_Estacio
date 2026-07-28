from Cliente import Cliente
from Conta import Conta
from ContaEspecial import ContaEspecial

def main():
    cliente1 = Cliente("123", "Joao", "Rua X")
    cliente2 = Cliente("456", "Maria", "Rua W")
    cliente3 = Cliente("789", "Joana", "Rua H")

    # Inicialização das contas
    conta1 = Conta(cliente1, 1, 2000)
    conta2 = Conta(cliente2, 2, 2000)
    conta3 = ContaEspecial(cliente3, 3, 1000, 2000)

    # Impressão inicial de saldos
    print(f"Cliente: {cliente1.cpf} da conta comum {conta1.numero} possui saldo R$ {conta1.saldo}")
    print(f"Cliente: {cliente2.cpf} da conta comum {conta2.numero} possui saldo R$ {conta2.saldo}")
    print(f"Cliente: {cliente3.cpf} da conta especial {conta3.numero} possui saldo R$ {conta3.saldo} e limite R$ {conta3.limite}\n")

    # Teste de Depósito e Saque Estourado na Conta Comum
    conta2.depositar(500)
    print(f"Cliente: {cliente2.cpf} da conta comum {conta2.numero} possui saldo R$ {conta2.saldo} \n")

    conta2.sacar(3000)
    print(f"Cliente: {cliente2.cpf} da conta comum {conta2.numero} possui saldo R$ {conta2.saldo} \n")

    # Teste de Depósito e Saque Utilizando o Limite na Conta Especial
    conta3.depositar(100)  # Saldo vai para 1100, limite continua 2000
    print(f"Cliente: {cliente3.cpf} da conta especial {conta3.numero} possui saldo R$ {conta3.saldo} e limite {conta3.limite}\n")

    conta3.sacar(2000)     # Consome os 1100 de saldo e pega 900 do limite. Novo limite: 1100. Saldo: -900
    print(f"Cliente: {cliente3.cpf} da conta especial {conta3.numero} possui saldo R$ {conta3.saldo} e limite {conta3.limite}\n")

    # Tentativa de saque acima do limite disponível
    conta3.sacar(2000)     # Saldo atual (-900) + limite atual (1100) = 200 disponíveis. 200 < 2000 (Bloqueia)
    print(f"Cliente: {cliente3.cpf} da conta especial {conta3.numero} possui saldo R$ {conta3.saldo} e limite R$ {conta3.limite}\n")

if __name__ == "__main__":
    main()
