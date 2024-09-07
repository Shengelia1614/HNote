#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include "music.h";

using namespace std;
using namespace sf;
#define windowS_X 1900
#define windowS_Y 1080
#define ToolBoxWidth 150

class toolbox
{
	RectangleShape playbutton;
	bool ReleaseTrigger = 0;
	
public:
	bool playCheck = 0;
	
	toolbox() {
		playbutton.setSize(Vector2f(120,40));
		
		playbutton.setPosition(Vector2f(windowS_X+15, windowS_Y-60));
		
		playbutton.setFillColor(Color::Green);
		

	}

	void Display(RenderWindow& window) {
		
		window.draw(playbutton);
		
	}

	void update(RenderWindow& window, View view) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f MouseViewPosition = window.mapPixelToCoords(mousePosition, view);
		//cout << MouseViewPosition.x << endl;
		
		if (Mouse::isButtonPressed(Mouse::Left) && MouseViewPosition.x > playbutton.getPosition().x && MouseViewPosition.x < (playbutton.getPosition().x + 120) && MouseViewPosition.y>playbutton.getPosition().y && MouseViewPosition.y < (playbutton.getPosition().y + 40)) {
			ReleaseTrigger = 1;
		}else
		if (ReleaseTrigger == 1 && MouseViewPosition.x > playbutton.getPosition().x && MouseViewPosition.x < (playbutton.getPosition().x + 120) && MouseViewPosition.y>playbutton.getPosition().y && MouseViewPosition.y < (playbutton.getPosition().y + 40)) {
			if (playCheck == 0)playCheck = 1;
			else playCheck = 0;
			cout << "button clicked" << endl;
			ReleaseTrigger = 0;
		}
	}

};

