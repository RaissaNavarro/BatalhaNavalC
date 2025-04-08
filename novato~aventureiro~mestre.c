#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

   
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    int linha_h = 2, coluna_h = 4;
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    int linha_v = 5, coluna_v = 1;
    int sobreposicao = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != 0) { //abreviei o nome das variaveis para nn me confundir.
            sobreposicao = 1;
        }
    }
    if (sobreposicao == 0) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    } else {
        printf("Os navios estão sobrepondo\n");
        return 1;
    }

    // Cone aq
    int cone[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz aq
    int cruz[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro aq
    int octaedro[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            octaedro[i][j] = 0;
        }
    }
    int meio = 2;
    for (i = 0; i < 5; i++) {
        int inicio, fim;
        if (i <= meio) {
            inicio = meio - i;
            fim = meio + i;
        } else {
            inicio = i - meio;
            fim = 4 - (i - meio);
        }
        for (j = inicio; j <= fim; j++) {
            octaedro[i][j] = 1;
        }
    }

    // Os pontos onde começam as habilidades
    int origem_cone_linha = 0, origem_cone_coluna = 2;
    int origem_cruz_linha = 4, origem_cruz_coluna = 4;
    int origem_octa_linha = 7, origem_octa_coluna = 7;

    // Funciona o cone
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_cone_linha + i;
            int c = origem_cone_coluna + j;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 && cone[i][j] == 1 && tabuleiro[l][c] == 0) {
                tabuleiro[l][c] = 5;
            }
        }
    }

    // Funciona a cruz
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_cruz_linha + i - 2;
            int c = origem_cruz_coluna + j - 2;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 && cruz[i][j] == 1 && tabuleiro[l][c] == 0) {
                tabuleiro[l][c] = 5;
            }
        }
    }

    // Funciona o octaedro
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_octa_linha + i - 2;
            int c = origem_octa_coluna + j - 2;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 && octaedro[i][j] == 1 && tabuleiro[l][c] == 0) {
                tabuleiro[l][c] = 5;
            }
        }
    }

    // Mostrando resultado final do tabuleiro
    printf("Tabuleiro final:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else if (tabuleiro[i][j] == 3) {
                printf("N ");
            } else if (tabuleiro[i][j] == 5) {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
