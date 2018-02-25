#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include<string>

using namespace std;

class IScene
{
public:
	IScene();
	~IScene();
	virtual void load() = 0;
	virtual void render(sf::RenderWindow& stage) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void unload() = 0;

	virtual string get_scene_name() = 0;
};

class Scene : public IScene
{
	string scene_name;
public:
	Scene(string scene_name);
	~Scene();
	void load();
	void render(sf::RenderWindow& stage);
	void update(sf::Time dt);
	void unload();
	string get_scene_name();
};

#endif
