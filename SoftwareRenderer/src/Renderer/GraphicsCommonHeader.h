#pragma once

enum class FillMode : unsigned int {
	Solid,
	Wireframe
};

enum class CullMode : unsigned int {
	None,
	Front,
	Back
};

enum class RenderCounterClockwise : unsigned int {
	FrontFacing,
	BackFacing
};

struct IAAssembleDescribe {
	FillMode FillMode;
	CullMode CullMode;
	RenderCounterClockwise RCCW;
};