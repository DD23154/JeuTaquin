#pragma once
#include <SFML/Graphics.hpp>

class Case
{
private:
	int valeur_;
	int poseX_; //position du texte qui affiche la valeur
	int poseY_;
	//sf::RectangleShape rect_case_;
	sf::Font police_;
	sf::Text texte_;

public:
	//Case();
	inline int getValeur() { return valeur_; };
	inline void setValeur(int v) { valeur_ = v; };
	inline void setPose(int x, int y) { poseX_ = x; poseY_ = y; };
	inline int getPoseX() { return poseX_; };
	inline int getPoseY() { return poseY_; };
	inline void drawCase(sf::RenderWindow& window) { window.draw(texte_); };
	void setTexte();
	inline void setFont(sf::Font p) { police_ = p; };
};