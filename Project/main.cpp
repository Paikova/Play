#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <list>
#include <vector>
#include "menu.h"
#include "finish.h"

using namespace sf;
using namespace std;

class Basic
{
public:
	float x, y, w, h, dx, dy, speed, moveTimer;
	float xMap = 500, yMap = 550, xMapa = 0, yMapa = 50;;
	bool life;
	int dir = 0;
	float dressSprite = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	String name;
	Basic(Image image, float X, float Y, float W, float H)
	{
		x = X;
		y = Y;
		w = W;
		h = H;

		moveTimer = 0;
		speed = 0;
		dx = 0;
		dy = 0;
		life = true;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);

	}
	virtual void update(float time) = 0;

};



class Player : public Basic
{
public:
	Player(Image image, float X, float Y, float W, float H) :Basic(image, X, Y, W, H)
	{
		sprite.setPosition(xMap, yMap);

		sprite.setTextureRect(IntRect(x, y, w, h));


	}
	
	int point = 0;
	void control(float time)
	{
		if (Keyboard::isKeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				dir = 1;
				speed = 0.2;
				sprite.setScale(1, 1);
				dressSprite += 0.005*time;
				if (dressSprite > 8)
					dressSprite -= 8;
				sprite.setTextureRect(IntRect(int(dressSprite)*w, y, w, h));
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				dir = 2;
				speed = 0.2;
				sprite.setScale(-1, 1);
				dressSprite += 0.005*time;
				if (dressSprite > 8)
					dressSprite -= 8;
				sprite.setTextureRect(IntRect(w*int(dressSprite), y, w, h));
			}
		}

	}
	void update(float time)
	{
		control(time);

		if (dir == 1)
		{
			dx = speed;


		}
		if (dir == 2)
		{
			dx = -speed;

		}
		xMap += dx * time;
		if (xMap < 0)
			xMap = 0;
		else if (xMap > 1200)
			xMap = 1200;
		
		sprite.setPosition(xMap, yMap);
		
		speed = 0;
		dx = 0;




	}

};
class Enemy :public Basic
{
public:
	Enemy(Image &image, float X, float Y, int W, int H) :Basic(image, X, Y, W, H)
	{
		xMapa = 20 + rand() % (1161), yMapa = 50;
		sprite.setPosition(xMapa, yMapa);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		dy = 0.09;
	}
	void update(float time)
	{
		yMapa += dy * time;
		dressSprite += 0.009*time;
		if (dressSprite > 3)
			dressSprite -= 3;
		sprite.setTextureRect(IntRect(int(dressSprite)*w, y, w, h));
		if (yMapa > 650)
		{
			yMapa = 650;
			
			life = false;
		}
		sprite.setPosition(xMapa + w / 2, yMapa + h / 2);
	}
	void color()
	{
		sprite.setColor(Color(255, 255, 255, 0));
	}
};


bool check(float yEnemy,float xEnemy, float yPlayer, float xPlayer, float h, float w)
{
	return (yEnemy > (yPlayer-h/2) 
		&& yEnemy<(yPlayer+h/2)
		&& xEnemy>(xPlayer-w/2) 
		&& xEnemy<(xPlayer+w/2));
};



