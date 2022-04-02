void board()
{
    int i;

    system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",player1,x,player2,o);

        printf("  %c |  %c | %c\n",Board[0],Board[1],Board[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n",Board[3],Board[4],Board[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n",Board[6],Board[7],Board[8]);
        printf("    |    |    \n");
    }
