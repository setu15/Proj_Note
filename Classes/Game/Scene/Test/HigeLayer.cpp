﻿#include "HigeLayer.h"
#include "Game/Object/Manager/NoteManager.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Audio/Define/Sample_DoReMi.h"
#include <math.h>
#include <random>

using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer(){
	//目る専ぬツイスター
	srand((unsigned)time(NULL));
}

HigeLayer::~HigeLayer() {
	mNoteManager->release();
}

bool HigeLayer::init() {
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255), 1280, 720)) return false;

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	auto back = Sprite::create("GamePlay/Character/NoteLine.png");
	back->setAnchorPoint(Vec2(0,0));
	addChild(back);

	mNoteManager = NoteManager::create(this);
	mNoteManager->retain();

	return true;
}

void HigeLayer::update(float deltaTime) {}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	mNoteManager->onTouchBegan(pos);
	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	mNoteManager->onTouchMove(pos);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	mNoteManager->onTouchEnd(pos);

}

HigeLayer* HigeLayer::create() {
	auto instance = new HigeLayer();

	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}