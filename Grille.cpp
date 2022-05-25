#include "Grille.h"
/// <summary>
/// Author : Cécilia PERETTE, Adèle MOURIER
/// </summary>
/// <param name="p"></param>

Grille::Grille(sf::Font p) 
{
	liste_.resize(16);
	police_ = p;

	//Affectation de valeurs de 0 à 16 par ordre croissant des les cases et définition de la police des cases
	for (int i = 0; i < 16; i++)
	{
		liste_[i].setValeur(i+1);
		liste_[i].setFont(police_);
	}

	// Création lignes verticales
	for (int i = 0; i < 5; i++)
		lignes_.push_back(sf::RectangleShape(sf::Vector2f(3, 400)));

	// Création lignes horizontales
	for (int i = 0; i < 4; i++)
	{
		lignes_.push_back(sf::RectangleShape(sf::Vector2f(400, 3)));
	}
	lignes_.push_back(sf::RectangleShape(sf::Vector2f(403, 3))); //403  au lieu de 400 pour l'esthetisme
}

Grille::~Grille()
{
	liste_.clear();
}

// E : la fenêtre d'affichage du jeu
// S : Affichage des lignes qui constituent la grille de jeu 
void Grille::drawGrille(sf::RenderWindow& window) {
	// Positionnement des lignes (x,y)
	int x = 50, y = 50;
	for (int i = 0; i < 10; i++)
	{
		lignes_[i].setPosition(x, y);
		if (i<4)
			x = x + 100;
		else
		{
			if (i==4)
				x = 50;
			else
				y = y + 100;	
		}
	}

	// Remplissage des lignes de couleurs noires
	for (size_t i = 0; i < lignes_.size(); i++)
		lignes_[i].setFillColor(sf::Color::Black);

	// Affichage des lignes
	for (size_t i = 0; i < lignes_.size(); i++)
		window.draw(lignes_[i]);
}

// E : la fenêtre d'affichage du jeu
// S : affichage des valeurs contenues dans les cases de la grille
void Grille::displayCases(sf::RenderWindow& window)
{
	int posHor[4] = {72,172,272,372};
	int posVer1char[4] = { 80,180,280,380 };
	int posVer2char[4] = { 89,189,289,389 };

	int i = 0;
	//Affecation position de chaque case 1ère ligne
	for (i = 0; i < 4; i++)
	{
		if (liste_[i].getValeur() > 9)
			liste_[i].setPose(posVer1char[i],posHor[0]);
		else
			liste_[i].setPose(posVer2char[i],posHor[0]);
	}
	//Affecation position de chaque case 2ème ligne
	for (i = 4; i < 8; i++)
	{
		if (liste_[i].getValeur() > 9)
			liste_[i].setPose(posVer1char[i-4], posHor[1]);
		else
			liste_[i].setPose(posVer2char[i-4], posHor[1]);
	}
	//Affecation position de chaque case 3ème ligne
	for (i = 8; i < 12; i++)
	{
		if (liste_[i].getValeur() > 9)
			liste_[i].setPose(posVer1char[i-8], posHor[2]);
		else
			liste_[i].setPose(posVer2char[i-8], posHor[2]);
	}
	//Affecation position de chaque case 4ème ligne
	for (i = 12; i < 16; i++)
	{
		if (liste_[i].getValeur() > 9)
			liste_[i].setPose(posVer1char[i-12], posHor[3]);
		else
			liste_[i].setPose(posVer2char[i-12], posHor[3]);
	}

	for (int m = 0; m < 16; m++)
	{
		if (liste_[m].getValeur()!=16)
		{
			liste_[m].setTexte();
			liste_[m].drawCase(window);
		}
	}
}


//E: liste des nombres entre 1 et 16 (16=case vide) ordre aléatoire
//S: un entier = 1 si le nombre de permutation pour revenir à un ordre croissant est impair, 0 si pair
int Grille::getParitePermut()
{
	std::vector<Case> tab_(liste_);
	int n, pos_max, val_max, perm;
	perm = 0;

	for (int i = 15; i > 0; i--)
	{
		pos_max = i;
		val_max = i + 1;
		while (tab_[pos_max].getValeur() != val_max && pos_max>0)
		{
			pos_max--;
		}
		if (pos_max != i)
		{
			perm++;
			n = liste_[i].getValeur();
			tab_[i].setValeur(liste_[pos_max].getValeur()); //tab_[i] = liste_[pos_max];
			tab_[pos_max].setValeur(n);
		}
	}
	return perm % 2;
	tab_.clear();
}



