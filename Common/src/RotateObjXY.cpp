#include "RotateObjXY.h"
#include "IGameObject.h"
#include "IMovable.h"

namespace
{
double GetRad(double degrees)
	{
		static const double pi = 3.14159265358979323846; // the value of pi
		const double radians = degrees * pi / 180.0;
		return radians;
	}
}


RotateObjXY::RotateObjXY(IGameObject* obj) : m_object(obj), m_angle(0.0)
{
	m_movableObject = dynamic_cast<IMovable*>(m_object);
}

RotateObjXY::~RotateObjXY() = default;

RotateObjXY* RotateObjXY::SetAngle(double angle)
{
	if (m_movableObject == nullptr)
		throw std::runtime_error("unmovable object");

	m_angle = angle;
	return this;
}

void RotateObjXY::Execute()
{
	if (m_movableObject == nullptr)
		throw std::runtime_error("unmovable object");

	quaternion::Quaternion<double> quat(std::cos(GetRad(m_angle)), 0., 0., std::sin(GetRad(m_angle)));

	auto q = quat;
	q *= m_object->GetOrientation();
	q *= quaternion::conj(quat);
	m_object->SetOrientation(q);

}
