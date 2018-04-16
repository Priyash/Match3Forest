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

	entityManager = new EntityManager();
	rootNode = new SceneNode();

	backgroundNode = new ForestNode();
	cursorNode = new ForestNode();
	gameBoardNode = new ForestNode();
	gameScoreHeaderNode = new ForestNode();

}


Scene::~Scene()
{

}

string Scene::get_scene_name()
{
	return scene_name;
}


void Scene::load()
{
	backgroundEntity = entityManager->CreateEntity("GameOBject1", "../../../../Assets/BG/bg.jpg");
	backgroundNode->attachEntity(backgroundEntity);

	cursorEntity = entityManager->CreateEntity("Game_Cursor", "../../../../Assets/Sprites/forest_cursor - Copy.png");
	cursorNode->attachEntity(cursorEntity);
	cursorNode->setNodeScale(0.8, 0.8);

	gameBoardEntity = entityManager->CreateEntity("Game_Board", "../../../../Assets/Sprites/Forest/game wooden field.png");
	gameBoardNode->attachEntity(gameBoardEntity);
	gameBoardNode->setNodeOrigin(gameBoardEntity->getSpriteInstance().getLocalBounds().width / 2, gameBoardEntity->getSpriteInstance().getLocalBounds().height / 2);
	gameBoardNode->setNodePosition(600, 400);
	gameBoardNode->setNodeScale(0.4, 0.4);

	gameScoreHeaderEntity = entityManager->CreateEntity("Game_Score_Board", "../../../../Assets/Sprites/Forest/slice01_01 (4).png");
	gameScoreHeaderNode->attachEntity(gameScoreHeaderEntity);
	gameScoreHeaderNode->setNodePosition(370, 0);
	gameScoreHeaderNode->setNodeScale(0.5, 0.5);

	rootNode->addChildNode(backgroundNode);
	rootNode->addChildNode(gameScoreHeaderNode);
	rootNode->addChildNode(gameBoardNode);
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
