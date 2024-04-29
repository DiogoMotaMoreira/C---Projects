#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char ip, char *comp)
{
    srand(time(NULL));
    int vcomp = rand()%100;

    if (vcomp>=0 && vcomp < 33) *comp = 's';
    else if (vcomp >= 33 && vcomp < 66) *comp = 'p';
    else if (vcomp >= 66 && vcomp <=100) *comp = 'z';

    if (ip == *comp) return -1;
 
    if (ip == 's' && *comp == 'p') return 0;
 
    else if (ip == 'p' && *comp == 's') return 1;
 
    if (ip == 's' && *comp == 'z') return 1;

    else if (ip == 'z' && *comp == 's') return 0;

    if (ip == 'p' && *comp == 'z') return 0;

    else if (ip == 'z' && *comp == 'p') return 1;
}

int main()
{
    char inputPlayer;
    int val=0;
    char comp;
    printf("Welcome to Rock Paper Scissors\n");
    printf("\n");
    printf("Enter s for STONE, p for PAPER and z for SCISSOR\n");
    scanf("%c",&inputPlayer);
    if (inputPlayer != 's' && inputPlayer != 'p' && inputPlayer != 'z' )
    {
        printf("INVALID!\n");
        main();
    }
    else
    {
        val=game(inputPlayer, &comp);
    }

    if(val == -1)
    {
        printf("\n");
        printf("Game Draw!\n");
    }
    else if(val==0)
    {
        printf("\n");
        printf("Game Lose!\n");
    }
    else if (val==1)
    {
        printf("\n");
        printf("Game Win!\n");
    }
    printf("You choose : %c and Computer choose : %c\n",inputPlayer, comp);

    return 0;
}