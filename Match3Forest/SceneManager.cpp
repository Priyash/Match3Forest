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
	ISceneFactory* sceneFactory = new SceneFactory();
	IScene* scene = sceneFactory->createScene(scene_name);
	return scene;
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

		sf::Event event;
		while (stage.pollEvent(event))
		{
			if (!handle_global_event(event)) {
				scene->handleEvent(event);
			}
		}
		
		//CLEAR THE SCREEN BEFORE RENDERING ANYTHING
		stage.clear();

		//LOAD THE SCENE DATA
		scene->load();

		//UPDATE THE RENDERING CURRENT SCREEN
		scene->update();

		//RENDER THE CURRENT SCENE
		scene->render(stage);

		//DISPLAY THE SCENE TO THE WINDOW
		stage.display();
	}


	//CLOSE THE RENDERING WINDOW
	stage.close();
}



bool SceneManager::handle_global_event(sf::Event& evt)
{
	switch (evt.type) {
		case sf::Event::Closed:
			m_end_play = true;
			return true;
		default:
			return false;
	}
}
