# PROJET_INFORMATIQUE_GROUPE 8
BOITE_NOIRE

RAPPORT DE PROJET – Boîte Noire 
1. Présentation du projet

Ce projet consiste à développer le logiciel embarqué d'une boite noire pour un véhicule expérimentale . L'objectif principal est d'intégrer une fonctionnalité de boite noire qui permet d'enregistrer en temps réel le comportement de cet engin. Le programme simule son comportement à travers l'accélération et le freinage. À chaque cycle, des données importantes sont enregistrées afin de permettre une analyse après incident, ce qui reproduit le fonctionnement des boites noires utilisées dans l'industrie aéronotique.


2. Choix techniques

Langage C : choisi parce que c'est le langage maitrisé 

Structures et listes chaînées :

Fichiers binaires (.bin) :

Code modulaire : séparation du projet en plusieurs fichiers (main.c, gestion mémoire, gestion des accès) 


3. Difficultés rencontrées

Les difficultés que nous avons rencontrées au cours du projet concernent :

L' allocation dynamique et la libération des frames.

L'implémentation correcte de certaines fonctions surtout celle que noua avons découvert au cours du projet 

Le dépot des fichiers sur github

Le calcul de la température et de la vitesse maximale 

L'affichage du temps 


4. Solutions apportées

Pour résoudre ces problèmes :

Un buffer circulaire de 10 frames a été utilisée afin de conserver uniquement les dernières frames avant le crash.

La température moteur est calculée à chaque cycle selon une formule intégrant la vitesse et un refroidissement progressif.

Recherches sur le net.


5. Liens du projet

 GitHub : https://github.com/adetonahdurotijeanclairaut-hub/Projet-Informatique-Groupe-8-
