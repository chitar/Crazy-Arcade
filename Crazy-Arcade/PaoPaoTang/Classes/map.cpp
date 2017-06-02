/**********************/
/*
*�ļ�˵�������ļ�������Ϸ����Ƭ��ͼ��������������غ����Ķ���
*���ߣ���Ǭ
*ʱ�䣺2017-6-2
*/
/**********************/
#include "map.h"

using namespace cocos2d;

CMap* CMap::initTileMap(const char *tmxfile)
{
	CMap *map = new CMap;
	if (map->initWithTMXFile(tmxfile))
	{
		CCTMXLayer *clayer = map->layerNamed("collision");       //ͨ�������ֻ�øò����  
		//clayer->setVisible(false);
		map->autorelease();
		return map;
	}

	CC_SAFE_DELETE(map);
	return NULL;
}

//ͨ��ָ��������ת��Ϊ��ͼ������  
CCPoint CMap::tilePosFromLocation(CCPoint pos)
{
	int x = pos.x / this->getTileSize().width;
	int y = pos.y / this->getTileSize().height;

	y = this->getMapSize().height - y-1;
	return ccp(x, y);
}
//�жϸ���Ƭ�Ƿ�Ϊ�ϰ�  
bool CMap::isTilePosBlocked(CCPoint pos)
{
	//�жϵ�ǰ���Ƿ�Ϊ��ײ��  
	CCPoint tilpos = tilePosFromLocation(pos);                //�����������תΪ������  
	CCTMXLayer *clayer = this->layerNamed("collision");      //ͨ�������ֻ�øò����  
															 //clayer->setVisible(true);  
	int tileGID = clayer->tileGIDAt(tilpos);             //��øÿ��GID��ʶ��  
	if (tileGID != 0)
	{
		CCDictionary* properties = this->propertiesForGID(tileGID);
		if (strcmp(properties->valueForKey("Collidable")->getCString(), "true") == 0)
			return true;
	}
	return false;
}