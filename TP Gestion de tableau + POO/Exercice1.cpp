#include <iostream>
#include "Outil.h"
#include <random>
#include <array>

using namespace std;

//TODO:Revoir la fonction rand() pour que les nombre aléatoire soit choisie correctement sans que forcément il 

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
		displayArray;	

		switch (choix)
		{
		case 1:
			intitialArray(tableau);
			displayArray(tableau, NB_CASES);
			displayMenu();

			cout << "" << endl;
			cout << "Choisissez votre fonction" << endl;
			cin >> choix;
			break;

		case 2:
			triArray(tableau);
			displayArray(tableau, NB_CASES);
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

			int* newTableau = deleteFirstOccurence(tableau, valeur);
			displayArray(newTableau, NB_CASES - 1);
			delete[] newTableau;
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
	cout << "****MENU****" << endl;
	cout << "\n\n** 0 ** Quitter le programme\n** 1 ** Affichage tableau aléatoire\n** 2 ** Tri tableau\n** 3 ** Suppression 1er occurence\n" << endl;
}

//Fonction permettant d'initialiser le tableau avec des valeur aléatoire.
void intitialArray(int *tableau)
{
	
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
int* deleteFirstOccurence(int *tableau, int valeur)
{
	int i;
	bool trouver = false;
	int indiceValeur = - 1;

	
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

	int *newTableau = new int[NB_CASES - 1] {};

	for (int i = 0 ,j = 0; i < NB_CASES; i++)
	{
		if (i != indiceValeur)
		{
			newTableau[j] = tableau[i];
			j++;
			
		}
	}


	return newTableau;
}

