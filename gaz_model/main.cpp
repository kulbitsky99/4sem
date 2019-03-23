#include "project.h"

int main()
{
	std::vector<Molecula> molecula;
	int rand_param = 0;
	sf::Event event;
	sf::Vector2i mousePosition;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "GAZ MODEL!");
	while(window.isOpen())
	{
		window.clear(sf::Color::Black);
		for(int i = 0; i < molecula.size(); i++)
		{
			sf::CircleShape pict(molecula[i].size_);
			if(molecula[i].size_ == SIZE_SMALL)
			{
				pict.setFillColor(sf::Color(250, 0, 0));
				pict.setPosition(molecula[i].coord_.x, molecula[i].coord_.y);
				if(molecula[i].coord_.x <= SIZE_SMALL || molecula[i].coord_.x >= WIDTH - SIZE_SMALL)
					molecula[i].velocity_.x = - molecula[i].velocity_.x;
				if(molecula[i].coord_.y <= SIZE_SMALL || molecula[i].coord_.y >= HEIGHT - SIZE_SMALL)
                                        molecula[i].velocity_.y = - molecula[i].velocity_.y;

			}
			if(molecula[i].size_ == SIZE_MIDDLE)
                        {
                                pict.setFillColor(sf::Color(0, 250, 0));
                                pict.setPosition(molecula[i].coord_.x, molecula[i].coord_.y);
				if(molecula[i].coord_.x <= SIZE_SMALL || molecula[i].coord_.x >= WIDTH - SIZE_MIDDLE)
                                        molecula[i].velocity_.x = - molecula[i].velocity_.x;
                                if(molecula[i].coord_.y <= SIZE_SMALL || molecula[i].coord_.y >= HEIGHT - SIZE_MIDDLE)
                                        molecula[i].velocity_.y = - molecula[i].velocity_.y;

                        }
			if(molecula[i].size_ == SIZE_LARGE)
                        {
                                pict.setFillColor(sf::Color(0, 0, 250));
				pict.setPosition(molecula[i].coord_.x, molecula[i].coord_.y);
				if(molecula[i].coord_.x <= SIZE_SMALL || molecula[i].coord_.x >= WIDTH - SIZE_LARGE)
                                        molecula[i].velocity_.x = - molecula[i].velocity_.x;
                                if(molecula[i].coord_.y <= SIZE_SMALL || molecula[i].coord_.y >= HEIGHT - SIZE_LARGE)
                                        molecula[i].velocity_.y = - molecula[i].velocity_.y;

                        }
			for(int j = 0; j < molecula.size(); j++)
			{
				if(i != j)
				{
					sf::Vector2f d;
					d.x = molecula[j].coord_.x - molecula[i].coord_.x;
					d.y = molecula[j].coord_.y - molecula[i].coord_.y;
					if((sqrt(d.x * d.x + d.y * d.y) <= molecula[i].size_ + molecula[j].size_) && ((molecula[j].velocity_.x - molecula[i].velocity_.x) * d.x + (molecula[j].velocity_.y - molecula[i].velocity_.y) * d.y <= 0))
					{
						sf::Vector2f d_imp;
						d_imp.x = 1.5 * (molecula[j].size_ * molecula[i].size_ / (molecula[j].size_ + molecula[i].size_)) * ((molecula[j].velocity_.x - molecula[i].velocity_.x) * d.x) / (sqrt(d.x * d.x + d.y * d.y));
						d_imp.y = 1.5 * (molecula[j].size_ * molecula[i].size_ / (molecula[j].size_ + molecula[i].size_)) * ((molecula[j].velocity_.y - molecula[i].velocity_.y) * d.y) / (sqrt(d.x * d.x + d.y * d.y));
						molecula[j].velocity_.x += d_imp.x / molecula[j].size_;
						molecula[j].velocity_.y += d_imp.y / molecula[j].size_;
						molecula[i].velocity_.x -= d_imp.x / molecula[i].size_;
						molecula[i].velocity_.y -= d_imp.y / molecula[i].size_;
					}
				}
			}

			molecula[i].coord_.x += molecula[i].velocity_.x;
			molecula[i].coord_.y += molecula[i].velocity_.y;
			window.draw(pict);
		}
		window.display();
		while(window.pollEvent(event))
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
						rand_param = 1 + rand() % 3;
						switch(rand_param)
						{
							case 1:
								{
									static Molecula element(SIZE_SMALL);
                                                                        element.coord_.x = mousePosition.x - SIZE_SMALL;
                                                                        element.coord_.y = mousePosition.y - SIZE_SMALL;
									if(rand() % 2 == 0)
                                                                        {
                                                                                element.velocity_.x = rand() % 5 + 1;
                                                                        }
                                                                        if(rand() % 2 == 1)
                                                                        {
                                                                                element.velocity_.x = (rand() % 5 + 1) * (-1);
                                                                        }

                                                                        if(rand() % 2 == 0)
                                                                        {
                                                                                element.velocity_.y = rand() % 5 + 1;
                                                                        }
                                                                        if(rand() % 2 == 1)
                                                                        {
                                                                                element.velocity_.y = (rand() % 5 + 1) * (-1);
                                                                        }

                                                                        molecula.push_back(element);
                                                                        break;

								}
							case 2:
                                                                {
                                                                        static Molecula element(SIZE_MIDDLE);
									element.coord_.x = mousePosition.x - SIZE_MIDDLE;
								        element.coord_.y = mousePosition.y - SIZE_MIDDLE;
									if(rand() % 2 == 0)
									{
										element.velocity_.x = rand() % 5 + 1;
									}
									if(rand() % 2 == 1)
									{
										element.velocity_.x = (rand() % 5 + 1) * (-1);
									}

									if(rand() % 2 == 0)
                                                                        {
                                                                                element.velocity_.y = rand() % 5 + 1;
                                                                        }
                                                                        if(rand() % 2 == 1)
                                                                        {
                                                                                element.velocity_.y = (rand() % 5 + 1) * (-1);
                                                                        }

									molecula.push_back(element);
									break;
                                                                }
							case 3:
                                                                {
									static Molecula element(SIZE_LARGE);
                                                                        element.coord_.x = mousePosition.x - SIZE_LARGE;
                                                                        element.coord_.y = mousePosition.y - SIZE_LARGE;
									if(rand() % 2 == 0)
                                                                        {
                                                                                element.velocity_.x = rand() % 5 + 1;
                                                                        }
                                                                        if(rand() % 2 == 1)
                                                                        {
                                                                                element.velocity_.x = (rand() % 5 + 1) * (-1);
                                                                        }

                                                                        if(rand() % 2 == 0)
                                                                        {
                                                                                element.velocity_.y = rand() % 5 + 1;
                                                                        }
                                                                        if(rand() % 2 == 1)
                                                                        {
                                                                                element.velocity_.y = (rand() % 5 + 1) * (-1);
                                                                        }

                                                                        molecula.push_back(element);
                                                                        break;

                                                                }
						}


					}
					break;
				}
			}
		}
	}
	return 0;
}



