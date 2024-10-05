/*

Fichier des prototypes des fonctions pour la vérification du gagnant

*/

int VerifWinner(char *p)
{
    int CasePlien = 0;

    if ((p[0] == 'X' && p[1] == 'X' && p[2] == 'X') || (p[0] == 'O' && p[1] == 'O' && p[2] == 'O')) // Horizontale
    {
        return 1;
    }
    else if ((p[3] == 'X' && p[4] == 'X' && p[5] == 'X') || (p[3] == 'O' && p[4] == 'O' && p[5] == 'O')) // Horizontale
    {
        return 1;
    }
    else if ((p[6] == 'X' && p[7] == 'X' && p[8] == 'X') || (p[6] == 'O' && p[7] == 'O' && p[8] == 'O')) // Horizontale
    {
        return 1;
    }
    else if ((p[0] == 'X' && p[3] == 'X' && p[6] == 'X') || (p[0] == 'O' && p[3] == 'O' && p[6] == 'O')) // Vertcale
    {
        return 1;
    }
    else if ((p[1] == 'X' && p[4] == 'X' && p[7] == 'X') || (p[1] == 'O' && p[4] == 'O' && p[7] == 'O')) // Vertcale
    {
        return 1;
    }
    else if ((p[2] == 'X' && p[5] == 'X' && p[8] == 'X') || (p[2] == 'O' && p[5] == 'O' && p[8] == 'O')) // Vertcale
    {
        return 1;
    }
    else if ((p[0] == 'X' && p[4] == 'X' && p[8] == 'X') || (p[0] == 'O' && p[4] == 'O' && p[8] == 'O')) // Diagonale
    {
        return 1;
    }
    else if ((p[2] == 'X' && p[4] == 'X' && p[6] == 'X') || (p[2] == 'O' && p[4] == 'O' && p[6] == 'O')) // Diagonale
    {
        return 1;
    }

    for (int i = 0; i < 9; i++)
    {
        if (p[i] == 'X' || p[i] == 'O')
        {
            CasePlien++;
        }
    }

    if (CasePlien == 9)
    {
        return 10;
    }

    return 0;
}
