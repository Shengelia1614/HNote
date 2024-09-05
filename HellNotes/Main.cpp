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

void scroll(RenderWindow & window, View& view, Event event) {
    
    if (event.type == sf::Event::MouseWheelMoved)
    {
        cout << view.getCenter().y << endl;
        if (event.mouseWheel.delta == 1 && view.getCenter().y <=530) {
            view.move(Vector2f(0, 30));
        } //else
        if(event.mouseWheel.delta == -1)  view.move(Vector2f(0, -30)); // uisng else statement here isntead of if causes sort of jitter effect where it snaps out and in where its limit is supposed to be
        //so two if statements are neccessary here isntead of single if else
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1900+ToolBoxWidth, 1080), "SFML works!");
    sf::View view(sf::FloatRect(0, 0, windowS_X+ ToolBoxWidth, windowS_Y));

    //RenderWindow tool(sf::VideoMode(100, 1080), "SFML works!");

    window.setView(view);

    //RectangleShape WhitePlacer(Vector2f(window.getSize().x / 51.99999, 100));
    RectangleShape WhitePlacer(Vector2f(windowS_X / 52, -10));
    

    WhitePlacer.setFillColor(sf::Color::Green);

    RectangleShape WhiteKeys[52];
    RectangleShape BlackKeys[36];
    
    music Music;

    for (size_t i = 0; i < 52; i++)
    {
        //WhiteKeys[i].setSize(Vector2f(window.getSize().x / 51.99999, window.getSize().y / 10));
        //WhiteKeys[i].setPosition(Vector2f(i* (window.getSize().x / 51.99999), (float)window.getSize().y*0.90));

        WhiteKeys[i].setSize(Vector2f(windowS_X /51.9999, windowS_Y / 10));
        WhiteKeys[i].setPosition(Vector2f(i * (windowS_X / 51.9999), windowS_Y * 0.90));

        if (i % 2 == 1) WhiteKeys[i].setFillColor(Color::White);
        else WhiteKeys[i].setFillColor(Color(200,200,200));
    }
    int ind = 1;
    for (size_t i = 0; i < 36; i++)
    {
        BlackKeys[i].setSize(Vector2f(windowS_X / 77.99999, windowS_Y / 17));
        BlackKeys[i].setFillColor(Color(20, 20, 20));
    }
    BlackKeys[0].setPosition(Vector2f(windowS_X / 51.99999 - BlackKeys[0].getSize().x / 2, windowS_Y * 0.90));
    while (ind<36)
    {
        
        BlackKeys[ind].setPosition(Vector2f(BlackKeys[ind-1].getPosition().x+WhiteKeys[0].getSize().x*2, (float)window.getSize().y * 0.90));

        BlackKeys[ind+1].setPosition(Vector2f(BlackKeys[ind].getPosition().x + WhiteKeys[0].getSize().x, (float)window.getSize().y * 0.90));

        BlackKeys[ind+2].setPosition(Vector2f(BlackKeys[ind + 1].getPosition().x + WhiteKeys[0].getSize().x*2, (float)window.getSize().y * 0.90));

        BlackKeys[ind+3].setPosition(Vector2f(BlackKeys[ind + 2].getPosition().x + WhiteKeys[0].getSize().x, (float)window.getSize().y * 0.90));

        BlackKeys[ind+4].setPosition(Vector2f(BlackKeys[ind + 3].getPosition().x + WhiteKeys[0].getSize().x, (float)window.getSize().y * 0.90));

        ind += 5;
    }
    


    //window.getSize().y - shape.getSize().y
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            scroll(window, view, event);

        }
        //shape.setSize(Vector2f(window.getSize().x / 53, window.getSize().y/20));
        //shape.setPosition(Vector2f(0.f,(float) window.getSize().y - shape.getSize().y));
        //shape.setPosition(Vector2f(0.f, (float)1080- shape.getSize().y));
        //cout << window.getSize().y<<"           " << window.getSize().y - shape.getSize().y << endl;
        window.setView(view);

        window.clear();
        Music.Draw(window);

        Music.Whitenoteplacer(window, WhitePlacer, view);
        for (size_t i = 0; i < 52; i++)
        {
            window.draw(WhiteKeys[i]);
        }
        for (size_t i = 0; i < 36; i++)
        {
            window.draw(BlackKeys[i]);
        }
        
        
        //window.draw(shape1);
        window.display();
    }

    return 0;
}