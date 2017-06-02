/**********************/
/*
*�ļ�˵�������ļ�������Ϸ����Ƭ��ͼ��������������غ���������
*���ߣ���Ǭ
*ʱ�䣺2017-6-2
*/
/**********************/

#ifndef _MAP_H_
#define _MAP_H_

#include "cocos2d.h"

class CMap :public cocos2d::CCTMXTiledMap
{
public:
	static CMap* initTileMap(const char* tmxFile);

	//ͨ��ָ������ת��Ϊ��ͼ������
	cocos2d::CCPoint tilePosFromLocation(cocos2d::CCPoint pos);
	//�ж���Ƭ�Ƿ�Ϊ�ϰ�
	bool isTilePosBlocked(cocos2d::CCPoint pos);
};


#endif // !_MAP_H_
