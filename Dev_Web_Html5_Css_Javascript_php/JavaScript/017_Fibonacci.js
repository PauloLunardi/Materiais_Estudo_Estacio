/*
  Função Fibonacci utilizando laço FOR.

  A sequência de Fibonacci segue a lógica:
  1, 1, 2, 3, 5, 8, 13, 21...

  Cada número é a soma dos dois anteriores.
*/

/*
  Gera toda a sequência de Fibonacci
  até a posição informada.
*/

const fibonacci = (x) => {

    let sequencia = [1];

    if (x === 0) {
        return sequencia;
    }

    sequencia.push(1);

    let fm1 = 1;
    let fm2 = 1;
    let fm;

    for (let i = 2; i <= x; i++) {

        fm = fm1 + fm2;

        sequencia.push(fm);

        fm2 = fm1;
        fm1 = fm;
    }

    return sequencia;
}
