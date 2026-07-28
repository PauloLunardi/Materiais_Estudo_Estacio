class Extrato:

  def __init__(self):
    self.transacoes = []

  def gerar_extrato(self, conta):
    print(f"Extrato da conta {conta}")
    for tran in self.transacoes:
      # Acesse: tran[0] para o tipo, tran[1] para o valor e tran[2] para a data
      print(f"{tran[0]:15s} {tran[1]:10.2f} {tran[2].strftime('%d/%b/%y')}")
