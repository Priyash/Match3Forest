#include "SceneFactory.h"



SceneFactory::SceneFactory()
{

}


SceneFactory::~SceneFactory()
{

}


IScene* SceneFactory::createScene(string scene_name)
{
	IScene* scene = new Scene(scene_name);
	return scene;
}
