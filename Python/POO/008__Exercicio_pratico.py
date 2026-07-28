class Televisao:
    # Método Construtor: Inicializa o estado da TV com o canal atual e os limites disponíveis
    def __init__(self, pcanal, min, max):
        self.canal = pcanal  # Armazena o canal atualmente sintonizado
        self.cmin = min      # Define o limite inferior (canal mínimo)
        self.cmax = max      # Define o limite superior (canal máximo)

    # Método para voltar canais
    def muda_canal_para_baixo(self):
        # Se subtrair 1 ainda mantiver a TV dentro do limite mínimo, decrementa o canal
        if self.canal - 1 >= self.cmin:
            self.canal -= 1
        # Efeito "Loop": Se já estiver no canal mínimo, dá a volta e vai para o canal máximo
        else:
            self.canal = self.cmax

    # Método para avançar canais
    def muda_canal_para_cima(self):
        # Se somar 1 ainda mantiver a TV dentro do limite máximo, incrementa o canal
        if self.canal + 1 <= self.cmax:
            self.canal += 1
        # Efeito "Loop": Se já estiver no canal máximo, dá a volta e retorna ao canal mínimo
        else:
            self.canal = self.cmin

# --- EXECUÇÃO E TESTES DO PROGRAMA ---

# Instanciação da TV 1 iniciando no canal 9, com limite mínimo 2 e máximo 10
tv1 = Televisao(9, 2, 10)
print(f"Canal Sintonizado TV1: ", tv1.canal)
print(f"Mudando canal para cima")

# Laço que executa 19 vezes seguidas para estourar o limite máximo e testar o efeito loop
for x in range(1, 20):
    tv1.muda_canal_para_cima()
    print(f"Canal Sintonizado TV1: ", tv1.canal)

# Instanciação da TV 2 iniciando no canal 3, com os mesmos limites de canais
tv2 = Televisao(3, 2, 10)
print(f"Canal Sintonizado TV2: ", tv2.canal)
print(f"Mudando canal para baixo")

# Laço que executa 19 vezes seguidas para estourar o limite mínimo e testar o efeito loop inverso
for x in range(1, 20):
    tv2.muda_canal_para_baixo()
    print(f"Canal Sintonizado TV2: ", tv2.canal)
