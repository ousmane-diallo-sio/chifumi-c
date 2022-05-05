#include <stdio.h>
#include "joueur.h"

int main(){

    int nbJoueurs;

    Joueur j1;
    Joueur j2;

    printf("\nSouhaitez-vous seul (contre un robot) ou a deux [1-2] ? ");
    scanf("%i", &nbJoueurs);

    printf("Vous avez choisi l'option avec %i joueur(s)", nbJoueurs);

    printf("\nInserez le nom des joueurs 1 et 2 (separes par un espace) : ");
    scanf("%s%s", &j1.nom, &j2.nom);

    printf("\tNom du Joueur 1 : %s \n\tNom du Joueur 2 : %s", j1.nom, j2.nom);

}