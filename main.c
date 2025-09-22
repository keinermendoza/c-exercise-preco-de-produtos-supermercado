#include <stdio.h>
#include <windows.h>

/* Seu programa deverá ser desenvolvido em linguagem C, respeitando os seguintes requisitos:
    1. Ler ou definir um vetor com 10 valores, relacionados a um tema escolhido por você (ex.: temperaturas, vendas, notas, idades, etc.);
    2. Exibir os dados originais do vetor, antes de qualquer ordenação;
    3. Aplicar o algoritmo de ordenação Bubble Sort para organizar os dados:
        3.1 Primeiro em ordem crescente (do menor para o maior);
        3.2 Depois em ordem decrescente (do maior para o menor);
    4. Exibir o vetor ordenado nas duas formas, com saídas claras e formatadas.
*/

#define NUM_PRODUTOS 10

typedef struct {
    char nome[20];
    float preco;
} Produto;

void imprimirArray(Produto arr[], int n);
void bubbleSortProduto(Produto arr[], int n);
void bubbleSortProdutoReverso(Produto arr[], int n);

int main(void) {
    SetConsoleOutputCP(CP_UTF8); // Comente esta linha se seu sistema operacional não for Windows
    SetConsoleCP(CP_UTF8); // Comente esta linha se seu sistema operacional não for Windows

    // 1. Vetor com os preços de 10 produtos diferentes de um supermercado.
    // vetor de produtos 
    Produto lista_produtos[NUM_PRODUTOS] = {
        {"Arroz", 12.35},
        {"Feijão Preto", 7.49},
        {"Macarrão", 4.25},
        {"Leite Integral", 6.99},
        {"Café Torrado", 18.75},
        {"Óleo de Soja", 5.80},
        {"Farinha de Trigo", 9.40},
        {"Margarina", 3.99},
        {"Sabão em Pó", 21.55},
        {"Detergente", 2.89},
    };

    // 2. Exibindo os dados originais do vetor
    printf("Preços antes da ordenação:\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printf("======================\n\n");

    // 3.1 Aplicando o algoritmo de ordenação Bubble Sort em ordem crescente (in place)
    bubbleSortProduto(lista_produtos, NUM_PRODUTOS);

    // 4.1 Exibindo o vetor ordenado em ordem crescente
    printf("Preços do menor para o maior:\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printf("======================\n\n");
    
    // 3.2 Aplicando o algoritmo de ordenação Bubble Sort em ordem decrescente (in place)
    bubbleSortProdutoReverso(lista_produtos, NUM_PRODUTOS);

    // 4.2 Exibindo o vetor ordenado em ordem decrescente
    printf("Preços do maior para o menor:\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);

    return 0;
}

void imprimirArray(Produto arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i + 1 < 10) printf("0");
        printf("%d.- ", i + 1);
        printf("%s: ", arr[i].nome);
        printf("%.2f ", arr[i].preco);
        printf("\n");
    }
    printf("\n");
}

void bubbleSortProduto(Produto arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].preco > arr[j + 1].preco) {
                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortProdutoReverso(Produto arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].preco < arr[j + 1].preco) {
                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}