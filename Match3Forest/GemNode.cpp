#include "GemNode.h"



GemNode::GemNode()
{

}


GemNode::~GemNode()
{

}


void GemNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	for (auto& i : entities)
	{
		states.transform.translate(posx,posy);
		target.draw(i.second->getInstance(), states);
	}
}

void GemNode::updateCurrent(sf::Time dt)
{

}
