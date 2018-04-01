#include "Game.h"



Game::Game()
{
	renderer  = new sf::RenderWindow(sf::VideoMode(980,680), "Forest Game" , sf::Style::None);
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
