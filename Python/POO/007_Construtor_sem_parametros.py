""""
Este arquivo exemplifica um construtor sem parâmetros de entrada, onde todos os objetos nascem com um estado inicial fixo padronizado pelo próprio sistema."
"""

# Arquivo: LogDoSistema.py

class LogDoSistema:
    # Construtor sem argumentos de dados (além do self obrigatório).
    # Garante que todo objeto desta classe nasça com os mesmos valores padrão idênticos.
    def __init__(self):
        self.autenticado = False    # Todo log nasce deslogado
        self.tentativas = 0         # O contador de erros sempre começa zerado
        self.historico_erros = []   # Lista de strings para auditoria

    # Método que altera o estado interno com base em uma tentativa de ação
    def registrar_tentativa_login(self, senha_correta, senha_digitada):
        if senha_digitada == senha_correta:
            self.autenticado = True
            self.tentativas = 0
            print("Acesso concedido com sucesso.")
        else:
            self.tentativas += 1
            self.historico_erros.append(f"Falha de senha. Tentativa número: {self.tentativas}")
            print(f"Senha incorreta! Erros acumulados: {self.tentativas}")


# --- Ambiente de Testes Isolado ---
def main():
    # Instanciação limpa (note que não passamos nenhum argumento nos parênteses)
    painel_seguranca = LogDoSistema()

    # Definimos uma senha padrão para a simulação do teste
    SENHA_CORRETA = "admin123"

    # Simulando duas falhas consecutivas de digitação do usuário
    painel_seguranca.registrar_tentativa_login(SENHA_CORRETA, "12345")
    painel_seguranca.registrar_tentativa_login(SENHA_CORRETA, "senhaErrada")

    # Simulando o acerto da credencial na terceira tentativa
    painel_seguranca.registrar_tentativa_login(SENHA_CORRETA, "admin123")

    # Exibindo o histórico gravado de forma interna no objeto
    print("\n--- Relatório de Auditoria do Objeto ---")
    print(f"Status Final do Usuário: Autenticado = {painel_seguranca.autenticado}")
    print(f"Eventos registrados na memória: {painel_seguranca.historico_erros}")

if __name__ == "__main__":
    main()

