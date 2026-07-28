from Classes.Conta import Conta
import datetime

class ContaEspecial(Conta):
    def __init__(self, clientes, numero, saldo, limite):
        # super().__init__(clinetes, numero, saldo) chama o construtor e inicializa os atributos herdados
        super().__init__(clientes, numero, saldo)
        # atributo limite exclusivo da ContaEspecial
        self.limite = limite
        # Atributo de referência para saber o teto original do limite
        self.limite_maximo = limite

    def sacar(self, valor):
        if (self.saldo + self.limite) < valor:
            print(f"Não existe saldo suficiente conta numero {self.numero} clientes {self.clientes.cpf}")
            return False
        else:
            self.saldo -= valor
            if (self.saldo < 0):
                self.limite += self.saldo
            self.extrato.transacoes.append(["SAQUE", valor, datetime.datetime.today()])
            return True

    # --- MÉTODO SOLICITADO: DEPOSITAR COM ABATIMENTO DE LIMITE ---
    def depositar(self, valor):
        # 1. Calcula quanto do limite foi gasto/debitado
        limite_gasto = self.limite_maximo - self.limite
        
        # 2. Se houver limite para recompor
        if limite_gasto > 0:
            if valor >= limite_gasto:
                # O depósito cobre todo o limite gasto e restabelece o teto máximo
                self.limite = self.limite_maximo
                # Subtrai o que foi usado para recompor o limite do valor total do depósito
                valor -= limite_gasto
            else:
                # O depósito não é suficiente para cobrir toda a dívida do limite
                self.limite += valor
                valor = 0  # Não sobra nada para o saldo
                
        # 3. Se o limite já foi totalmente recuperado e ainda sobrou dinheiro, vai para o saldo
        if valor > 0:
            self.saldo += valor
            
        # Registra a transação no extrato herdado
        self.extrato.transacoes.append(["DEPÓSITO", valor, datetime.datetime.today()])
