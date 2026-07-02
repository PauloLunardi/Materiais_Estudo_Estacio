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

// Desenha o gráfico de linha básico
const drawBasic = () => {
    // Inicializa a tabela de dados estruturada do Google Charts
    var data = new google.visualization.DataTable();
    // Define as colunas do gráfico: Posição (Eixo X) e Valor X (Eixo Y)
    data.addColumn('number', 'Pos');
    data.addColumn('number', 'X');
    // Alimenta o gráfico adicionando todas as linhas da matriz 'valores' de uma vez
    data.addRows(valores);

    // Configura os títulos que vão aparecer nos eixos H (horizontal) e V (vertical)
    var options = { hAxis: { title: 'Posicao' }, vAxis: { title: 'Valor de X' } };

    // Aponta para a div HTML onde o gráfico de linha será renderizado
    var chart = new google.visualization.LineChart(document.getElementById('chart_div'));
    
    // Desenha o gráfico na tela aplicando os dados e as configurações de títulos
    chart.draw(data, options);
}
