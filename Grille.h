#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Case.h"
#include <fstream>

class Grille
{
private:
	std::vector<Case> liste_; //voir faire tableau
	std::vector<sf::RectangleShape> lignes_; //voir pour faire tableau
	sf::Font police_;

public:
	Grille(sf::Font);
	~Grille();
	void drawGrille(sf::RenderWindow& window);
	void displayCases(sf::RenderWindow& window);
	int getParitePermut();
	int getPariteVide();
	int getValeurCase(int i);
	sf::Vector2i getPosVide();
	int getIdVide();
	void setListe();
	void exemple();
	void switchCases(sf::Event&, sf::RenderWindow&);
	bool checkVictory();
	void saveGrid(std::fstream&, std::string);
	void chargerGrid(std::fstream&, std::string);
};