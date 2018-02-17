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
};


class Entity : public IEntity
{
	sf::Sprite sprite;
	sf::Texture texture;
	string entityName;
public:
	Entity(string entityName, string file);
	~Entity();
	sf::Sprite getInstance();
};



#endif

