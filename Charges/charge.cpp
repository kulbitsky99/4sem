#include "charge.h"



void CreatePositiveCharge(sf::RenderWindow& window, std::vector<sf::CircleShape>& positive_charges, sf::Vector2i& mousePosition)
{
	sf::CircleShape circle(CHARGE);
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color(0, 0, 250));
	circle.setFillColor(sf::Color(200, 200, 200));
	circle.setPosition(mousePosition.x, mousePosition.y);
	positive_charges.push_back(circle);
}
void CreateNegativeCharge(sf::RenderWindow& window,  std::vector<sf::CircleShape>& negative_charges, sf::Vector2i& mousePosition)
{
	sf::CircleShape circle(CHARGE);
	circle.setOutlineThickness(10);
        circle.setOutlineColor(sf::Color(250, 0, 0));
        circle.setFillColor(sf::Color(200, 200, 200));
	circle.setPosition(mousePosition.x, mousePosition.y);
	negative_charges.push_back(circle);

}

void CalculateForwardField(sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& forward_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges, sf::Vector2f& field)
{
	float power;
	sf::Vector2f center;
	sf::Vector2f cfield;
	field.x = 0;
	field.y = 0;
	for(int i = 0; i < positive_charges.size(); i++)
	{
		center = positive_charges[i].getPosition();
		cfield.x = mousePosition.x - center.x;
		cfield.y = mousePosition.y - center.y;
		power = PROPORT_CONST / (cfield.x * cfield.x + cfield.y * cfield.y);
		field.x += power * (cfield.x / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));
		field.y += power * (cfield.y / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));

	}
	for(int i = 0; i < negative_charges.size(); i++)
	{
		center = positive_charges[i].getPosition();
                cfield.x = mousePosition.x - center.x;
                cfield.y = mousePosition.y - center.y;
                power = PROPORT_CONST / (cfield.x * cfield.x + cfield.y * cfield.y);
                field.x -= power * (cfield.x / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));
                field.y -= power * (cfield.y / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));

	}
	field.x = STEP * field.x / sqrt(field.x * field.x + field.y * field.y);
	field.y = STEP * field.y / sqrt(field.x * field.x + field.y * field.y);
	point.x += field.x;
	point.y += field.y;
	forward_points.push_back(point);

}

void CalculateBackField(sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& back_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges, sf::Vector2f& field)
{
	float power;
        sf::Vector2f center;
        sf::Vector2f cfield;
        field.x = 0;
        field.y = 0;
        for(int i = 0; i < positive_charges.size(); i++)
        {
                center = positive_charges[i].getPosition();
                cfield.x = mousePosition.x - center.x;
                cfield.y = mousePosition.y - center.y;
                power = PROPORT_CONST / (cfield.x * cfield.x + cfield.y * cfield.y);
                field.x += power * (cfield.x / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));
                field.y += power * (cfield.y / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));

        }
        for(int i = 0; i < negative_charges.size(); i++)
        {
                center = positive_charges[i].getPosition();
                cfield.x = mousePosition.x - center.x;
                cfield.y = mousePosition.y - center.y;
                power = PROPORT_CONST / (cfield.x * cfield.x + cfield.y * cfield.y);
                field.x -= power * (cfield.x / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));
                field.y -= power * (cfield.y / sqrt(cfield.x * cfield.x + cfield.y * cfield.y));

        }
        field.x = STEP * field.x / sqrt(field.x * field.x + field.y * field.y);
        field.y = STEP * field.y / sqrt(field.x * field.x + field.y * field.y);
        point.x -= field.x;
        point.y -= field.y;
        back_points.push_back(point);

}

void DrawForwardLine(sf::RenderWindow& window, sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& forward_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges)
{
	point.x = mousePosition.x;
        point.y = mousePosition.y;
	forward_points.push_back(point);
	sf::Vector2f field(0, 0);
	sf::Vector2f center(0, 0);
	bool flag = true;
	while(point.x >= 0 && point.x <= WIDTH && point.y >= 0 && point.y <= HEIGTH && flag == true)
	{
		CalculateForwardField(mousePosition, point, forward_points, positive_charges, negative_charges, field);
		for(int i = 0; i < positive_charges.size(); i++)
                {
			center = positive_charges[i].getPosition();
                	if(fabs(point.x - center.x) <= CHARGE && fabs(point.y - center.y) <= CHARGE)
                        {
                                flag = false;
                                break;
                        }
                }
                for(int i = 0; i < negative_charges.size(); i++)
                {
			center = negative_charges[i].getPosition();
                        if(fabs(point.x - center.x) <= CHARGE && fabs(point.y - center.y) <= CHARGE)
                        {
                                flag = false;
                                break;
                        }
                }
	}
}

void DrawBackLine(sf::RenderWindow& window, sf::Vector2i& mousePosition, sf::Vector2f& point, std::vector<sf::Vertex>& back_points, std::vector<sf::CircleShape>& positive_charges, std::vector<sf::CircleShape>& negative_charges)
{
	point.x = mousePosition.x;
        point.y = mousePosition.y;
	back_points.push_back(point);
	sf::Vector2f field(0, 0);
        sf::Vector2f center(0, 0);
	bool flag = true;
	while(point.x >= 0 && point.x <= WIDTH && point.y >= 0 && point.y <= HEIGTH && flag == true)
	{
                 CalculateBackField(mousePosition, point, back_points, positive_charges, negative_charges, field);
		 for(int i = 0; i < positive_charges.size(); i++)
		 {
			center = positive_charges[i].getPosition();
		 	if(fabs(point.x - center.x) <= CHARGE && fabs(point.y - center.y) <= CHARGE)
			{
				flag = false;
				break;
			}
		 }
		 for(int i = 0; i < negative_charges.size(); i++)
                 {
			center = negative_charges[i].getPosition(); 
                        if(fabs(point.x - center.x) <= CHARGE && fabs(point.y - center.y) <= CHARGE)
                        {
                                flag = false;
                                break;
                        }
                 }
	}
}	



