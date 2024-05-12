#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct oeuvre {
    int id_oeuvre;
    char description[50];
    char date[20];
    char categorie[30];
};

struct artiste {
    int id_artist;
    char nom_a[40];
    char prenom_a[30];
    char nationalite_a[30];
};

// Tableau artist
struct artiste tab_artiste[10];
//
int nbartiste = 0;

struct exposition {
    int id_expo;
    char date_ouverture[20];
    char date_fermeture[20];
    char designation[30];
};

struct commisaire {
    int id_commisaire;
    char nom_commisaire[40];
    char prenom_commisaire[30];
    char fonction[30];
};

struct musee {
    int id_musee;
    char adresse[40];
    char heure_ouverture[20];
    char heure_fermeture[20];
};


void ajouter_artiste() {

    struct artiste a;

    printf("Entrer le nom de l'artiste : ");
    scanf("%s", a.nom_a);
    printf("\nEntrer le prénom de l'ariste : ");
    scanf("%s", a.prenom_a);
    printf("\nEntrer la nationalité de l'artiste : ");
    scanf("%s", a.nationalite_a);
    tab_artiste[nbartiste] = a;
    nbartiste++;
}

void consulter_artiste() {

}

void afficher_tous_artistes() {
    for (int i = 0; i < 10; i++) {
        printf("Nom du %d : %s", i, tab_artiste[i].nom_a);
        printf("Prénom du %d artiste : %s", i, tab_artiste[i].prenom_a);
        printf("Nationalité du %d artiste : %s", i, tab_artiste[i].nationalite_a);
    }
}

void supprimer_artiste() {

}

void trier_artiste_nom() {
    int i, j, temp;

    for (i = 0; i < 9; i++) {
        for (j = i+1; i < 10; i++) {
            if (strcmp(tab_artiste[i].nom_a,tab_artiste[j].nom_a)>0) {
                temp = tab_artiste[i];
                tab_artiste[i] = tab_artiste[j];
                tab_artiste[j] = temp;
            }
        }
    }
}

int main() {
    int choix;
    do {


        printf("### MENU ###\n");
        printf("1 - Ajouter un/une artiste\n");
        printf("2 - Consulter un/une artiste\n");
        printf("3 - Afficher tous les artistes\n");
        printf("4 - Supprimer un/une artiste\n");
        printf("### MENU ###\n");
        printf("Faite votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                ajouter_artiste();
                break;
            case 2:
                consulter_artiste();
                break;
            case 3:
                afficher_tous_artistes();
                break;
            case 4:
                supprimer_artiste();
                break;
        }
    } while (choix != 0);
}