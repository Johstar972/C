#include <stdio.h>
#include <stdlib.h>
#include "equipe.h" // bibliothèque de gestion d'une équipe
#include "equipe_alloc_dyn.h"
#include <string.h>

int main()
{

//Il te restera le menu a faire de la question 5
    equipe eqFoot;
    ptrjoueur capitaineLOSC1, capitaineLOSC2; //capitaineLOSC3;
    equipe nouvEqFoot;
    equipeAllocDyn eqFootDyn;
    joueur *capitaineLOSC3, *capitaineLOSC4;
    equipeAllocDyn nouvEqFootDyn;
    int choixTp =0, choix = 0;
    char nomFicEq[20];

    printf("Choisissez votre TP:\n");
    printf("choix 1: TP2\nchoix 2: TP2-bis\n\n");
    scanf("%d",&choixTp);

    lire_equipe_fichier("LOSC.txt",&eqFoot);

    while(choixTp != 1 && choixTp != 2)
    {
        printf("choix invalide\n");
        printf("Choisissez votre TP:\n");
        printf("choix 1: TP2\nchoix 2: TP2-bis");
        scanf("%d",&choixTp);
    }

    if(choixTp == 1)
    {
        affichageMenuTP2();
        scanf("%d",&choix);

        while (choix != 0)
        {
        
        
        switch (choix)
        {
        case 1://Question 1
            printf("appelle normal\n\n");
            afficher_equipe(eqFoot);
            long tailleEqFoot = sizeof(eqFoot);
            printf("\n %llu octets\n\n",tailleEqFoot);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;
        
        case 2://Question 2.1
            capitaineLOSC1 = eqFoot.joueurs+16;
            printf("Capitaine 1: %s %s\n",capitaineLOSC1->nom, capitaineLOSC1->prenom);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;

        case 3://Question 2.2
            
            definir_capitaine2(&eqFoot, &capitaineLOSC2);
            printf("Capitaine 2: %s %s\n",capitaineLOSC2->nom, capitaineLOSC2->prenom);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;
        
        case 4://Question 2.3
            capitaineLOSC3 = eqFoot.joueurs+16;
            printf("Capitaine 3: %s %s\n",capitaineLOSC3->nom, capitaineLOSC3->prenom);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;

        case 5://Question 2.4
            definir_capitaine4(&eqFoot, &capitaineLOSC4);
            printf("Capitaine 4: %s %s\n",capitaineLOSC4->nom, capitaineLOSC4->prenom);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;
        
        case 6://Question 3
            lire_equipe_clavier(&nouvEqFoot);
            afficher_equipe(nouvEqFoot);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;

        case 7://Question 4
            ecrire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);
            lire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;

        case 8://Question 5
            strcpy(nomFicEq, nouvEqFoot.nom);
            strcat(nomFicEq,".txt");
            ecrire_equipe_fichier(nomFicEq, &nouvEqFoot);
            lire_equipe_fichier("nouvelleEquipe.txt", &nouvEqFoot);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;

        case 9://Question 6
            int resultat;
            resultat = trouver_maillot_joueur(&eqFoot);

            affichageMenuTP2();
            scanf("%d",&choix);
            break;
        
        case 0:
            printf("Programme terminé");
        default:
            printf("choix incorrect");
            affichageMenuTP2();
            scanf("%d",&choix);
            break;
        }
        }
    }
    else if(choixTp == 2)
    {
        affichageMenuTP2Bis();
        scanf("%d",&choix);

        while(choix != 0)
        {

        switch (choix)
        {
        case 0:
            printf("Quitter le programme");  
        case 1:
            printf("\nappelle dynamique\n\n");
            lire_equipe_fichier_alloc_dyn("LOSC.txt",&eqFootDyn);
            afficher_equipe_alloc_dyn(eqFootDyn);

            affichageMenuTP2Bis();
            scanf("%d",&choix);
            break;

        case 2:
            long tailleEqFootDyn = occupation_memoire_equipe_alloc_dyn(eqFootDyn);
            printf("\n %llu octets\n\n",tailleEqFootDyn);

            affichageMenuTP2Bis();
            scanf("%d",&choix);
            break;
        
        case 3:
            ecrire_equipe_fichier_alloc_dyn("nouvelleEquipeDyn.txt", &nouvEqFootDyn);
            lire_equipe_fichier_alloc_dyn("nouvelleEquipeDyn.txt", &nouvEqFootDyn);

            affichageMenuTP2Bis();
            scanf("%d",&choix);
            break;

        default:
            printf("valeur incorrect");
            affichageMenuTP2Bis();
            scanf("%d",&choix);
            break;
        }
        }
    }

    
    

    

    


    //-------------------------------------
    //--- Question 3
    //-------------------------------------
    

    //-------------------------------------
    //--- Question 4
    //-------------------------------------
    

    //-------------------------------------
    //--- Question 5
    //-------------------------------------
    




   

    return 0;
}
