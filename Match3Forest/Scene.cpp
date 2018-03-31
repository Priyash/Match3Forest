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
	gemNode = new GemNode();

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
	gameObject1 = entityManager->CreateEntity("GameOBject1", "../../../../Assets/Sprites/Forest/start bg.png");
	gemNode->attachObject(gameObject1);
	rootNode->addChildNode(gemNode);
}

void Scene::render(sf::RenderWindow& stage)
{
	stage.draw(*rootNode);
}

void Scene::update()
{

}


void Scene::handleEvent(sf::Event& event)
{

}

void Scene::unload()
{

}
