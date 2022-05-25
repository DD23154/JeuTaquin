#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <vector>

void drawGrid(sf::RenderWindow& window);
void drawButtons(sf::RenderWindow& window);
void drawText(sf::RenderWindow& window);
int getParitePermut(const vector<int>& tab);
int getPariteVide(const vector<int>& tab);