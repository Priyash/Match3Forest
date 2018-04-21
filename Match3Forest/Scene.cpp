#include "Scene.h"



IScene::IScene()
{
	
}


IScene::~IScene()
{

}

//=================================================SCENE_CLASS_STARTED====================================================

Scene::Scene(string scene_name)
{
	this->scene_name = scene_name;

	BOARD_WIDTH = 5;
	BOARD_HEIGHT = 6;

	xOffset = 10;
	yOffset = 5;

	grid = vector<vector<int>>(BOARD_HEIGHT, vector<int>(BOARD_WIDTH));


	entityManager = new EntityManager();
	rootNode = new SceneNode();

	backgroundNode = new ForestNode();
	cursorNode = new ForestNode();
	gameBoardNode = new ForestNode();
	gameScoreHeaderNode = new ForestNode();

	
	powerUpContainerNode = new ForestNode();
	bombPowerUpNode = new ForestNode();

	powerUpArrowContainerNode = new ForestNode();
	arrowsPowerUpNode = new ForestNode();

	powerUpRainbowContainerNode = new ForestNode();
	rainbowPowerUpNode = new ForestNode();

	shopNode = new ForestNode();

	activeBlockNode = new ForestNode();
}


Scene::~Scene()
{

}

string Scene::get_scene_name()
{
	return scene_name;
}


void Scene::buildMatrix()
{
	random_device rd;
	mt19937 gen(rd());
	int lo = 1;
	int hi = 7;
	uniform_int_distribution<>dis(lo, hi);
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			do
			{
				grid[i][j] = dis(gen);
			} while (checkHorizontal(i, j) || checkVertical(i, j));
		}
	}
}

bool Scene::checkHorizontal(int i, int j)
{
	if (j >= 2 && grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2])
	{
		return true;
	}

	return false;
}
bool Scene::checkVertical(int i, int j)
{
	if (i >= 2 && grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j])
	{
		return true;
	}

	return false;
}

AbstractForestNode* Scene::createCoconut(AbstractForestNode* containerNode, int i , int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Coconut", "../../../../Assets/Sprites/Forest/slice01_01 (3).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset , containerNode->getNodePosition().y + yOffset + 5);
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}

AbstractForestNode* Scene::createApple(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Apple", "../../../../Assets/Sprites/Forest/slice05_05 (2).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset, containerNode->getNodePosition().y + yOffset);
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}

AbstractForestNode* Scene::createBerry(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Berry", "../../../../Assets/Sprites/Forest/slice03_03 (3).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset, containerNode->getNodePosition().y + yOffset);
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}

AbstractForestNode* Scene::createClover(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Clover", "../../../../Assets/Sprites/Forest/slice06_06 (2).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset, containerNode->getNodePosition().y + yOffset);
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}


AbstractForestNode* Scene::createGrape(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Grape", "../../../../Assets/Sprites/Forest/slice04_04 (3).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset, containerNode->getNodePosition().y + yOffset );
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}


AbstractForestNode* Scene::createMushroom(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Mushroom", "../../../../Assets/Sprites/Forest/slice02_02 (3).png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset - 5, containerNode->getNodePosition().y + yOffset);
	fruitNode->setNodeScale(0.4, 0.4);

	return fruitNode;
}

AbstractForestNode* Scene::createStrawberry(AbstractForestNode* containerNode, int i, int j)
{
	IEntity* fruitEntity = entityManager->CreateEntity("Fruit_Strawberry_" + to_string(i) + "_" + to_string(j), "../../../../Assets/Sprites/Forest/strawberry.png");
	AbstractForestNode* fruitNode = new ForestNode();
	fruitNode->attachEntity(fruitEntity);
	fruitNode->setNodePosition(containerNode->getNodePosition().x + xOffset, containerNode->getNodePosition().y);
	fruitNode->setNodeScale(0.4, 0.4);
	return fruitNode;
}


AbstractForestNode* Scene::getFruitList(AbstractForestNode* containerNode,int i ,int j , int fruitIndex)
{
	AbstractForestNode* fruitNode;
	switch (fruitIndex)
	{
		case FRUIT_TYPE::COCONUT:
			fruitNode = createCoconut(containerNode, i, j);
			break;
		case FRUIT_TYPE::APPLE:
			fruitNode = createApple(containerNode, i, j);
			break;
		case FRUIT_TYPE::BERRY:
			fruitNode = createBerry(containerNode, i, j);
			break;
		case FRUIT_TYPE::CLOVER:
			fruitNode = createClover(containerNode, i, j);
			break;
		case FRUIT_TYPE::GRAPE:
			fruitNode = createGrape(containerNode, i, j);
			break;
		case FRUIT_TYPE::MUSHROOM:
			fruitNode = createMushroom(containerNode, i, j);
			break;
		case FRUIT_TYPE::STRAWBERRY:
			fruitNode = createStrawberry(containerNode, i, j);
			break;
	}


	return fruitNode;
}

