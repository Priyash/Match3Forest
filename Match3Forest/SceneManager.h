#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include"SceneFactory.h"
#include"EventListener.h"
#include <functional>
#include"EventListener.h"

//==========================================================CUSTOM_USER_DEFINED_LISTENER_CLASSES===========================================
class KeyBoardListener : public IListener
{

public:
	KeyBoardListener();
	~KeyBoardListener();
	void onNotify(sf::Event& evt) override;

};


//===============================================================SCENE_MANAGER_CLASS============================================
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

