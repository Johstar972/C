#include <stdio.h>
#include <stdlib.h>
#include "equipe.h" // bibliothèque de gestion d'une équipe
#include <string.h>

int main()
{
    ptrjoueur capitaineLOSC1, capitaineLOSC2; //capitaineLOSC3;
    equipe eqFoot;
    
    equipe nouvEqFoot;

    joueur *capitaineLOSC3, *capitaineLOSC4;

    char nomFicEq[20];

    lire_equipe_fichier("LOSC.txt",&eqFoot);
    //-------------------------------------
    //--- Question 1
    //-------------------------------------
    afficher_equipe(eqFoot);

    //-------------------------------------
    //--- Question 2   1/
    //-------------------------------------
    capitaineLOSC1 = eqFoot.joueurs+16;
    printf("Capitaine 1: %s %s\n",capitaineLOSC1->nom, capitaineLOSC1->prenom);

    //-------------------------------------
    //--- Question 2   2/
    //-------------------------------------
    definir_capitaine2(&eqFoot, &capitaineLOSC2);
    printf("Capitaine 2: %s %s\n",capitaineLOSC2->nom, capitaineLOSC2->prenom);

    //-------------------------------------
    //--- Question 2   3/
    //-------------------------------------
    capitaineLOSC3 = eqFoot.joueurs+16;
    printf("Capitaine 3: %s %s\n",capitaineLOSC3->nom, capitaineLOSC3->prenom);
    
    //-------------------------------------
    //--- Question 2   4/
    //-------------------------------------
    definir_capitaine4(&eqFoot, &capitaineLOSC4);
    printf("Capitaine 4: %s %s\n",capitaineLOSC4->nom, capitaineLOSC4->prenom);
    
    //-------------------------------------
    //--- Question 3
    //-------------------------------------
    lire_equipe_clavier(&nouvEqFoot);
    afficher_equipe(nouvEqFoot);

    //-------------------------------------
    //--- Question 4
    //-------------------------------------
    ecrire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);
    lire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);

    //-------------------------------------
    //--- Question 5
    //-------------------------------------
    strcpy(nomFicEq, nouvEqFoot.nom);
    strcat(nomFicEq,".txt");
    ecrire_equipe_fichier(nomFicEq, &nouvEqFoot);
    lire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);

    //-------------------------------------
    //--- Question 6
    //-------------------------------------
    int resultat;
    

    resultat = trouver_maillot_joueur(&eqFoot);

   

    return 0;
}
