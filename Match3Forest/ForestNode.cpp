#include "ForestNode.h"


void ForestNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(entity->getSpriteInstance(), states);
}


void ForestNode::setNodePosition(float x, float y)
{
	entity->getSpriteInstance().setPosition(x, y);

}

sf::Vector2f ForestNode::getNodePosition()
{
	return entity->getSpriteInstance().getPosition();
}

void ForestNode::setNodeScale(float x, float y)
{
	entity->getSpriteInstance().setScale(x, y);
}

sf::Vector2f ForestNode::getNodeScale()
{
	return entity->getSpriteInstance().getScale();
}


void ForestNode::setNodeOrigin(float x, float y)
{
	entity->getSpriteInstance().setOrigin(x, y);
}
sf::Vector2f ForestNode::getNodeOrigin()
{
	return entity->getSpriteInstance().getOrigin();
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

