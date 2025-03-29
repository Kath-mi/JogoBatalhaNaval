#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

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
        if (orientacao == 0) c += i;
        else if (orientacao == 1) r += i;
        else if (orientacao == 2) { r += i; c += i; }
        else { r += i; c -= i; }

        if (r >= TAMANHO || c >= TAMANHO || c < 0 || tabuleiro[r][c] == NAVIO) {
            return 0;
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

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tipo) {
    int padrao[5][5] = {0};
    
    if (tipo == 0) { // Cone
        padrao[0][2] = 1;
        padrao[1][1] = padrao[1][2] = padrao[1][3] = 1;
        padrao[2][0] = padrao[2][1] = padrao[2][2] = padrao[2][3] = padrao[2][4] = 1;
    } else if (tipo == 1) { // Cruz
        for (int i = 0; i < 5; i++) {
            padrao[2][i] = 1;
            padrao[i][2] = 1;
        }
    } else if (tipo == 2) { // Octaedro
        padrao[0][2] = padrao[1][1] = padrao[1][3] = 1;
        padrao[2][0] = padrao[2][1] = padrao[2][2] = padrao[2][3] = padrao[2][4] = 1;
        padrao[3][1] = padrao[3][3] = padrao[4][2] = 1;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int r = linha + i - 2;
            int c = coluna + j - 2;
            if (r >= 0 && r < TAMANHO && c >= 0 && c < TAMANHO && padrao[i][j]) {
                tabuleiro[r][c] = HABILIDADE;
            }
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

    int coordenadas[4][3] = {
        {2, 3, 0},
        {5, 6, 1},
        {1, 1, 2},
        {6, 8, 3}
    };

    for (int i = 0; i < 4; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        int orientacao = coordenadas[i][2];

        if (podePosicionar(tabuleiro, linha, coluna, orientacao)) {
            posicionarNavio(tabuleiro, linha, coluna, orientacao);
        }
    }

    aplicarHabilidade(tabuleiro, 3, 3, 0); // Cone
    aplicarHabilidade(tabuleiro, 6, 5, 1); // Cruz
    aplicarHabilidade(tabuleiro, 8, 8, 2); // Octaedro

    exibirTabuleiro(tabuleiro);
    return 0;
}
