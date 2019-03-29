#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstdio>
#include <cstdlib>


#define DISCR 44100
#define FREQ1 240
#define FREQ2 340
#define FREQ3 440

int main()
{
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "MUSIC!!!");
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	sf::SoundBuffer buffer3;

	sf::Sound sound1;
	sf::Sound sound2;
	sf::Sound sound3;

	std::vector<sf::Int16> samples1;
	std::vector<sf::Int16> samples2;
	std::vector<sf::Int16> samples3;

	sf::Int16 x = 0; 
	sf::Int16 y = 0;
        for(int i = 0; i < DISCR; i++)
        {
                if(i % 2 == 0)
                {
                        x = (sf::Int16)(sin(2 * 3.1415926 * FREQ1 * (float)i / DISCR) * 32767);
                        samples1.push_back(x);
                }
                if(i % 2 == 1)
                {
                        y = (sf::Int16)(sin(2 * 3.1415926 * FREQ1 * (float)i / DISCR) * 32767);
                        samples1.push_back(y);
                }
        }
	buffer1.loadFromSamples(&samples1[0], samples1.size(), 2, DISCR);
        sound1.setBuffer(buffer1);

	for(int i = 0; i < DISCR; i++)
        {
                if(i % 2 == 0)
                {
                        x = (sf::Int16)(sin(2 * 3.1415926 * FREQ2 * (float)i / DISCR) * 32767);
                        samples2.push_back(x);
                }
                if(i % 2 == 1)
                {
                        y = (sf::Int16)(sin(2 * 3.1415926 * FREQ2 * (float)i / DISCR) * 32767);
                        samples2.push_back(y);
                }
        }
        buffer2.loadFromSamples(&samples2[0], samples2.size(), 2, DISCR);
        sound2.setBuffer(buffer2);

	for(int i = 0; i < DISCR; i++)
        {
                if(i % 2 == 0)
                {
                        x = (sf::Int16)(sin(2 * 3.1415926 * FREQ3 * (float)i / DISCR) * 32767);
                        samples3.push_back(x);
                }
                if(i % 2 == 1)
                {
                        y = (sf::Int16)(sin(2 * 3.1415926 * FREQ3 * (float)i / DISCR) * 32767);
                        samples3.push_back(y);
                }
        }
        buffer3.loadFromSamples(&samples3[0], samples3.size(), 2, DISCR);
        sound3.setBuffer(buffer3);

   
	while(window.isOpen())	
	{
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					sound1.play();	
				}
				if(event.mouseButton.button == sf::Mouse::Middle)
                                {
					sound2.play();
                                }
				if(event.mouseButton.button == sf::Mouse::Right)
                                {
					sound3.play();
                                }
				break;
			}
		}
	}
	return 0;

}
