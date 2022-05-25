#include "Bouton.h"

/// <summary>
/// Author : Adèle MOURIER
/// </summary>

/*Bouton::Bouton(std::string val, int txtX, int txtY, int pX, int pY, int taX, int taY)
{
	//police_ = f;
	valeur_ = val;
	textX_ = txtX;
	textY_ = txtY;
	posX_ = pX;
	posY_ = pY;
	tailleX_ = taX;
	tailleY_ = taY;
}*/

void Bouton::drawBtn(sf::RenderWindow& window)
{
	//Definition des caractéristiques de l'affichage de la forme
	rect_.setOrigin(25, 40);
	rect_.setSize(sf::Vector2f(tailleX_, tailleY_));
	rect_.setPosition(posX_, posY_);
	rect_.setFillColor(sf::Color::White);
	rect_.setOutlineColor(sf::Color::Black);
	rect_.setOutlineThickness(2);

	window.draw(rect_);
}

void Bouton::drawText(sf::RenderWindow& window)
{
	//Definition des caractéristiques de l'affichage du texte
	texte_.setFont(police_);
	texte_.setString(valeur_);
	texte_.setCharacterSize(20);
	texte_.setFillColor(sf::Color::Black);
	texte_.setPosition(textX_, textY_);

	window.draw(texte_);
}

void Bouton::setBouton(std::string val, int txtX, int txtY, int pX, int pY, int taX, int taY, sf::Font f)
{
	police_ = f;
	valeur_ = val;
	textX_ = txtX;
	textY_ = txtY;
	posX_ = pX;
	posY_ = pY;
	tailleX_ = taX;
	tailleY_ = taY;
}