//E: liste des nombres entre 1 et 16 (16=case vide) ordre aléatoire
//S: un entier = 0 si le nombre de cases séparant la case vide de son emplacement en bas à droite (16 = dernier de la liste) est pair, 1 si impair
int Grille::getPariteVide()
{
	int parite;
	if (liste_[0].getValeur() == 16 || liste_[2].getValeur() == 16 || liste_[5].getValeur() == 16 || liste_[7].getValeur() == 16 || liste_[8].getValeur() == 16 || liste_[10].getValeur() == 16 || liste_[13].getValeur() == 16 || liste_[15].getValeur() == 16)
		parite = 0;
	else
		parite = 1;
	return parite;
}


//Générer une liste de nombre aléatoire et les assigner à des cases
void Grille::setListe()
{
	int paritePerm, pariteVide;

	srand(time(0)); //srand() donne a fct aléatoire un nv0 pts de départ, time(0) donne temps en s
	do
	{
		//Generation d'une liste de 16 entiers de 1 à 16 aléatoire random_shuffle
		std::random_shuffle(liste_.begin(), liste_.end()); //shuffle de manière solvable ?
		paritePerm = getParitePermut();
		pariteVide = getPariteVide();
	} while (paritePerm != pariteVide);
}

void Grille::exemple()
{
	liste_[11].setValeur(16);
	liste_[15].setValeur(12);
}

int Grille::getValeurCase(int i)
{
	return liste_[i].getValeur();
}

int Grille::getIdVide()
{
	int idVide = 0;
	while (liste_[idVide].getValeur() != 16 && idVide < 16)
	{
		idVide++;
	}
	return idVide;
}

sf::Vector2i Grille::getPosVide()
{
	sf::Vector2i posVide;
	int idVide = getIdVide();

	posVide.x = liste_[idVide].getPoseX();
	posVide.y = liste_[idVide].getPoseY();
	
	return posVide;
}

void Grille::switchCases(sf::Event& e, sf::RenderWindow& w)
{
	//Grille : e.mouseButton.x >= 50 && e.mouseButton.x <= 450 && e.mouseButton.y >= 50 && e.mouseButton.y <= 450
	sf::Vector2i pVide = getPosVide();
	int idVide = getIdVide();
	Case temp;

	//Click dans la case supérieure à la case vide
	if (e.mouseButton.y <= pVide.y - 23 && e.mouseButton.y >= pVide.y - 123 && e.mouseButton.x >= pVide.x - 31 && e.mouseButton.x <= pVide.x + 69 && idVide - 4>=0)
	{
		temp = liste_[idVide];
		liste_[idVide] = liste_[idVide - 4];
		liste_[idVide - 4] = temp;
	}
	else
	{
		//Click dans la case inférieure à la case vide
		if (e.mouseButton.y <= pVide.y + 177 && e.mouseButton.y >= pVide.y + 77 && e.mouseButton.x >= pVide.x - 31 && e.mouseButton.x <= pVide.x + 69 && idVide + 4 <= 15)
		{
			temp = liste_[idVide];
			liste_[idVide] = liste_[idVide + 4];
			liste_[idVide + 4] = temp;
		}
		else
		{
			//Click dans la case de droite à la case vide
			if (e.mouseButton.y <= pVide.y + 77 && e.mouseButton.y >= pVide.y - 23 && e.mouseButton.x >= pVide.x + 69 && e.mouseButton.x <= pVide.x + 169 && idVide + 1 <= 15)
			{
				temp = liste_[idVide];
				liste_[idVide] = liste_[idVide + 1];
				liste_[idVide + 1] = temp;
			}
			else
			{
				//Click dans la case de gauche à la case vide
				if (e.mouseButton.y <= pVide.y + 77 && e.mouseButton.y >= pVide.y - 23 && e.mouseButton.x >= pVide.x - 131 && e.mouseButton.x <= pVide.x - 31 && idVide - 1 >= 0)
				{
					temp = liste_[idVide];
					liste_[idVide] = liste_[idVide - 1];
					liste_[idVide - 1] = temp;
				}
			}
		}
	}
}

//S: vrai si toutes les valeurs sont dans l'ordre croissant dans la liste, faux sinon
bool Grille::checkVictory()
{
	bool victory = false;
	int i = 0;

	while (i < 16 && liste_[i].getValeur()==i+1)
	{
		i++;
	}
	if (i == 16)
		victory = true;
	else
		victory = false;

	return victory;
}

void Grille::saveGrid(std::fstream& f, std::string s)
{
	f.open(s, std::ios_base::out);
	for (int i = 0; i < 16; i++)
		f << liste_[i].getValeur() << std::endl;
	f.close();
}

void Grille::chargerGrid(std::fstream& f, std::string s)
{
	f.open(s,std::ios_base::in);
	int n = 0;
	for (int i = 0; i < 16; i++)
	{
		f >> n;
		liste_[i].setValeur(n);
	}
	f.ignore();
	f.close();
}
