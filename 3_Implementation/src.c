#include<stdio.h>
#include<string.h>
char x,o;
char Board[9]={'1','2','3','4','5','6','7','8','9'};
char player1[50],player2[50];
void board();
void rules();
int win();
int main()
{
    FILE *p;
    p=fopen("score.txt","a+");
    fclose(p);
    int player=1;
    int choice,score=-1;
    char symbol;
    int s;
    rules();
    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%d",&s);
    if(s==1)
    {
		read:
        p=fopen("score.txt","a+");
    printf("\nEnter name of player1:");
    scanf("%40s",player1);
    fprintf(p,"\n%s",player1);
    printf("Enter name of player2:");
    scanf("%40s",player2);
    fprintf(p,"\t%s",player2);
    fclose(p);
    if(!strcmp(player1,player2))
    {
        printf("Enter names of different players!\n\n");
        goto read;
    }
    else
        decision();
    board();

    do
    {

        player=((player%2)?1:2);
        if(player==1)
        printf("%s Type any digit from 1-9 to fill your response:- ",player1);
        else
            printf("%s Type any digit from 1-9 to fill your response:- ",player2);
        scanf("%d",&choice);
        symbol=((player==1)?x:o);
        if(choice==1 && Board[0]=='1')
            Board[0]=symbol;
        else if(choice==2 && Board[1]=='2')
            Board[1]=symbol;
        else if(choice==3 && Board[2]=='3')
            Board[2]=symbol;
        else if(choice==4 && Board[3]=='4')
            Board[3]=symbol;
        else if(choice==5 && Board[4]=='5')
            Board[4]=symbol;
        else if(choice==6 && Board[5]=='6')
            Board[5]=symbol;
        else if(choice==7 && Board[6]=='7')
            Board[6]=symbol;
        else if(choice==8 && Board[7]=='8')
            Board[7]=symbol;
        else if(choice==9 && Board[8]=='9')
            Board[8]=symbol;
        else
            {printf("Wrong Selection\n");player--;}

        score=win();
        player++;
        board();
    }while(score == -1);


    p=fopen("score.txt","a+");
    if(score==1)
    {

        if(player==2)
        {printf("\n\nPlayer1 %s Wins!\n\n",player1);fprintf(p,"\t%s",player1);
        getch();}
        else
            {printf("\n\nPlayer2 %s Wins!\n\n",player2);fprintf(p,"\t%s",player2);
        getch();
            }
        fclose(p);
    }
    else
        printf("\n\nGame Draws!\n\n");fprintf(p,"\t%s","DRAW");
        getch();
    }
    if(s==2)
    {
        int cho;
        printf("\n\n");
        printf("\tLEADERBOARD\n\n");
        char c;
        p=fopen("score.txt","r");
        while((c=getc(p))!=EOF)
        {
            printf("%c",c);
        }
        fclose(p);
        printf("\n\nPress 1 to start the game:- ");
        scanf("%d",&cho);
        if(cho==1)
            goto read;
        else
            getch();
    }
    else
    {
        printf("\n\nShould have typed 1 to play the game!\nHope to see you back soon!\n\n");
        getch();
    }
}
int win()
{
    if(Board[0]==Board[1] && Board[1]==Board[2])
        return 1;
    else if(Board[3]==Board[4] && Board[4]==Board[5])
        return 1;
    else if(Board[6]==Board[7] && Board[7]==Board[8])
        return 1;
    else if(Board[0]==Board[3] && Board[3]==Board[6])
        return 1;
    else if(Board[1]==Board[4] && Board[4]==Board[7])
        return 1;
    else if(Board[2]==Board[5] && Board[5]==Board[8])
        return 1;
    else if(Board[0]==Board[4] && Board[4]==Board[8])
        return 1;
    else if(Board[2]==Board[4] && Board[4]==Board[6])
        return 1;
    else if(Board[0]!='1' && Board[1]!='2' && Board[2]!='3' && Board[3]!='4' && Board[4]!='5' && Board[5]!='6' && Board[6]!='7' && Board[7]!='8' && Board[8]!='9')
        return 0;
    else
        return -1;
}

void board()
{
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
void rules()
{
    printf("\tTic-Tac-Toe\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game!\n\n");

}
int decision()
{
    char dec;
	deci:
        printf("\n\nPlayer1 %s choose the X or 0:",player1);
        dec=getchar();
        scanf("%c",&dec);
        {
            if(dec=='X' || dec=='x')
            {
                x='X';
                o='0';
            }
            else if(dec=='0')
            {
                x='0';
                o='X';
            }
            else
            {
                printf("Please enter either X or 0 only \n\n");
				goto deci;
            }
        }
}
