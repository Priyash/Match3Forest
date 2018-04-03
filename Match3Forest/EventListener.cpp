#include"EventListener.h"

EventManager* EventManager::eventManager = nullptr;


//==================================================================ABSTRACT_CLASSES===============================================

ListenerFactory::ListenerFactory()
{

}
ListenerFactory::~ListenerFactory()
{

}


map<int, IListener*>::iterator ListenerFactory::findListener(int event_id)
{
	map<int, IListener*>::iterator iterator;
	if (event_id != -1 && event_id > 0)
	{
		for (map<int , IListener*>::iterator itr = listener_objects.begin(); itr != listener_objects.end(); ++itr)
		{
			int tmp_event_id = itr->first;
			if (tmp_event_id = event_id)
			{
				iterator = itr;
			}
		}

	}


	return iterator;
}


void ListenerFactory::registerListener(int event_id, IListener* listener)
{
	//TODO : Boundary case - search the event if that event exist dont add
	if (listener != nullptr && event_id != -1 && event_id > 0)
	{
		listener_objects.insert(pair<int, IListener*>(event_id, listener));
	}
}

void ListenerFactory::unregister_listener(int event_id)
{
	if (event_id != -1 && event_id > 0 )
	{
		auto listener_itr = findListener(event_id);
		if (listener_itr != listener_objects.end())
		{
			listener_objects.erase(listener_itr);
		}
	}
}

void ListenerFactory::notifyListener(int event_id, sf::Event& evt)
{
	if (event_id != -1 && event_id > 0 )
	{
		auto listener_itr = findListener(event_id);
		if (listener_itr != listener_objects.end())
		{
			listener_itr->second->onNotify(evt);
		}
	}
}

void ListenerFactory::notifyAll(sf::Event& evt)
{
	for (map<int, IListener*>::iterator itr = listener_objects.begin(); itr != listener_objects.end(); ++itr)
	{
		IListener* listener = itr->second;
		listener->onNotify(evt);
	}
}


//====================================================EVENT_MANAGER========================================================


EventManager* EventManager::getInstance()
{
	if (eventManager == nullptr)
	{
		eventManager = new EventManager();
	}

	return eventManager;
}


EventManager::EventManager()
{
	listenerFactory = new ListenerFactory();
}

EventManager::~EventManager()
{

}


void EventManager::subscribe_listener(int event_id, IListener* listener)
{
	listenerFactory->registerListener(event_id, listener);
}

void EventManager::unsubscribe_listener(int event_id)
{
	listenerFactory->unregister_listener(event_id);
}

void EventManager::notifyListener(int event_id, sf::Event& evt)
{
	listenerFactory->notifyListener(event_id, evt);
}

void EventManager::notifyAll(sf::Event& evt)
{
	listenerFactory->notifyAll(evt);
}
