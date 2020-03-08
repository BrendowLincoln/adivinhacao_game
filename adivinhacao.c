#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS_INCIAIS 1000
#define NIVEL_FACIL 20
#define NIVEL_MEDIO 15
#define NIVEL_DIFICIL 5
#define NEGATIVO 0

int main(void) {

    int jogar_de_novo = 0;

    while (jogar_de_novo == 0) {

        printf("\n\n");
        printf("|           /\\                                              |\n");
        printf("|          /  \\                                             |\n");
        printf("|         /    \\                     BEM VINDO AO           |\n");
        printf("|        /  <0> \\                 JOGO DA ADIVINHAÇÃO       |\n");
        printf("|       /________\\                                          |\n");
        printf("|      /__I___I___\\                                         |\n");
        printf("|     /_I___I___I__\\                                        |\n");
        printf("|    /I___I___I___I_\\                                       |\n");
        printf("|   /___I___I___I___I\\                                      |\n");
        printf("\n\n");


        double pontos = PONTOS_INCIAIS;

        int nivel;
        int totaldetentativas;
        int acertou;
        int chute;
        int limite;
        int ja_chutou = 0;

        int continuar = 1;    

        printf("Qual o limite dos números: ");
        scanf("%d", &limite);

        srand(time(0));
        int numerosecreto = rand() % limite;

        printf("________________________________________________________\n");
        printf("Qual o nível de dificuldade?\n");
        printf("\n");
        printf("(1) Fácil\n");
        printf("(2) Médio\n");
        printf("(3) Difícil\n");
        printf("\n");
        printf("Nível: ");
        scanf(("%d"), &nivel);
        printf("\n");

        /*Utilização da estrutura de switch/case para escolher os níveis.*/

        switch(nivel) {
            case 1:
                totaldetentativas = NIVEL_FACIL;
                break;
            case 2:
                totaldetentativas = NIVEL_MEDIO;
                break;
            default:
                totaldetentativas = NIVEL_DIFICIL;
                break;
        }



        for(int i = 1; i <= totaldetentativas; i++) {

            printf("--------------------------------------------------\n");
            printf("Tentativa %d de %d\n", i, totaldetentativas);
            printf("\n");

            printf("Chute um número: ");
            scanf("%d", &chute);
            printf("\n");

            /* Início - Bloco de comparação de erros.*/

            if(chute < 0 || chute > limite) {
                i--;
                printf("\n\n");
                printf("ERRO 001 - Entrada invalida!\n");
                printf("\n\n");
                continue;
            }

            if(chute == ja_chutou){
                i--;
                printf("\n\n");
                printf("ERRO 02 - Já chutou esse número!\n");
                printf("\n\n");
                continue;
            }

            /*Final - Bloco de comparação de erros.*/


            acertou = chute == numerosecreto;
            int maior = chute > numerosecreto;

            if(acertou) {
                break;
            } else if(maior) {
                printf("Seu chute foi maior do que o número secreto...\n");
                printf("\n");
            } else {
                printf("Seu chute foi menor do que o número secreto...\n");
                printf("\n");
            }

            ja_chutou = chute;

        }

            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;

        if(acertou) {
            printf("\n");
            printf("________________________________________________________\n");
            printf("     _.-'''''-._ \n");
            printf("   .'  _     _  '.\n");
            printf("  /   (_)   (_)   \\\n");
            printf(" |  ,           ,  |\n");
            printf(" |  \\`.       .`/  |\n");
            printf(" \\  '.`'\"\"'\"`.'  /\n");
            printf("   '.  `'---'`  .'\n");
            printf("     '-._____.-'\n");
            printf("\n");
            printf("PARABÉÉÉÉÉNNNNNSS!!! Você acertou!\n");
            printf("________________________________________________________\n");
            printf("Você fez %.2f pontos\n", pontos);
            printf("\n");
        } else {
            printf("\n");
            printf("________________________________________________________\n");
            printf("    .-\"\"\"\"\"\"-.\n");
            printf("  .'          '.\n");
            printf(" /   O      O   \\ \n");
            printf(":           `    :\n");
            printf("|                |\n");
            printf(":   .------.     :\n");
            printf(" \\ '        '   /\n");
            printf("  '.          .'\n");
            printf("    '-......-'\n");
            printf("\n");
            printf("Você perdeu! Tente novamente...\n");
            printf("________________________________________________________\n");
            printf("\n");
        }

        printf("Jogar outra vez?\n");
        printf("\n");
        printf("[1] SIM\n");
        printf("[2] NÂO\n");
        printf("Escolha: ");
        scanf("%d", &continuar);

        switch(continuar) {
            case 1: 
                jogar_de_novo;
                continue;
            default:
                jogar_de_novo++;
        }
    }

}