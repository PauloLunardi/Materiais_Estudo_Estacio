# 🖱️ Documentação Prática: Tratamento de Eventos em Python (`tkinter`)

O tratamento de eventos permite mapear e responder a ações físicas do usuário, como o movimento do mouse, cliques de botões ou pressionamento de teclas no teclado.

---

## 🔑 O Conceito de Vinculação (*Binding*)

No `tkinter`, associamos um evento físico a uma função em Python utilizando o método `.bind()`. A sintaxe padrão é:

```python
componente.bind("<NomeDoEvento>", funcao_tratadora)
```

> **Nota:** A função que vai tratar o evento obrigatoriamente precisa receber um parâmetro (geralmente chamado de `event`), que carrega detalhes como as coordenadas `x` e `y` de onde a ação aconteceu.

---

## 📁 Prática 1: Capturando os Movimentos do Mouse (`eventomouse.py`)

Este código monitora o movimento do mouse dentro da janela e exibe as coordenadas `X` e `Y` em tempo real. O evento nativo para rastreamento de movimento é o `<Motion>`.

```python
import tkinter as tk

# 1. Função para mapear as coordenadas do mouse
def monitorar_movimento(event):
    # event.x e event.y capturam a posição exata do cursor em pixels
    texto_coordenadas = f"Mouse está em -> X: {event.x} | Y: {event.y}"
    lbl_status.config(text=texto_coordenadas)

# 2. Criando a janela principal
janela = tk.Tk()
janela.title("Rastreador de Movimento")
janela.geometry("400x200")

# 3. Criando o rótulo de instrução
lbl_status = tk.Label(janela, text="Movimente o mouse aqui dentro...", font=("Arial", 12))
lbl_status.pack(expand=True, fill="both")

# 4. Ligação (Binding) da captura do movimento com a função
# <Motion> monitora qualquer deslocamento do cursor dentro do componente
janela.bind("<Motion>", monitorar_movimento)

# 5. Rode a janela principal
janela.mainloop()
```

---

## 📁 Prática 2: Capturando o Clique do Botão Esquerdo (`eventomouse2.py`)

Este código detecta quando o usuário clica com o botão esquerdo do mouse na janela e mostra onde o clique ocorreu. O evento nativo para o botão esquerdo do mouse é o `<Button-1>`.

```python
import tkinter as tk
from tkinter import messagebox

# 1. Função para capturar o clique
def capturar_clique(event):
    # Exibe um alerta com o local exato onde o clique físico aconteceu
    mensagem = f"Você clicou na posição:\nX: {event.x}\nY: {event.y}"
    messagebox.showinfo("Clique Detectado!", mensagem)

# 2. Criando a janela principal
janela = tk.Tk()
janela.title("Detector de Cliques")
janela.geometry("400x200")

# 3. Criando o rótulo pedindo a ação do usuário
lbl_instrucao = tk.Label(janela, text="Clique em qualquer lugar desta janela", font=("Arial", 12))
lbl_instrucao.pack(expand=True, fill="both")

# 4. Ligação (Binding) do clique do mouse à função de captura
# <Button-1> representa especificamente o clique com o botão esquerdo
janela.bind("<Button-1>", capturar_clique)

# 5. Rode a janela principal
janela.mainloop()
```

---

## 📌 Tabela de Eventos Mais Utilizados para Revisão

| Código do Evento | Ação Física do Usuário |
| :--- | :--- |
| `<Motion>` | Mover o ponteiro do mouse sobre o componente. |
| `<Button-1>` | Clicar com o botão **esquerdo** do mouse. |
| `<Button-2>` | Clicar com o botão do **meio** (roda do mouse). |
| `<Button-3>` | Clicar com o botão **direito** do mouse. |
| `<Double-Button-1>` | Dar **duplo clique** com o botão esquerdo. |
| `<Key>` | Pressionar **qualquer** tecla do teclado. |
| `<Return>` | Pressionar especificamente a tecla **Enter**. |
