#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Bouton
{
private:
	sf::Text texte_;
	sf::RectangleShape rect_;
	sf::Font police_;
	std::string valeur_="";
	int textX_=0;
	int textY_=0;
	int posX_=0;
	int posY_=0;
	int tailleX_=0;
	int tailleY_=0;

public:
	//Bouton();
	//Bouton(std::string, int, int, int,int, int, int);
	void setBouton(std::string, int, int, int, int, int, int, sf::Font);
	inline void setFont(sf::Font f) { police_ = f; };
	void drawBtn(sf::RenderWindow& window);
	void drawText(sf::RenderWindow& window);
};
