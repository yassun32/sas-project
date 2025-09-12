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

Joueur j[25];
int countJoueurs = 0;

void Ajoutejoueur()
{
    j[countJoueurs].id = countJoueurs + 1;

    printf("Nom: ");
    fgets(j[countJoueurs].nom, sizeof(j[countJoueurs].nom), stdin);
    j[countJoueurs].nom[strcspn(j[countJoueurs].nom, "\n")] = 0;

    printf("Prenom: ");
    fgets(j[countJoueurs].prenom, sizeof(j[countJoueurs].prenom), stdin);
    j[countJoueurs].prenom[strcspn(j[countJoueurs].prenom, "\n")] = 0;

    printf("Numero de maillot: ");
    scanf("%d", &j[countJoueurs].numeroMaillot);
    getchar();

    printf("Poste (Gardien/Defenseur/Milieu/Attaquant): ");
    fgets(j[countJoueurs].poste, sizeof(j[countJoueurs].poste), stdin);
    j[countJoueurs].poste[strcspn(j[countJoueurs].poste, "\n")] = 0;
    getchar();

    printf("Age: ");
    scanf("%d", &j[countJoueurs].age);
    getchar();

    printf("Buts marques: ");
    scanf("%d", &j[countJoueurs].buts);
    getchar();

    countJoueurs++;

    printf("\nJoueur ajoute avec succes.\n");
}

void plusieursJoueurs()
{
    int n;
    printf("Combien de joueurs voulez-vous ajouter ?\n");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Joueur %d ---\n", i + 1);
        Ajoutejoueur();
    }
}

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
        getchar();

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

void RecherchJoueurs()
{
    int id;
    char nome[20];
    int found = 0;
    printf("0 :le recherche par ID \n1  :Le recherche par un nome\n ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
    case 0:
        printf("Entrer le ID de joueur\n");
        scanf("%d", &id);
        getchar();
        for (int i = 0; i < countJoueurs; i++)
        {
            if (j[i].id == id)
            {
                found = 1;
                printf("ID: %d | Nom: %s | Prenom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
                       j[i].id, j[i].nom, j[i].prenom, j[i].numeroMaillot, j[i].poste, j[i].age, j[i].buts);
            }
        }
        break;
    case 1:
        printf("Entre le nome de joueur :\n");
        scanf("%s", nome);
        getchar();
        for (int x = 0; x < countJoueurs; x++)
        {
            if (strcasecmp(j[x].nom, nome) == 0)
            {
                found = 1;
                printf("ID: %d | Nom: %s | Prenom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
                       j[x].id, j[x].nom, j[x].prenom, j[x].numeroMaillot, j[x].poste, j[x].age, j[x].buts);
            }
        }
    default:
        printf("option non valide");
        break;
    }

    if (found == 0)
    {
        printf("Joueer not found");
    }
}
void modification(int id)
{
    int Nage, Nbuts;
    char Nposte[20];

    printf("1 .Modifier le poste d'un joueur \n");
    printf("2 .Modifier l'age d'un joueur \n");
    printf("3 .Modifier le nombre de buts marques \n");
    printf("4 .Retour a la page principale\n");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
    case 1:
        printf("Entre un neuvelle post\n");
        scanf("%s", Nposte);
        getchar();
        for (int i = 0; i < countJoueurs; i++)
        {
            strcpy(j[i].poste, Nposte);
        }
        break;
    case 2:
        printf("Entre un neuvelle age\n");
        scanf("%d", &Nage);
        getchar();
        for (int i = 0; i < countJoueurs; i++)
        {
            (j[i].age == Nage);
        }

    case 3:
        printf("Entre un neuvelle nombre des buts\n");
        scanf("%d", &Nbuts);
        getchar();
        for (int i = 0; i < countJoueurs; i++)
        {
            (j[i].buts == Nbuts);
        }
    case 4:
        break;
    default:
        printf("\nChoix invalide!!\n");
    }
}

void afficherJoueurs()
{
    // choseie  le mode de l'affichage
    if (countJoueurs == 0)
    {
        printf("\nAucun joueur dans l'equipe.\n");
        return;
    }

    printf("\nListe des joueurs:\n");
    for (int i = 0; i < countJoueurs; i++)
    {
        printf("ID: %d | Nom: %s | Prenom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
               j[i].id, j[i].nom, j[i].prenom, j[i].numeroMaillot, j[i].poste, j[i].age, j[i].buts);
    }
}
void suppristion()
{
    int SupId;
    printf("Entrer l'identifiant de joeur pour supprimer\n");
    scanf("%d", &SupId);
    for (int i = 0; i < countJoueurs; i++)
    {
        j[i].id == SupId;
    }
}
void statistique()
{
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
        getchar();

        switch (choix)
        {
        case 1:
            menuAjouterJoueur();
            break;
        case 2:
            menuAjouterJoueur();
            break;
        case 3:
            suppristion();
            break;
        case 4:
            afficherJoueurs();
            break;
        case 5:
            RecherchJoueurs();
            break;
        case 6:
            statistique();
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