int main()
{
	RenderWindow window(VideoMode(1200, 700), "Catch it if you can");
	int NumberPlayer;
	NumberPlayer= menu(window);
	int NumberEnemy = menuEnemy(window);

	Clock clock;
	

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 50);
	Text text1("", font, 50);
	
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);


	Image ImagePlayer;
	int x = 0, y = 0, w = 80, h = 115;


	if (NumberPlayer == 1)
	{

		ImagePlayer.loadFromFile("images/1попытка.png");
	}
	else
		if (NumberPlayer == 2)
		{
			ImagePlayer.loadFromFile("images/girl.png");
		}
		else
			if (NumberPlayer == 3)
			{
				ImagePlayer.loadFromFile("images/Player.png");
			}
			else
				if (NumberPlayer == 4)
				{
					ImagePlayer.loadFromFile("images/Soldier.png");
				}
				else
					if (NumberPlayer == 5)
					{
						ImagePlayer.loadFromFile("images/Zombie.png");
					}

	Player player(ImagePlayer, x, y, w, h);


	Image imageEnemy;
	if (NumberEnemy == 1)
	{
		imageEnemy.loadFromFile("images/cat(1).png");
		x = 0;
		y = 0;
		w = 49;
		h = 35;

	}
	else
	{
		if (NumberEnemy == 2)
		{
			imageEnemy.loadFromFile("images/Raccoon.png");
			x = 0;
			y = 0;
			w = 49;
			h = 35;
		}
	}
	
	int amoutEnemy = 60;
	vector<Enemy*> vectorEnemy(amoutEnemy);
	for (auto& unit : vectorEnemy)
		unit = new Enemy(imageEnemy, x, y, w, h);
	
	int amountEnemyNow = 0;


	Texture texFon;
	texFon.loadFromFile("images/BackGroundPlay.jpg");
	Sprite spriteFon(texFon);

	SoundBuffer catchbuffer;
	catchbuffer.loadFromFile("sound/catch.ogg");
	Sound soundcatch;
	soundcatch.setBuffer(catchbuffer);

	SoundBuffer fallbuffer;
	fallbuffer.loadFromFile("sound/fall.ogg");
	Sound soundfall;
	soundfall.setBuffer(fallbuffer);



	int level = 0;
	
	int nenado = 0;
	
	float timeE = 0;
	while (window.isOpen())
	{
		window.clear();
		window.draw(spriteFon);
		float time = clock.getElapsedTime().asMicroseconds();
		
	
		clock.restart();

		time = time / 800;
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			menu(window);

		}



		player.update(time);
		window.draw(player.sprite);

		if (amountEnemyNow == amoutEnemy)
		{
			if(player.point>40)
				finish(window, 1);
			else
				finish(window, 2);
			amountEnemyNow = 0;
			
		}

		if (level == 0)
		{
			vectorEnemy[amountEnemyNow]->dy = 0.09;
		}
		else
		{
			if (level == 1)
			{
				vectorEnemy[amountEnemyNow]->dy = 0.15;
			}
			else
				if (level >= 2)
				{
					vectorEnemy[amountEnemyNow]->dy = 0.2;
				}
		}


		if (player.point > 2 && level < 1)
			level++;
		else
			if (player.point > 5 && level < 2)
			{
				level++;
			}

		timeE += time;

		

		if (int(timeE) < 10000 && amountEnemyNow<amoutEnemy)
		{
			vectorEnemy[amountEnemyNow]->update(time);
			window.draw(vectorEnemy[amountEnemyNow]->sprite);
			if (check(vectorEnemy[amountEnemyNow]->yMapa,
				vectorEnemy[amountEnemyNow]->xMapa,
				player.yMap, player.xMap, player.h, player.w))
			{
				vectorEnemy[amountEnemyNow]->color();
				if (vectorEnemy[amountEnemyNow]->life)
				{
					soundcatch.play();
					player.point++;
					vectorEnemy[amountEnemyNow]->life = false;
					timeE = 10001;
				}

			}
		}
		if (vectorEnemy[amountEnemyNow]->yMapa == 650 && timeE<9000)
		{
			soundfall.play();
			timeE = 9000;
		}
		if (timeE>10000)
		{
			
			amountEnemyNow++;
			timeE = 0;
		}

		


		ostringstream playerPointString;  
		ostringstream levelString;
		playerPointString << player.point;
		text.setString("Очки: " + playerPointString.str());
		text.setPosition(50, 50);
		
		levelString << level;
		text1.setString("Уровень: " + levelString.str());
		text1.setPosition(50, 90);
		window.draw(text);
		window.draw(text1);

		window.display();
	}


	return 0;
}


