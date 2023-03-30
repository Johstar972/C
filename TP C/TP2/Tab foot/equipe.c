#include <stdio.h>
#include <stdlib.h>
#include "equipe.h"
#include <string.h>

/* Fonctions de manipulation d'une équipe */

void lire_equipe_fichier(char nomfic[],equipe* e)
{
    FILE *f;
    int i;

    if ((f=fopen(nomfic,"r"))!=NULL)
    {
        fscanf(f,"%s",e->nom);
        fscanf(f,"%d",&e->nbjoueurs);
        for (i=0;i<e->nbjoueurs;i++)
            fscanf(f,"%s%s%d",e->joueurs[i].nom,e->joueurs[i].prenom,&e->joueurs[i].numeromaillot);
        fclose(f);
    }
    else
        printf("\nErreur de lecture du fichier %s\n\n",nomfic);
}

//Fonction qui permet de construire son équipe
void lire_equipe_clavier(equipe *e)
{

    printf("Lecture d'une nouvelle equipe\n");
    printf("Nom de l equipe (sans espace) ?");
    scanf("%s",e->nom);

    printf("Nombre de joueur ?");
    scanf("%d",&e->nbjoueurs);

    for (int i = 0; i < e->nbjoueurs; i++)
    {
        printf("Saisir les nom prenom et numero de maillot du joueur %d ? ", i +1);
        scanf("%s %s %d",e->joueurs[i].nom, e->joueurs[i].prenom, &e->joueurs[i].numeromaillot);

        printf("Fin de lecture de l equipe,merci\n");
    }
}

//Fonction permettant d'ecrire dans un fichier une equipe
void ecrire_equipe_fichier(char nomfic[], equipe *e)
{
    FILE *f;
    int i;

    if((f=fopen(nomfic,"w")) != NULL)
    {
        fprintf(f,"%s :",e->nom);
        fprintf(f," %s\n",&e->nbjoueurs);

        printf("debut.\n");
        for (i = 0; i < e->nbjoueurs; i++)
        {
            fprintf(f,"%s %s %d\n",e->joueurs[i].nom,e->joueurs[i].prenom,e->joueurs[i].numeromaillot);
            printf("ecriture ok\n");
        }
        fclose(f);
        printf("Le fichier a ete ecrit avec succes.\n");
    }
}




//Fonction qui affiche le joueur
void afficher_joueurs(joueur *j,int nbj)
{
    for(int i = 0; i < nbj; i++)
    {
        printf("%d %s %s\n", j->numeromaillot, j->prenom, j->nom);
        j++;

    }
}

//Fonction qui affiche l'equipe
void afficher_equipe(equipe e)
{
    printf("%s : %d joueurs\n",e.nom,e.nbjoueurs);
    afficher_joueurs(e.joueurs,e.nbjoueurs);

}

//Fonction qui attribut au capitaine 2 le joueur numero 17
void definir_capitaine2(equipe *e, joueur **j)
{
    *j = e->joueurs + 16;
}

//Fonction qui attribut au capitaine 4 le joueur numero 17
void definir_capitaine4(equipe *e, joueur **capitaineLOSC4) // il faut mettre en parametre l'equipe 
{
    *capitaineLOSC4 = e->joueurs + 16;
}

//Fonction qui permet de trouver un numéro de maillot par le nom et le prenom d'un joueur
int trouver_maillot_joueur( equipe *e)
{
    char nom[20], prenom[20];
    int resultat1, resultat2, numero;
    int trouver = -1;
    int i = 0;

    printf("Recherche d'un numero de maillot :\n");
    printf("Nom du joueur ?\n");
    scanf("%s",&nom);
    
    printf("Prenom du joueur ?\n");
    scanf("%s",&prenom);

    while(trouver == -1)
    {
        resultat1 = strcmp(nom,e->joueurs[i].nom);
        resultat2 = strcmp(prenom,e->joueurs[i].prenom);

        if(resultat1 == 0 && resultat2 == 0)
        {
            numero = e->joueurs[i].numeromaillot;
            printf("%s %s porte le numero %d", nom, prenom , numero);
            trouver = 1;
        }
        else
        {
            i++;
        }
        
        if(i == e->nbjoueurs)
        {
            trouver = 1;
            printf("Le joueur n'existe pas");
        }
    }

    
    return numero;
}

