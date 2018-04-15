#include "ForestNode.h"


void ForestNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(entity->getSpriteInstance(), states);
}


void ForestNode::updateCurrent(sf::Time dt)
{
	float posx = entity->getSpriteInstance().getPosition().x;
	//float speedX = 800.0f;
	//posx += speedX*dt.asSeconds();

	//entity->getSpriteInstance().setPosition(posx, 400);

	if (entity->getName() == "Game_Cursor")
	{
		entity->getSpriteInstance().setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
	}
}


void ForestNode::attachEntity(IEntity* entity)
{
	this->entity = entity;
}

