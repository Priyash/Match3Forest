#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
#include"Entity.h"



class IEntityFactory
{
public:
	IEntityFactory();
	~IEntityFactory();
};



class EntityFactory : public IEntityFactory
{
public:
	EntityFactory();
	~EntityFactory();
};

#endif