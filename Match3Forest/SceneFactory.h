#ifndef SCENEFACTORY
#define SCENEFACTORY
#include"Scene.h"


class ISceneFactory
{
public:
	ISceneFactory() {}
	~ISceneFactory() {}
	virtual IScene* createScene(string scene_name) = 0;
};


class SceneFactory
{
	SceneFactory();
	~SceneFactory();

	IScene* createScene(string scene_name);
};

#endif

