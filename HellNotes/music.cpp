#include "music.h"

void music::Draw(RenderWindow& window)
{
	for (size_t i = 0; i < Wnotes.size(); i++)
	{
		window.draw(Wnotes[i].visual);
	}
}



void music::Play(Music Notes[])
{


	for (size_t i = 0; i < Wnotes.size(); i++)
	{
		Wnotes[i].visual.move(0, 1);
		if (Wnotes[i].visual.getPosition().y  == windowS_Y * 0.90) Notes[Wnotes[i].keyNumber].play();
		//if (Wnotes[i].visual.getPosition().y + Wnotes[i].visual.getSize().y == windowS_Y * 0.90) Notes[Wnotes[i].keyNumber].stop();
	}
}
