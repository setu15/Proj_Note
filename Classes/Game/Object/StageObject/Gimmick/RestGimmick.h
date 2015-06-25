#ifndef _REST_GIMMICK_H_
#define _REST_GIMMICK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "GimmickData.h"
#include "Utility/Timer/Timer.h"

enum class ObjectType : int;

class RestGimmick : public cocos2d::Sprite, public Collider {
protected:
	RestGimmick();
	~RestGimmick();
public:
	static RestGimmick* create(const std::string& nodeName, const GimmickData& data);
	bool init(const std::string& nodeName, const GimmickData& data);
	virtual void onContactBegin(cocos2d::Node* contactNode) override;
private:
	void initPhysics();
private:
	GimmickData mGimmickData;
	MyUtil::Timer mTimer;
};

#endif