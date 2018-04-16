#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include<string>
#include"EntityManager.h"
#include"ForestNode.h"

using namespace std;

class IScene
{
public:
	IScene();
	~IScene();
	virtual void load() = 0;
	virtual void render(sf::RenderWindow& stage) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual void unload() = 0;

	virtual string get_scene_name() = 0;
};

class Scene : public IScene
{
	string scene_name;

	EntityManager* entityManager;
	SceneNode* rootNode;
	
	//FOR BACKGROUND SCENE
	IEntity* backgroundEntity;
	AbstractForestNode* backgroundNode;
	

	//SPRITE_CURSOR
	IEntity* cursorEntity;
	AbstractForestNode* cursorNode;


	//GAME_BOARD
	IEntity* gameBoardEntity;
	AbstractForestNode* gameBoardNode;

	//GAME_HEADER
	IEntity* gameScoreHeaderEntity;
	AbstractForestNode* gameScoreHeaderNode;

public:
	Scene(string scene_name);
	~Scene();
	void load();
	void render(sf::RenderWindow& stage);
	void update(sf::Time dt);
	void handleEvent(sf::Event& event);
	void unload();
	string get_scene_name();
};

#endif
