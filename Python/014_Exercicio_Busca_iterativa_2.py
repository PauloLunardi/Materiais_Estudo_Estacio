def encontrar_maior_elemento_iterativo(lista):
    """
    Encontra o maior elemento em uma lista de números inteiros de forma não recursiva.
    """
    # MELHORIA: Evita que o programa quebre se a lista vier totalmente vazia
    if not lista:
        return None

    # CASO BASE: Se a lista tiver exatamente 1 elemento, ele já é o maior
    if len(lista) == 1:
        return lista[0]

    maior_elemento = lista[0]
    for numero in lista[1:]:
        if numero > maior_elemento:
            maior_elemento = numero

    return maior_elemento

# Exemplo de uso testando a segurança do código
lista_vazia = []
lista_exemplo = [7, 2, 5, 1, 4, 3, 6]

print(f"Resultado com lista vazia: {encontrar_maior_elemento_iterativo(lista_vazia)}") 
print(f"O maior elemento da lista é: {encontrar_maior_elemento_iterativo(lista_exemplo)}")
