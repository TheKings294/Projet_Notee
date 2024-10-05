/*

Fichier de l'anticheat

*/

#ifndef ANTICHEAT_H // Vérifie si ANTICHEAT_H n'est pas défini
#define ANTICHEAT_H // Définit ANTICHEAT_H

int AntiCheat(int Choix, char Plateau[])
{
    if (Plateau[Choix] != 0)
    {
        return 1;
    }

    return 0;
}

#endif