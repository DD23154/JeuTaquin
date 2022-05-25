#include "Menu.h"

/// <summary>
/// Author : Cécilia PERETTE
/// </summary>
/// <param name="f"></param>
/// <param name="g"></param>

Menu::Menu(sf::Font f, Grille* g)
{
	grille_ = g;
	newGame_.setBouton("Nouveau Jeu", 44, 510, 55, 530, 150, 60, f);
	saveGame_.setBouton("Sauvegarder", 215, 510, 232, 530, 132, 60, f);
	quitGame_.setBouton("Quitter", 382, 510, 392, 530, 100, 60, f);
}

Menu::~Menu()
{
	delete grille_; //problème pointeur référence
}

void Menu::drawBoutons(sf::RenderWindow & w)
{
	newGame_.drawBtn(w);
	newGame_.drawText(w);

	saveGame_.drawBtn(w);
	saveGame_.drawText(w);

	quitGame_.drawBtn(w);
	quitGame_.drawText(w);
}

void Menu::startNewGame(sf::Event& e, sf::RenderWindow& window)
{
	if (e.mouseButton.x >= 27 && e.mouseButton.x <= 180 && e.mouseButton.y >= 486 && e.mouseButton.y <= 550)
		grille_->setListe();
}

void Menu::saveGame(sf::Event& e, sf::RenderWindow& window, std::fstream& f, std::string s)
{
	//mettre une seule fois la liste dans le fichier
	if (e.mouseButton.x >= 204 && e.mouseButton.x <= 335 && e.mouseButton.y >= 486 && e.mouseButton.y <= 550)
		grille_->saveGrid(f, s);
	//else
}