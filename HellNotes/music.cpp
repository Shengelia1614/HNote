#include "music.h"
using namespace std::chrono;
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
		

int temp;

void music::Play(Music Notes[])
{


	for (size_t i = 0; i < max(Wnotes.size(),Bnotes.size()); i++)
	{
		//cout << max(Wnotes.size(), Bnotes.size())<<"this is the size" << endl;
		if (i < Wnotes.size()) {
			Wnotes[i].visual.move(0, 1);

			if (Wnotes[i].visual.getPosition().y == windowS_Y * 0.90) { 
				
				Notes[Wnotes[i].keyNumber].play(); 
			
			}
			
			//k = 100;
			//Notes[Wnotes[i].keyNumber].setVolume(k);
			
		}

		if (i < Bnotes.size())
		Bnotes[i].visual.move(0, 1);

		
		

		if (Wnotes[i].visual.getPosition().y + Wnotes[i].visual.getSize().y >= windowS_Y * 0.90) { 
			chrono::milliseconds ms = duration_cast<chrono::milliseconds>(
				system_clock::now().time_since_epoch()
			);

			if ((long)ms.count() % 1 == 0) {
				temp = Wnotes[i].volume;
				Wnotes[i].volume--;
			}
			Notes[Wnotes[i].keyNumber].setVolume(Wnotes[i].volume);

			cout << temp << " - " << Notes[Wnotes[i].keyNumber].getVolume() << "   volume" << endl;
			//cout << Wnotes[i].volume << "   k" << endl;
			//Notes[Wnotes[i].keyNumber].stop();


			if (Wnotes[i].volume <= 0) {
				Notes[Wnotes[i].keyNumber].stop();
				Notes[Wnotes[i].keyNumber].setVolume(100);
				Wnotes.erase(Wnotes.begin() + i);
			}
		}

		//Fade(Notes, i);
		


	}

	

}

//void music::Fade(Music Notes[], int i) {
//
//	while (k >0) {
//
//		if (clock.getElapsedTime().asMilliseconds() % 2 == 0) {
//			k--;
//			Notes[Wnotes[i].keyNumber].setVolume(k);
//		}
//		cout << Notes[Wnotes[i].keyNumber].getVolume() << "   volume" << endl;
//		cout << k << "   k" << endl;
//		//Notes[Wnotes[i].keyNumber].stop();
//		
//
//	}
//	Notes[Wnotes[i].keyNumber].stop();
//	k = 100;
//	Notes[Wnotes[i].keyNumber].setVolume(k);
//}