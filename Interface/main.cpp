#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(750,750),"SFML project"); //Appelle du constructeur RenderWindow pour creer une fenetre
    //La classe VideoMode elle permet  de spécifier les paramètres de résolution et de profondeur de couleur de la fenêtre

    sf::Vertex ligne [] = { //Il s'agit d'un tableau de sommet qui relier entre eux font des lignes
            sf::Vertex(sf::Vector2f(250,0)),
            sf::Vertex(sf::Vector2f(250,750)),
            sf::Vertex(sf::Vector2f(500,0)),
            sf::Vertex(sf::Vector2f(500,750)),
            sf::Vertex(sf::Vector2f(0,250)),
            sf::Vertex(sf::Vector2f(750,250)),
            sf::Vertex(sf::Vector2f(0,500)),
            sf::Vertex(sf::Vector2f(750,500)),
    }; //Ajouter des ligne grâce a des points (Vertex) qui sont des sommets.


    while (window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))//la methode pollEvent permet de récupérer un évènement,
            // dans un while on vérifie s'il y a un évènement généré par l'utilisateur et si oui on entre dans le while
        {
            switch (event.type) //On vérifie le type de l'évènement
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Space) //Si l'on presse la barre d'espace
                    {
                        cout << "Vous avez appuyer sur la touche espace" << endl;


                    }
                    break;

                case sf::Event::MouseMoved: //Si la souris bouge
                    cout << "new mouse x :" << event.mouseMove.x << endl;
                    cout << "new mouse y :" << event.mouseMove.y << endl;
                    break;

                // on ne traite pas les autres types d'évènements
                default:
                    break;
            }

        }

        window.clear();
        window.draw(ligne,8,sf::Lines);
        window.display();
    }

    return 0;
}
