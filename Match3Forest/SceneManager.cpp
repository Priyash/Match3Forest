#include "SceneManager.h"

const sf::Time timePerFrame = sf::seconds(1 / 30.0f);

bool m_end_play = false;

//=============================================LISTENER_CLASS=========================================================================


KeyBoardListener::KeyBoardListener()
{

}

KeyBoardListener::~KeyBoardListener()
{

}

void KeyBoardListener::onNotify(sf::Event& evt)
{
	string s = "Keyboard Event recieved";

	if (evt.key.code == sf::Keyboard::Escape)
	{
		m_end_play = true;
	}
	
	return;
}


//===================================================================================================================================
//======================================================MANAGER_CLASS==========================================================
//===================================================================================================================================

SceneManager::SceneManager()
{
	m_end_play = false;
	EventManager::getInstance()->subscribe_listener(EVENT::KEYBOARD_PRESSED, new KeyBoardListener());
}


SceneManager::~SceneManager()
{
	EventManager::getInstance()->unsubscribe_listener(EVENT::KEYBOARD_PRESSED);
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

	stage.setMouseCursorVisible(false);

	//GET THE SCENE FROM THE LIST OF SCENES
	IScene* scene = scene_list.begin()->second;

	//CLEAR THE SCREEN BEFORE RENDERING ANYTHING
	stage.clear();

	//LOAD THE SCENE DATA[ONE_TIME]
	scene->load();

	//MAIN GAME LOOP
	while (!m_end_play)
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			if (m_end_play == true)break;
			
			sf::Event event;
			while (stage.pollEvent(event))
			{
				if (!handle_global_event(event,stage)) {
					scene->handleEvent(event);
				}
			}

			//UPDATE THE RENDERING CURRENT SCREEN
			scene->update(timePerFrame);

			//RENDER THE CURRENT SCENE
			scene->render(stage);

			//DISPLAY THE SCENE TO THE WINDOW
			stage.display();

			//TODO : SCENE SWITCH METHOD WILL BE CALLED LATER ON 

		}

	}


	//CLOSE THE RENDERING WINDOW
	if (stage.isOpen())
	{
		stage.close();
	}
}


bool SceneManager::handle_global_event(sf::Event& evt, sf::RenderWindow& stage)
{
	switch (evt.type) {
		case sf::Event::Closed:
			m_end_play = true;
			return true;
		case sf::Event::KeyPressed:
			EventManager::getInstance()->notifyListener(EVENT::KEYBOARD_PRESSED, evt);
			return true;
		default:
			return false;
	}
}
