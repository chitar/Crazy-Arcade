#ifndef BEGIN_SCENE_H_
#define BEGIN_SCENE_H_
#include "cocos2d.h"
#include "BaseScene.h"
using namespace cocos2d;
class CBeginScene:public CBaseScene
{
public:
	CBeginScene()
	{
		
	}
	virtual void onEnterScene(int i);
	virtual void onExitScene();
	virtual void onUpdate(float dt)
	{

	}
};
#endif