# Projet 1: Gestion de bibliothèque

## Objectif :

### Créer un ***programme de gestion de bibliothèque*** qui permettra aux utilisateurs ***d'ajouter***, ***supprimer***, ***modifier*** et ***rechercher des livres dans une base de données***.

## Quelques étapes pour réaliser ce projet:

1. Créer une structure pour représenter les livres avec des champs tels que le titre, l'auteur, l'éditeur, la date de publication, le nombre de pages, etc.

2. Définir des fonctions pour ajouter, supprimer, modifier et rechercher des livres dans la base de données. Ces fonctions peuvent utiliser des fichiers pour stocker les informations des livres.
 * Stocker les informations dans une fichier est une solution qu'il ne faudra pas laisser au hasard, cependant il ya la possibilité d'interroger une base de donnée en local avec **postgresql** et d'avoir le contenu des tables dans un dossier en local à l'intérieur du projet.
 * Pour stocker une base de donner postgres sous forme de fichier il faudra utiliser cette commande:
     * 
     
     ```bash
createdb -h /chemin/vers/votre/projet/ma_base_de_donnees ma_base_de_donnees
	 ```
 * Pour ce connecter et interroger cette base de donnée en C il faudra utiliser la bibliothèque **libpq**.
     * _Exemple :_
     
     ```c
		     #include <stdio.h>
		#include <stdlib.h>
		#include <libpq-fe.h>
		
		int main() {
		    PGconn *conn = PQconnectdb("dbname=mydatabase user=myuser password=mypassword");
		    if (PQstatus(conn) != CONNECTION_OK) {
		        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		        PQfinish(conn);
		        exit(1);
		    }
		
		    PGresult *res = PQexec(conn, "SELECT * FROM books;");
		    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		        fprintf(stderr, "Query failed: %s\n", PQresultErrorMessage(res));
		        PQclear(res);
		        PQfinish(conn);
		        exit(1);
		    }
		
		    int n = PQntuples(res);
		    int m = PQnfields(res);
		
		    for (int i = 0; i < n; i++) {
		        for (int j = 0; j < m; j++) {
		            printf("%s\t", PQgetvalue(res, i, j));
		        }
		        printf("\n");
		    }
		
		    PQclear(res);
		    PQfinish(conn);
		
		    return 0;
		}
     ``` 


3. Implémenter une interface utilisateur qui permettra aux utilisateurs d'interagir avec le programme. Vous pouvez utiliser des menus, des messages d'erreur, des demandes d'entrée de données, etc.
 * Utilisation de la bibliothèque GTK+
     * _Exemple de fenêtre:_
 
```c
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello, World!");
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    gtk_widget_show(window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();
    return 0;
}
```

4. Tester le programme pour vous assurer qu'il fonctionne correctement. Vous pouvez ajouter des fonctionnalités supplémentaires comme la possibilité de trier les livres par titre, auteur, ou autres champs.



#### Apprentissage: 
_Ce projet vous donnera l'occasion de pratiquer la manipulation de structures, la lecture et l'écriture de fichiers, la gestion de la mémoire, et l'interaction utilisateur-programme en C._
