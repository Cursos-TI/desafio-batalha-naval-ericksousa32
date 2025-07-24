#include <stdio.h>

int main(){
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'}; // Este vetor demarcará as colunas visualmente.
    int tabuleiro[10][10]; // Declaração da matriz que servirá como tabuleiro.

    int navio1[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na horizontal.
    int navio2[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na vertical.

    int pos1[2] = {1,3}; // Define a posição inicial (x,y) do navio horizontal.
    int pos2[2] = {5,2}; // Define a posição inicial (x.y) do navio vertical.

    int flag = 0; // Flag que verifica se o navio foi inserido numa posição inválida.

    printf("***TABULEIRO DE BATALHA NAVAL***\n\n");

    for(int i = 0; i < 10; i++){ // Preenche todo o tabuleiro 10x10 com valor 0.
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    printf("   ");
    for(int i = 0; i < 10; i++){ //Imprime a demarcação das colunas de A a J.
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){ // Loop externo responsável pela inserção do navio horizontal.
        for(int j = 0; j < 10; j++){ // Loop interno responsável pela inserção do navio horizontal.
            if(i == pos1[0] && j == pos1[1]){ // Busca a posição inicial do navio.
                if(pos1[1] > 7){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será acrescentada.
                    flag++;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i][j+1] != 0 || tabuleiro[i][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será acrescentada.
                    flag++;
                    break;
                }
                tabuleiro[i][j] = navio1[0]; // Inserção do navio.
                tabuleiro[i][j+1] = navio1[1];
                tabuleiro[i][j+2] = navio1[2];
            }
        }
    }

    for(int i = 0; i < 10; i++){ // Loop externo responsável pela inserção do navio vertical.
        for(int j = 0; j < 10; j++){ // Loop interno responsável pela inserção do navio vertical.
            if(i == pos2[0] && j == pos2[1]){ // Busca a posição inicial do navio.
                if(pos2[0] > 7){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será acrescentada.
                    flag++;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i+1][j] != 0 || tabuleiro[i+2][j] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será acrescentada.
                    flag++;
                    break;
                }
                tabuleiro[i][j] = navio1[0]; // Inserção do navio.
                tabuleiro[i+1][j] = navio1[1];
                tabuleiro[i+2][j] = navio1[2];
            }
        }
    }

    for(int i = 0; i < 10; i++){ // Imprime todo o tabuleiro.
        if(i != 9){
            printf(" %d ", i+1);
        }else{
            printf("%d ", i+1);
        }
        for(int j = 0; j < 10; j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }

    if(flag != 0){ // Verifica se a flag foi alterada, se sim, houve algum navio inválido.
        printf("\nPosição de algum navio está inválida!\n");
    }

    return 0;
}