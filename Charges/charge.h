#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

enum SIZE
{
	WIDTH = 1920,
	HEIGTH = 1080,
	CHARGE = 10,
	PROPORT_CONST = 1000000, 
	STEP = 10	
};



void CreatePositiveCharge(sf::RenderWindow& window, std::vector<sf::CircleShape>& positive_charges, sf::Vector2i& mousePosition);
void CreateNegativeCharge(sf::RenderWindow& window, std::vector<sf::CircleShape>& negative_charges, sf::Vector2i& mousePosition);
void CalculateForwardField(sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& forward_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges, sf::Vector2f& field);
void CalculateBackField(sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& back_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges, sf::Vector2f& field);
void DrawForwardLine(sf::RenderWindow& window, sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& forward_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges);
void DrawBackLine(sf::RenderWindow& window, sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& back_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges);


