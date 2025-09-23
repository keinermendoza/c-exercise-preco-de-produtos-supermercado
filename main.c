#include <stdio.h>
#include <stdlib.h>

// Define o número total de produtos
#define NUM_PRODUTOS 10

// Estrutura que representa um produto com nome e preço
typedef struct {
    char nome[20];
    float preco;
} Produto;

// Protótipos das funções
void imprimirArray(Produto arr[], int n);
void bubbleSortProduto(Produto arr[], int n);
void bubbleSortProdutoReverso(Produto arr[], int n);
void lerPrecos(Produto arr[], int n);
void printLine(void);
void apresentar_programa(void);

int main(void) {
    // Vetor de produtos com nomes pré-definidos e preços iniciados em 0
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

    // Apresenta a mensagem inicial
    apresentar_programa();

    // Solicita ao usuário os preços de cada produto
    lerPrecos(lista_produtos, NUM_PRODUTOS);
    printLine();

    // Mostra a lista de preços na ordem em que foram inseridos
    printf("🗂️  Preços antes da ordenação:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printLine();

    // Ordena em ordem crescente utilizando Bubble Sort
    bubbleSortProduto(lista_produtos, NUM_PRODUTOS);

    // Mostra os resultados em ordem crescente
    printf("📈 Preços do menor para o maior:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);
    printLine();
    
    // Ordena em ordem decrescente utilizando Bubble Sort
    bubbleSortProdutoReverso(lista_produtos, NUM_PRODUTOS);

    // Mostra os resultados em ordem decrescente
    printf("📉 Preços do maior para o menor:\n\n");
    imprimirArray(lista_produtos, NUM_PRODUTOS);

    // Mensagem de despedida
    printf("\nObrigado por usar o melhor programa para ordenar produtos por preços em supermercados! Até a próxima!\n");
    return 0;
}

// Imprime a lista de produtos com seus respectivos preços
void imprimirArray(Produto arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i + 1 < 10) printf("0"); // Adiciona zero à esquerda se o índice < 10
        printf("%d.- ", i + 1);
        printf("%s: ", arr[i].nome);
        printf("%.2f ", arr[i].preco);
        printf("\n");
    }
}

// Ordena em ordem crescente (do menor para o maior preço)
void bubbleSortProduto(Produto arr[], int n) {
    int ordenada = 0; // flag para verificar se o vetor já está ordenado

    for (int i = 0; i < n; i++) {
        ordenada = 1; // assume que está ordenado
        for (int j = 0; j < n - i - 1; j++) {
            // Se o preço atual for maior que o próximo, troca
            if (arr[j].preco > arr[j + 1].preco) {
                ordenada = 0; // encontrou elemento fora de ordem
                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (ordenada) break; // se não houve trocas, já está ordenado
    }
}

// Ordena em ordem decrescente (do maior para o menor preço)
void bubbleSortProdutoReverso(Produto arr[], int n) {
    int ordenada = 0;

    for (int i = 0; i < n; i++) {
        ordenada = 1;
        for (int j = 0; j < n - i - 1; j++) {
            // Se o preço atual for menor que o próximo, troca
            if (arr[j].preco < arr[j + 1].preco) {
                ordenada = 0;
                Produto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (ordenada) break; // já está ordenado
    }
}

// Solicita ao usuário os preços dos produtos com validação
void lerPrecos(Produto arr[], int n) {
    int i = 0;
    float preco_temp; 
    char linha[50];
    char *endptr;

    printf("Por favor, digite o valor dos produtos e pressione Enter:\n");
    do {
        if (i + 1 < 10) printf("0");
        printf("%d/10", i + 1);
        printf(" - %s: ", arr[i].nome);

        fgets(linha, sizeof(linha), stdin);
        preco_temp = strtof(linha, &endptr);

        // Validação: apenas números positivos são aceitos
        if (preco_temp > 0 && *endptr == '\n') {
            arr[i].preco = preco_temp;
        } else {
            printf("❌  ERRO: só é possível utilizar números positivos.\n");
            printf("⚠️  Por favor, digite um número positivo.\n");
            continue; // repete até que o usuário insira corretamente
        }
        i++;
    } while(i < n);
}

// Imprime uma linha de separação
void printLine(void) {
    printf("\n==========================\n");
}

// Apresenta o programa mostrando um ASCII Art
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
