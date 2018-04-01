#include "SceneManager.h"

const sf::Time timePerFrame = sf::seconds(1 / 60.0f);

SceneManager::SceneManager()
{
	m_end_play = false;
	//listener = new KeyBoardListener();
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
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (!m_end_play)
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			if (m_end_play == true)break;
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
			scene->update(timePerFrame);

			//RENDER THE CURRENT SCENE
			scene->render(stage);

			//DISPLAY THE SCENE TO THE WINDOW
			stage.display();
		}

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
		case sf::Event::KeyPressed:
		{
			if (evt.key.code == sf::Keyboard::Escape)
			{
				m_end_play = true;
			}
			//function<void(sf::Event& event,bool result)>callback_listener = listener->updateListener;
			//callback_listener(evt,m_end_play);
			return true;
		}
		default:
			return false;
	}
}
