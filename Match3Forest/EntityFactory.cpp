#include "EntityFactory.h"


IEntityFactory::IEntityFactory()
{

}

IEntityFactory::~IEntityFactory()
{

}

//=================================================ENTITY_FACTORY======================================================================

EntityFactory::EntityFactory()
{
	
}


EntityFactory::~EntityFactory()
{
	delete entity;
}

IEntity* EntityFactory::CreateEntity(string entityName, string file)
{
	entity = new Entity(entityName,file);
	return entity;

}
