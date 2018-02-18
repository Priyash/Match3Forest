#ifndef ENTITY_H
#define ENTITY_H
#include<string>
#include<SFML\Graphics.hpp>

using namespace std;

class IEntity
{

public:
	IEntity();
	~IEntity();

	virtual sf::Sprite getInstance() = 0;
	virtual string getName() = 0;
	virtual void setName(string name) = 0;

	virtual void setEntityPosition(float x, float y) = 0;
	virtual sf::Vector2f getEntityPosition() = 0;
	virtual void setEntityRotation(float angle) = 0;
	virtual float getEntityRotation() = 0;
	virtual void setEntityScale(float x, float y) = 0;
	virtual sf::Vector2f getEntityScale() = 0;

};


class Entity : public IEntity
{
	sf::Sprite sprite;
	sf::Texture texture;
	string entityName;
	float posx, posy;
	float angle;
	float scalex, scaley;
public:
	Entity(string entityName, string file);
	~Entity();
	sf::Sprite getInstance();
	string getName();
	void setName(string name);

	void setEntityPosition(float x, float y);
	void setEntityRotation(float angle);
	void setEntityScale(float x, float y);

	sf::Vector2f getEntityPosition();
	float getEntityRotation();
	sf::Vector2f getEntityScale();
};



#endif

