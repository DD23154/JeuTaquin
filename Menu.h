#pragma once
#include "Bouton.h"
#include "Grille.h"

class Menu
{
private:
	Bouton newGame_;
	Bouton saveGame_;
	Bouton quitGame_;
	Grille* grille_;

public:
	Menu(sf::Font, Grille*); 
	~Menu(); //problème de mémoire au niveau du destructeur
	void drawBoutons(sf::RenderWindow&);
	void startNewGame(sf::Event& e, sf::RenderWindow& window);
	void saveGame(sf::Event& e, sf::RenderWindow& window, std::fstream&, std::string);
};