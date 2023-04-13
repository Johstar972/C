#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int i, base = 10;
    size_t len = strlen(argv[1]);
    char *paramcc = malloc(sizeof (len + 1));
    strcpy(paramcc, argv[1]);


    //float paramreel = atof(argv[3]);
    float paramreel;
    char nombreReel[20];
    char * endPtrFloat;

    paramreel = strtod(argv[3],&endPtrFloat);

    //Question4
    if(errno == ERANGE || *endPtrFloat !='\0')
    {
        perror("Erreur lors de la conversion du char vers float\n");
        
        exit(EXIT_FAILURE);
    }


    //int paramentier = atoi(argv[2]);
    long paramentier;
    char nombre[20];
    char * endPtr;

    paramentier = strtol(argv[2], &endPtr,base);

    //Question4
    if(errno == ERANGE || *endPtr !='\0')
    {
        perror("Erreur lors de la conversion du char vers int\n");
        //Question5
        exit(EXIT_FAILURE);
    }

    if(argc > 4)
    {
        //Questtion2
        printf("3 arguments attendus, une chaine, un entier et un nombre reel.\n");
    }
    else {
            for (i = 0; i < argc; i++)
            {

                printf("parametre %d : '%s'\n", i, argv[i]);
            }

            //Question1

            printf("%s\n", paramcc);
            printf("%ld\n", paramentier);
            printf("%lf\n", paramreel);

    }
    free(paramcc);
    //Question5
    exit(EXIT_SUCCESS) ;
}
