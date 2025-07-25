#include <stdio.h>

#define TAM 10

int main(){
    char coluna[TAM] = {'A','B','C','D','E','F','G','H','I','J'}; // Este vetor demarcará as colunas visualmente.
    int tabuleiro[TAM][TAM]; // Declaração da matriz que servirá como tabuleiro.

    int navio1[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na horizontal.
    int navio2[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na vertical.
    int navio3[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na diagonal principal.
    int navio4[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na diagonal secundária.

    int pos1[2] = {4,4}; // Define a posição inicial (x,y) do navio horizontal.
    int pos2[2] = {2,2}; // Define a posição inicial (x.y) do navio vertical.
    int pos3[2] = {7,7}; // Define a posição inicial (x.y) do navio na diagonal principal.
    int pos4[2] = {2,7}; // Define a posição inicial (x.y) do navio na diagonal secundária.

    int flag = 0; // Flag que verifica se o navio foi inserido numa posição inválida.

    printf("***TABULEIRO DE BATALHA NAVAL***\n\n");

    for(int i = 0; i < TAM; i++){ // Preenche todo o tabuleiro TAMxTAM com valor 0.
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    printf("   ");
    for(int i = 0; i < TAM; i++){ //Imprime a demarcação das colunas de A a J.
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for(int i = 0; i < TAM; i++){ // Loop externo responsável pela inserção do navio horizontal.
        for(int j = 0; j < TAM; j++){ // Loop interno responsável pela inserção do navio horizontal.
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

    for(int i = 0; i < TAM; i++){ // Loop externo responsável pela inserção do navio vertical.
        for(int j = 0; j < TAM; j++){ // Loop interno responsável pela inserção do navio vertical.
            if(i == pos2[0] && j == pos2[1]){ // Busca a posição inicial do navio.
                if(pos2[0] > 7){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será acrescentada.
                    flag++;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i+1][j] != 0 || tabuleiro[i+2][j] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será acrescentada.
                    flag++;
                    break;
                }
                tabuleiro[i][j] = navio2[0]; // Inserção do navio.
                tabuleiro[i+1][j] = navio2[1];
                tabuleiro[i+2][j] = navio2[2];
            }
        }
    }

    for(int i = 0; i < TAM; i++){ // Loop externo responsável pela inserção do navio na diagonal principal.
        for(int j = 0; j < TAM; j++){ // Loop interno responsável pela inserção do navio na diagonal principal.
            if(i == pos3[0] && j == pos3[1]){ // Busca a posição inicial do navio.
                if(pos3[0] > 7 || pos3[1] > 7){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será acrescentada.
                    flag++;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i+1][j+1] != 0 || tabuleiro[i+2][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será acrescentada.
                    flag++;
                    break;
                }
                tabuleiro[i][j] = navio3[0]; // Inserção do navio.
                tabuleiro[i+1][j+1] = navio3[1];
                tabuleiro[i+2][j+2] = navio3[2];
            }
        }
    }

    for(int i = 0; i < TAM; i++){ // Loop externo responsável pela inserção do navio na diagonal secundária.
        for(int j = 0; j < TAM; j++){ // Loop interno responsável pela inserção do navio na diagonal secundária.
            if(i == pos4[0] && j == pos4[1]){ // Busca a posição inicial do navio.
                if(pos4[0] < 2 || pos4[1] > 7){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será acrescentada.
                    flag++;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i-1][j+1] != 0 || tabuleiro[i-2][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será acrescentada.
                    flag++;
                    break;
                }
                tabuleiro[i][j] = navio4[0]; // Inserção do navio.
                tabuleiro[i-1][j+1] = navio4[1];
                tabuleiro[i-2][j+2] = navio4[2];
            }
        }
    }

    for(int i = 0; i < TAM; i++){ // Imprime todo o tabuleiro.
        if(i != 9){
            printf("%2d ", i+1);
        }else{
            printf("%d ", i+1);
        }
        for(int j = 0; j < TAM; j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }

    if(flag != 0){ // Verifica se a flag foi alterada, se sim, houve algum navio inválido.
        printf("\nPosição de algum navio está inválida!\n");
    }

    return 0;
}