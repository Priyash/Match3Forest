#include "ForestNode.h"


void ForestNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(entity->getSpriteInstance(), states);
}


void ForestNode::updateCurrent(sf::Time dt)
{
	float posx = entity->getSpriteInstance().getPosition().x;
	float speedX = 800.0f;
	posx += speedX*dt.asSeconds();

	entity->getSpriteInstance().setPosition(posx, 400);
}


void ForestNode::attachEntity(IEntity* entity)
{
	this->entity = entity;
}

