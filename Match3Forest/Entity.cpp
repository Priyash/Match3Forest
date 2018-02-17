#include "Entity.h"



IEntity::IEntity()
{

}


IEntity::~IEntity()
{

}

//=========================================================SPRITE-ENTITY==============================================================

Entity::Entity(string entityName , string file)
{
	texture.loadFromFile(file);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	this->entityName = entityName;
}

Entity::~Entity()
{

}


sf::Sprite Entity::getInstance()
{
	return sprite;
}

