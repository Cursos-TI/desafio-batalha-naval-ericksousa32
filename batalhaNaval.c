#include <stdio.h>

#define TAM 10
#define MAX 7
#define MIN 2

int main(){
    char coluna = 'A'; // Este char demarcará as colunas visualmente, de A a J.
    int tabuleiro[TAM][TAM]; // Declaração da matriz que servirá como tabuleiro.

    int navio1[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na horizontal.
    int navio2[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na vertical.
    int navio3[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na diagonal principal.
    int navio4[3] = {3,3,3}; // Inicialização do vetor correspodente ao navio que ficará na diagonal secundária.

    int pos1[2] = {4,3}; // Define a posição inicial (x,y) do navio horizontal.
    int pos2[2] = {5,2}; // Define a posição inicial (x.y) do navio vertical.
    int pos3[2] = {6,7}; // Define a posição inicial (x.y) do navio na diagonal principal.
    int pos4[2] = {2,7}; // Define a posição inicial (x.y) do navio na diagonal secundária.

    int posCone[2] = {7,7}; // Define a posição inicial da habilidade cone.
    int posCruz[2] = {4,6}; // Define a posição inicial da habilidade cruz.
    int posOcta[2] = {2,2}; // Define a posição inicial da habilidade octaedro.

    // OBS: Mesmo que a posição inicial dos navios e das habilidades já seja conhecida, o programa buscará na matriz, para exercitar a lógica de loops aninhados, optei por esse método ao invés da inserção direta.

    int cone[3][5], cruz[5][5], octaedro[5][5]; // matrizes responsáveis por armazenar a área de efeito das habilidades.

    int flag = 0; // Flag que verifica se o navio foi inserido numa posição inválida.


    printf("***TABULEIRO DE BATALHA NAVAL***\n\n");

    for(int i = 0; i < TAM; i++){ // Preenche todo o tabuleiro TAMxTAM com valor 0.
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    printf("   ");
    for(int i = 0; i < TAM; i++){ //Imprime a demarcação das colunas de A a J.
        printf("%c ", coluna);
        coluna++;
    }
    printf("\n");

    for(int i = 0; i < TAM; i++){ // Loop externo responsável pela inserção do navio horizontal.
        for(int j = 0; j < TAM; j++){ // Loop interno responsável pela inserção do navio horizontal.
            if(i == pos1[0] && j == pos1[1]){ // Busca a posição inicial do navio.
                if(pos1[1] > MAX){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será alterada.
                    flag = 1;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i][j+1] != 0 || tabuleiro[i][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será alterada.
                    flag = 2;
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
                if(pos2[0] > MAX){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será alterada.
                    flag = 3;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i+1][j] != 0 || tabuleiro[i+2][j] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será alterada.
                    flag = 4;
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
                if(pos3[0] > MAX || pos3[1] > MAX){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será alterada.
                    flag = 5;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i+1][j+1] != 0 || tabuleiro[i+2][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será alterada.
                    flag = 6;
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
                if(pos4[0] < MIN || pos4[1] > MAX){ // Verifica se o navio ficará dentro do tabuleiro (levando em conta que o tamanho fixo dos navios é 3), se não, a flag será alterada.
                    flag = 7;
                    break;
                }
                if(tabuleiro[i][j] != 0 || tabuleiro[i-1][j+1] != 0 || tabuleiro[i-2][j+2] != 0){ // Verifica se o campo está livre para inserção, se não estiver, a flag será alterada.
                    flag = 8;
                    break;
                }
                tabuleiro[i][j] = navio4[0]; // Inserção do navio.
                tabuleiro[i-1][j+1] = navio4[1];
                tabuleiro[i-2][j+2] = navio4[2];
            }
        }
    }

    for(int i = 0; i < 3; i++){ // Preenche a matriz de habilidade Cone.
        for(int j = 0; j < 5; j++){
            if(i == 0 && j == 2)
                cone[i][j] = 1;
            else if(i == 1 && (j > 0 && j < 4))
                cone[i][j] = 1;
            else if(i == 2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    for(int i = 0; i < 5; i++){ // Preenche a matriz de habilidade Cruz.
        for(int j = 0; j < 5; j++){
            if(j == 2)
                cruz[i][j] = 1;
            else if(i == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    for(int i = 0; i < 5; i++){ // Preenche a matriz de habilidade Octaedro.
        for(int j = 0; j < 5; j++){
            if((i == 0 || i == 4) && j == 2)
                octaedro[i][j] = 1;
            else if((i == 1 || i == 3) && (j > 0 && j < 4))
                octaedro[i][j] = 1;
            else if(i == 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    /*for(int i = 0; i < 5; i++){ // apenas para teste e visualização das matrizes de habilidade
        for(int j = 0; j < 5; j++){
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }*/

    // OBS: as habilidades poderiam ter sido implementadas no mesmo loop geral (for i, for j), no entanto foram feitas separadamente para facilitar a visualização.

    for(int i = 0; i < TAM; i++){ // Bloco responsável pela inserção da habilidade cone na matriz tabuleiro.
        for(int j = 0; j < TAM; j++){
            if(posCone[0] == i && posCone[1] == j){ // Localiza a posição inicial de cone.
                if(posCone[0] > 7 || posCone[1] > 7 || posCone[1] < 2){ // Verifica se é uma posição inválida.
                    flag = 9;
                    break;
                }
                for(int x = 0, a = i; x < 3; x++, a++){ // Preenche a matriz tabuleiro com a área de efeito da habilidade cone.
                    for(int y = 0, b = j; y < 5; y++, b++){
                        if(cone[x][y] == 0){
                            continue;
                        }
                        tabuleiro[a][b - 2] = cone[x][y];
                    }
                }
            }
        }
    }

    for(int i = 0; i < TAM; i++){ // Bloco responsável pela inserção da habilidade cruz na matriz tabuleiro.
        for(int j = 0; j < TAM; j++){
            if(posCruz[0] == i && posCruz[1] == j){ // Localiza a posição inicial de cruz.
                if(posCruz[0] > 7 || posCruz[0] < 2 || posCruz[1] > 7 || posCruz[1] < 2){ // Verifica se é uma posição inválida.
                    flag = 10;
                    break;
                }
                for(int x = 0, a = i; x < 5; x++, a++){ // Preenche a matriz tabuleiro com a área de efeito da habilidade cruz.
                    for(int y = 0, b = j; y < 5; y++, b++){
                        if(cruz[x][y] == 0){
                            continue;
                        }
                        tabuleiro[a - 2][b - 2] = cruz[x][y];
                    }
                }
            }
        }
    }

    for(int i = 0; i < TAM; i++){ // Bloco responsável pela inserção da habilidade octaedro na matriz tabuleiro.
        for(int j = 0; j < TAM; j++){
            if(posOcta[0] == i && posOcta[1] == j){ // Localiza a posição inicial de octaedro.
                if(posOcta[0] > 7 || posOcta[0] < 2 || posOcta[1] > 7 || posOcta[1] < 2){ // Verifica se é uma posição inválida.
                    flag = 11;
                    break;
                }
                for(int x = 0, a = i; x < 5; x++, a++){ // Preenche a matriz tabuleiro com a área de efeito da habilidade octaedro.
                    for(int y = 0, b = j; y < 5; y++, b++){
                        if(octaedro[x][y] == 0){
                            continue;
                        }
                        tabuleiro[a - 2][b - 2] = octaedro[x][y];
                    }
                }
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

    printf("\n");

    switch(flag){ // De acordo com o valor de flag, o programa irá orientar o usuário.
        case 1:
            printf("Navio horizontal fora dos limites do tabuleiro!\n");
            break;
        case 2:
            printf("Navio horizontal está sobrepondo outro navio!\n");
            break;
        case 3:
            printf("Navio vertical fora dos limites do tabuleiro!\n");
            break;
        case 4:
            printf("Navio vertical está sobrepondo outro navio!\n");
            break;
        case 5:
            printf("Navio na diagonal principal fora dos limites do tabuleiro!\n");
            break;
        case 6:
            printf("Navio na diagonal principal está sobrepondo outro navio!\n");
            break;
        case 7:
            printf("Navio na diagonal secundária fora dos limites do tabuleiro!\n");
            break;
        case 8:
            printf("Navio na diagonal secundária está sobrepondo outro navio!\n");
            break;
        case 9:
            printf("Habilidade cone fora dos limites do tabuleiro!\n");
            break;
        case 10:
            printf("Habilidade cruz fora dos limites do tabuleiro!\n");
            break;
        case 11:
            printf("Habilidade octaedro fora dos limites do tabuleiro!\n");
    }

    return 0;
}