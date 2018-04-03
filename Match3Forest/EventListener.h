#pragma once
#include <SFML\Graphics.hpp>
#include<map>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;



enum EVENT
{
	KEYBOARD_PRESSED = 1
};


class IListener
{

public:
	IListener() {}
	~IListener() {}
	
	virtual void onNotify(sf::Event& evt) = 0;
};

//=========================================================ABSTRACT_FACTORY_CLASSES============================================
class AbstractListenerFactory
{

public:
	AbstractListenerFactory() {}
	~AbstractListenerFactory() {}

	virtual void registerListener(int event_id, IListener*) = 0;
	virtual void unregister_listener(int event_id) = 0;
	virtual void notifyListener(int event_id, sf::Event& evt) = 0;
	virtual void notifyAll(sf::Event& evt) = 0;
};

class ListenerFactory : public AbstractListenerFactory
{
	
	map<int, IListener*>listener_objects;
public:
	ListenerFactory();
	~ListenerFactory();

	void registerListener(int event_id, IListener*);
	void unregister_listener(int event_id);
	void notifyListener(int event_id, sf::Event& evt);
	void notifyAll(sf::Event& evt);

private:
	map<int, IListener*>::iterator findListener(int event_id);
};







//=======================================================EVENT_MANAGER_CLASSES===================================================
class EventManager
{
	AbstractListenerFactory* listenerFactory;

	static EventManager* eventManager;
	
private:
	EventManager();
public:
	~EventManager();
	static EventManager* getInstance();
	void subscribe_listener(int event_id, IListener*);
	void unsubscribe_listener(int event_id);
	void notifyListener(int event_id, sf::Event& evt);
	void notifyAll(sf::Event& evt);

};


