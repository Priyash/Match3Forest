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

}

void Scene::render(sf::RenderWindow& stage)
{

}

void Scene::update(sf::Time dt)
{

}

void Scene::unload()
{

}
