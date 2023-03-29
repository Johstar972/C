#pragma once

//Const
#define NB_CASES 20
#define MIN_RANDOM 0
#define MAX_RANDOM 9

//Fonction
void displayMenu();
void intitialArray(int *tableau);
void displayArray(int *tableau, int taille);
void triArray(int *tableau);
int* deleteFirstOccurence(int *tableau, int valeur);