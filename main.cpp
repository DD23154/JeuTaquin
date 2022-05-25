#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include"Case.h"
#include"Grille.h"
#include "Menu.h"

int main()
{
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(500, 580), "Jeu de Taquin");

	//Création des flux --> à passer en CSV
	string filename("taquin.txt");
	fstream file;

	//Ajout d'une police de caractères
	sf::Font font;
	font.loadFromFile("font.ttf");

	//Création d'objets grille et boutons
	Grille myGrid(font);

	//Création du menu
	Menu myMenu(font, &myGrid);

	//Savoir si la partie est réussie
	bool victory = false;
	bool setNewGame = false;

	//Génération d'une combinaison aléatoire 
	//myGrid.setListe();
	//myGrid.exemple();
	myGrid.chargerGrid(file, filename);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) { //pollevent ??????
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			else
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					myMenu.startNewGame(event, window);
					myGrid.switchCases(event, window);
					//Vérification de l'odre des cases : 1 si toutes les cases dans l'ordre croissant
					//Ne pas répéter le message lors du click
					victory = myGrid.checkVictory();
					if (victory)
						cout << "Vous avez gagner" << endl;
					else
						myMenu.saveGame(event, window, file, filename);

				}	
		}
		// On efface la fenêtre (en blanc)
		window.clear(sf::Color::White);
				
		// On affiche la grille et les boutons et les chiffres dans les cases
		myGrid.drawGrille(window);
		myMenu.drawBoutons(window);
		myGrid.displayCases(window);

		//Mise à jour de la fenêtre
		window.display();
	}

	return 0;
}
