"""
    Encontra o maior elemento em uma lista de números inteiros de forma não recursiva.
"""

def buscar_maior_elemento_recursivo(lista):
 
    # evita que o programa quebre se a lista vier totalmente vazia
    if not lista:
        return None

    # Se a lista tiver exatamente 1 elemento, ele já é o maior
    if len(lista) == 1:
        return lista[0]

    # Busca o maior elemento no resto da lista (fatiando a partir do índice 1)
    maior_elemento = buscar_maior_elemento_recursivo(lista[1:])
    if lista[0] > maior_elemento:
        return lista[0]
    else:
        return maior_elemento

    return maior_elemento

# Exemplo de uso testando a segurança do código
lista_vazia = []
lista_exemplo = [7, 2, 5, 1, 4, 3, 6]

print(f"Resultado com lista vazia: {buscar_maior_elemento_recursivo(lista_vazia)}") 
print(f"O maior elemento da lista é: {buscar_maior_elemento_recursivo(lista_exemplo)}")
