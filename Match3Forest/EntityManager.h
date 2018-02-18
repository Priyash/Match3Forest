#ifndef ENTITYMANAGER
#define ENTITYMANAGER
#include"EntityFactory.h"
#include<map>


class EntityManager
{
	IEntityFactory* entityFactory;
	map<string,IEntity*>entity_list;
public:
	EntityManager();
	~EntityManager();

	IEntity* CreateEntity(string entityName, string file);
	IEntity* find(string entityName);
	void update_entity(string entity_id, IEntity* update_entity);
	void RemoveEntity(string entityName);
	void add(string,IEntity*);
};


#endif

