#include <iostream>
#include <limits>
#include "Plateau.h"
#include "Symbole.h"
#include "Player.h"


/*TODO:
 * Revoir le code pour que quand le joueur 1 gagne le joueur ne puisse plus jouer
 * Faire toute le documentation/commentaire du code
 * Faire une fonction pour le match nul
 * Faire l'interface graphique
 */

//Je fais un test pour comprendre


using namespace std;

bool victoireEnLigne(Plateau *plateau, Player joueur);
bool victoireEnColonne(Plateau *plateau, Player joueur);
bool victoireEnDiagonale(Plateau *plateau, Player joueur);


int main() {
    string name1, name2;

    Symbole symbole1, symbole2;

    int choix = 0;

    bool coupGagnant = false, ligne = false, colonne = false, diagonale = false;

    Plateau plateau = Plateau();

    cout << "Joueur 1:\nChoisissez votre pseudo :";
    cin >> name1;
    cout << "Choisissez votre symbole :" << endl;
    cout << "1. X  2. O" << endl;
    cin >> choix;

    while (choix != 1 && choix != 2)
    {
        if(cin.fail()) //si cin.fail return true c'est que l'utilisateur a entrer une valeur dont le type n'est pas conforme au type attendue
        {
            cin.clear();//On remet l'indicateur d'entrée/sortie a son état par défaut
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//On vide le tempon d'entrée pour effacer tout ce qui à été entrer par l'utilisateur
        }
        cout << "Votre choix est incorrect" << endl;
        cout << "Choisissez votre symbole :" << endl;
        cout << "1. X  2. O" << endl;
        cin >> choix;
    }

    if(choix == 1)
    {
        symbole1.setCharactere('X');
    }
    else
    {
        symbole1.setCharactere('O');
    }

    Player joueur1(name1,symbole1);

    cout << "Joueur 2:\nChoisissez votre pseudo :";
    cin >> name2;
    if(symbole1.getCharactere() == 'X')
    {
        symbole2.setCharactere('O');
    }
    else
    {
        symbole2.setCharactere('X');
    }

    Player joueur2(name2, symbole2);

    joueur1.afficherPlayer();
    joueur2.afficherPlayer();

    int tour = 0;
    while(!coupGagnant)
    {

        if(joueur1.getSymbole().getCharactere() == 'X')
        {
            cout << "Les X commence !!" << endl;
            cout << "C'est au tour de :" + joueur1.getName() << endl;
            joueur1.tourDeJeu(&plateau);
                
            if (victoireEnLigne(&plateau, joueur1) || victoireEnColonne(&plateau, joueur1) || victoireEnDiagonale(&plateau, joueur1))
            {
                cout << "Le joueur " << joueur1.getName() << " gagne avec les " << joueur1.getSymbole().getCharactere() << endl;
                coupGagnant = true;
            }


            cout << "C'est au tour de :" + joueur2.getName() << endl;
            joueur2.tourDeJeu(&plateau);

            if ( victoireEnLigne(&plateau, joueur2) || victoireEnColonne(&plateau, joueur2) || victoireEnDiagonale(&plateau, joueur2))
            {
                coupGagnant = true;
                cout << "Le joueur " << joueur2.getName() << " gagne avec les " << joueur2.getSymbole().getCharactere() << endl;
            }
        }

        else
        {
            cout << "Les X commence !!" << endl;
            cout << "C'est au tour de :" + joueur2.getName() << endl;
            joueur2.tourDeJeu(&plateau);

            if( victoireEnLigne(&plateau, joueur2) || victoireEnColonne(&plateau, joueur2) || victoireEnDiagonale(&plateau, joueur2))
            {
                coupGagnant = true;
                cout << "Le joueur " << joueur2.getName() << " gagne avec les " << joueur2.getSymbole().getCharactere() << endl;
            }


            cout << "C'est au tour de :" + joueur1.getName() << endl;
            joueur1.tourDeJeu(&plateau);

            if (victoireEnLigne(&plateau, joueur1) || victoireEnColonne(&plateau, joueur1) || victoireEnDiagonale(&plateau, joueur1))
            {
                coupGagnant = true;
                cout << "Le joueur " << joueur1.getName() << " gagne avec les " << joueur1.getSymbole().getCharactere() << endl;
            }

        }
        tour += 1;
    }


    return 0;
}

