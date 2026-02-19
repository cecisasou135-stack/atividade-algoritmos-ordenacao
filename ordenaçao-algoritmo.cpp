#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais para contagem, conforme as dicas
long long comparacoes = 0;
long long movimentacoes = 0;

void criarVetorDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++; // Conta cada comparação
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                movimentacoes++; // Conta cada troca
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++; // Conta cada comparação
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            movimentacoes++; // Conta cada troca
        }
    }
}

void executarTeste(char* nomeAlgoritmo, int tamanho, int tipo) {
    int *vetor = (int*)malloc(tamanho * sizeof(int));
    criarVetorDecrescente(vetor, tamanho); // Gera o pior caso

    comparacoes = 0;
    movimentacoes = 0;

    clock_t inicio, fim;
    double tempo_ms;

    inicio = clock(); //
    if (tipo == 1) bubbleSort(vetor, tamanho);
    else selectionSort(vetor, tamanho);
    fim = clock(); //

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC; //

    printf("%-15s | %-7d | %-10.2f | %-12lld | %-13lld\n", 
           nomeAlgoritmo, tamanho, tempo_ms, comparacoes, movimentacoes);

    free(vetor);
}

int main() {
    int tamanhos[] = {100, 1000, 10000};

    printf("Algoritmo       | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        executarTeste("Bubble Sort", tamanhos[i], 1);
    }
    
    for (int i = 0; i < 3; i++) {
        executarTeste("Selection Sort", tamanhos[i], 2);
    }

    return 0;
}
