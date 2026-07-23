# ===============================================================================
# 📝 PARTE 1: EXEMPLO ORIGINAL DO PROFESSOR (Abordagem Funcional / Procedural)
# ===============================================================================
from tkinter import *

janelaPrincipal = Tk()
janelaPrincipal.title("Versão do Professor")
janelaPrincipal.geometry("300x200")

# Cria o componente e define explicitamente quem é o seu container 'pai' (master)
texto = Label(janelaPrincipal, text="Minha janela exibida")

# Posiciona o texto usando coordenadas fixas em pixels (Engessado se redimensionar)
texto.place(x=50, y=100)

# Deixado comentado para não travar a execução do código de melhorias abaixo
# janelaPrincipal.mainloop()


# ===============================================================================
# 🚀 PARTE 2: VERSÃO REFATORADA (Melhores Práticas de Mercado e Uso Comercial)
# ===============================================================================
# MELHORIA 1: Importação com apelido 'as tk'. Evita poluir a memória global do 
# script e previne conflitos de nomes de funções entre bibliotecas diferentes.
import tkinter as tk

# MELHORIA 2: Uso de Orientação a Objetos (Classes). Padrão exigido no mercado 
# que elimina o uso de variáveis soltas/globais e facilita a manutenção do app.
class InterfaceProfissional:
    def __init__(self, janela):
        self.root = janela
        self.root.title("Versão Melhorada")
        self.root.geometry("300x200")
        
        # MELHORIA 3: Acesso aos componentes via prefixo 'tk.Label'
        self.texto = tk.Label(self.root, text="Minha janela exibida", font=("Arial", 11))
        
        # MELHORIA 4: Substituição do '.place()' pelo '.pack()'. 
        # O gerenciador '.pack()' calcula dinamicamente o posicionamento do texto.
        # Se o usuário esticar ou maximizar a janela, o texto se adapta e continua
        # centralizado automaticamente na tela, em vez de ficar congelado em pixels fixos.
        # O 'pady' adiciona um espaçamento interno para dar respiro ao layout.
        self.texto.pack(pady=40)

# Bloco padrão para garantir que a janela só abra se o arquivo for executado diretamente
if __name__ == "__main__":
    app_janela = tk.Tk()
    app = InterfaceProfissional(app_janela)
    app_janela.mainloop()
