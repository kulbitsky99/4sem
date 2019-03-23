#include "project.h"

Molecula :: Molecula():
	coord_         (0, 0),
	velocity_      (0, 0),
//	impulse_       (0, 0),
	size_             (0)
{}

Molecula :: Molecula(int size):
	coord_        (0, 0),
	velocity_     (0, 0),
//	impulse_      (0 ,0),
	size_         (size)
{}

sf::Vector2f Molecula :: GetImpulse(sf::Vector2f & result)
{	
	result.x = velocity_.x * size_;
	result.y = velocity_.y * size_;
	return result;
}
