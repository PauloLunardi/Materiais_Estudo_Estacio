import tkinter as tk
from tkinter import messagebox

# --- FUNÇÃO DE PROCESSAMENTO COM TRATAMENTO DE ERROS ---
def div_numeros():
    try:
        # Puxa os textos digitados e os converte em números decimais (float)
        num1 = float(entry_num1.get())
        num2 = float(entry_num2.get())
        
        # Realiza a operação matemática de divisão
        resultado = num1 / num2
        
        # Se a conta der certo, exibe um pop-up de sucesso com o resultado
        messagebox.showinfo("Resultado", f"O quociente é : {resultado}")
        
    except ValueError:
        # Captura o erro caso o usuário digite letras, símbolos ou deixe em branco
        messagebox.showerror("Erro", "Por favor, insira números válidos.")
        
    except ZeroDivisionError:
        # Captura o erro matemático clássico de tentar dividir algo por 0
        messagebox.showerror("Erro", " Divisão por zero não é permitida.")

# --- CONSTRUÇÃO DA INTERFACE GRÁFICA (GUI) ---
# Inicializa a janela principal do aplicativo
janela = tk.Tk()
janela.title("Calculadora de Divisão")

# Linha 0: Cria e posiciona o texto explicativo do primeiro número à direita (sticky="e")
label_num1 = tk.Label(janela, text="Dividendo:")
label_num1.grid(row=0, column=0, padx=10, pady=5, sticky="e")

# Linha 0: Cria e posiciona a caixa de digitação para o primeiro número
entry_num1 = tk.Entry(janela)
entry_num1.grid(row=0, column=1, padx=10, pady=5)

# Linha 1: Cria e posiciona o texto explicativo do segundo número
label_num2 = tk.Label(janela, text="Divisor:")
label_num2.grid(row=1, column=0, padx=10, pady=5, sticky="e")

# Linha 1: Cria e posiciona a caixa de digitação para o segundo número
entry_num2 = tk.Entry(janela)
entry_num2.grid(row=1, column=1, padx=10, pady=5)

# Linha 2: Cria o botão que dispara a função 'div_numeros' ao receber o clique do mouse
# columnspan=2 faz o botão ocupar o espaço centralizado das duas colunas juntas
botao_div = tk.Button(janela, text="Dividir", command=div_numeros)
botao_div.grid(row=2, columnspan=2, padx=100, pady=50)

# Mantém a janela aberta e escutando os eventos/cliques do usuário na tela
janela.mainloop()
