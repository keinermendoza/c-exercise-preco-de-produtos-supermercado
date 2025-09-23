#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUTOS 10

typedef struct {
    char nome[20];
    float preco;
} Produto;

void imprimirArray(Produto arr[], int n);
void bubbleSortProduto(Produto arr[], int n);
void bubbleSortProdutoReverso(Produto arr[], int n);
void lerPrecos(Produto arr[], int n);
void printLine(void);
void apresentar_programa(void);

int main(void) {
    // vetor de produtos 
    Produto lista_produtos[NUM_PRODUTOS] = {
        {"Arroz", 0},
        {"Feijão Preto", 0},
        {"Macarrão", 0},
        {"Leite Integral", 0},
        {"Café Torrado", 0},
        {"Óleo de Soja", 0},
        {"Farinha de Trigo", 0},
        {"Margarina", 0},
        {"Sabão em Pó", 0},
        {"Detergente", 0},
    };

    // Apresentar programa
    apresentar_programa();

    // Pedir para o cliente colocar os preços dos produtos
    lerPrecos(lista_produtos, NUM_PRODUTOS);
    printLine();

    // Exibindo os dados originais do vetor
    printf("🗂️  Preços antes da ordenação:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printLine();

    // Aplicando o algoritmo de ordenação Bubble Sort em ordem crescente (in place)
    bubbleSortProduto(lista_produtos, NUM_PRODUTOS);

    // Exibindo o vetor ordenado em ordem crescente
    printf("📈 Preços do menor para o maior:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printLine();
    
    // Aplicando o algoritmo de ordenação Bubble Sort em ordem decrescente (in place)
    bubbleSortProdutoReverso(lista_produtos, NUM_PRODUTOS);

    // Exibindo o vetor ordenado em ordem decrescente
    printf("📉 Preços do maior para o menor:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);

    printf("\nObrigado por usar o melhor programa para ordenar produtos por preços em supermercados! Até a próxima!\n");
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
}

void bubbleSortProduto(Produto arr[], int n) {
    int ordenada = 0; // switch para terminar se a array já esta ordenada

    for (int i = 0; i < n; i++) {
        ordenada = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].preco > arr[j + 1].preco) {
                ordenada = 0; // achou um elemento não ordenado

                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if(ordenada) break;
        }
    }
}

void bubbleSortProdutoReverso(Produto arr[], int n) {
    int ordenada = 0; // switch para terminar se a array já esta ordenada

    for (int i = 0; i < n; i++) {
        ordenada = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].preco < arr[j + 1].preco) {
                ordenada = 0; // achou um elemento não ordenado

                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(ordenada) break;

    }
}

void lerPrecos(Produto arr[], int n) {
    int i = 0;
    float preco_temp; 
    char linha[50];
    char *endptr;

    printf("Por favor introduza o valor dos produtos e precione Enter:\n");
    do {
        if (i + 1 < 10) printf("0");
        printf("%d/10", i + 1);
        printf(" - %s: ", arr[i].nome);

        fgets(linha, sizeof(linha), stdin);
        preco_temp = strtof(linha, &endptr);

        if(preco_temp > 0 && *endptr == '\n'){
            arr[i].preco = preco_temp;
        } else {
            printf("❌  ERRO: só é possível utilizar números postivos.\n");
            printf("⚠️  Por favor, digite um número positivo\n");
            continue;
        }
        i++;
    } while(i < n);
}

    
void printLine(void) {printf("\n==========================\n");} 

void apresentar_programa(void) {
    printf("   ___   ____    ____   ____  ____   ____  _____   ____  ___     ___   ____       ___      ___      ____  ____     ___    __   ___   _____    \n");
    printf("  /   \\ |    \\  /    | /    ||    \\ |    ||     | /    ||   \\   /   \\ |    \\     |   \\    /  _]    |    \\|    \\   /  _]  /  ] /   \\ / ___/    \n");
    printf(" |     ||  D  )|   __||  o  ||  _  | |  | |__/  ||  o  ||    \\ |     ||  D  )    |    \\  /  [_     |  o  )  D  ) /  [_  /  / |     (   \\_     \n");
    printf(" |  O  ||    / |  |  ||     ||  |  | |  | |   __||     ||  D  ||  O  ||    /     |  D  ||    _]    |   _/|    / |    _]/  /  |  O  |\\__  |    \n");
    printf(" |     ||    \\ |  |_ ||  _  ||  |  | |  | |  /  ||  _  ||     ||     ||    \\     |     ||   [_     |  |  |    \\ |   [_/   \\_ |     |/  \\ |    \n");
    printf(" |     ||  .  \\|     ||  |  ||  |  | |  | |     ||  |  ||     ||     ||  .  \\    |     ||     |    |  |  |  .  \\|     \\     ||     |\\    |    \n");
    printf("  \\___/ |__|\\_||___,_||__|__||__|__||____||_____||__|__||_____| \\___/ |__|\\_|    |_____||_____|    |__|  |__|\\_||_____|\\__  | \\___/  \\___|    \n");
    printf("                                                                                                                          \\|            ");
    printf("\n");
    printf("O melhor programa para ordenar produtos por preços em supermercados! 🛒\n\n");
}
