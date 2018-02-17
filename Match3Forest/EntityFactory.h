#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include"Entity.h"



class IEntityFactory
{
public:
	IEntityFactory();
	~IEntityFactory();

	//METHOD FOR CREATION OF ENTITY
	virtual IEntity* CreateEntity(string entityName, string file) = 0;
};



class EntityFactory : public IEntityFactory
{
	IEntity* entity;
public:
	EntityFactory();
	~EntityFactory();

	//METHOD WHICH WILL CREATE ENTITY OBJECTS
	IEntity* CreateEntity(string entityName, string file);
};

#endif