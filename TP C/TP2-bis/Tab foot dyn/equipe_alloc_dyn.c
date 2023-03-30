#include <stdio.h>
#include <stdlib.h>
#include "equipe_alloc_dyn.h"
#include <string.h>

/* Fonctions de manipulation d'une équipe */

void lire_equipe_fichier_alloc_dyn(char nomfic[],equipeAllocDyn* e)
{
    FILE *f;
    int i;

    if ((f=fopen(nomfic,"r"))!=NULL)
    {
        char c[100];
        fscanf(f,"%s",c);
        e->nom = malloc(strlen(c) + 1 * sizeof(char));
        e->nom = c;
        fscanf(f,"%d",&e->nbjoueurs);
        e->joueurs = malloc(e->nbjoueurs * sizeof(joueurAllocDyn));

        char nom[100];
        char prenom[100];

        for (i=0;i<e->nbjoueurs;i++)
        {
            fscanf(f,"%s%s%d",nom,prenom,&e->joueurs[i].numeromaillot);
            e->joueurs[i].nom = malloc(strlen(nom) + 1 * sizeof(char));
            e->joueurs[i].prenom =  malloc(strlen(prenom) + 1 * sizeof(char));

            strcpy(e->joueurs[i].nom, nom);
            strcpy(e->joueurs[i].prenom, prenom);
        }
        fclose(f);
    }
    else
        printf("\nErreur de lecture du fichier %s\n\n",nomfic);
}

//Fonction qui permet de construire son équipe
void lire_equipe_clavier_alloc_dyn(equipeAllocDyn *e)
{

    printf("Lecture d'une nouvelle equipe\n");
    printf("Nom de l equipe (sans espace) ?");
    char c[100];
    scanf("%s",c);
    e->nom = malloc((strlen(c) + 1) * sizeof(char));
    e->nom = c;

    printf("Nombre de joueur ?");
    scanf("%d",&e->nbjoueurs);
    e->joueurs = malloc(e->nbjoueurs * sizeof(joueurAllocDyn));

    char nom[100];
    char prenom[100];
    for (int i = 0; i < e->nbjoueurs; i++)
    {
        printf("Saisir les nom prenom et numero de maillot du joueur %d ? ", i +1);
        scanf("%s %s %d",e->joueurs[i].nom, e->joueurs[i].prenom, &e->joueurs[i].numeromaillot);
        e->joueurs[i].nom = malloc((strlen(nom) + 1) * sizeof(char));
        e->joueurs[i].prenom =  malloc((strlen(prenom) + 1) * sizeof(char));

        strcpy(e->joueurs[i].nom, nom);
        strcpy(e->joueurs[i].prenom, prenom);

        printf("Fin de lecture de l equipe,merci\n");
    }
}

//Fonction permettant d'ecrire dans un fichier une equipe
void ecrire_equipe_fichier_alloc_dyn(char nomfic[], equipeAllocDyn *e)
{
    FILE *f;
    int i;

    if((f=fopen(nomfic,"w")) != NULL)
    {
        char c[100];
        fprintf(f,"%s",c);
        e->nom = malloc((strlen(c) + 1) * sizeof(char));
        e->nom = c;
        fprintf(f,"%s",&e->nbjoueurs);
        e->joueurs = malloc(e->nbjoueurs * sizeof(joueurAllocDyn));

        printf("debut.\n");
        char nom[100];
        char prenom[100];
        for (i = 0; i < e->nbjoueurs; i++)
        {
            
            fprintf(f,"%s %s %d\n",e->joueurs[i].nom,e->joueurs[i].prenom,e->joueurs[i].numeromaillot);
            e->joueurs[i].nom = malloc((strlen(nom) + 1) * sizeof(char));
            e->joueurs[i].prenom =  malloc((strlen(prenom) + 1) * sizeof(char));

            strcpy(e->joueurs[i].nom, nom);
            strcpy(e->joueurs[i].prenom, prenom);
            printf("ecriture ok\n");
        }
        fclose(f);
        printf("Le fichier a ete ecrit avec succes.\n");
    }
}




//Fonction qui affiche le joueur
void afficher_joueurs_alloc_dyn(joueurAllocDyn *j,int nbj)
{
    for(int i = 0; i < nbj; i++)
    {
        printf("%d %s %s\n", j->numeromaillot, j->prenom, j->nom);
        j++;

    }
}

//Fonction qui affiche l'equipe
void afficher_equipe_alloc_dyn(equipeAllocDyn e)
{
    printf("%s : %d joueurs\n",e.nom,e.nbjoueurs);
    afficher_joueurs_alloc_dyn(e.joueurs,e.nbjoueurs);

}

long occupation_memoire_equipe_alloc_dyn(equipeAllocDyn e)
{
    long nbOctet = 0;

    for(int i = 0; i< e.nbjoueurs; i++)
    {
        nbOctet += sizeof(e.joueurs[i].nom);
        nbOctet += sizeof(e.joueurs[i].prenom);
        nbOctet += sizeof(e.joueurs[i].numeromaillot);
    }

    nbOctet += sizeof(e.nom);
    nbOctet += sizeof(e.nbjoueurs);

    

    return nbOctet;
}

void affichageMenuTP2Bis()
{
    printf("Vous avez choisie le TP2\n");
    printf("1-- Question 1\n2-- Question 2\n3-- Question 3\n");
    printf("Quelle est votre choix ?");
        
}


