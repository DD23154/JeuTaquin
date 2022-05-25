#include "Case.h"
/// <summary>
/// Author : Adèle MOURIER
/// </summary>

void Case::setTexte()
{
	texte_.setFont(police_);
	texte_.setString(std::to_string(valeur_));
	texte_.setCharacterSize(50);
	texte_.setFillColor(sf::Color::Black);
	texte_.setPosition(poseX_, poseY_);
}