# Classe base para todos os animais
class Animal:
    def __init__(self, nome):
        self.nome = nome

    def falar(self):
        pass

    def mover(self):
        pass

# Subclasse Cachorro que sobrescreve os métodos falar e mover
class Cachorro(Animal):
    def falar(self):
        return "Au!"

    def mover(self):
        return f"{self.nome} está andando."

# Subclasse Gato que sobrescreve os métodos falar e mover
class Gato(Animal):
    def falar(self):
        return "Miau!"

    def mover(self):
        return f"{self.nome} está andando."

# Subclasse Vaca que sobrescreve os métodos falar e mover
class Vaca(Animal):
    def falar(self):
        return "Muu!"

    def mover(self):
        return f"{self.nome} está andando."

class Voador:
    def voar(self):
        return f"{self.nome} está voando."

# Mixin para animais que podem nadar
class Nadador:
    def nadar(self):
        return f"{self.nome} está nadando."

# Subclasse Pato que herda de Animal, Voador e Nadador
class Pato(Animal, Voador, Nadador):
    def falar(self):
        return "Quack!"

    def mover(self):
        return f"{self.andar()}, {self.nadar()} E {self.voar()}"

    def andar(self):
        return f"{self.nome} está andando."

# --- NOVA CLASSE: JACARÉ (Herda de Animal e Nadador) ---
class Jacare(Animal, Nadador):
    def falar(self):
        # Som característico do jacaré (ronco/Rugido)
        return "Grrr!"

    def mover(self):
        # Combina a habilidade própria de andar com a habilidade herdada de nadar
        return f"{self.andar()} E {self.nadar()}"

    def andar(self):
        return f"{self.nome} está rastejando/andando."


# Função que usa polimorfismo para chamar o método falar
def fazer_som(animal):
    return animal.falar()

# Função que usa polimorfismo para chamar o método mover
def fazer_movimento(animal):
    return animal.mover()

# --- AMBIENTE DE TESTES PROTEGIDO ---
def main():
    # Instâncias das classes
    cachorro = Cachorro('Lug')
    gato = Gato('Floquinho')
    vaca = Vaca('Mimosa')
    pato = Pato("Pato Donald")
    
    # Criando o objeto da nova classe Jacaré
    jacare = Jacare("Cuca")

    # Chamando os métodos polimórficos de som
    print("--- Testando Sons (Polimorfismo) ---")
    print(fazer_som(cachorro))  
    print(fazer_som(gato))      
    print(fazer_som(vaca))      
    print(fazer_som(pato))
    print(fazer_som(jacare))    # Saída: Grrr!
    print()

    # Chamando os métodos polimórficos de movimento
    print("--- Testando Movimentos (Polimorfismo) ---")
    print(fazer_movimento(cachorro))  
    print(fazer_movimento(gato))      
    print(fazer_movimento(vaca))      
    print(fazer_movimento(pato))  
    print(fazer_movimento(jacare))  # Saída: Cuca está rastejando/andando E Cuca está nadando.

if __name__ == "__main__":
    main()
