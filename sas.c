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

int rechercheById(int id)
{

    printf("Entrer le ID de joueur\n");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < countJoueurs; i++)
    {
        if (j[i].id == id)
        {

            printf("ID: %d | Nom: %s | Prenom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
                   j[i].id, j[i].nom, j[i].prenom, j[i].numeroMaillot, j[i].poste, j[i].age, j[i].buts);
        }       return i;
    }
    return -1;
}

int rechercheByNom(char nom[60])
{

    printf("Entre le nome de joueur :\n");
    scanf("%s", nom);
    getchar();
    for (int x = 0; x < countJoueurs; x++)
    {
        if (strcasecmp(j[x].nom, nom) == 0)
        {

            printf("ID: %d | Nom: %s | Prenom: %s | Maillot: %d | Poste: %s | Age: %d | Buts: %d\n",
                   j[x].id, j[x].nom, j[x].prenom, j[x].numeroMaillot, j[x].poste, j[x].age, j[x].buts);
        }
        return x;
    }
    return -1;
}

void RecherchJoueurs()
{
    int id;
    char nome[20];

    printf("0 :le recherche par ID \n1  :Le recherche par un nome\n ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
    case 0:
        rechercheById(id);
        break;
    case 1:
        rechercheByNom(nome);
        break;
    default:
        printf("option non valide");
        break;
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
    printf("entrer le id joeur tu va etudier ");
    scanf("%d", &id);
    getchar();
    switch (choix)
    {
    case 1:
        int index = rechercheById(id);

        if (index == -1)
        {
            printf("le joueur non declare !!");
        }
        else
        {

            printf("Entre un nouvelle post\n");
            scanf("%s", Nposte);
            getchar();

            strcpy(j[index].poste, Nposte);
        }
        break;
    case 2:
        if (index == -1)
        {
            printf("le joueur non declare !!");
        }
        else
        {
            printf("Entre un neuvelle age\n");
            scanf("%d", &Nage);
            getchar();
            (j[index].age == Nage);
        }

    case 3:
        printf("Entre un neuvelle nombre des buts\n");
        scanf("%d", &Nbuts);
        getchar();
        if (index == -1)
        {
            printf("le joueur non declare !!");
        }
        else
        {
            (j[index].buts == Nbuts);
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

    Joueur joueursInitiaux[] = {
        {1, "Ronaldo", "Cristiano", 7, "Attaquant", 39, 850},
        {2, "Messi", "Lionel", 10, "Attaquant", 37, 900},
        {3, "Neuer", "Manuel", 1, "Gardien", 38, 0},
        {4, "Ramos", "Sergio", 4, "Defenseur", 39, 120},
        {5, "Modric", "Luka", 10, "Milieu", 38, 150},
        {6, "Mbappe", "Kylian", 9, "Attaquant", 26, 250},
        {7, "Kante", "N'Golo", 6, "Milieu", 33, 40},
        {8, "VanDijk", "Virgil", 5, "Defenseur", 34, 50}};

    int n = sizeof(joueursInitiaux) / sizeof(joueursInitiaux[0]);

    for (int i = 0; i < n; i++)
    {
        j[countJoueurs++] = joueursInitiaux[i];
    }

    int id;
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
            modification(id);
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
