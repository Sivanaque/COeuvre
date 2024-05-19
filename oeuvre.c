#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct oeuvre {
    int id_oeuvre;
    char description[50];
    char date[20];
    char categorie[30];
    int appartient_artiste;
    int appartient_musee;
};

// Tableau oeuvre
struct oeuvre tab_oeuvre[10];
size_t n = sizeof(tab_oeuvre) / sizeof(tab_oeuvre[0]);
//
int nboeuvre = 0;

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

    system("clear");
    printf("Entrer le nom de l'artiste : ");
    scanf("%s", a.nom_a);
    system("clear");
    printf("Entrer le prénom de l'ariste : ");
    scanf("%s", a.prenom_a);
    system("clear");
    printf("Entrer la nationalité de l'artiste : ");
    scanf("%s", a.nationalite_a);
    system("clear");
    tab_artiste[nbartiste] = a;
    nbartiste++;
}

void consulter_artiste() {
    int id_a;

    do {
        printf("Entrer l'ID de l'artiste : ");
        scanf("%d", &id_a);
        system("clear");

        printf("\n### INFORMATION ARTISTE N°%d ###", id_a);
        printf("\nNom de l'artiste N°%d : %s", id_a, tab_artiste[id_a].nom_a);
        printf("\nPrénom de l'artiste N°%d : %s", id_a, tab_artiste[id_a].prenom_a);
        printf("\nNationalité de l'artiste N°%d : %s\n", id_a, tab_artiste[id_a].nationalite_a);
    }

    while (id_a > 10);
}

void afficher_tous_artistes() {
    for (int i = 0; i < n; i++) {
        printf("\nNom de l'artiste N°%d : %s", i, tab_artiste[i].nom_a);
        printf("\nrénom de l'artiste N°%d : %s", i, tab_artiste[i].prenom_a);
        printf("\nNationalité de l'artiste N°%d : %s\n", i, tab_artiste[i].nationalite_a);
    }
}

void supprimer_artiste() {
        int id_a;
        printf("Entrer l'ID de l'artiste à supprimer : ");
        scanf("%d", &id_a);
        system("clear");

        strcpy(tab_artiste[id_a].nom_a, "");
        strcpy(tab_artiste[id_a].prenom_a, "");
        strcpy(tab_artiste[id_a].nationalite_a, "");
}

void trier_artiste_nom() {
    int i, j;
    struct artiste temp;

    for (i = 0; i < 9; i++) {
        for (j = i+1; i < 10; i++) {
            if (strcmp(tab_artiste[i].nom_a,tab_artiste[j].nom_a)>0) {
                temp = tab_artiste[i];
                tab_artiste[i] = tab_artiste[j];
                tab_artiste[j] = temp;
                printf("Nom de l'artiste : %s", tab_artiste[j].nom_a);
            }
        }
    }
}




// FUNCTIONS OEUVRES

void ajouter_oeuvre() {
    struct oeuvre o;

    system("clear");
    printf("Entrer la description de l'œuvre : ");
    scanf(" %[^\n]%*c", o.description);
    system("clear");
    printf("Entrer la date de réalisation de l'œuvre : ");
    scanf(" %s", o.date);
    system("clear");
    printf("Entrer la catégorie de l'œuvre : ");
    scanf(" %s", o.categorie);
    system("clear");
    printf("Entrer l'ID de l'artiste à l'origine de l'œuvre : ");
    scanf("%d", &o.appartient_artiste);
    printf("Entrer l'ID du musée où l'œuvre est exposé : ");
    scanf("%d", &o.appartient_musee);
    tab_oeuvre[nboeuvre] = o;
    nboeuvre++;
}

void afficher_toutes_oeuvres() {
    for (int i = 0; i < n; i++) {
        printf("\nDescription de l'œuvre N°%d : %s", i, tab_oeuvre[i].description);
        printf("\nDate de création de l'œuvre N°%d : %s", i, tab_oeuvre[i].date);
        printf("\nCatégorie de l'œuvre N°%d : %s", i, tab_oeuvre[i].categorie);
        printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d", i, tab_oeuvre[i].appartient_artiste);
        printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[i].appartient_musee);
    }
}

void afficher_oeuvres_artiste(int id_a) {
    for (int i = 0; i < n; i++) {
        if (tab_oeuvre[i].appartient_artiste == id_a) {
            printf("\n### OEUVRE N°%d ###", i);
            printf("\nDescription de l'œuvre N°%d : %s", i, tab_oeuvre[i].description);
            printf("\nDate de création de l'œuvre N°%d : %s", i, tab_oeuvre[i].date);
            printf("\nCatégorie de l'œuvre N°%d : %s", i, tab_oeuvre[i].categorie);
            printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d", i, tab_oeuvre[i].appartient_artiste);
            printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[i].appartient_musee);
        }
    }
}

void modifier_artiste_oeuvre() {
        int id_o;
        int new_artiste;
        printf("Entrer l'ID de l'œuvre auquelle l'artiste doit changer : ");
        scanf("%d", &id_o);
        system("clear");
        printf("Entrer l'ID de l'artiste remplaçant : ");
        scanf("%d", &new_artiste);
        tab_oeuvre[id_o].appartient_artiste = new_artiste;
        system("clear");
}

void modifier_oeuvre_date() {
        int id_o;
        char new_date[20];
        printf("Entrer l'ID de l'œuvre auquelle la date doit changer : ");
        scanf("%d", &id_o);
        system("clear");
        printf("Entrer une nouvelle date : ");
        scanf(" %s", new_date);
        strcpy(tab_oeuvre[id_o].date, new_date);
        system("clear");
}

