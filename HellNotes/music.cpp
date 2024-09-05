#include "music.h"

void music::Draw(RenderWindow& window)
{
	for (size_t i = 0; i < Wnotes.size(); i++)
	{
		window.draw(Wnotes[i].visual);
	}
}

void music::NoteMovement()
{
	for (size_t i = 0; i < Wnotes.size(); i++)
	{
		Wnotes[i].visual.move(0, 1);
	}
}

void music::Play()
{
	NoteMovement();

}
