#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include"SceneFactory.h"
#include"EventListener.h"
#include <functional>

class SceneManager
{
	map<string, IScene*>scene_list;
	//IEventListener* listener;
	bool m_end_play;
public:
	SceneManager();
	~SceneManager();
	IScene* CreateScene(string scene_name);
	void addScene(IScene*);
	IScene* get_Scene(string scene_name);
	void removeScene(string scene_name);
	void play(sf::RenderWindow& stage);
	bool handle_global_event(sf::Event& evt);
};



#endif

