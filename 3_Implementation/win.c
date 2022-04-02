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
