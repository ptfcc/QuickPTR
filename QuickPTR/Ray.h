#pragma once

#include "Math/MathUtils.h"

struct RayHit
{
	Float3 Location;
	Float3 Normal;
	Float3 OutGoingDir;
	float  Time;
};

class Ray
{
public:

	Ray() 
		: m_Origin(0.0f)
		, m_Direction(0.0f)
		, m_Time(0.0f)
		, m_tMax(FLT_MAX)
	{}

	Ray(const Float3& Origin, const Float3& Dir)
		: m_Origin(Origin)
		, m_Direction(Dir)
		, m_Time(0.0f)
		, m_tMax(FLT_MAX)
	{}

	Ray(const Float3& Origin, const Float3& Dir, float tMax)
		: m_Origin(Origin)
		, m_Direction(Dir)
		, m_Time(0.0f)
		, m_tMax(tMax)
	{}

	Ray(const Float3& Origin, const Float3& Dir, float tMax, float Time)
		: m_Origin(Origin)
		, m_Direction(Dir)
		, m_Time(Time)
		, m_tMax(tMax)
	{}

	~Ray() {}

	inline Float3 Origin() const { return m_Origin; }
	inline Float3 Direction() const { return m_Direction; }
	inline float Time() const { return m_Time; }
	inline float TMax() const { return m_tMax; }

	Float3 operator()(float t) const { return m_Origin + m_Direction*t; }

private:

	Float3 m_Origin;
	Float3 m_Direction;
	float m_Time;
	float m_tMax;		// to give the ray a length
};