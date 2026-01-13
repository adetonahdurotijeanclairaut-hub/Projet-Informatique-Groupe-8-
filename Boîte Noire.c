#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Boîte Noire.h"


// SAUVEGARDE D’URGENCE

void dump_memory(BoiteNoire *b)
{
    FILE *fichier = fopen("crash.bin", "wb");            //Ouverture de notre fichier crash.bin
    if (fichier == NULL)
    {
        perror("Erreur ouverture crash.bin\n");
        exit(1); //Tout s'arrête là au cas où fichier = NULL et l'erreur sera affiché grace à perror
    }

    Frame *courant = b->debut;          //Pointeur courant pointant vers la première frame
    while (courant != NULL)
    {
        fwrite(courant, sizeof(Frame), 1, fichier);
        courant = courant->suivant;
    }

    fclose(fichier);
    printf("\nCRASH : donnees sauvegardees dans crash.bin\n");
}




//  ANALYSE

void crash_analyse()// Analyse des fichiers du crash.bin
{
    FILE *fichier = fopen("crash.bin", "rb");
    if (fichier == NULL)
    {
        perror("Aucun fichier crash.bin trouve\n");
        exit(2);//Tout s'arrête là au cas où f=NULL et l'erreur sera affiché grace à perror
    }

    Frame temp;
    float somme_vitesse = 0;
    float temp_max = 0;
    int compteur = 0;

    while (fread(&temp, sizeof(Frame), 1, fichier) == 1)
    {
        somme_vitesse += temp.vitesse;
        if (temp.temperature > temp_max)
        {
            temp_max = temp.temperature;
        }
        compteur++;
    }

    fclose(fichier);

    if (compteur > 0)
    {
        printf("\n===== ANALYSE POST-MORTEM =====\n");
        printf("Vitesse moyenne : %.2f km/h\n", somme_vitesse / compteur);
        printf("Temperature maximale : %.2f °C\n", temp_max);
    } else
    {
        printf("Fichier vide\n");
    }
}







