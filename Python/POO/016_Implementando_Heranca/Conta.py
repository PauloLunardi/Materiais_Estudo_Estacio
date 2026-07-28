import datetime
from Classes.Extrato import Extrato

class Conta:

  def __init__(self, clientes, numero, saldo):
    self.clientes = clientes
    self.numero = numero
    self.saldo = saldo
    self.data_abertura = datetime.datetime.today()
    self.extrato = Extrato()

  def depositar(self, valor):
    self.saldo += valor
    self.extrato.transacoes.append(["DEPÓSITO", valor, datetime.datetime.today()])

  def sacar(self, valor):
    if (self.saldo) < valor:
      print(f"Não existe saldo suficiente na conta numero {self.numero}")
      return False
    else:
      self.saldo -= valor
      self.extrato.transacoes.append(["SAQUE", valor, datetime.datetime.today()])
      return True

  def transfere_valor(self, conta_destino, valor):
      if self.saldo < valor:
        return "Não existe saldo suficiente"
      else: 
        conta_destino.depositar(valor)
        self.saldo -= valor
        self.extrato.transacoes.append(["TRANSFERENCIA", valor, datetime.datetime.today()])
        return "Transferencia Realizada"

  def gerar_saldo(self):
    print(f"Conta: {self.numero}")
    print(f"Saldo: R${self.saldo:10.2f}")
                                        
