#ifndef ENTITY_H
#define ENTITY_H
#include<string>


using namespace std;

class IEntity
{

public:
	IEntity();
	~IEntity();
};


class Entity : public IEntity
{

public:
	Entity();
	~Entity();
};



#endif

