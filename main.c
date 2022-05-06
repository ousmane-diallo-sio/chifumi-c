#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

int jouer(Joueur *j1, Joueur *j2);
void demanderNbJoueurs(int *nbJoueurs);

int main(){

    int nbJoueurs;
    char *choix[4];
    choix[0] = "Pierre";
    choix[1] = "Feuille";
    choix[2] = "Ciseaux"; 

    Joueur j1 = {0};
    Joueur j2 = {0};

    printf("%i", nbJoueurs);

    demanderNbJoueurs(&nbJoueurs);
    
    printf("\nInserez le nom des joueurs 1 et 2 (separes par un espace) : ");
    scanf("%s%s", &j1.nom, &j2.nom);

    printf("\tNom du Joueur 1 : %s \n\tNom du Joueur 2 : %s", j1.nom, j2.nom);

    jouer(&j1, &j2);

}

void demanderNbJoueurs(int *nbJoueurs){
    printf("\nSouhaitez-vous jouer seul (contre un robot) ou a deux [1-2] ? ");
    char nb[2];
    fgets(nb, 2, stdin);
    *nbJoueurs = strtol(nb, NULL, 10);
    if(*nbJoueurs == 1 || *nbJoueurs == 2){
        printf("Vous avez choisi l'option avec %i joueur(s)", *nbJoueurs);
    } else {
        printf("\nVous n'avez pas saisie une des valeurs attendue.\n");
        demanderNbJoueurs(nbJoueurs);
    }
}

int jouer(Joueur *j1, Joueur *j2){

    printf("\n\nDebut de la partie : [ %s vs %s ]\n", j1->nom, j2->nom);

    printf("\n[Joueur 1] Choisissez entre Pierre Feuille et Ciseaux [1-2-3] : ");
    scanf("%i", j1->choix);

    printf("\n[Joueur 2] Choisissez entre Pierre Feuille et Ciseaux [1-2-3] : ");
    scanf("%i", j2->choix);

    printf("\n%s contre %s", j1->choix, j2->choix);

}