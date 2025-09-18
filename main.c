#include <stdio.h>

/* Seu programa deverá ser desenvolvido em linguagem C, respeitando os seguintes requisitos:
    1. Ler ou definir um vetor com 10 valores, relacionados a um tema escolhido por você (ex.: temperaturas, vendas, notas, idades, etc.);
    2. Exibir os dados originais do vetor, antes de qualquer ordenação;
    3. Aplicar o algoritmo de ordenação Bubble Sort para organizar os dados:
        3.1 Primeiro em ordem crescente (do menor para o maior);
        3.2 Depois em ordem decrescente (do maior para o menor);
    4. Exibir o vetor ordenado nas duas formas, com saídas claras e formatadas.
*/

#define NUM_PRODUTOS 10

void imprimirArray(float arr[], int n);
void bubbleSortBasico(float arr[], int n);
void bubbleSortReverso(float arr[], int n);

int main(void) {
    // 1. Vetor com os preços de 10 produtos diferentes de um supermercado.
    float precos[] = {5.50, 89.99, 97.50, 0.99, 24.99, 8.49, 12.50, 71.25, 2.49, 7.25};

    // 2. Exibindo os dados originais do vetor
    printf("Preços antes da ordenação:\n");
    imprimirArray(precos, NUM_PRODUTOS);
    printf("\n");

    // 3.1 Aplicando o algoritmo de ordenação Bubble Sort em ordem crescente (in place)
    bubbleSortBasico(precos, NUM_PRODUTOS);

    // 4.1 Exibindo o vetor ordenado em ordem crescente
    printf("Preços do menor para o maior:\n");
    imprimirArray(precos, NUM_PRODUTOS);
    printf("\n");
    
    // 3.2 Aplicando o algoritmo de ordenação Bubble Sort em ordem decrescente (in place)
    bubbleSortReverso(precos, NUM_PRODUTOS);

    // 4.2 Exibindo o vetor ordenado em ordem decrescente
    printf("Preços do maior para o menor:\n");
    imprimirArray(precos, NUM_PRODUTOS);

    return 0;
}

void imprimirArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void bubbleSortBasico(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortReverso(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}