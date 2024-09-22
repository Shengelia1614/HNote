#include "music.h"

void music::Draw(RenderWindow& window)
{
	if (Wnotes.size() != 0)
		for (size_t i = 0; i < Wnotes.size(); i++)
		{
			window.draw(Wnotes[i].visual);
		};
	if (Bnotes.size() != 0)
		for (size_t i = 0; i < Bnotes.size(); i++)
		{
			window.draw(Bnotes[i].visual);
		};
}
		



void music::Play(Music Notes[])
{


	for (size_t i = 0; i < max(Wnotes.size(),Bnotes.size()); i++)
	{
		cout << max(Wnotes.size(), Bnotes.size())<<"this is the size" << endl;
		if (i < Wnotes.size()) {
			Wnotes[i].visual.move(0, 1);
			if (Wnotes[i].visual.getPosition().y == windowS_Y * 0.90) Notes[Wnotes[i].keyNumber].play();
		}

		if (i < Bnotes.size())
		Bnotes[i].visual.move(0, 1);

		//if (Wnotes[i].visual.getPosition().y + Wnotes[i].visual.getSize().y == windowS_Y * 0.90) Notes[Wnotes[i].keyNumber].stop();
	}
}
