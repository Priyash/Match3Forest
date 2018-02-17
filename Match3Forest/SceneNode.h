#ifndef SCENENODE_H
#define SCENENODE_h
#include<SFML\Graphics.hpp>
#include<vector>
#include<string>
#include<memory>
#include"Entity.h"
#include <SFML\System\Vector2.hpp>

using namespace std;

class SceneNode : public sf::Drawable, sf::Transformable, sf::NonCopyable
{

protected:
	vector<unique_ptr<SceneNode>>children;
	SceneNode* parent;
	map<int, IEntity*>entities;
	int object_index;
	float posx, posy;
	float angle;
	float scalex, scaley;
public:
	SceneNode();
	~SceneNode();

	//UPDATE METHOD FOR UPDATING THE GAME OBJECTS
	void update(sf::Time dt);

	//ATTACH METHODS FOR ATTACHING OR DETTACHING THE ENTITY OBJECTS
	void attachObject(IEntity*);
	void dettachObject(int id);

	//SET POSITION OF THE NODE
	void setNodePosition(float x, float y);
	void setNodeRotation(float angle);
	void setNodeScale(float x, float y);
	void move(float x, float y);

	sf::Vector2<float> getNodePos();
	float getNodeRotation();
	sf::Vector2<float> getNodeScale();

	//METHODS FOR ADDING OR SEARCHING OR REMOVING A NODE FROM A SCENENODE
	void addChildNode(unique_ptr<SceneNode>);
	void removeChildNode(SceneNode&);
	SceneNode* findNode(SceneNode&);

	

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void updateCurrent(sf::Time dt);

	void draw(sf::RenderTarget& target, sf::RenderStates states)const;

	void updateChildren(sf::Time dt);
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states)const;
	

private:


};


#endif

