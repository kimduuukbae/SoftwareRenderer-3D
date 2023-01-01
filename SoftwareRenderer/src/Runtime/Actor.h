#pragma once

#include "GameObject.h"

class Actor : public GameObject {
public:
	Actor();
	virtual ~Actor();

private:
	class TransformComponent* __transform{ nullptr };
};