#include <stdio.h>
#include <string.h>

int choix;

typedef struct 
{
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
} Joueur;

Joueur j[12];
int countJoueurs = 0;

// ajouter un joueur
void Ajoutejoueur()
{
    j[countJoueurs].id = countJoueurs + 1;

    printf("Nom: ");
    scanf("%s", j[countJoueurs].nom);

    printf("Prenom: ");
    scanf("%s", j[countJoueurs].prenom);

    printf("Numero de maillot: ");
    scanf("%d", &j[countJoueurs].numeroMaillot);

    printf("Poste (Gardien/Defenseur/Milieu/Attaquant): ");
    scanf("%s", j[countJoueurs].poste);

    printf("Age: ");
    scanf("%d", &j[countJoueurs].age);

    printf("Buts marques: ");
    scanf("%d", &j[countJoueurs].buts);

    countJoueurs++;

    printf("\nJoueur ajoute avec succes.\n");
}

// Ajouter plusieurs joueurs
void plusieursJoueurs()
{
    int n;
    printf("Combien de joueurs voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Joueur %d ---\n", i + 1);
        Ajoutejoueur();
    }
}

// menu ajout
void menuAjouterJoueur() 
{
    do
    {
        printf("\n----- Menu Ajout Joueur -----\n");
        printf("1. Ajouter un seul joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("3. Retour a la page principale\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                Ajoutejoueur();
                break;
            case 2:
                plusieursJoueurs();
                break;
            case 3:
                break;
            default:
                printf("\nChoix invalide!!\n");
        }   
    } while (choix != 3);
}

// Afficher tous les joueurs
void afficherJoueurs()
{
    if (countJoueurs == 0) {
        printf("\nAucun joueur dans l'equipe.\n");
        return;
    }

    printf("\nListe des joueurs:\n");
    for (int i = 0; i < countJoueurs; i++) {
        printf("ID: %d | Nom: %s | Prénom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
               j[i].id, j[i].nom, j[i].prenom,
               j[i].numeroMaillot, j[i].poste,
               j[i].age, j[i].buts
        );
    }
}

int main()
{
    do 
    {
        printf("\n--------------------------------------\n");
        printf("--- Gestion equipe de Football --\n");
        printf("--------------- MENU -----------------\n");
        printf("1 - Ajouter joueur\n");
        printf("2 - Modifier joueur\n");
        printf("3 - Supprimer joueur\n");
        printf("4 - Afficher joueurs\n");
        printf("5 - Rechercher joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                menuAjouterJoueur();
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                afficherJoueurs();
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                printf("\nAu revoir !!!\n");
                break;
            default:
                printf("\nChoix invalide!!\n");
        }

    } while (choix != 7);

    return 0;
}
