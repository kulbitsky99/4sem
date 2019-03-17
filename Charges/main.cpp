#include "charge.h"


sf::RenderWindow window(sf::VideoMode(1920, 1080), "CHARGES!");
sf::CircleShape circle(CHARGE);
std::vector<sf::CircleShape> positive_charges;
std::vector<sf::CircleShape> negative_charges;
std::vector<sf::Vertex> forward_points;
std::vector<sf::Vertex> back_points;



int main()
{
	sf::Event event;
	sf::Vector2i mousePosition;
	sf::Vector2f point;
	while(window.isOpen())
	{
		window.clear(sf::Color::Black);
		for(int i = 0; i < positive_charges.size(); i++)
	        {
			window.draw(positive_charges[i]);
        	}
		for(int i = 0; i < negative_charges.size(); i++)
		{
			window.draw(negative_charges[i]);
        	}
		for(int i = 1; i < forward_points.size(); i++)
                {
                        sf::Vertex line[] =
                        {
                                sf::Vertex(forward_points[i - 1]),
                                sf::Vertex(forward_points[i])
                        };
                        window.draw(line, 2, sf::Lines);
                        window.display();
                }
		for(int i = 1; i < back_points.size(); i++)
       		{
                	//sf::Vector2f coord = back_points[i - 1].position;
                	//std::cout << coord.x << " " << coord.y << std::endl;
                	sf::Vertex line[] =
               		{
                      		sf::Vertex(back_points[i - 1]),
                        	sf::Vertex(back_points[i])
               		};
                	window.draw(line, 2, sf::Lines);
                	window.display();
        	}


		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				case sf::Event::MouseButtonPressed:
				{
					if(event.mouseButton.button == sf::Mouse::Left)
					{
				 		mousePosition = sf::Mouse::getPosition(window);
						CreatePositiveCharge(window, positive_charges, mousePosition);
					}
					if(event.mouseButton.button == sf::Mouse::Right)
                                        {
						mousePosition = sf::Mouse::getPosition(window);
                                                CreateNegativeCharge(window, negative_charges, mousePosition);
                                        }
					if(event.mouseButton.button == sf::Mouse::Middle)
					{
						mousePosition = sf::Mouse::getPosition(window);
						DrawForwardLine(window, mousePosition, point, forward_points, positive_charges, negative_charges);
						DrawBackLine(window, mousePosition, point, back_points, positive_charges, negative_charges);
					}
				}
			}
		}
		window.display();
	}
	return 0;
}


