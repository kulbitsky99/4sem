#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

enum SIZE
{
        WIDTH = 1920,
        HEIGHT = 1080,
        SIZE_SMALL = 30,
        SIZE_MIDDLE = 40,
        SIZE_LARGE = 50
};


class Molecula
{
	public:
		Molecula();
		Molecula(int size);
		sf::Vector2f coord_;
		sf::Vector2f velocity_;
//		sf::Vector2f impulse_;
		sf::Vector2f GetImpulse(sf::Vector2f & result);
		float size_;

};
