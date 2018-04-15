#include "Scene.h"



IScene::IScene()
{

}


IScene::~IScene()
{

}

//=================================================SCENE_CLASS_STARTED====================================================

Scene::Scene(string scene_name)
{
	this->scene_name = scene_name;

	entityManager = new EntityManager();
	rootNode = new SceneNode();

	backgroundNode = new ForestNode();
	appleNode = new ForestNode();
	cursorNode = new ForestNode();

}


Scene::~Scene()
{

}

string Scene::get_scene_name()
{
	return scene_name;
}


void Scene::load()
{
	backgroundEntity = entityManager->CreateEntity("GameOBject1", "../../../../Assets/BG/bg.jpg");
	backgroundNode->attachEntity(backgroundEntity);

	appleEntity = entityManager->CreateEntity("GameOBject2", "../../../../Assets/Sprites/Forest/slice05_05 (2).png");
	appleNode->attachEntity(appleEntity);
	appleNode->setNodePosition(400, 100);

	cursorEntity = entityManager->CreateEntity("Game_Cursor", "../../../../Assets/Sprites/forest_cursor - Copy.png");
	cursorNode->attachEntity(cursorEntity);
	

	rootNode->addChildNode(backgroundNode);
	rootNode->addChildNode(cursorNode);
	//rootNode->addChildNode(appleNode);

}

void Scene::render(sf::RenderWindow& stage)
{
	//stage.setMouseCursorVisible(false);
	stage.draw(*rootNode);
}

void Scene::update(sf::Time dt)
{
	rootNode->update(dt);
}


void Scene::handleEvent(sf::Event& event)
{

}

void Scene::unload()
{

}
