#include <SFML/Graphics.hpp>
#include<Windows.h>
#include"EntityManager.h"
#include"GemNode.h"

#include "Game.h"

int main()
{


	Game* game = new Game();
	game->play();



	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	EntityManager* entityManager = new EntityManager();


	//LOGIC PART
	IEntity* gameObject1 = entityManager->CreateEntity("GameOBject1", "../../../../Assets/Sprites/Cupcake@2x.png");
	IEntity* gameObject2 = entityManager->CreateEntity("GameOBject2", "../../../../Assets/Sprites/Croissant-Highlighted@2x.png");
	
	
	//RENDERING PART
	SceneNode* rootNode = new SceneNode();

	SceneNode* gemNode = new GemNode();
	gemNode->attachObject(gameObject1);
	gemNode->setNodePosition(200, 10);

	SceneNode* gemNode2 = new GemNode();
	gemNode2->attachObject(gameObject2);
	gemNode2->setNodePosition(100, 10);

	gemNode->addChildNode(gemNode2);


	rootNode->addChildNode(gemNode);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(*rootNode);
		window.display();
	}

	return 0;
}