﻿#ifndef GOAL_H
#define GOAL_H

#include "StageObj.h"

class Goal : public StageObj {

public:
	Goal* create(const std::string textureName);

	bool init(const std::string textureName);

	void update(float deltatime) override;

protected:
	Goal() = default;

	~Goal() = default;

};

#endif