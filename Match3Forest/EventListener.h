#pragma once
#include <SFML\Graphics.hpp>

using namespace std;

class IEventListener
{

public:
	IEventListener();
	~IEventListener();
	
	virtual void updateListener(sf::Event& event, bool result) = 0;
};


class KeyBoardListener : public IEventListener
{

public:
	KeyBoardListener();
	~KeyBoardListener();
	void updateListener(sf::Event& event, bool result) override;

};


