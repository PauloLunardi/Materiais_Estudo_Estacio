/*
  Função Fibonacci utilizando laço FOR.

  A sequência de Fibonacci segue a lógica:
  1, 1, 2, 3, 5, 8, 13, 21...

  Cada número é a soma dos dois anteriores.
*/

const fibonacci = (x) => {

    // Casos iniciais da sequência
    if (x === 0 || x === 1) {
        return 1;
    }

    let fm1 = 1; // Fibonacci anterior
    let fm2 = 1; // Fibonacci atual
    let fm;      // Resultado temporário

    // Calcula a sequência até a posição desejada
    for (let i = 2; i <= x; i++) {

        fm = fm1 + fm2;

        fm2 = fm1;
        fm1 = fm;
    }

    return fm;
}
