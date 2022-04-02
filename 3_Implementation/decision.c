int decision()
{
    char dec;
        deci:
        printf("\n\nPlayer1 %s choose the X or 0:",player1);
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
