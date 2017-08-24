#pragma once

#include <memory>
#include "Ray.h"

class Shape
{

public:

	Shape()
		: m_Location(0.0f)
		, m_Rotations(0.0f)
	{}
	
	explicit Shape(const Float3& Location)
		: m_Location(Location)
		, m_Rotations(0.0f)
	{}

	Shape(const Float3& Location, const Float3& RotationAngles)
		: m_Location(Location)
		, m_Rotations(RotationAngles)
	{}

	virtual ~Shape(){}

	virtual bool Intersect(const Ray& inRay, float& outT, RayHit& outHit) const = 0;

	inline Float3 Origin() const { return m_Location; }

protected:
	Float3 m_Location;
	Float3 m_Rotations;
};

using ShapeShrdPtr = std::shared_ptr<Shape>;
using ShapeUnqPtr = std::unique_ptr<Shape>;