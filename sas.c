#include <stdio.h>
#include <string.h>

#define MAX 150

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
} Joueur;

Joueur joueurs[MAX];
int countJoueurs = 0;

//ajouter un joueur
void ajouterJoueur() {
    Joueur j;
    j.id = countJoueurs + 1;

    printf("Nom: ");
    scanf("%s", j.nom);
    getchar();

    printf("Prénom: ");
    scanf("%s", j.prenom);
    getchar();

    printf("Numéro de maillot: ");
    scanf("%d", &j.numeroMaillot);
    getchar();

    printf("Poste (Gardien/Defenseur/Milieu/Attaquant): ");
    scanf("%s", j.poste);
    getchar();

    printf("Age: ");
    scanf("%d", &j.age);
    getchar();

    printf("Buts marqués: ");
    scanf("%d", &j.buts);
    getchar();

    joueurs[countJoueurs] = j;
    countJoueurs++;

    printf("\nJoueur ajouté avec succès.\n");
}

// afficher tous les joueurs
void afficherJoueurs() {
    if (countJoueurs == 0) {
        printf("\nAucun joueur dans l'équipe.\n");
        return;
    }

    printf("\nListe des joueurs:\n");
    for (int i = 0; i < countJoueurs; i++) {
        printf("ID: %d | Nom: %s | Prénom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
               joueurs[i].id, joueurs[i].nom, joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
    }
}


int main() {
    int choix;

    do {
        printf("\n-----------------------------------\n");
        printf("--- Gestion Equipe de Football ---\n");
        printf("-----------------------------------\n");
        printf("1 - Ajouter joueur\n");
        printf("2 - Modifier joueur\n");
        printf("3 - Supprimer joueur\n");
        printf("4 - Afficher joueurs\n");
        printf("5 - Rechercher joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                ajouterJoueur();
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
