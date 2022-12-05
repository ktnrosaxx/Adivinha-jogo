#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>


int main () {
    //habilitando pontuações da língua portuguesa
    setlocale (LC_ALL, "Portuguese_Brazil");

    //Cabeçalho do jogo
    printf("\n\n");
    printf("*************************************\n");
    printf(" _   |~  _                           \n");
    printf("[_]--'--[_]      Bem vindo ao        \n");
    printf("|'|''`''|'|  Jogo de Adivinhação!    \n");
    printf("| | /^\\ | |                         \n");
    printf("|_|_|I|_|_|                          \n");
    printf("*************************************\n");
    printf("\n");
    printf("VOCÊ PRECISA DESCOBRIR QUAL É O NÚMERO SECRETO DA VEZ!\n");
    printf("\n");

    //Variáveis que serão usadas durante o jogo, gerando número secreto aleatório
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
    printf("Qual o nível de dificuldade você quer tentar?\n");
    printf("(1)Fácil (2)Médio (3)Difícil\n");
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
        printf("Você tem %d chances. Tentativa %d de %d:\n",numerodetentativas, tentativas, numerodetentativas);
        printf("\n");
        printf("Chute um número entre 01 e 100:\n");

        scanf("%d", &chute);

        if(chute <0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
    acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;

    if (acertou){
        break;
    }
    else if(maior){
        printf("Seu chute foi maior que o número secreto, escolha um número menor!\n");
    }
    else{
        printf("Seu chute foi menor que o número secreto, escolha um número maior!\n");
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
     printf("  /   (o)   (o)   \\              PARABÉNS!!          \n");
     printf(" |                 |   Você acertou o número secreto! \n");
     printf(" |  \\           /  |                                 \n");
     printf("  \\  '.       .'  /                                  \n");
     printf("   '.  `'---'`  .'                                    \n");
     printf("     '-._____.-'                                      \n\n");
     printf("******************************************************\n");
     printf("Você acertou em %d tentativas!\n", tentativas);
     printf("Total de pontos: %.1f\n", pontos);
    }
    else {
         printf("******************************************************\n");
         printf("    .-''''''-.                                        \n");
         printf("  .'          '.                                      \n");
         printf(" /   O      O   \\                                    \n");
         printf(":           `    :            VOCÊ PERDEU!            \n");
         printf("|                |    O NÚMERO SECRETO ERA:%d         \n",numerosecreto);
         printf(":    .------.    :   Você pode tentar mais uma vez!!  \n");
         printf(" \\  '        '  /                                    \n");
         printf("  '.          .'                                      \n");
         printf("    '-......-'                                        \n");
         printf("******************************************************\n");
    }

return 0;
}








