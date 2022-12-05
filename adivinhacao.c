#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>


int main () {
    //habilitando pontua��es da l�ngua portuguesa
    setlocale (LC_ALL, "Portuguese_Brazil");

    //Cabe�alho do jogo
    printf("\n\n");
    printf("*************************************\n");
    printf(" _   |~  _                           \n");
    printf("[_]--'--[_]      Bem vindo ao        \n");
    printf("|'|''`''|'|  Jogo de Adivinha��o!    \n");
    printf("| | /^\\ | |                         \n");
    printf("|_|_|I|_|_|                          \n");
    printf("*************************************\n");
    printf("\n");
    printf("VOC� PRECISA DESCOBRIR QUAL � O N�MERO SECRETO DA VEZ!\n");
    printf("\n");

    //Vari�veis que ser�o usadas durante o jogo, gerando n�mero secreto aleat�rio
    //E quantidade de pontos
    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande %100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o n�vel de dificuldade voc� quer tentar?\n");
    printf("(1)F�cil (2)M�dio (3)Dif�cil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel){
    case 1:
        numerodetentativas=15;
        break;
    case 2:
        numerodetentativas=10;
        break;
    default:
        numerodetentativas=6;
        break;
    }
    for(int i=1; i<=numerodetentativas; i++){
        printf("\n");
        printf("Voc� tem %d chances. Tentativa %d de %d:\n",numerodetentativas, tentativas, numerodetentativas);
        printf("\n");
        printf("Chute um n�mero entre 01 e 100:\n");

        scanf("%d", &chute);

        if(chute <0) {
            printf("Voc� n�o pode chutar n�meros negativos!\n");
            continue;
        }
    acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;

    if (acertou){
        break;
    }
    else if(maior){
        printf("Seu chute foi maior que o n�mero secreto, escolha um n�mero menor!\n");
    }
    else{
        printf("Seu chute foi menor que o n�mero secreto, escolha um n�mero maior!\n");
    }
    tentativas++;

    //Calcula quantidade de pontos
    double pontosperdidos = abs(chute-numerosecreto)/(double)2;
    pontos = pontos-pontosperdidos;
    }
    printf("Fim de jogo!\n");
    printf("\n\n");

    if (acertou) {
     printf("******************************************************\n");
     printf("     _.-'''''-._                                      \n");
     printf("   .'  _     _  '.                                    \n");
     printf("  /   (o)   (o)   \\              PARAB�NS!!          \n");
     printf(" |                 |   Voc� acertou o n�mero secreto! \n");
     printf(" |  \\           /  |                                 \n");
     printf("  \\  '.       .'  /                                  \n");
     printf("   '.  `'---'`  .'                                    \n");
     printf("     '-._____.-'                                      \n\n");
     printf("******************************************************\n");
     printf("Voc� acertou em %d tentativas!\n", tentativas);
     printf("Total de pontos: %.1f\n", pontos);
    }
    else {
         printf("******************************************************\n");
         printf("    .-''''''-.                                        \n");
         printf("  .'          '.                                      \n");
         printf(" /   O      O   \\                                    \n");
         printf(":           `    :            VOC� PERDEU!            \n");
         printf("|                |    O N�MERO SECRETO ERA:%d         \n",numerosecreto);
         printf(":    .------.    :   Voc� pode tentar mais uma vez!!  \n");
         printf(" \\  '        '  /                                    \n");
         printf("  '.          .'                                      \n");
         printf("    '-......-'                                        \n");
         printf("******************************************************\n");
    }

return 0;
}








