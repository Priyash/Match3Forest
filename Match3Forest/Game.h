#ifndef GAME_H
#define GAME_H
#include"SceneManager.h"

class Game
{
	sf::RenderWindow* renderer;
	SceneManager* sceneManager;
public:
	Game();
	~Game();
	void play();
};


#endif

