#include "Outil.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>


using namespace std;

//TODO:Revoir la fonction rand() pour que les nombre aléatoire soit choisie correctement sans que forcément il
//Enlever l'initailisation du tableau du switch
//Trouver une autre manière de gérer la fonction deleteFirst et LastOcurrence pour ne pas avoir à allouer dynamiquement de la mémoire

//Main
int main(int argc, char* argv[])
{
	

	int tableau[NB_CASES] {}; //Pas besoin d'allocation dynamique sur le tableau
	
	int choix;
	displayMenu();

	cout << "Choisissez votre fonction" << endl;
	cin >> choix;

	while (choix != 0)
	{

		switch (choix)
		{
		case 1:
			intitialArray(tableau);
			displayArray(tableau, (sizeof(tableau) / sizeof(int)));
			displayMenu();

			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;
			break;

		case 2:
			triArray(tableau);
			displayArray(tableau, (sizeof(tableau)/sizeof(int)));
			displayMenu();

			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;
			break;

		case 3:
		{
			int valeur = 0;

			cout << "Choisissez la valeur que vous voulez efface ? :";
			cin >> valeur;

			vector<int> newTableau = deleteFirstOccurence(tableau, valeur);
			displayDynArray(newTableau);
			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;

			displayMenu();
			break;
		}

		case 4:
		{
			int valeur = 0;

			cout << "Choisissez la valeur que vous voulez efface ? :";
			cin >> valeur;

			vector<int> newTableau = deleteLastOccurence(tableau, valeur);
			displayDynArray(newTableau);
			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;

			displayMenu();
			break;
		}

		case 5:
		{
			int valeur = 0;

			cout << "Choisissez la valeur que vous voulez efface ? :";
			cin >> valeur;

			vector<int> newTableau = deleteAllOccurence(tableau, valeur);
			displayDynArray(newTableau);
			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;

			displayMenu();
			break;
		}
			
		
		default:
			cout << "Cette fonction n'existe pas !!" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;
			break;
		}
	}
	
	return 0;
}

//Fonction permettant d'afficher le menu des différentes fonctions du programme
void displayMenu()
{
	string menu = "\n\n** 0 ** Quitter le programme\n** 1 ** Affichage tableau aléatoire\n** 2 ** Tri tableau\n** 3 ** Suppression 1er occurence\n** 4 ** Suppression dernière occurence\n** 5 ** Supression de toute les occurences";
	cout << "****MENU****" << endl;
	cout << menu << endl;
}

//Fonction permettant d'initialiser le tableau avec des valeur aléatoire.
void intitialArray(int *tableau)
{
	srand(time(NULL));
	for (int i = 0; i < NB_CASES; i++)
	{
		
		int aleatoire = rand() % (MAX_RANDOM - MIN_RANDOM + 1) + MIN_RANDOM;
		tableau[i] = aleatoire;
	}
}

//Fonction permettant d'afficher le tableau passer en parametre, avec sa taille
void displayArray(int *tableau, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		cout << tableau[i] << " ";
	}
	cout << endl;
}

void displayDynArray(vector<int> tableau)
{
	for (auto i = tableau.begin(); i != tableau.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//Fonction permettant de trier le tableau dans l'orde croissant des valeurs
void triArray(int *tableau)
{
	for (int i = 0; i < NB_CASES; i++)
	{
		for (int j = 0; j < NB_CASES - 1; j++)
		{
			if (tableau[j] > tableau[j + 1])
			{
				int t = tableau[j];
				tableau[j] = tableau[j + 1];
				tableau[j + 1] = t;
			}
		}
	}
}

//Fonction permettant de supprimer la première occurence choisie.
vector<int>& deleteFirstOccurence(int *tableau, int valeur)
{
	int i, indiceValeur = -1;
	bool trouver = false;

	
	i = 0;

	while (trouver == false)
	{
		if (tableau[i] == valeur)
		{
			trouver = true;
			indiceValeur = i;
		}
		else
			i++;
	}

	vector<int>* newTableau = new vector<int>();

	for (int i = 0; i < NB_CASES; i++)
	{
		if (i != indiceValeur)
		{
			newTableau->push_back(tableau[i]);
			
			
		}
	}


	return *newTableau;
}


//Fonction permettant de supprimer la dernière occurence choisie.
vector<int>& deleteLastOccurence(int* tableau, int valeur)
{
	int i, indiceValeur = -1;
	bool trouver = false;

	for(int i = 0; i < NB_CASES; i++)
	{
		if (tableau[i] == valeur)
		{
			indiceValeur = i;
		}
	}

	vector<int> *newTableau = new vector<int>();

	for (int i = 0; i < NB_CASES; i++)
	{
		if (i != indiceValeur)
		{
			newTableau->push_back(tableau[i]);
			
		}
	}

	return *newTableau;
}

//Fonction permettant de supprimer toute les occurences similaires.
vector<int> &deleteAllOccurence(int* tableau, int valeur)
{
	int indiceValeur = -1, nbValeur = 0;

	for(int i = 0; i < NB_CASES; i++)
	{
		if (tableau[i] == valeur)
		{
			nbValeur += 1;
		}
	}

	vector<int>* newTableau;
	newTableau = new vector<int>();

	for (int i = 0; i < NB_CASES; i++)
	{
		if (tableau[i] != valeur)
		{
			newTableau->push_back(tableau[i]);

		}
	}

	return *newTableau;

}


