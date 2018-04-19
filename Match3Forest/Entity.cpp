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
	spriteTexture.loadFromFile(file);	
	sprite.setTexture(spriteTexture);
	spriteTexture.setSmooth(true);
	this->entityName = entityName;

}

Entity::~Entity()
{

}


string Entity::getName()
{
	return entityName;
}


void Entity::setName(string name)
{
	this->entityName = name;
}

sf::Sprite& Entity::getSpriteInstance()
{
	return sprite;
}