int Scene::getIndex(int i, int j)
{
	int index = (i*BOARD_WIDTH) + j;
	return index;
}

vector<AbstractForestNode*> Scene::populateFruits(vector<AbstractForestNode*>containerList)
{
	vector<AbstractForestNode*>fruitList;
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			int containerListIndex = getIndex(i, j);
			AbstractForestNode* containerNode = containerList[containerListIndex];

			fruitList.push_back(getFruitList(containerNode, i, j, grid[i][j]));

		}
	}

	return fruitList;
}


vector<AbstractForestNode*> Scene::buildContainerCell(AbstractForestNode* boardNode)
{
	int xOffset = 74;
	int yOffset = 76;
	vector<AbstractForestNode*>containerList;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			IEntity* containerEntity = entityManager->CreateEntity("container_" + to_string(i), "../../../../Assets/Sprites/Forest/block for game item.png");
			AbstractForestNode* containerNode = new ForestNode();
			containerNode->attachEntity(containerEntity);
			containerNode->setNodePosition(boardNode->getNodePosition().x + 15 + j * 74, boardNode->getNodePosition().y + 15 + i*76);
			containerNode->setNodeScale(0.4, 0.4);
			containerList.push_back(containerNode);
		}
	}

		return containerList;
}

void Scene::load()
{
	buildMatrix();

	//BACKGROUND_GAME_THEME
	backgroundEntity = entityManager->CreateEntity("GameOBject1", "../../../../Assets/BG/bg.jpg");
	backgroundNode->attachEntity(backgroundEntity);
	
	//CUSTOMIZED_GAME_CURSOR
	cursorEntity = entityManager->CreateEntity("Game_Cursor", "../../../../Assets/Sprites/forest_cursor - Copy.png");
	cursorNode->attachEntity(cursorEntity);
	cursorNode->setNodeScale(0.8, 0.8);


	
	//GAME SCORE BOARD
	gameScoreHeaderEntity = entityManager->CreateEntity("Game_Score_Board", "../../../../Assets/Sprites/Forest/top_panel_1.png");
	gameScoreHeaderNode->attachEntity(gameScoreHeaderEntity);
	gameScoreHeaderNode->setNodePosition(backgroundEntity->getSpriteInstance().getGlobalBounds().width/2 - 235, 0);
	gameScoreHeaderNode->setNodeScale(0.5, 0.5);

	//MAIN_GAME_BOARD 
	gameBoardEntity = entityManager->CreateEntity("Game_Board", "../../../../Assets/Sprites/Forest/game wooden field.png");
	gameBoardNode->attachEntity(gameBoardEntity);
	//gameBoardNode->setNodeOrigin(gameBoardEntity->getSpriteInstance().getGlobalBounds().width / 2, gameBoardEntity->getSpriteInstance().getGlobalBounds().height / 2);
	//gameBoardNode->setNodePosition(backgroundEntity->getSpriteInstance().getGlobalBounds().width / 2, backgroundEntity->getSpriteInstance().getGlobalBounds().height / 2 + 20);
	gameBoardNode->setNodePosition(gameScoreHeaderNode->getNodePosition().x + 40 , gameScoreHeaderNode->getNodePosition().y + 165);
	gameBoardNode->setNodeScale(0.4, 0.4);

	//POWER_UPS_BOMB
	powerUpContainerEntity = entityManager->CreateEntity("Power_Up_Bomb_Container", "../../../../Assets/Sprites/Forest/wooden power-up form.png");
	powerUpContainerNode->attachEntity(powerUpContainerEntity);
	powerUpContainerNode->setNodePosition(backgroundEntity->getSpriteInstance().getGlobalBounds().width / 2 - 175, backgroundEntity->getSpriteInstance().getGlobalBounds().height-125);
	powerUpContainerNode->setNodeScale(0.32, 0.32);

	bombPowerUpEntity = entityManager->CreateEntity("Power_Up_Node", "../../../../Assets/Sprites/Forest/bomb power-up.png");
	bombPowerUpNode->attachEntity(bombPowerUpEntity);
	bombPowerUpNode->setNodePosition(powerUpContainerNode->getNodePosition().x + 12, powerUpContainerNode->getNodePosition().y - 5);
	bombPowerUpNode->setNodeScale(0.32, 0.32);

	powerUpContainerNode->addChildNode(bombPowerUpNode);


	//POWER_UPS_ARROW
	powerUpArrowContainerEntity = entityManager->CreateEntity("Arrows_Power_Up", "../../../../Assets/Sprites/Forest/wooden power-up form.png");
	powerUpArrowContainerNode->attachEntity(powerUpArrowContainerEntity);
	powerUpArrowContainerNode->setNodePosition(powerUpContainerNode->getNodePosition().x + 90, powerUpContainerNode->getNodePosition().y);
	powerUpArrowContainerNode->setNodeScale(0.32, 0.32);

	arrowsPowerUpEntity = entityManager->CreateEntity("Arrows_Power_Up", "../../../../Assets/Sprites/Forest/arrows power-up.png");
	arrowsPowerUpNode->attachEntity(arrowsPowerUpEntity);
	arrowsPowerUpNode->setNodePosition(powerUpArrowContainerNode->getNodePosition().x + 11, powerUpArrowContainerNode->getNodePosition().y + 5);
	arrowsPowerUpNode->setNodeScale(0.32, 0.32);

	powerUpArrowContainerNode->addChildNode(arrowsPowerUpNode);


	//POWER_UPS_RAINBOW
	powerUpRainbowContainerEntity = entityManager->CreateEntity("Rainbow_Container", "../../../../Assets/Sprites/Forest/wooden power-up form.png");
	powerUpRainbowContainerNode->attachEntity(powerUpRainbowContainerEntity);
	powerUpRainbowContainerNode->setNodePosition(powerUpArrowContainerNode->getNodePosition().x + 90, powerUpArrowContainerNode->getNodePosition().y);
	powerUpRainbowContainerNode->setNodeScale(0.32, 0.32);

	rainbowPowerUpEntity = entityManager->CreateEntity("Arrows_Power_Up", "../../../../Assets/Sprites/Forest/rainbow power-up.png");
	rainbowPowerUpNode->attachEntity(rainbowPowerUpEntity);
	rainbowPowerUpNode->setNodePosition(powerUpRainbowContainerNode->getNodePosition().x + 14, powerUpRainbowContainerNode->getNodePosition().y + 12);
	rainbowPowerUpNode->setNodeScale(0.33, 0.33);

	powerUpRainbowContainerNode->addChildNode(rainbowPowerUpNode);


	//SHOP
	shopEntity = entityManager->CreateEntity("Shop","../../../../Assets/Sprites/Forest/shop icon.png");
	shopNode->attachEntity(shopEntity);
	shopNode->setNodePosition(powerUpRainbowContainerNode->getNodePosition().x + 90, powerUpRainbowContainerNode->getNodePosition().y + 5);
	shopNode->setNodeScale(0.32, 0.32);

	//POPULATION OF THE CONTAINER CELL 
	containerList = buildContainerCell(gameBoardNode);
	//POPULATION OF THE FRUITS IN THE CONTAINER CELL
	fruitList = populateFruits(containerList);
	//ACTIVE BLOCK NODE
	activeBlockEntity = entityManager->CreateEntity("Active_Block", "../../../../Assets/Sprites/Forest/active game block.png");
	activeBlockNode->attachEntity(activeBlockEntity);
	activeBlockNode->setNodeScale(0.4, 0.4);


	//ADDING THE NODES TO THE ROOT NODE CHILD
	rootNode->addChildNode(backgroundNode);
	rootNode->addChildNode(gameScoreHeaderNode);
	rootNode->addChildNode(gameBoardNode);

	//ADDING THE CONTAINER_NODES[CONTAINER_CELL] AS A CHILD OF THE ROOT NODE
	for (int i = 0; i < containerList.size(); i++)
	{
		gameBoardNode->addChildNode(containerList[i]);
	}

	//ADDING THE FRUIT_NODES AS A CHILD OF THE CONTAINER_NODES
	for (int i = 0; i < fruitList.size(); i++)
	{
		containerList[i]->addChildNode(fruitList[i]);
	}


	rootNode->addChildNode(powerUpContainerNode);
	rootNode->addChildNode(powerUpArrowContainerNode);
	rootNode->addChildNode(powerUpRainbowContainerNode);
	rootNode->addChildNode(shopNode);
	rootNode->addChildNode(cursorNode);

}

void Scene::render(sf::RenderWindow& stage)
{
	//stage.setMouseCursorVisible(false);
	stage.draw(*rootNode);
}

void Scene::update(sf::Time dt)
{
	rootNode->update(dt);
}


void Scene::handleEvent(sf::RenderWindow& window,sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (int i = 0; i < containerList.size(); i++)
		{
			//CHECK IF THE MOUSE CONTAINS INSIDE THE CONTAINER BLOCK
			//IF EXIST SET A COMMAND TO BOTH RENDERER AND UPDATER TO UPDATE THE POSITION.
		}
	}
}

void Scene::unload()
{

}
