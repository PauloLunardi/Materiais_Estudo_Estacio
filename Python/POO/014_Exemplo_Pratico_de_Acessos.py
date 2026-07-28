

class SensorIndustrial:
    # Atributo de classe público (compartilhado por todos os sensores)
    tipo_dispositivo = "Termômetro Digital"
    
    # Atributo de classe privado (fortemente privado)
    __chave_fabricação = "MIG-2026-X"

    def __init__(self, identificador, localizacao, calibracao_inicial):
        # 1. ATRIBUTO PÚBLICO: Livre para leitura e escrita por qualquer arquivo
        self.id = identificador
        
        # 2. ATRIBUTO PROTEGIDO: Indica que o uso deve ser restrito à classe ou subclasses
        self._local = localizacao
        
        # 3. ATRIBUTO PRIVADO (FORTEMENTE PRIVADO): Trancado e mascarado via Name Mangling
        self.__calibracao = calibracao_inicial

    # --- MÉTODOS DE DEMONSTRAÇÃO ---

    # Método Público: Interface aberta do objeto
    def ler_temperatura(self):
        return 24.5

    # Método Protegido: Comportamento restrito por convenção
    def _reiniciar_hardware(self):
        return "Hardware reiniciado."

    # Método Privado (Fortemente Privado): Algoritmo de segurança interno
    def __criptografar_dados(self):
        return "Dados codificados."


# --- AMBIENTE DE TESTES E IMPRESSÕES ---
def main():
    # Instanciando o objeto da classe
    sensor = SensorIndustrial("SN-994", "Almoxarifado Central", 0.015)

    print("=======================================================")
    print("📋 DIAGNÓSTICO DE ACESSOS E IMPRESSÕES DE COMPONENTES")
    print("=======================================================\n")

    # 1. TESTANDO COMPONENTES PÚBLICOS
    print("--- 🟢 COMPONENTES PÚBLICOS ---")
    print(f"Atributo Público (id): {sensor.id}")
    print(f"Atributo de Classe Público: {SensorIndustrial.tipo_dispositivo}")
    print(f"Método Público (ler_temperatura): {sensor.ler_temperatura()}\n")

    # 2. TESTANDO COMPONENTES PROTEGIDOS
    print("--- 🟡 COMPONENTES PROTEGIDOS ---")
    # Funciona diretamente, mas a IDE/Editor emitirá um alerta visual de má prática
    print(f"Atributo Protegido (_local): {sensor._local}")
    print(f"Método Protegido (_reiniciar_hardware): {sensor._reiniciar_hardware()}\n")

    # 3. TESTANDO COMPONENTES PRIVADOS (FORTEMENTE PRIVADOS)
    print("--- 🔴 COMPONENTES PRIVADOS (FORTEMENTE PRIVADOS) ---")
    
    # Tentativa de ler o Atributo Privado
    try:
        print(f"Atributo Privado (__calibracao): {sensor.__calibracao}")
    except AttributeError:
        print("Atributo Privado (__calibracao): BLOQUEADO! O Python impede o acesso direto.")

    # Tentativa de ler o Método Privado
    try:
        print(f"Método Privado (__criptografar_dados): {sensor.__criptografar_dados()}")
    except AttributeError:
        print("Método Privado (__criptografar_dados): BLOQUEADO! Função oculta na memória.")

    # Tentativa de ler o Atributo de Classe Privado
    try:
        print(f"Atributo de Classe Privado (__chave_fabricação): {SensorIndustrial.__chave_fabricação}")
    except AttributeError:
        print("Atributo de Classe Privado (__chave_fabricação): BLOQUEADO! Indisponível fora da classe.\n")

    # 4. BURLE DE SEGURANÇA (APENAS PARA FINS DIDÁTICOS DE ANÁLISE DE MEMÓRIA)
    print("--- 🔬 CASO EXCEPCIONAL: BURLANDO O ENCAPSULAMENTO COM NAME MANGLING ---")
    print("Se usarmos o padrão '_NomeDaClasse__nome', o Python revela o dado trancado:")
    print(f"Burlado - Atributo Privado: {sensor._SensorIndustrial__calibracao}")
    print(f"Burlado - Método Privado: {sensor._SensorIndustrial__criptografar_dados()}")
    print(f"Burlado - Atributo de Classe Privado: {SensorIndustrial._SensorIndustrial__chave_fabricação}\n")
    
    print("=======================================================")

if __name__ == "__main__":
    main()

"""
O que acontece quando esse arquivo roda?
Os blocos Público e Protegido imprimem os valores direto na tela.
O bloco Privado (Fortemente Privado) aciona os mecanismos de proteção try/except. 
O interpretador desvia para a mensagem de bloqueio porque, de fora da classe, as assinaturas __calibracao e __criptografar_dados deixaram de existir textualmente devido ao Name Mangling.
O bloco de Burle prova o comportamento físico do interpretador, revelando que os dados ainda estão lá, mas sob uma nova roupagem interna estruturada pelo Python.
"""
