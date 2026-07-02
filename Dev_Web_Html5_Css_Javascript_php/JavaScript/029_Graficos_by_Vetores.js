let valores = [];

const addValor = (x) => {
    // Insere na lista um par contendo: [próxima_posição, valor_x]
    valores.push([valores.length + 1, x]);
}

const media = () => {
    let soma = 0;
    
    // Percorre cada par [posição, valor] contido na matriz
    for (x of valores) {
        // Soma apenas o valor, que está armazenado no índice 1 do par
        soma += x;
    }
    
    // Divide a soma total pela quantidade de elementos da matriz
    return soma / valores.length;
}
