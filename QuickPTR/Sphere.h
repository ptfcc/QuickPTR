#pragma once
#include "Shape.h"

// No textures in this quick PT, so no need for rotations in 
class Sphere : public Shape
{
public:

	explicit Sphere(const Float3& Location) 
		: Shape(Location)
		, m_Radius(1.0f)
	{}

	Sphere(const Float3& Location, float Radius)
		: Shape(Location)
		, m_Radius(Radius)
	{}

	~Sphere() {}

	virtual bool Intersect(const Ray& inRay, float& outT, RayHit& outHit) const;


private:
	float m_Radius;
};

