#include <SFML/Graphics.hpp>
#include<Windows.h>
#include"EntityManager.h"
#include"GemNode.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	EntityManager* entityManager = new EntityManager();

	IEntity* gameObject1 = entityManager->CreateEntity("GameOBject1", "../../../../Assets/Sprites/Cupcake@2x.png");
	IEntity* gameObject2 = entityManager->CreateEntity("GameOBject2", "../../../../Assets/Sprites/Croissant-Highlighted@2x.png");
	
	SceneNode* rootNode = new SceneNode();


	GemNode* gem = new GemNode();
	gem->attachObject(gameObject1);
	gem->setNodePosition(500, 100);
	unique_ptr<GemNode>gemNode(gem);

	rootNode->addChildNode(move(gemNode));

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