void supprimer_oeuvre() {
        int id_o;
        printf("Entrer l'ID de l'artiste à supprimer : ");
        scanf("%d", &id_o);
        system("clear");

        strcpy(tab_oeuvre[id_o].description, "");
        strcpy(tab_oeuvre[id_o].date, "");
        strcpy(tab_oeuvre[id_o].categorie, "");
        tab_oeuvre[id_o].appartient_artiste = 0;
        tab_oeuvre[id_o].appartient_musee = 0;
}

void trier_par_oeuvre() {
    int i, j;
    struct oeuvre temp;

    for (i = 0; i < 9; i++) {
        for (j = i+1; i < 10; i++) {
            if (strcmp(tab_oeuvre[i].categorie,tab_oeuvre[j].categorie)>0) {
                temp = tab_oeuvre[i];
                tab_oeuvre[i] = tab_oeuvre[j];
                tab_oeuvre[j] = temp;
                printf("\n### OEUVRE N°%d ###", i);
                printf("\nDescription de l'œuvre N°%d : %s", i, tab_oeuvre[j].description);
                printf("\nDate de création de l'œuvre N°%d : %s", i, tab_oeuvre[j].date);
                printf("\nCatégorie de l'œuvre N°%d : %s", i, tab_oeuvre[j].categorie);
                printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[j].appartient_artiste);
                printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[j].appartient_musee);
            }
        }
    }
}


// FUNCTIONS MUSEE

void afficher_musee_oeuvre(int id_m) {
    for (int i = 0; i < n; i++) {
        if (tab_oeuvre[i].appartient_musee == id_m) {
            printf("\n### OEUVRE N°%d ###", i);
            printf("\nDescription de l'œuvre N°%d : %s", i, tab_oeuvre[i].description);
            printf("\nDate de création de l'œuvre N°%d : %s", i, tab_oeuvre[i].date);
            printf("\nCatégorie de l'œuvre N°%d : %s", i, tab_oeuvre[i].categorie);
            printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[i].appartient_artiste);
            printf("\nID de l'artiste à l'origine de l'œuvre N°%d : %d\n", i, tab_oeuvre[i].appartient_musee);
        }
    }
}


// MAIN

int main() {

    int choix_principal;
    int choix_sous_menu;

    do {
        system("clear");
        printf("\nMENU PRINCIPAL\n");
        printf("1 = Gérer Artiste\n");
        printf("2 = Gérer Œuvre\n");
        printf("3 = Gérer Musée\n");
        printf("0 = Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix_principal);

        switch (choix_principal) {
            case 1:
                system("clear");
                do {
                    printf("\nMENU Gérer Artiste\n");
                    printf("1 = Ajouter un/une artiste\n");
                    printf("2 = Consulter un/une artiste\n");
                    printf("3 = Afficher tous les artistes\n");
                    printf("4 = Supprimer un/une artiste\n");
                    printf("5 = Trier artiste par nom\n");
                    printf("0 = Retour\n");
                    printf("Entrez votre choix: ");
                    scanf("%d", &choix_sous_menu);
                    switch (choix_sous_menu) {
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
                        case 5:
                            trier_artiste_nom();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide. Veuillez entrer un choix valide.\n");
                    }
                } while (choix_sous_menu != 0);
                break;
            case 2:
                system("clear");
                do {
                    int id_artiste;

                    printf("\nMENU Gérer Œuvre\n");
                    printf("1 = Ajouter une œuvre\n"); // ✅
                    printf("2 = Afficher toutes les œuvres\n"); // ✅
                    printf("3 = Afficher les œuvres d'un artiste\n"); // ✅
                    printf("4 = Supprimer une œuvre\n"); // ✅
                    printf("5 = Trier les œuvres par catégorie\n"); // ✅
                    printf("6 = Modifier la date d'une œuvre\n"); // ✅
                    printf("7 = Modifier l'artiste d'une œuvre\n"); // ✅
                    printf("0 = Retour\n");
                    printf("Entrez votre choix: ");
                    scanf("%d", &choix_sous_menu);
                    switch (choix_sous_menu) {
                        case 1:
                            ajouter_oeuvre();
                            break;
                        case 2:
                            afficher_toutes_oeuvres();
                            break;
                        case 3:
                            system("clear");
                            printf("Entrer l'ID de l'artiste en question : ");
                            scanf("%d", &id_artiste);
                            afficher_oeuvres_artiste(id_artiste);
                            break;
                        case 4:
                            supprimer_oeuvre();
                            break;
                        case 5:
                            trier_par_oeuvre();
                            break;
                        case 6:
                            modifier_oeuvre_date();
                            break;
                        case 7:
                            modifier_artiste_oeuvre();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide. Veuillez entrer un choix valide.\n");
                    }
                } while (choix_sous_menu != 0);
                break;
            case 3:
                system("clear");
                do {
                    int id_musee;

                    printf("\nMENU Gérer Musée\n");
                    printf("1 = Ajouter un musée\n");
                    printf("2 = Afficher toutes les musées\n");
                    printf("3 = Afficher le musée contenant une œuvre spécifique\n");
                    printf("4 = Consulter un musée\n");
                    printf("5 = Supprimer un musée\n");
                    printf("0 = Retour\n");
                    printf("Entrez votre choix: ");
                    scanf("%d", &choix_sous_menu);
                    switch (choix_sous_menu) {
                        case 1:
                            ajouter_oeuvre();
                            break;
                        case 2:
                            afficher_toutes_oeuvres();
                            break;
                        case 3:
                            system("clear");
                            printf("Entrer l'ID de l'artiste en question : ");
                            scanf("%d", &id_musee);
                            afficher_musee_oeuvre(id_musee);
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide. Veuillez entrer un choix valide.\n");
                    }
                } while (choix_sous_menu != 0);
                break;
            case 0:
                system("clear");
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un choix valide.\n");
        }
    } while (choix_principal != 0);

    return 0;
}