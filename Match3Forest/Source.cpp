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


	//LOGIC PART
	IEntity* gameObject1 = entityManager->CreateEntity("GameOBject1", "../../../../Assets/Sprites/Cupcake@2x.png");
	IEntity* gameObject2 = entityManager->CreateEntity("GameOBject2", "../../../../Assets/Sprites/Croissant-Highlighted@2x.png");
	
	//gameObject1->setPosition(100, 300);


	//RENDERING PART
	SceneNode* rootNode = new SceneNode();

	GemNode* gem = new GemNode();
	gem->setNodePosition(300, 100);
	gem->attachObject(gameObject1);

	GemNode* gem2 = new GemNode();
	gem2->setNodePosition(300, 30);
	gem2->attachObject(gameObject2);


	unique_ptr<GemNode>gemNode(gem);
	unique_ptr<GemNode>gemNode2(gem2);

	rootNode->addChildNode(move(gemNode));
	rootNode->addChildNode(move(gemNode2));

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