#include "SceneNode.h"



SceneNode::SceneNode()
{
	object_index = 0;
}


SceneNode::~SceneNode()
{
	entities.clear();
	parent = nullptr;
	children.clear();
	object_index = 0;
}

//====================================SCENENODE-RELATED-METHODS==============================================================
void SceneNode::addChildNode(unique_ptr<SceneNode>childNode)
{
	childNode->parent = this;
	children.push_back(std::move(childNode));
}

void SceneNode::removeChildNode(SceneNode& childNode)
{
	auto found = find_if(children.begin(), children.end(), [&](unique_ptr<SceneNode>&node)->bool {return node.get() == &childNode; });
	if (found != children.end())
	{
		(*found)->parent = nullptr;
		children.erase(remove_if(children.begin(), children.end(), [&](unique_ptr<SceneNode>&n2)->bool {return (*found).get() == n2.get(); }), children.end());
	}
}


SceneNode* SceneNode::findNode(SceneNode& node)
{
	auto itr = find_if(children.begin(), children.end(), [&](unique_ptr<SceneNode>& node2)->bool {return &node == node2.get(); });
	if (itr != children.end())
	{
		//unique_ptr<SceneNode>temp = std::move(*itr);
		return itr->get();
	}

	return nullptr;
}



//====================================ENTITY-RELATED-METHODS=================================================================

void SceneNode::attachObject(IEntity* entity)
{
	entities[object_index] = entity;
	object_index = object_index + 1;
}

void SceneNode::dettachObject(int id)
{
	auto object_found_itr = entities.find(id);
	if (object_found_itr != entities.end())
	{
		entities.erase(object_found_itr);
	}
	else
	{
		return;
	}
}

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

void SceneNode::setNodePosition(float x, float y)
{
	this->posx = x;
	this->posy = y;
}

sf::Vector2f SceneNode::getNodePosition()
{
	return sf::Vector2f(posx, posy);
}
//=================================================DRAW-RELATED-METHODS==========================================

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	auto trans = getTransform();
	states.transform *= trans;
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