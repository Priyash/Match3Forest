#include "EntityManager.h"



EntityManager::EntityManager()
{

}


EntityManager::~EntityManager()
{

}


IEntity* EntityManager::CreateEntity(string entityName, string file)
{
	entityFactory = new EntityFactory();
	IEntity* entity_obj = entityFactory->CreateEntity(entityName,file);
	add(entityName,entity_obj);
	return entity_obj;
}


void EntityManager::add(string entity_ID,IEntity* entity)
{
	if (entity != nullptr)
	{
		entity_list.insert(pair<string,IEntity*>(entity_ID,entity));
	}
	else
	{
		return;
	}
}


IEntity* EntityManager::find(string entity_id)
{	
	IEntity* found_entity;
	auto search_itr = entity_list.find(entity_id);
	if (search_itr != entity_list.end())
	{
		found_entity = search_itr->second;
	}
	else
	{
		found_entity = nullptr;
	}

	return found_entity;
}

void EntityManager::RemoveEntity(string entity_id)
{
	auto del_itr = entity_list.find(entity_id);
	if (del_itr != entity_list.end())
	{
		entity_list.erase(del_itr);
	}
	else
	{
		return;
	}
}


void EntityManager::update_entity(string entity_id,IEntity* update_entity)
{
	auto update_itr = entity_list.find(entity_id);
	if (update_itr != entity_list.end())
	{
		update_itr->second = update_entity;
		int k = 0;
	}
	else
	{
		return;
	}
}
