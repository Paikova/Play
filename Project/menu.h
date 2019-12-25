#include <SFML/Graphics.hpp>
using namespace sf;

int menuPlayer(RenderWindow & window);
int menu(RenderWindow & window)
{
	Texture menuTextureChoicePlayer, menuTextureLaw, menuTextureExit, menuBackground;
	menuTextureChoicePlayer.loadFromFile("images/ChoicePlayer.png");
	menuTextureLaw.loadFromFile("images/Law.png");

	menuTextureExit.loadFromFile("images/Exit.png");

	menuBackground.loadFromFile("images/BackGround.jpg");
	Sprite menuChoicePlayer(menuTextureChoicePlayer), menuLaw(menuTextureLaw), menuExit(menuTextureExit), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menuChoicePlayer.setPosition(100, 30);
	menuLaw.setPosition(100, 90);
	menuExit.setPosition(100, 150);
	menuBg.setPosition(345, 0);

	Texture menuTextureLawAbout;
	menuTextureLawAbout.loadFromFile("images/BackGroundMenu.jpg");
	Sprite menuLawAbout(menuTextureLawAbout);

	
	while (isMenu)
	{
		menuChoicePlayer.setColor(Color::White);
		menuLaw.setColor(Color::White);
		menuExit.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menuChoicePlayer.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menuLaw.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menuExit.setColor(Color::Blue); menuNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false;
			
				int N = menuPlayer(window);
		
				return N;

			}
			if (menuNum == 2) { window.draw(menuLawAbout); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		window.draw(menuChoicePlayer);
		window.draw(menuLaw);
		window.draw(menuExit);
		window.display();
	}
};

