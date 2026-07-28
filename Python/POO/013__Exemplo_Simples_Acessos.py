
class Conta:
    def __init__(self):
        # 1. Atributo Público
        self.titular = "João"
        
        # 2. Atributo Protegido (Um sublinhado)
        self._agencia = "0001"
        
        # 3. Atributo Privado / Fortemente Privado (Dois underscores)
        self.__saldo = 1000

# --- Bloco de Testes e Impressões ---
def main():
    minha_conta = Conta()

    print("--- TESTANDO AS IMPRESSÕES ---")

    # Impressão do Objeto Público (Funciona direto)
    print(f"Objeto Público: {minha_conta.titular}")

    # Impressão do Objeto Protegido (Funciona direto, mas é má prática)
    print(f"Objeto Protegido: {minha_conta._agencia}")

    # Impressão do Objeto Privado (Gera erro e cai no 'except')
    try:
        print(f"Objeto Privado: {minha_conta.__saldo}")
    except AttributeError:
        print("Objeto Privado: Erro! Não é permitido imprimir direto.")

    # Impressão do Objeto Privado Burlando com Name Mangling
    print(f"Objeto Privado Burlado: {minha_conta._Conta__saldo}")

if __name__ == "__main__":
    main()
