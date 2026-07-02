let valores = [];

const addValor = (x) => {
    // .split(" ") quebra o texto em vários pedaços usando o espaço como separador
    const numerosDigitados = String(x).split(" ");

    // Percorre cada pedaço que foi separado por espaço
    for (let i = 0; i < numerosDigitados.length; i++) {
        // Converte o pedaço de texto para número real
        const numero = parseFloat(numerosDigitados[i]);
        
        // Garante que só vai adicionar se o pedaço não for um espaço vazio ou texto inválido
        if (!isNaN(numero)) {
            valores.push([valores.length + 1, numero]);
        }
    }
}

const media = () => {
    let soma = 0;
    
    // Percorre cada par [posição, valor] contido na matriz
    for (let x of valores) {
        // CORREÇÃO CRUCIAL: Adicionado [1] para somar apenas o número, ignorando o índice da posição
        soma += x[1];
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
