import datetime
from Classes.Extrato import Extrato

class Conta:

  def __init__(self, clientes, numero, saldo):
    self.clientes = clientes
    self.numero = numero
    self.saldo = saldo
    self.data_abertura = datetime.datetime.today()
    self.extrato = Extrato()

  def depositar(self.valor...
