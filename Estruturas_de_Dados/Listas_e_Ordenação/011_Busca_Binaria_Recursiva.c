// --- A SUA FUNÇÃO (O motor recursivo) ---
// Descrição: Procura por um 'valor' em uma fatia de um 'vetor' ORDENADO,
//            definida por 'inicio' e 'fim'.
// Pré-requisito: O vetor deve estar em ordem crescente.
// Retorno: O índice do valor se encontrado; -1 caso contrário.
int buscaBinariaRecursiva(int vetor[], int inicio, int int_fim, int valor) {
    // || CASO BASE: Se a área de busca se torna inválida (inicio > fim),
    // // o elemento não existe na lista. O trabalho da recursão para aqui.
    if (inicio > int_fim) {
        return -1;
    }

    // Calcula a posição do meio.
    // // Usar 'inicio + (fim - inicio) / 2' é mais seguro contra overflow
    // // em vetores extremamente grandes.
    int meio = inicio + (int_fim - inicio) / 2;

    // // Se o elemento do meio é o que procuramos, encontramos!
    // // Este é o outro CASO BASE (de sucesso).
    if (vetor[meio] == valor) {
        return meio;
    }

    // // PASSO RECURSIVO (Delegação):
    // // Se o elemento do meio for menor que o valor, delegamos a busca
    // // para a metade direita do vetor.
    else if (vetor[meio] < valor) {
        return buscaBinariaRecursiva(vetor, meio + 1, int_fim, valor);
    }
    // // Caso contrário, delegamos a busca para a metade esquerda.
    else {
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
    }
}
