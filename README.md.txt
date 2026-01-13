# PROJET_INFORMATIQUE
BOITE_NOIRE

📄 RAPPORT DE PROJET – Boîte Noire Logicielle (1 page)
1. Présentation du projet

Dans le cadre du projet d’informatique, nous avons réalisé une simulation de véhicule intégrant une boîte noire logicielle en langage C.
Le programme simule le comportement d’un véhicule à travers deux actions utilisateur : accélération (A) et freinage (F).
À chaque cycle, des données importantes sont enregistrées afin de permettre une analyse post-incident, comme dans une véritable boîte noire.


2. Choix techniques

Plusieurs choix techniques ont été effectués :

Langage C : choisi pour sa proximité avec le matériel, sa gestion fine de la mémoire et son adéquation avec les systèmes embarqués.

Structures et listes chaînées : utilisées pour stocker dynamiquement les données (frames) enregistrées par la boîte noire.

Fichiers binaires (.bin) : utilisés pour sauvegarder rapidement les données lors d’un crash ou d’un arrêt du système.

Code modulaire : séparation du projet en plusieurs fichiers (main.c, gestion de la boîte noire, gestion des accès) afin d’améliorer la lisibilité et la maintenance.

Système de contrôle d’accès : implémentation d’un fichier acces.config contenant les utilisateurs autorisés à lancer le programme.


3. Difficultés rencontrées

Plusieurs difficultés ont été rencontrées au cours du projet :

La gestion correcte de la mémoire dynamique (allocation et libération des frames).

L’enregistrement de la dernière frame lors d’un crash, notamment en cas de surchauffe.

La compréhension et l’application d’une formule de température moteur réaliste tout en respectant les contraintes de l’énoncé.

La gestion d’un dépôt GitHub protégé, empêchant les push directs sur la branche principale.


4. Solutions apportées

Pour résoudre ces problèmes :

Une liste chaînée circulaire limitée a été utilisée afin de conserver uniquement les dernières frames pertinentes.

Une sauvegarde d’urgence a été déclenchée avant l’arrêt du programme pour garantir l’enregistrement complet des données.

La température moteur est calculée à chaque cycle selon une formule intégrant la vitesse et un refroidissement progressif.

Les règles GitHub ont été configurées pour imposer l’utilisation de branches secondaires et de pull requests.


5. Liens du projet

📁 GitHub :
👉 https://github.com/adetonahdurotijeanclairaut-hub/Projet-Informatique-Groupe-8-