int menuPlayer(RenderWindow & window)
{
	
	
	Texture menuTexturePlayerBoy, menuTexturePlayerGirl, menuTexturePlayerPlayer, menuTexturePlayerSoldier, menuTexturePlayerZombie;
	
	menuTexturePlayerBoy.loadFromFile("images/adventurer_idle.png");
	menuTexturePlayerGirl.loadFromFile("images/female_idle.png");
	menuTexturePlayerPlayer.loadFromFile("images/Player_idle.png");
	menuTexturePlayerSoldier.loadFromFile("images/Soldier_idle.png");
	menuTexturePlayerZombie.loadFromFile("images/Zombie_idle.png");
	Sprite menuPlayerBoy(menuTexturePlayerBoy);
	Sprite menuPlayerGirl(menuTexturePlayerGirl);
	Sprite menuPlayerPlayer(menuTexturePlayerPlayer);
	Sprite menuPlayerSoldier(menuTexturePlayerSoldier);
	Sprite menuPlayerZombie(menuTexturePlayerZombie);
	bool isMenuPlayer = true;
	int menuNumPlayer;
	menuPlayerBoy.setTextureRect(IntRect(0, 0, 80, 110));
	menuPlayerGirl.setTextureRect(IntRect(0, 0, 80, 110));
	menuPlayerPlayer.setTextureRect(IntRect(0, 0, 80, 110));
	menuPlayerSoldier.setTextureRect(IntRect(0, 0, 80, 110));
	menuPlayerZombie.setTextureRect(IntRect(0, 0, 80, 110));
	menuPlayerBoy.setPosition(400, 10);
	menuPlayerGirl.setPosition(800, 10);
	menuPlayerPlayer.setPosition(300, 250);
	menuPlayerSoldier.setPosition(600, 250);
	menuPlayerZombie.setPosition(900, 250);


	int player;

	while (isMenuPlayer)
	{
		window.display();

		menuPlayerBoy.setColor(Color::White);
		menuPlayerGirl.setColor(Color::White);
		menuPlayerPlayer.setColor(Color::White);
		menuPlayerSoldier.setColor(Color::White);
		menuPlayerZombie.setColor(Color::White);
		window.clear(Color(129, 181, 221));

		
		if (IntRect(400, 10, 80, 110).contains(Mouse::getPosition(window)))
		{ 
			menuPlayerBoy.setColor(Color::Blue); 
			menuNumPlayer = 1;
		}
		if (IntRect(800, 10, 80, 110).contains(Mouse::getPosition(window))) 
		{ 
			menuPlayerGirl.setColor(Color::Blue); 
			menuNumPlayer = 2; 
		}
		if (IntRect(300, 250, 80, 110).contains(Mouse::getPosition(window)))
		{
			menuPlayerPlayer.setColor(Color::Blue);
			menuNumPlayer = 3;
		}
		if (IntRect(600, 250, 80, 110).contains(Mouse::getPosition(window)))
		{
			menuPlayerSoldier.setColor(Color::Blue);
			menuNumPlayer = 4;
		}
		if (IntRect(900, 250, 80, 110).contains(Mouse::getPosition(window)))
		{
			menuPlayerZombie.setColor(Color::Blue);
			menuNumPlayer = 5;
		}

		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNumPlayer == 1) {

				player = 1;
				isMenuPlayer = false;
				return player;
			}
			if (menuNumPlayer == 2) {
				player = 2;
				isMenuPlayer = false;

				return player;
			}
			if (menuNumPlayer == 2) {
				player = 2;
				isMenuPlayer = false;

				return player;
			}
			if (menuNumPlayer == 3) {
				player = 3;
				isMenuPlayer = false;
				return player;
			}
			if (menuNumPlayer == 4) {
				player = 4;
				isMenuPlayer = false;
				return player;
			}
			if (menuNumPlayer == 5) {
				player = 5;
				isMenuPlayer = false;
				return player;
			}

		}
		window.draw(menuPlayerBoy);
		window.draw(menuPlayerGirl);
		window.draw(menuPlayerPlayer);
		window.draw(menuPlayerSoldier);
		window.draw(menuPlayerZombie);
		//window.display();
	}

};
int menuEnemy(RenderWindow & window)
{
	Texture menuTextureEnemyCat, menuTextureEnemyRaccoon;
	menuTextureEnemyCat.loadFromFile("images/Cat(1).png");
	menuTextureEnemyRaccoon.loadFromFile("images/Raccoon.png");
	Sprite menuEnemyCat(menuTextureEnemyCat);
	Sprite menuEnemyRaccon(menuTextureEnemyRaccoon);
	bool isMenuEnemy = true;
	int menuNumEnemy = 0;
	menuEnemyCat.setTextureRect(IntRect(0, 0, 45, 45));
	menuEnemyRaccon.setTextureRect(IntRect(0, 0, 45, 45));
	menuEnemyCat.setPosition(10, 10);
	menuEnemyRaccon.setPosition(700, 10);
	menuEnemyCat.setScale(2, 2);
	menuEnemyRaccon.setScale(2, 2);
	menuTextureEnemyCat.setSmooth(true);
	menuTextureEnemyRaccoon.setSmooth(true);
	int enemy;
	while (isMenuEnemy)
	{
		window.display();
		menuEnemyCat.setColor(Color::White);
		menuEnemyRaccon.setColor(Color::White);
		window.clear(Color(129, 181, 221));
		if (IntRect(10, 10, 90, 90).contains(Mouse::getPosition(window)))
		{
			menuEnemyCat.setColor(Color::Red);
			menuNumEnemy = 1;
		}
		if (IntRect(700, 10, 90, 90).contains(Mouse::getPosition(window)))
		{
			menuEnemyRaccon.setColor(Color::Red);
			menuNumEnemy = 2;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNumEnemy == 1)
			{
				enemy = 1;
				isMenuEnemy = false;
				return enemy;
			}
			if (menuNumEnemy == 2)
			{
				enemy = 2;
				isMenuEnemy = false;
				return enemy;
			}
		}
		window.draw(menuEnemyCat);
		window.draw(menuEnemyRaccon);
	}
};