/**
 * Vérification de victoire en ligne.
 *
 * @param plateau: un pointeur vers un objet de type plateau
 * @param joueur: un objet de type Player
 * 
 * @return false s'il n'y a pas de ligne de symbole identique, ou true si l'on trouve une ligne de symbole identique
 */
bool victoireEnLigne(Plateau *plateau, Player joueur)
{
    int x = joueur.getSymbole().getPosition().getX();
    int y = joueur.getSymbole().getPosition().getY();

    int position = x * (ARRAY_SIZE)/3 + y;
    int enLigne = 0;
    bool ligne = false, pasDeLigne = false;

    while(!ligne && !pasDeLigne)
    {
        if (position == 3 || position == 5)
        {
            enLigne = 0;
        }
        if (plateau->getArray()[position] == joueur.getSymbole().getCharactere())
        {
            enLigne += 1;
            
            
            if (enLigne == 3)
            {
                ligne = true;
                return ligne;
            }
            
            
        }
        position++;
        if (position >= ARRAY_SIZE)
        {
            pasDeLigne = true;
        }

        
    }
    return false;
}

/**
 * Vérification de victoire en colonne.
 * 
 * @param plateau: un pointeur vers un objet de type plateau
 * @param joueur: un objet de type Player
 * 
 * @return false s'il n'y a pas de colonne de symbole identique, ou true si l'on trouve une colonne de symbole identique
 */
bool victoireEnColonne(Plateau *plateau, Player joueur)
{
    int x = joueur.getSymbole().getPosition().getX();
    int y = joueur.getSymbole().getPosition().getY();

    int position = x * (ARRAY_SIZE)/3 + y, positionDepart = 0;
    int enColonne = 0;
    bool colonne = false, pasDeColonnne = false;

    while(!colonne && !pasDeColonnne)
    {
        if( (plateau->getArray()[position] == joueur.getSymbole().getCharactere()))
        {
            enColonne += 1;
            if(enColonne == 3)
            {
                colonne = true;
                return colonne;
            }
            else
            {
                position += 3;
            }
        }

        else
        {
            enColonne = 0;
            positionDepart += 1;
            position = positionDepart;

        }

        if (position >= ARRAY_SIZE)
        {
            pasDeColonnne = true;

        }
        
    }
    return false;
}

/**
 * Vérification de victoire en diagonale.
 *
 * @param plateau: un pointeur vers un objet de type plateau
 * @param joueur: un objet de type Player
 * 
 * @return false s'il n'y a pas de diagonale de symbole identique, ou true si l'on trouve une diagonale de symbole identique
 */
bool victoireEnDiagonale(Plateau* plateau, Player joueur)
{
    int x = joueur.getSymbole().getPosition().getX();
    int y = joueur.getSymbole().getPosition().getY();

    int position = x * (ARRAY_SIZE) / 3 + y;
    int enDiagonale = 0, positionDepart = 0;

    bool diagonale = false, pasDeDiagonale = false;

    while (!diagonale && !pasDeDiagonale)
    {
        if (plateau->getArray()[position] == joueur.getSymbole().getCharactere())
        {

            enDiagonale += 1;
            if (enDiagonale == 3)
            {
                diagonale = true;
                return diagonale;
            }
            else
            {
                if(positionDepart == 2)
                {
                    position += 2;
                }
                else
                {
                    position += 4;
                }

            }
        }
        else
        {
            if(positionDepart == 2)
            {
                pasDeDiagonale = true;
            }
            else
            {
                enDiagonale = 0;
                positionDepart = 2;
                position = positionDepart;
            }

        }

    }
    return false;
}
