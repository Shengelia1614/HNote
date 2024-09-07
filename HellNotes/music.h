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
//Music Notes[88];

struct note {
	float playtime=0;
	int keyNumber;
    float startPos;
    float startTime=0;
    RectangleShape visual;


};

class music
{
	vector<note> Wnotes;
    int Counter = 0;
    bool ReleaseTrigger = 0;
    note tempNote;

public:





    void Whitenoteplacer(RenderWindow& window, RectangleShape shape, View view) {

        for (size_t i = 0; i < 52; i++)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f MouseViewPosition = window.mapPixelToCoords(mousePosition, view);
            //if (mousePosition.x > (i * ((window.getSize().x - ToolBoxWidth*((float)window.getSize().x/(windowS_X+ ToolBoxWidth))) / 51.99999)) && mousePosition.x < ((i + 1) * ((window.getSize().x - ToolBoxWidth * ((float)window.getSize().x / (windowS_X + ToolBoxWidth))) / 51.99999))) {
            if (MouseViewPosition.x > (i * ((windowS_X) / 51.99999)) && MouseViewPosition.x < ((i + 1) * (windowS_X / 51.99999))) {

                //cout << ((float)window.getSize().x)/ windowS_X << endl;

                // Convert the mouse position to world coordinates (view coordinates)
               

                
                shape.setPosition(Vector2f(i * (windowS_X / 51.99999), MouseViewPosition.y));
                //cout << Mouse::getPosition(window).x << endl;

                
                
                
                if (Mouse::isButtonPressed(Mouse::Left)) {

                    
                    

                    
                    if (Counter == 0) {
                        tempNote.visual.setSize((Vector2f((windowS_X / 52),0)));
                        tempNote.startPos=MouseViewPosition.y;
                        tempNote.visual.setPosition(i * (windowS_X / 51.99999), MouseViewPosition.y);
                        tempNote.visual.setFillColor(Color::Green);
                        tempNote.keyNumber = i;
                        //cout << "created" << endl;
                    }
                    
                    tempNote.visual.setSize((Vector2f(windowS_X / 52,  MouseViewPosition.y - tempNote.startPos)));
                    window.draw(tempNote.visual);
                    //cout << "draw" << endl;
                    ReleaseTrigger = 1;
                    +
                    Counter++;
                }else
                if (ReleaseTrigger == 1) {
                    //cout << "added" << endl;
                    Wnotes.push_back(tempNote);
                    ReleaseTrigger = 0;
                    Counter =0;
                    
                }
                window.draw(shape);
            }
        }

    }


    void Draw(RenderWindow&);
    
    void Play(Music Notes[]);





};

