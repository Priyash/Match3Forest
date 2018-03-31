#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include<string>
#include"EntityManager.h"
#include"GemNode.h"

using namespace std;

class IScene
{
public:
	IScene();
	~IScene();
	virtual void load() = 0;
	virtual void render(sf::RenderWindow& stage) = 0;
	virtual void update() = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual void unload() = 0;

	virtual string get_scene_name() = 0;
};

class Scene : public IScene
{
	string scene_name;

	EntityManager* entityManager;
	IEntity* gameObject1;
	SceneNode* rootNode;
	SceneNode* gemNode;
public:
	Scene(string scene_name);
	~Scene();
	void load();
	void render(sf::RenderWindow& stage);
	void update();
	void handleEvent(sf::Event& event);
	void unload();
	string get_scene_name();
};

#endif
