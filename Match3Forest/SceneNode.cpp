#include "SceneNode.h"



SceneNode::SceneNode()
{

}


SceneNode::~SceneNode()
{
	
	parent = nullptr;
	children.clear();
}

//====================================SCENENODE-RELATED-METHODS==============================================================
void SceneNode::addChildNode(SceneNode* childNode)
{
	childNode->parent = this;
	children.push_back(std::move(childNode));
}

void SceneNode::removeChildNode(SceneNode& childNode)
{
	auto found = find_if(children.begin(), children.end(), [&](SceneNode* node)->bool {return node == &childNode; });
	if (found != children.end())
	{
		(*found)->parent = nullptr;
		children.erase(remove_if(children.begin(), children.end(), [&](SceneNode* n2)->bool {return *found == n2; }), children.end());
	}
}


SceneNode* SceneNode::findNode(SceneNode& node)
{
	auto itr = find_if(children.begin(), children.end(), [&](SceneNode* node2)->bool {return &node == node2; });
	if (itr != children.end())
	{
		//unique_ptr<SceneNode>temp = std::move(*itr);
		return *itr;
	}

	return nullptr;
}

SceneNode* SceneNode::getNodeParent()
{
	return parent;
}

vector<SceneNode*>SceneNode::getNodeChildren()
{
	return children;
}

//====================================ENTITY-RELATED-METHODS=================================================================


//====================================UPDATE-RELATED-METHODS=================================================================

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
	//EMPTY BASE CLASS METHOD
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (auto& i : children)
	{
		i->update(dt);
	}
}


//=================================================DRAW-RELATED-METHODS==========================================

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	drawChildren(target, states);
}


void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	//EMPTY BASE CLASS METHOD

}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states)const
{
	for (auto& i : children)
	{
		i->draw(target,states);
	}
}