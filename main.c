#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

int jouer(Joueur *j1, Joueur *j2, char *choix[]);
void demanderNbJoueurs(int *nbJoueurs);

int main(){

    int nbJoueurs;
    char *choix[4];
    choix[0] = "Pierre";
    choix[1] = "Feuille";
    choix[2] = "Ciseaux"; 

    Joueur j1 = {0};
    Joueur j2 = {0};

    demanderNbJoueurs(&nbJoueurs);
    
    printf("\nInserez le nom des joueurs 1 et 2 (separes par un espace) : ");
    scanf("%s%s", j1.nom, j2.nom);

    printf("\n\tNom du Joueur 1 : %s \n\tNom du Joueur 2 : %s", j1.nom, j2.nom);

    jouer(&j1, &j2, choix);

}

int clean_stdin(){
    while (getchar()!='\n');
    return 1;
}

void demanderNbJoueurs(int *nbJoueurs){
    printf("\nSouhaitez-vous jouer seul (contre un robot) ou a deux [1-2] ? ");
    scanf("%i", nbJoueurs);
    if(*nbJoueurs == 1 || *nbJoueurs == 2){
        printf("Vous avez choisi l'option avec %i joueur(s)", *nbJoueurs);
    } else {
        printf("\n\n\nVous n'avez pas saisie une des valeurs attendue.\n");
        clean_stdin();
        demanderNbJoueurs(nbJoueurs);
    }
}

int jouer(Joueur *j1, Joueur *j2, char *choix[]){

    printf("\n\nDebut de la partie : [ %s vs %s ]\n", j1->nom, j2->nom);

    do{
        printf("\n[Joueur 1] Choisissez entre Pierre Feuille et Ciseaux [1-2-3] : ");
        clean_stdin();
        scanf("%i", &j1->choix);
    } while(j1->choix != 1 && j1->choix != 2 && j1->choix != 3);

    do{
        printf("\n[Joueur 2] Choisissez entre Pierre Feuille et Ciseaux [1-2-3] : ");
        clean_stdin();
        scanf("%i", &j2->choix);
    } while(j2->choix != 1 && j2->choix != 2 && j2->choix != 3);

    
    printf("\n%s contre %s", choix[j1->choix -1], choix[j2->choix -1]);

    return 0;

}