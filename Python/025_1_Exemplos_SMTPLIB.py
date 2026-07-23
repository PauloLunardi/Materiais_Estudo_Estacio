import tkinter as tk
from tkinter import messagebox
import smtplib
from email.message import EmailMessage

class TelaRecuperacaoSenha:
    def __init__(self, janela):
        # Guarda a janela principal na memória do aplicativo
        self.root = janela
        self.root.title("Recuperação de Acesso")
        self.root.geometry("450x200")
        
        # --- CONFIGURAÇÕES DE REDE (DADOS DO SERVIDOR DE E-MAIL) ---
        # Endereço do servidor SMTP do seu provedor (Ex: ://gmail.com)
        self.SERVIDOR_SMTP = "://provedor.com"
        # Porta 587 é o padrão mundial para conexões com criptografia STARTTLS
        self.PORTA_SMTP = 587
        # O e-mail oficial que a sua empresa usa para disparar mensagens automáticas
        self.REMETENTE = "sistema@empresa.com"
        # Senha de aplicativo gerada na conta do e-mail (não é a sua senha comum de login)
        self.SENHA_SISTEMA = "senha_de_aplicativo_aqui"

        # --- CONSTRUÇÃO DOS ELEMENTOS VISUAIS (INTERFACE) ---
        # Cria um texto de título grande e em negrito na tela
        self.lbl_instrucao = tk.Label(self.root, text="Recuperar Senha", font=("Arial", 14, "bold"))
        self.lbl_instrucao.pack(pady=15) # O .pack posiciona na tela e o 'pady' dá um espaço vertical

        # Cria uma linha de texto orientando o usuário
        self.lbl_email = tk.Label(self.root, text="Digite o e-mail cadastrado no sistema:", font=("Arial", 10))
        self.lbl_email.pack(pady=5)

        # Cria a caixinha em branco para o usuário digitar o e-mail dele
        self.txt_email = tk.Entry(self.root, font=("Arial", 10), width=35)
        self.txt_email.pack(pady=5)
        self.txt_email.focus() # Faz o cursor do teclado já nascer piscando dentro dessa caixa

        # Cria o botão que, ao ser clicado, chama a função 'processar_envio' lá embaixo
        self.btn_enviar = tk.Button(self.root, text="Enviar Código por E-mail", command=self.processar_envio,
                                    bg="#4CAF50", fg="white", font=("Arial", 10, "bold"))
        self.btn_enviar.pack(pady=15)

    def processar_envio(self):
        """
        Esta função cuida da lógica da tela: ela pega o texto digitado e valida se o envio deu certo.
        """
        # O método .get() entra na caixinha de texto e puxa o que o usuário escreveu. 
        # O .strip() remove espaços em branco acidentais digitados no começo ou fim.
        email_destino = self.txt_email.get().strip()

        # Validação de segurança: se a caixinha estiver vazia, interrompe o programa aqui
        if not email_destino:
            messagebox.showwarning("Campo Vazio", "Por favor, insira um endereço de e-mail!")
            return # O 'return' solto força a função a parar imediatamente

        # Passa o e-mail capturado para a função de rede e espera ela responder True ou False
        sucesso_no_envio = self.enviar_email_recuperacao(email_destino)

        # Analisa a resposta recebida da função de rede para decidir qual pop-up mostrar
        if sucesso_no_envio:
            messagebox.showinfo("Sucesso", f"Um link de redefinição foi enviado para:\n{email_destino}")
            self.txt_email.delete(0, tk.END) # Limpa a caixinha de texto para o usuário
        else:
            messagebox.showerror("Erro no Servidor", "Não foi possível estabelecer conexão com o servidor de e-mail.")

    def enviar_email_recuperacao(self, destinatario):
        """
        Esta função trabalha em segundo plano e cuida puramente do protocolo de internet (smtplib).
        """
        # 1) CRIAÇÃO DO PACOTE DA MENSAGEM (O envelope do e-mail)
        msg = EmailMessage()
        msg['Subject'] = "🔒 Redefinição de Senha de Acesso" # Define o assunto do e-mail
        msg['From'] = self.REMETENTE                        # Define quem está enviando
        msg['To'] = destinatario                            # Define quem vai receber (o e-mail da caixinha)
        
        # Define o texto que vai escrito dentro do e-mail
        msg.set_content(
            f"Olá!\n\nRecebemos uma solicitação para redefinir a senha da sua conta.\n"
            f"Use o código temporário abaixo para acessar o sistema:\n\n"
            f"👉 COD-98432\n\n"
            f"Se você não solicitou essa mudança, ignore este e-mail."
        )

        # 2) CONEXÃO DE REDE E TRANSMISSÃO DO E-MAIL
        # Usamos o 'try' porque conexões de internet podem falhar (queda de rede, senha errada, servidor fora do ar)
        try:
            # Conecta fisicamente ao endereço do servidor na porta 587
            # O 'with' garante que o Python vai fechar essa conexão mesmo se ocorrer uma queda de internet no meio
            with smtplib.SMTP(self.SERVIDOR_SMTP, self.PORTA_SMTP) as servidor:
                
                servidor.ehlo()          # O programa diz "Olá" para se identificar ao servidor SMTP
                servidor.starttls()      # Exige que a partir deste ponto toda a conversa seja criptografada
                servidor.ehlo()          # Diz "Olá" novamente, agora dentro do canal seguro e criptografado
                
                servidor.login(self.REMETENTE, self.SENHA_SISTEMA) # Autentica o usuário e senha no servidor
                servidor.send_message(msg)                         # Envia o envelope da mensagem que montamos acima
                
            return True # Se tudo correu bem e o e-mail foi transmitido, responde Verdadeiro para a tela
            
        except Exception as erro:
            # Se a internet cair ou o login falhar, o Python cai aqui e imprime o erro técnico no terminal do desenvolvedor
            print(f"Log de erro interno do sistema: {erro}")
            return False # Responde Falso para a tela, avisando que o envio falhou

# --- INICIALIZAÇÃO DO PROGRAMA ---
if __name__ == "__main__":
    app_janela = tk.Tk()
    app = TelaRecuperacaoSenha(app_janela)
    app_janela.mainloop()
