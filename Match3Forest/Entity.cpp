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
	posx = 0.0f;
	posy = 0.0f;
	angle = 0.0f;
	scalex = 0.0f;
	scalex = 0.0f;

}

Entity::~Entity()
{

}


sf::Sprite Entity::getInstance()
{
	return sprite;
}

string Entity::getName()
{
	return entityName;
}


void Entity::setName(string name)
{
	this->entityName = name;
}


void Entity::setEntityPosition(float x, float y)
{
	this->posx = x;
	this->posy = y;

	sprite.setPosition(posx, posy);
}

void Entity::setEntityRotation(float angle)
{
	this->angle = angle;
	sprite.setRotation(angle);
}

void Entity::setEntityScale(float x, float y)
{
	this->scalex = x;
	this->scaley = y;
	sprite.setScale(scalex, scaley);
}


sf::Vector2f Entity::getEntityPosition()
{
	return sf::Vector2f(posx, posy);
}

float Entity::getEntityRotation()
{

	return angle;
}
sf::Vector2f Entity::getEntityScale()
{
	return sf::Vector2f(scalex, scaley);
}


