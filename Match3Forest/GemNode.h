#ifndef GEMNODE_H
#define GEMNODE_H

#include"SceneNode.h"




class GemNode : public SceneNode
{

public:
	GemNode();
	~GemNode();

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void updateCurrent();
};

#endif