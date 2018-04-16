#ifndef GEMNODE_H
#define GEMNODE_H

#include"SceneNode.h"




class AbstractForestNode : public SceneNode
{

public:
	AbstractForestNode() {}
	~AbstractForestNode() {}

	virtual void setNodePosition(float x, float y) {}
	virtual sf::Vector2f getNodePosition() { sf::Vector2f tmp; return tmp; }
	virtual void setNodeScale(float x, float y) {}
	virtual sf::Vector2f getNodeScale() { sf::Vector2f tmp; return tmp; }
	virtual void setNodeOrigin(float x, float y){}
	virtual sf::Vector2f getNodeOrigin() { sf::Vector2f tmp; return tmp; }

	virtual void attachEntity(IEntity*) = 0;
};


class ForestNode : public AbstractForestNode
{
	IEntity* entity;
public:

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void updateCurrent(sf::Time dt);

	void setNodePosition(float x, float y);
	sf::Vector2f getNodePosition();

	void setNodeScale(float x, float y);
	sf::Vector2f getNodeScale();

	void setNodeOrigin(float x, float y);
	sf::Vector2f getNodeOrigin();
	void attachEntity(IEntity*);
};

#endif