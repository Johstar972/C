//
// Created by johstar on 12/04/23.
//
#include "moyenne.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction de lecture d'un fichier
void lire_moyennes(char *nomfic, moyPromo *m)
{
    FILE *f = fopen(nomfic, "r");
    int i;

    if (f != NULL)
    {
        char n[100], p[100];
        fscanf(f, "%d", &m->nbEtudiants);
        fscanf(f, "%d", &m->nbUE);

        m->etudiants = malloc(m->nbEtudiants * sizeof(moyEtu));

        for (i = 0; i < m->nbEtudiants; i++)
        {
            fscanf(f, "%s%s", p, n);
            m->etudiants[i].prenom = malloc((strlen(p) + 1) * sizeof(char));
            m->etudiants[i].nom = malloc((strlen(n) + 1) * sizeof(char));

            strcpy(m->etudiants[i].nom, n);
            strcpy(m->etudiants[i].prenom, p);
            m->etudiants[i].moyennes = malloc(m->nbUE * sizeof(double));
            for (int j = 0; j < m->nbUE; j++)
            {
                fscanf(f, "%lf", &m->etudiants[i].moyennes[j]);
            }
        }
        printf("Le fichier a ete lu avec succes\n");
        fclose(f);
    }
    else
        printf("\nErreur de lecture du fichier %s\n\n", nomfic);
}

void decisionJury(moyPromo *m)
{
    for (int i = 0; i < m->nbEtudiants; i++)
    {
        m->etudiants[i].nbUEValide = 0;

        for (int j = 0; j < m->nbUE; j++)
        {
            if (m->etudiants[i].moyennes[j] >= 10)
            {
                m->etudiants[i].nbUEValide += 1;
            }
        }

        if (m->etudiants[i].nbUEValide >= 4)
        {
            m->etudiants[i].decision = 'V';
            printf("decision: %c\n", m->etudiants[i].decision);
        }
        else
        {
            m->etudiants[i].decision = 'E';
        }
    }
}

