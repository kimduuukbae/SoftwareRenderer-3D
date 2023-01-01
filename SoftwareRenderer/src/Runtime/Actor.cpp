#include "Actor.h"
#include "TransformComponent.h"

Actor::Actor() {
	__transform = AddComponent<TransformComponent>();
}

Actor::~Actor() {

}