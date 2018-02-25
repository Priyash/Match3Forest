#include "SceneManager.h"



SceneManager::SceneManager()
{
	m_end_play = false;
}


SceneManager::~SceneManager()
{

}

IScene* SceneManager::CreateScene(string scene_name)
{
	return sceneFactory->createScene(scene_name);
}

void SceneManager::addScene(IScene* scene)
{
	if (scene != nullptr)
	{
		scene_list.insert(pair<string, IScene*>(scene->get_scene_name(), scene));
	}
}

IScene* SceneManager::get_Scene(string scene_name)
{
	auto scene_itr = scene_list.find(scene_name);
	IScene* found_scene = nullptr;
	if (scene_itr != scene_list.end())
	{
		found_scene = scene_itr->second;
	}

	return found_scene;
}

void SceneManager::removeScene(string scene_name)
{
	auto del_itr = scene_list.find(scene_name);
	if (del_itr != scene_list.end())
	{
		scene_list.erase(del_itr);
	}
	else
	{
		return;
	}
}


void SceneManager::play(sf::RenderWindow& stage)
{
	while (!m_end_play)
	{
		IScene* scene = scene_list.begin()->second;

		//PENDING WILL DO THE SCENE LOAD , UNLOAD , UPDATE , RENDER METHOD WITH MAIN GAME LOOP WITH TIME
	}
}
