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
int Stream_index = 0;
int trigg = 1;
int trigg1 = 1;

void music::Play(String Notes[])
{
	

	for (size_t i = 0; i < max(Wnotes.size(),Bnotes.size()); i++)
	{
		//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y<<" in creator and the amount of notes: "<<Bnotes.size() << endl;
		//cout << max(Wnotes.size(), Bnotes.size())<<"this is the size" << endl;
		if (i < Wnotes.size()) {
			Wnotes[i].visual.move(0,1);

			if (Wnotes[i].visual.getPosition().y == windowS_Y * 0.90) { 
				//Wnotes[i].KeySound.openFromFile(Notes[Wnotes[i].keyNumber]);
				//Notes[Wnotes[i].keyNumber].play();
				Wnotes[i].KeySound = &S_Streams[Stream_index];

				S_Streams[Stream_index].openFromFile(Notes[Wnotes[i].keyNumber]);
				S_Streams[Stream_index].play();
				Stream_index++;
			}
			
			//k = 100;
			//Notes[Wnotes[i].keyNumber].setVolume(k);
			
		}
		//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y << endl;

		if (i < Bnotes.size()) {

			//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y << endl;

			Bnotes[i].visual.move(0,1);

			//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y << endl;


			if (Bnotes[i].visual.getPosition().y == windowS_Y * 0.90) {
				//Wnotes[i].KeySound.openFromFile(Notes[Wnotes[i].keyNumber]);
				//Notes[Wnotes[i].keyNumber].play();

				trigg1 = 0;
				Bnotes[i].KeySound = &S_Streams[Stream_index];

				cout << Bnotes[i].KeySound<<endl;
				S_Streams[Stream_index].openFromFile(Notes[Bnotes[i].keyNumber]);
				S_Streams[Stream_index].play();
				Stream_index++;
			}

			//k = 100;
			//Notes[Wnotes[i].keyNumber].setVolume(k);

		}

		
		

		if (i<Wnotes.size() && (Wnotes[i].visual.getPosition().y + Wnotes[i].visual.getSize().y) >= windowS_Y * 0.90) { 

			chrono::milliseconds ms = duration_cast<chrono::milliseconds>(
				system_clock::now().time_since_epoch()
			);

			if ((long)ms.count() % 1 == 0) {
				temp = Wnotes[i].volume;
				Wnotes[i].volume--;
			}

			//cout << Wnotes[i].visual.getPosition().y + Wnotes[i].visual.getSize().y << endl;

			Wnotes[i].KeySound->setVolume(Wnotes[i].volume);

			cout << temp << " - " << Wnotes[i].KeySound->getVolume() << "   volume" << endl;
			//cout << Wnotes[i].volume << "   k" << endl;
			//Notes[Wnotes[i].keyNumber].stop();


			if (Wnotes[i].volume <= 0) {
				Wnotes[i].KeySound->stop();
				Wnotes[i].KeySound->setVolume(100);
				Wnotes.erase(Wnotes.begin() + i);
				//Sound_Streams.erase(Sound_Streams.begin() + i);
			}
		}

		//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y << endl;

		if (i < Bnotes.size() && (Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y) >= windowS_Y * 0.90) {
			//trigg1 = 1;
		
			chrono::milliseconds ms = duration_cast<chrono::milliseconds>(
				system_clock::now().time_since_epoch()
			);

			if ((long)ms.count() % 1 == 0) {
				temp = Bnotes[i].volume;
				Bnotes[i].volume--;
			}

			

			Bnotes[i].KeySound->setVolume(Bnotes[i].volume);

			cout << temp << " - " << Bnotes[i].KeySound->getVolume() << "   volume" << endl;
			//cout << Wnotes[i].volume << "   k" << endl;
			//Notes[Wnotes[i].keyNumber].stop();


			if (Bnotes[i].volume <= 0) {
				Bnotes[i].KeySound->stop();
				Bnotes[i].KeySound->setVolume(100);
				Bnotes.erase(Bnotes.begin() + i);
				//Sound_Streams.erase(Sound_Streams.begin() + i);
			}
		}

		//cout << Bnotes[i].visual.getPosition().y + Bnotes[i].visual.getSize().y << endl;
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