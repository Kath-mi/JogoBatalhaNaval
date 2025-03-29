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

int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int r = linha, c = coluna;
        if (orientacao == 0) c += i;       // Horizontal
        else if (orientacao == 1) r += i;  // Vertical
        else if (orientacao == 2) { r += i; c += i; } // Diagonal principal
        else { r += i; c -= i; }           // Diagonal secundária

        if (r >= TAMANHO || c >= TAMANHO || c < 0 || tabuleiro[r][c] == NAVIO) {
            return 0; // Fora dos limites ou sobreposição
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int r = linha, c = coluna;
        if (orientacao == 0) c += i;
        else if (orientacao == 1) r += i;
        else if (orientacao == 2) { r += i; c += i; }
        else { r += i; c -= i; }
        tabuleiro[r][c] = NAVIO;
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

    // Definição de coordenadas e orientações
    int coordenadas[4][3] = {
        {2, 3, 0}, // Horizontal
        {5, 6, 1}, // Vertical
        {1, 1, 2}, // Diagonal principal
        {6, 8, 3}  // Diagonal secundária
    };

    // Posicionamento dos navios
    for (int i = 0; i < 4; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        int orientacao = coordenadas[i][2];

        if (podePosicionar(tabuleiro, linha, coluna, orientacao)) {
            posicionarNavio(tabuleiro, linha, coluna, orientacao);
        }
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}
