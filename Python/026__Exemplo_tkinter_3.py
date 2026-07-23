import tkinter as tk
# Importamos o messagebox separadamente para exibir alertas visuais na tela
from tkinter import messagebox

class InterfaceAvancada:
    def __init__(self, janela):
        self.root = janela
        self.root.title("Sistema de Cadastro - Avançado")
        self.root.geometry("400x250")
        
        # Centraliza a janela automaticamente na tela do monitor do usuário
        self.centralizar_janela(400, 250)
        
        # Uso do '.grid()'. É o gerenciador de layout mais utilizado no mercado,
        # pois organiza a tela como se fosse uma planilha Excel (linhas e colunas).
        
        # --- LINHA 0: Título do Formulário ---
        # columnspan=2 faz o texto ocupar o espaço de duas colunas juntas
        self.lbl_titulo = tk.Label(self.root, text="Controle de Acesso", font=("Arial", 14, "bold"))
        self.lbl_titulo.grid(row=0, column=0, columnspan=2, pady=15, padx=10)
        
        # --- LINHA 1: Campo de Usuário ---
        self.lbl_usuario = tk.Label(self.root, text="Usuário:", font=("Arial", 10))
        self.lbl_usuario.grid(row=1, column=0, sticky="e", padx=10, pady=5) # 'sticky=e' alinha à direita (East)
        
        # Entry: Caixa de texto para digitação do usuário
        self.txt_usuario = tk.Entry(self.root, font=("Arial", 10), width=25)
        self.txt_usuario.grid(row=1, column=1, sticky="w", padx=10, pady=5) # 'sticky=w' alinha à esquerda (West)
        
        # Foco Automático. O cursor já nasce piscando dentro deste campo de texto
        self.txt_usuario.focus()
        
        # --- LINHA 2: Campo de Senha ---
        self.lbl_senha = tk.Label(self.root, text="Senha:", font=("Arial", 10))
        self.lbl_senha.grid(row=2, column=0, sticky="e", padx=10, pady=5)
        
        # 'show="*"' esconde os caracteres digitados, transformando-os em asteriscos por segurança
        self.txt_senha = tk.Entry(self.root, font=("Arial", 10), width=25, show="*")
        self.txt_senha.grid(row=2, column=1, sticky="w", padx=10, pady=5)
        
        # --- LINHA 3: Botões de Ação ---
        # Container (Frame) invisível apenas para organizar os botões lado a lado na mesma linha
        self.frame_botoes = tk.Frame(self.root)
        self.frame_botoes.grid(row=3, column=0, columnspan=2, pady=20)
        
        # Botão Confirmar: Executa a função 'validar_login' ao ser clicado
        self.btn_confirmar = tk.Button(self.frame_botoes, text="Entrar", command=self.validar_login, 
                                       bg="#2196F3", fg="white", font=("Arial", 10, "bold"), width=10)
        self.btn_confirmar.pack(side="left", padx=5)
        
        # Botão Limpar: Executa a função 'limpar_campos'
        self.btn_limpar = tk.Button(self.frame_botoes, text="Limpar", command=self.limpar_campos, 
                                    bg="#f44336", fg="white", font=("Arial", 10), width=10)
        self.btn_limpar.pack(side="left", padx=5)

        # 4: Captura de Eventos (Key Binding). 
        # Se o usuário apertar a tecla 'Enter' do teclado, o sistema dispara a validação automaticamente
        self.root.bind("<Return>", lambda event: self.validar_login())

    def validar_login(self):
        # O método '.get()' extrai textualmente o que está escrito dentro das caixas de entrada
        usuario = self.txt_usuario.get().strip()
        senha = self.txt_senha.get().strip()
        
        if not usuario or not senha:
            # Pop-up de aviso/erro caso algum campo esteja em branco
            messagebox.showwarning("Campos Vazios", "Por favor, preencha todos os campos!")
        elif usuario == "admin" and senha == "1234":
            # Pop-up de sucesso informando login correto
            messagebox.showinfo("Sucesso", "Login efetuado com sucesso!")
        else:
            messagebox.showerror("Erro de Acesso", "Usuário ou senha incorretos.")

    def limpar_campos(self):
        # Deleta o texto do índice 0 até o fim ('end') da caixa de digitação
        self.txt_usuario.delete(0, tk.END)
        self.txt_senha.delete(0, tk.END)
        self.txt_usuario.focus()

    def centralizar_janela(self, largura, altura):
        # Obtém as dimensões totais da tela do computador do usuário
        largura_tela = self.root.winfo_screenwidth()
        altura_tela = self.root.winfo_screenheight()
        
        # Calcula a coordenada exata para a janela nascer bem no centro do monitor
        pos_x = int((largura_tela / 2) - (largura / 2))
        pos_y = int((altura_tela / 2) - (altura / 2))
        
        # Aplica a geometria final: largura x altura + posiçao_x + posicao_y
        self.root.geometry(f"{largura}x{altura}+{pos_x}+{pos_y}")

if __name__ == "__main__":
    app_janela = tk.Tk()
    app = InterfaceAvancada(app_janela)
    app_janela.mainloop()
