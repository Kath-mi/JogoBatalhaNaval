#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else { // Vertical
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais fixas (poderiam ser geradas aleatoriamente ou solicitadas ao usuário)
    int linha1 = 2, coluna1 = 3; // Navio horizontal
    int linha2 = 5, coluna2 = 6; // Navio vertical

    // Verificações básicas para evitar sobreposição e estar dentro dos limites
    if (coluna1 + TAM_NAVIO <= TAMANHO) {
        posicionarNavio(tabuleiro, linha1, coluna1, 0);
    }
    if (linha2 + TAM_NAVIO <= TAMANHO) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1);
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
