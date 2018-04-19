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


void Scene::buildGameBoard()
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{

		}
	}
}


vector<AbstractForestNode*> Scene::buildContainerCell(AbstractForestNode* boardNode)
{
	int xOffset = 74;
	int yOffset = 74;
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

	vector<AbstractForestNode*>containerList = buildContainerCell(gameBoardNode);


	//ADDING THE NODES TO THE ROOT NODE CHILD
	rootNode->addChildNode(backgroundNode);
	rootNode->addChildNode(gameScoreHeaderNode);
	rootNode->addChildNode(gameBoardNode);

	for (int i = 0; i < containerList.size(); i++)
	{
		rootNode->addChildNode(containerList[i]);
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


void Scene::handleEvent(sf::Event& event)
{

}

void Scene::unload()
{

}
