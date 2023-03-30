#include <stdio.h>
#include<stdlib.h>

void affichageMenu();
void echanger(int *a, int *b);
void trier(int *a, int *b, int *c);
int puissance2(int a);
void fois2(int *a);
void puissance2_par_adresse(int *a, int *puissance);
int pgcd(int *a, int *b);
int ppcm(int *a, int *b, int *pgcd);
void pgcd_ppcm(int *a, int *b, int *c, int *d);

int main(void) {
int choix, nombre, nombre1, nombre2, valeurPgcd, valeurPpcm, puissance;
int resultat = 0;


printf("Quelle est votre choix :");

scanf("%d",&choix);

while(choix != 0)
{
    affichageMenu();

    switch (choix)
{
case 0:
    printf("Programme terminé");
    break;
case 1:
    printf("Choisissez les valeurs à échanger\n");
    int x , y;

    printf("Valeurs de x: ");
    scanf("%d",&x);

    printf("Valeur de y: ");
    scanf("%d",&y);
    
    printf("voici la valeur de x : %d \n", x);
    printf("voici la valeur de y: %d \n", y);

    echanger(&x, &y);

    printf("voici la valeur de x : %d \n", x);
    printf("voici la valeur de y: %d \n ", y);

    printf("Quelle est votre choix :");

    scanf("%d",&choix);
    
    break;
case 2:
    printf("Choisissez les valeurs à trier\n");
    int a , b, c;

    printf("Valeurs de a: ");
    scanf("%d",&a);

    printf("Valeur de b: ");
    scanf("%d",&b);

    printf("Valeur de b: ");
    scanf("%d",&c);

    printf("voici les valeurs non trier : %d , %d, %d \n", a, b, c);

    trier(&a, &b, &c);

    printf("voici les valeurs trier : %d , %d, %d \n", a, b, c);

    printf("Quelle est votre choix :");

    scanf("%d",&choix);
    
    break;

case 3:
    printf("Entrez une puissance :\n");
    scanf("%d",&nombre);
    resultat = puissance2(nombre);
    printf("2^%d = %d\n", nombre, resultat);
    printf("Quelle est votre choix :");
    scanf("%d",&choix);
    break;

case 4:
    printf("Entrez un nombre :\n");
    scanf("%d",&nombre);
    printf("Entrez la puissance :\n");
    scanf("%d",&puissance);
    puissance2_par_adresse(&nombre, &puissance);
    printf("Le résultat est : %d \n", nombre);
    printf("Quelle est votre choix :");
    scanf("%d",&choix);
    break;

case 5: // ma fonction ppcm-pgcd ne fonctionne pas
printf("Entrer un nombre : \n");
scanf("%d", nombre1);
printf("Entrer un nombre : \n");
scanf("%d", nombre2);
valeurPgcd = pgcd(&nombre1,&nombre2);
valeurPpcm = ppcm(&nombre1, &nombre2, &valeurPgcd);
pgcd_ppcm(&nombre1,&nombre2, &valeurPgcd, &valeurPpcm);
printf("Vos valeurs sont : %d et %d \nle pgcd est %d\nle ppcm %d", nombre1, nombre2, valeurPgcd, valeurPpcm);
default:
    break;
}
}


    
    return 0;
}

void echanger(int *a, int *b)
{
    
    int c = *a;
    *a = *b;
    *b = c;
}

void trier(int *a, int *b, int *c)
{
    int d = 0;

    if(*a > *b)
    {
        echanger(a,b);
    }
    if (*a > *c)
    {
        echanger(a, c);
    }
    if (*b > *c)
    {
        echanger(b, c);
    }
    
}

void affichageMenu()
{
    printf("----------MENU---------- \n");
    printf(" 1- échnager\n 2- trier\n 3- puissance2\n 0- quitter\n");
}

void fois2(int *a)
{

    *a = *a * 2;

}

int puissance2(int a)
{
    int resultat = 1;

    for(int i = 0; i < a; i++ )
    {
        fois2(&resultat);
    }

    return resultat;

}

void puissance2_par_adresse(int *a, int *puissance)
{
    

    for(int i = 0; i < *puissance; i++ )
    {
        fois2(a);
    }

}

int pgcd(int *a, int *b)
{
    while (*b != 0)
    {
        int t = *b;
        *b = *a % *b;
        *a = t;
    }
    
    return *a;
}

int ppcm(int *a, int *b, int *pgcd)
{
    
    int resultat = (*a * *b)/ *pgcd;

    return resultat;
}


void pgcd_ppcm(int *a, int *b, int *c, int *d)
{
    int *c = pgcd(&a, &b);
    int *d = ppcm(&a, &b, &c);
}