#include "Game.h"



Game::Game()
{
	renderer  = new sf::RenderWindow(sf::VideoMode(640, 480), "Forest Game");
	sceneManager = new SceneManager();
}


Game::~Game()
{
	delete renderer;
	delete sceneManager;
}

void Game::play()
{
	IScene* first_scene = sceneManager->CreateScene("First_Scene");
	sceneManager->addScene(first_scene);
	sceneManager->play(*renderer);
}
