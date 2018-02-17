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
	void RemoveEntity(string entityName);
private:
	void add(string,IEntity*);
};


#endif

