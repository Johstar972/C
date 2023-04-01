#pragma once

#ifndef CONSTANTE_H

#define NB_CASES 20
#define MIN_RANDOM 0
#define MAX_RANDOM 9

#endif



#ifndef FONCTION_H
#define FONCTION_H

#include <vector>

void displayMenu();
void intitialArray(int *tableau);
void displayArray(int *tableau, int taille);
void displayDynArray(std::vector<int>);
void triArray(int *tableau);
std::vector<int>& deleteFirstOccurence(int *tableau, int valeur);
std::vector<int>& deleteLastOccurence(int *tableau, int valeur);
std::vector<int>& deleteAllOccurence(int *tableau, int valeur);

#endif