
class Livro:
    def __init__(self, titulo, autor, isbn):
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn

class Biblioteca:
    def __init__(self, nome):
        self.nome = nome
        self.livros = []

    def adicionar_livro(self, livro):
        self.livros.append(livro)
        print(f'Livro "{livro.titulo}" adicionado à biblioteca "{self.nome}".')

    def remover_livro(self, isbn):
        for livro in self.livros:
            if livro.isbn == isbn:
                self.livros.remove(livro)
                print(f'Livro "{livro.titulo}" removed da biblioteca "{self.nome}".')
                return
        print(f'Livro com ISBN {isbn} não encontrado na biblioteca "{self.nome}".')

    def listar_livros(self):
        if not self.livros:
            print(f'A biblioteca "{self.nome}" não tem livros.')
        else:
            print(f'Livros na biblioteca "{self.nome}":')
            for livro in self.livros:
                print(f'- {livro.titulo} por {livro.autor} (ISBN: {livro.isbn})')

    def buscar_livro_por_titulo(self, titulo):
        for livro in self.livros:
            if livro.titulo.lower() == titulo.lower():
                # Primeiro fazemos as impressões de sucesso
                print(f'\nLivro encontrado na biblioteca "{self.nome}":')
                print(f'- {livro.titulo} por {livro.autor} (ISBN: {livro.isbn})')
                # Depois entregamos o objeto e encerramos a função
                return livro
                
    # Se o laço 'for' terminar e o código chegar aqui, significa que o livro não existe
        print(f'A biblioteca "{self.nome}" não tem este livro.')
        return None


# --- Ambiente de Testes Protegido e Automatizado ---
def main():
    # Criando alguns livros
    livro1 = Livro('O Senhor dos Anéis', 'J.R.R. Tolkien', '1234567890')
    livro2 = Livro('1984', 'George Orwell', '0987654321')
    livro3 = Livro('O Apanhador no Campo de Centeio', 'J.D. Salinger', '1122334455')

    # Criando uma biblioteca
    biblioteca = Biblioteca('Biblioteca Central')

    # Adicionando livros à biblioteca
    print("--- Testando Adições ---")
    biblioteca.adicionar_livro(livro1)
    biblioteca.adicionar_livro(livro2)
    biblioteca.adicionar_livro(livro3)
    print()

    # Listando todos os livros na biblioteca
    print("--- Testando Listagem Completa ---")
    biblioteca.listar_livros()
    print()

    # Removendo um livro da biblioteca
    print("--- Testando Remoção ---")
    biblioteca.remover_livro('0987654321')
    print()

    # Listando todos os livros na biblioteca após a remoção
    print("--- Testando Listagem Após Remoção ---")
    biblioteca.listar_livros()

    # Buscando livro por titulo
    print("\n--- Testando a Nova Busca ---")
    biblioteca.buscar_livro_por_titulo('O Senhor dos Anéis')


if __name__ == "__main__":
    main()

"""
Proposta para ganho de performance, mudando de lista para dicionario{}

class BibliotecaDeAltaPerformance:
    def __init__(self, nome):
        self.nome = nome
        # Em vez de lista [], usamos Dicionário {} para busca instantânea
        self.livros = {} 

    def adicionar_livro(self, livro):
        # Guarda o objeto usando o título em minúsculo como chave de busca
        self.livros[livro.titulo.lower()] = livro

    def buscar_livro_por_titulo(self, titulo):
        # GANHO DE PROCESSAMENTO: O 'if not' confere se a biblioteca está vazia
        if not self.livros:
            print("Busca cancelada: A biblioteca está totalmente vazia.")
            return None
            
        # O método .get() busca a chave direto na memória sem fazer nenhum laço 'for'
        # É uma busca direta e instantânea, mesmo com milhões de livros
        return self.livros.get(titulo.lower(), None)
"""
