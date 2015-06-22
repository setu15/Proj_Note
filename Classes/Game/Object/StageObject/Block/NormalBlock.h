#ifndef _NORMAL_BLOCK_H_
#define _NORMAL_BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "BlockData.h"

enum class ObjectType : int;

class NormalBlock : public cocos2d::Sprite, public Collider
{
	
protected:
	
	NormalBlock();
	
	~NormalBlock();
	
public:
	
	static NormalBlock* create( const std::string& nodeName, const BlockData& data );
	
	bool init( const std::string& nodeName, const BlockData& data );
	
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
	
private:
	
	void initPhysics();
	
private:
	
	BlockData	mBlockData;
};

#endif