#include <stdio.h>

// esta Função recebe uma CÓPIA do valor
void dobrar(int x) {
  x = x * 2;
  printf("Dentro da função, o valor da cópia é: %d\n", x);
}

int main() {
  int numero = 5;
  printf("Antes de chamar a função, o valor original é: %d\n", numero);

  // Passando 'numero' por valor
  dobrar(numero);
  printf("Depois de chamar a função, o valor original é: %d\n", numero);

  return 0;
}
