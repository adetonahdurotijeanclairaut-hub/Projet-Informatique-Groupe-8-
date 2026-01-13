#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Boîte Noire.h"


int main()
{
    BoiteNoire boite = {NULL, 0}; //Déclaration d'une variable boite

    float vitesse = 0;
    float temperature = 20; //Température ambiante
    char choix;

    printf("Simulation du vehicule (A=accelerer, F=freiner)\n");

    while (1)
    {
        printf("\nVitesse=%.2f | Temperature=%.2f\n", vitesse, temperature);
        printf("Action (A/F) : ");
        scanf(" %c", &choix);

        if (choix == 'A' || choix == 'a')
            vitesse += 5;
        else if (choix == 'F' || choix == 'f')
        {
            vitesse -= 7;
            if (vitesse < 0)
            {
                vitesse = 0;
            }
        }

        temperature = temperature + (0.5 * vitesse) - (0.1 * (temperature - 20));

        add_frame(&boite, vitesse, temperature);

        if (vitesse == 0 || temperature > 110)
        {
            dump_memory(&boite);
            break;
        }

    }

    crash_analyse();        //Analyse des éléments des 10 dernières secondes avant le crash
    return 0;
}
