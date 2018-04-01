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

	virtual string getName() = 0;
	virtual void setName(string name) = 0;
	virtual sf::Sprite& getSpriteInstance() = 0;
};


class Entity : public IEntity
{
	string entityName;
	sf::Sprite sprite;
	sf::Texture spriteTexture;
public:
	Entity(string entityName, string file);
	~Entity();
	string getName();
	void setName(string name);

	sf::Sprite& getSpriteInstance();
};



#endif

