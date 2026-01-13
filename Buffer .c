#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Boîte Noire.h"


void add_frame(BoiteNoire *b, float v, float t)         // Pour ajouter une nouvelle frame
{
    Frame *new = malloc(sizeof(Frame));         //allocation mémoire pour une frame à chaque seconde
    if (new == NULL)
    {
        perror("Echec de l'allocation mémoire");        //l'erreur sera affiché grace à perror
        return;
    }

    new->timestamp = time(NULL);            //Remplissage de la frame avec les données envoyées
    new->vitesse = v;
    new->temperature = t;
    new->suivant = NULL;

    if (b->debut == NULL)               //Aucune frame
    {
        b->debut = new;              //Création de la première frame
    }
    else
    {
        Frame *tmp = b->debut;          //Pointeur tempon pointant vers la première frame
        while (tmp->suivant != NULL)    //Tant qu'il existe une frame à la suite de celle pointée
        {
            tmp = tmp->suivant;         //Pointeur tempon pointant vers la frame suivante
        }
            tmp->suivant = new;            //Crée une nouvelle frame à la suite de celle pointée

    }

    b->nb_frames++;

    // VISUALISATION
    printf("Enregistrement Frame [Time=%ld] (Memoire : %d/10)\n",new->timestamp, b->nb_frames);

    // ROTATION MÉMOIRE
    if (b->nb_frames > 10)
    {
        printf("Rotation : Frame ancienne ecrasee.\n");
        delete_first(b);
    }
}

void delete_first(BoiteNoire *b)
{
    if (b->debut == NULL)
    {
        return;
    }

    Frame *tmp = b->debut;          //Pointeur tempon pointant vers la première frame
    b->debut = tmp->suivant;        //Le pointeur pointant vers la première frame, pointe maintenant vers la suivante qui devient donc la première
    free(tmp);                      //Libération de l'espace allouer à l'encienne première frame
    b->nb_frames--;                 //Le nombre de frame d'iminue d'un
}

