#include <stdio.h>

// A função agora recebe um ENDERECO(ponteiro para int)
void dobrar(int* x) {
  // Acessamos o valor no ENDERECO e o modificamos
  *x = (*x) * 2;

int main() {
  int numero = 5;
  printf("Antes da função, o valor é: %d\n", numero);

  // Passamos o ENDERECO de 'numero' com o operador &
  dobrar(&numero);

  printf("Depois da função, o valor é: %d\n" numero);

  return 0;
}
