#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace sf;


void finish(RenderWindow & window, int point)
{
	Texture TextureExit;
	TextureExit.loadFromFile("images/Exit.png");
	Sprite Exit(TextureExit);
	Exit.setPosition(450, 300);

	SoundBuffer winbuffer;
	winbuffer.loadFromFile("sound/you_win.ogg");
	Sound soundwin;
	soundwin.setBuffer(winbuffer);

	SoundBuffer losebuffer;
	losebuffer.loadFromFile("sound/you_lose.ogg");
	Sound soundlose;
	soundlose.setBuffer(losebuffer);

	if (point == 1)
		soundwin.play();
	else
		soundlose.play();

	

	bool isFinish = 1;
	int finishNum;
	while (isFinish)
	{
		

		window.clear(Color(129, 181, 221));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		};
		Exit.setColor(Color::White);
		finishNum = 0;

		if (IntRect(450, 300, 300, 50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Blue); finishNum = 1; }
		if (Mouse::isButtonPressed(Mouse::Left))
			if (finishNum == 1) { window.close(); isFinish = false; }
	

		window.draw(Exit);
		window.display();
	}
};
