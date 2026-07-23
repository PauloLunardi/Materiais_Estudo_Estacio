def validar_cpf(cpf):
    # Removendo caracteres não numéricos
    cpf = ''.join(filter(str.isdigit, cpf))

    # Verificando se o CPF possui 11 dígitos
    if len(cpf) != 11:
        return False

    # Verificando se todos os dígitos são iguais (caso raro, mas inválido)
    if cpf == cpf[0] * 11:
        return False

    # Calculando o primeiro dígito verificador
    soma = sum(int(cpf[i]) * (10 - i) for i in range(9))
    resto = soma % 11
    if resto < 2:
        digito_verificador_1 = 0
    else:
        digito_verificador_1 = 11 - resto

    # Verificando o primeiro dígito verificador
    if int(cpf[9]) != digito_verificador_1:
        return False

    # Calculando o segundo dígito verificador
    soma = sum(int(cpf[i]) * (11 - i) for i in range(10))
    resto = soma % 11
    if resto < 2:
        digito_verificador_2 = 0
    else:
        digito_verificador_2 = 11 - resto

    # Verificando o segundo dígito verificador
    if int(cpf[10]) != digito_verificador_2:
        return False

    # CPF válido
    return True
 
# --- TRECHO PARA TESTES NO SISTEMA ---
# Exemplo fixo simulando dados vindos do banco de dados/sistema
cpf = "123.456.789-09"

# Descomente as duas linhas abaixo caso queira testar digitando seu próprio CPF no terminal:
# import os
# cpf = input("Digite o seu CPF para testar (pode usar pontos e traço): ")

if validar_cpf(cpf):
    print(f"O CPF {cpf} é válido.")
else:
    print(f"O CPF {cpf} é inválido.")


"""
===============================================================================
COMO FUNCIONA A MATEMÁTICA DO CPF (PASSO A PASSO)
===============================================================================

Para entender o cálculo do Módulo 11 na prática, vamos usar como base os 
9 primeiros dígitos: 123.456.789

1) DESCOBRINDO O PRIMEIRO DÍGITO VERIFICADOR:
A gente pega os 9 primeiros números e multiplica por uma sequência que vai de 10 até 2.

   1  x  10  =  10
   2  x   9  =  18
   3  x   8  =  24
   4  x   7  =  28
   5  x   6  =  30
   6  x   5  =  30
   7  x   4  =  28
   8  x   3  =  24
   9  x   2  =  18
  ------------------
  SOMA TOTAL = 270   <-- A soma que bateu no seu cálculo!

Com o resultado da soma (270), fazemos a divisão por 11:
   - 270 dividido por 11 dá 24.
   - 11 x 24 é igual a 264.
   - De 264 para chegar em 270, sobram 6 (esse é o resto da divisão).

Agora aplicamos a regra final: Subtrair o resto de 11.
   - 11 - 6 = 5.
   
Pronto, descobrimos que o primeiro dígito é 5.

-------------------------------------------------------------------------------

2) DESCOBRINDO O SEGUNDO DÍGITO VERIFICADOR:
O processo é quase igual, mas agora o primeiro dígito que descobrimos (o 5) 
entra no final da conta, e a sequência de multiplicação muda, indo de 11 até 2.

   1  x  11  =  11
   2  x  10  =  20
   3  x   9  =  27
   4  x   8  =  32
   5  x   7  =  35
   6  x   6  =  36
   7  x   5  =  35
   8  x   4  =  32
   9  x   3  =  27
   5  x   2  =  10   <-- O primeiro dígito entra aqui com peso 2
  ------------------
  SOMA TOTAL = 302

Fazemos a mesma conta de divisão com a nova soma (302):
   - 302 dividido por 11 dá 27.
   - 11 x 27 é igual a 297.
   - De 297 para chegar em 302, sobram 5 (resto da divisão).

Aplicamos a regra final de subtração:
   - 11 - 5 = 6.

No caso dessa sequência (123456789), os dígitos finais corretos são 56. 
Se quiséssemos que o segundo dígito terminasse em 7, a soma final precisaria 
ter dado 300, pois:
   - 300 dividido por 11 deixa resto 4.
   - 11 - 4 = 7.

Essa dinâmica garante que se você errar um único número ou inverter a ordem 
deles na digitação, a soma muda e o código acusa que o CPF é inválido.
===============================================================================
"""
