#pragma once
#include"functions.h"

// Affichage de la grille
void drawGrid(sf::RenderWindow& window) {
	std::vector<sf::RectangleShape> lines;

	// Lignes verticales
	lines.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));

	// Lignes horizontales
	lines.push_back(sf::RectangleShape(sf::Vector2f(400, 3)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(400, 3)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(400, 3)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(400, 3)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(403, 3)));

	// Positionnement des lignes
	lines[0].setPosition(150, 50); // (x,y)
	lines[1].setPosition(250, 50);
	lines[2].setPosition(350, 50);
	lines[3].setPosition(50, 50);
	lines[4].setPosition(450, 50);
	lines[5].setPosition(50, 150);
	lines[6].setPosition(50, 250);
	lines[7].setPosition(50, 350);
	lines[8].setPosition(50, 50);
	lines[9].setPosition(50, 450);

	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::Black);

	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);
}

//Affichage des boutons (Nouvelle partie, Sauvegarder, Quitter)
void drawButtons(sf::RenderWindow& window)
{
	sf::RectangleShape newGameB (sf::Vector2f(150, 60));
	sf::RectangleShape saveGameB (sf::Vector2f(130, 60));
	sf::RectangleShape quitGameB (sf::Vector2f(100, 60));

	newGameB.setOrigin(25, 40);
	saveGameB.setOrigin(25, 40);
	quitGameB.setOrigin(25, 40);

	newGameB.setPosition(45, 530);
	saveGameB.setPosition(225, 530);
	quitGameB.setPosition(380, 530);

	newGameB.setFillColor(sf::Color::Red);
	saveGameB.setFillColor(sf::Color::Red);
	quitGameB.setFillColor(sf::Color::Red);

	newGameB.setOutlineColor(sf::Color::Black);
	saveGameB.setOutlineColor(sf::Color::Black);
	quitGameB.setOutlineColor(sf::Color::Black);

	newGameB.setOutlineThickness(2);
	saveGameB.setOutlineThickness(2);
	quitGameB.setOutlineThickness(2);

	window.draw(newGameB);
	window.draw(saveGameB);
	window.draw(quitGameB);
}

void drawText(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text newGameT;
	sf::Text saveGameT;
	sf::Text quitGameT;

	newGameT.setFont(font);
	saveGameT.setFont(font);
	quitGameT.setFont(font);

	newGameT.setString("Nouvelle partie");
	saveGameT.setString("Sauvegarder");
	quitGameT.setString("Quitter");

	newGameT.setCharacterSize(20);
	saveGameT.setCharacterSize(20);
	quitGameT.setCharacterSize(20);

	newGameT.setFillColor(sf::Color::Black);
	saveGameT.setFillColor(sf::Color::Black);
	quitGameT.setFillColor(sf::Color::Black);

	newGameT.setPosition(30,510);
	saveGameT.setPosition(210, 510);
	quitGameT.setPosition(370, 510);

	window.draw(newGameT);
	window.draw(saveGameT);
	window.draw(quitGameT);
}

//E: liste des nombres entre 1 et 16 (16=case vide) ordre aléatoire
//S: un entier = 1 si le nombre de permutation pour revenir à un ordre croissant est impair, 0 si pair
int getParitePermut(const vector<int>& tab)
{
	vector<int> tab_(tab);
	int n, pos_max, val_max, perm;
	perm = 0;

	for (int i = 15; i > 0; i--)
	{
		pos_max = i;
		val_max = i + 1;
		while (tab_[pos_max] != val_max)
		{
			pos_max--;
		}
		if (pos_max != i)
		{
			perm++;
			n = tab[i];
			tab_[i] = tab[pos_max];
			tab_[pos_max] = n;
		}
		return perm % 2;
		//tab_.clear();
	}
}

//E: liste des nombres entre 1 et 16 (16=case vide) ordre aléatoire
//S: un entier = 0 si le nombre de cases séparant la case vide de son emplacement en bas à droite (16 = dernier de la liste) est pair, 1 si impair
int getPariteVide(const vector<int>& tab)
{
	int parite;
	if (tab[0] == 16 || tab[2] == 16 || tab[5] == 16 || tab[7] == 16 || tab[8] == 16 || tab[10] == 16 || tab[13] == 16 || tab[15] == 16)
	{
		parite = 0;
	}
	else
	{
		parite = 1;
	}
	return parite;
}