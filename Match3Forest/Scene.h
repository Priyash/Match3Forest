#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include<string>
#include"EntityManager.h"
#include"ForestNode.h"
#include<random>

using namespace std;

enum FRUIT_TYPE
{
	EMPTY = 0,
	STRAWBERRY = 1,
	COCONUT = 2,
	APPLE = 3,
	CLOVER = 4,
	MUSHROOM = 5,
	BERRY = 6,
	GRAPE = 7,
	BLOCKED = 8
};



class IScene
{
public:
	IScene();
	~IScene();
	virtual void load() = 0;
	virtual void render(sf::RenderWindow& stage) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void handleEvent(sf::RenderWindow& window,sf::Event& event) = 0;
	virtual void unload() = 0;

	virtual string get_scene_name() = 0;
};

class Scene : public IScene
{
	string scene_name;

	int BOARD_WIDTH;
	int BOARD_HEIGHT;

	vector<vector<int>>grid;

	EntityManager* entityManager;
	SceneNode* rootNode;
	
	//FOR BACKGROUND SCENE
	IEntity* backgroundEntity;
	AbstractForestNode* backgroundNode;
	

	//SPRITE_CURSOR
	IEntity* cursorEntity;
	AbstractForestNode* cursorNode;


	//GAME_BOARD
	IEntity* gameBoardEntity;
	AbstractForestNode* gameBoardNode;

	//GAME_TOP_PANEL
	IEntity* gameScoreHeaderEntity;
	AbstractForestNode* gameScoreHeaderNode;

	//GAME_BOTTOM_PANEL_BOMB_POWER_UP_CONTAINER
	//GAME_BOTTOM_PANEL_BOMB_POWER_UP_ENTITY
	IEntity* powerUpContainerEntity;
	AbstractForestNode* powerUpContainerNode;
	
	IEntity* bombPowerUpEntity;
	AbstractForestNode* bombPowerUpNode;

	//ARROWS
	IEntity* powerUpArrowContainerEntity;
	AbstractForestNode* powerUpArrowContainerNode;

	IEntity* arrowsPowerUpEntity;
	AbstractForestNode* arrowsPowerUpNode;

	//RAINBOW	
	IEntity* powerUpRainbowContainerEntity;
	AbstractForestNode* powerUpRainbowContainerNode;

	IEntity* rainbowPowerUpEntity;
	AbstractForestNode* rainbowPowerUpNode;

	//SHOP
	IEntity* shopEntity;
	AbstractForestNode* shopNode;

	//ACTIVE_BLOCK
	IEntity* activeBlockEntity;
	AbstractForestNode* activeBlockNode;
	
	//FRUIT_PLACEMENT OFFSET VARIABLES
	int xOffset;
	int yOffset;

	vector<AbstractForestNode*>containerList;
	vector<AbstractForestNode*>fruitList;

public:
	Scene(string scene_name);
	~Scene();
	void load();
	void render(sf::RenderWindow& stage);
	void update(sf::Time dt);
	void handleEvent(sf::RenderWindow& window,sf::Event& event);
	void unload();
	string get_scene_name();

private:
	void buildMatrix();
	bool checkHorizontal(int i, int j);
	bool checkVertical(int i, int j);
	vector<AbstractForestNode*> populateFruits(vector<AbstractForestNode*>);
	vector<AbstractForestNode*> buildContainerCell(AbstractForestNode* gameBoardNode);
	AbstractForestNode* createCoconut(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createStrawberry(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createApple(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createClover(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createMushroom(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createBerry(AbstractForestNode* boardNode, int i, int j);
	AbstractForestNode* createGrape(AbstractForestNode* boardNode, int i, int j);

	AbstractForestNode* getFruitList(AbstractForestNode* boardNode, int i, int j, int fruitIndex);

	int getIndex(int i, int j);
};

#endif
