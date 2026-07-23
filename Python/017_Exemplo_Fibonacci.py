# Docstring
# Determina o n-ésimo termo da sequência de Fibonacci de forma recursiva.

def fibo(n):
    if n == 1 or n == 2:
        return 1
    else: 
        return fibo(n - 1) + fibo(n - 2)

vfibo = fibo(6)
print(f"Resultado do Fibonacci: {vfibo}")

# Chame o help direto, sem colocar dentro de um print()
help(fibo)
