#include "Sphere.h"

bool Sphere::Intersect(const Ray& inRay, float& outT, RayHit& outHit) const
{
	// Move the ray to object space. 
	Ray objectSpaceRay(inRay.Origin() - m_Location, inRay.Direction(), inRay.TMax(), inRay.Time());

	// tmp hack
	objectSpaceRay = inRay;

	// x^2 + y^2 + z^2 = Radius^2 -> (ray.Origin +  ray.Dir * t)^2
	// Reshuffling stuff around we can reduce this to a second order equation (a t^2 + b t + c = 0) where
	// a = ray.Dir.x * ray.Dir.x + ray.Dir.y * ray.Dir.y + ray.Dir.z*ray.Dir.z 
	// b = 2 * (ray.Dir.x*ray.Origin.x + ray.Dir.y*ray.Origin.y + ray.Dir.z*ray.Origin.z)
	// c = ray.Origin.x*ray.Origin.x + ray.Origin.y*ray.Origin.y + ray.Origin.z*ray.Origin.z - Radius*Radius	
	// By using dot products this becomes: 

	float a = dot(objectSpaceRay.Direction(), objectSpaceRay.Direction());
	float b = 2.0f * dot(objectSpaceRay.Origin(), objectSpaceRay.Direction());
	float c = dot(objectSpaceRay.Origin(), objectSpaceRay.Origin()) - m_Radius*m_Radius;

	// Let's find the two solutions. 
	float discriminant = b*b - a*c;

	if (discriminant > 0) // there is a solution
	{
		float sqrtDiscriminat = std::sqrt(discriminant);
		float t = (-b - sqrtDiscriminat) / a;
		if (t > 0.0f && t < inRay.TMax())
		{
			outT = t;
			outHit.Location = inRay(t);
			outHit.Normal = outHit.Location - m_Location;
			outHit.OutGoingDir = -inRay.Direction();
			outHit.Time = 0.0f; // not yet supported. 
			return true;
		}
		t = (-b + sqrtDiscriminat) / a;
		if (t > 0.0f && t < inRay.TMax())
		{
			outT = t;
			outHit.Location = inRay(t);
			outHit.Normal = outHit.Location - m_Location;
			outHit.OutGoingDir = -inRay.Direction();
			outHit.Time = 0.0f; // not yet supported. 
			return true;
		}

		return false;
	}

}