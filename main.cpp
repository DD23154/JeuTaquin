#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include"Case.h"
#include"Grille.h"
#include "Menu.h"

//nvffjqlrjhglkqejglqzmgkz

int main()
{
	// Cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(500, 580), "Jeu de Taquin");

	//Cr�ation des flux --> � passer en CSV
	string filename("taquin.txt");
	fstream file;

	//Ajout d'une police de caract�res
	sf::Font font;
	font.loadFromFile("font.ttf");

	//Cr�ation d'objets grille et boutons
	Grille myGrid(font);

	//Cr�ation du menu
	Menu myMenu(font, &myGrid);

	//Savoir si la partie est r�ussie
	bool victory = false;
	bool setNewGame = false;

	//G�n�ration d'une combinaison al�atoire 
	//myGrid.setListe();
	//myGrid.exemple();
	myGrid.chargerGrid(file, filename);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) { //pollevent ??????
			// Demande de fermeture de la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
			else
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					myMenu.startNewGame(event, window);
					myGrid.switchCases(event, window);
					//V�rification de l'odre des cases : 1 si toutes les cases dans l'ordre croissant
					//Ne pas r�p�ter le message lors du click
					victory = myGrid.checkVictory();
					if (victory)
						cout << "Vous avez gagner" << endl;
					else
						myMenu.saveGame(event, window, file, filename);

				}	
		}
		// On efface la fen�tre (en blanc)
		window.clear(sf::Color::White);
				
		// On affiche la grille et les boutons et les chiffres dans les cases
		myGrid.drawGrille(window);
		myMenu.drawBoutons(window);
		myGrid.displayCases(window);

		//Mise � jour de la fen�tre
		window.display();
	}

	return 0;
}
