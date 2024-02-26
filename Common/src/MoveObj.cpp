#include "MoveObj.h"

#include <stdexcept>

#include "IGameObject.h"
#include "IMovable.h"

MoveObj::MoveObj(IGameObject* obj) : m_object(obj)
{
	m_movableObject = dynamic_cast<IMovable*>(m_object);
}

MoveObj::~MoveObj() = default;

MoveObj* MoveObj::SetVelocity(std::tuple<double, double, double>& velocity)
{
	if (m_movableObject == nullptr)
		throw std::runtime_error("unmovable object");

	m_movableObject->SetVelocity(velocity);
	return this;
}

void MoveObj::Execute()
{
	if (m_movableObject == nullptr)
		throw std::runtime_error("unmovable object");

	auto [x, y, z] = m_object->GetPosition();
	auto [vx,vy,vz] = m_movableObject->GetVelocity();

	std::tuple newPos ={ x + vx, y + vy, z + vz };
	m_object->SetPosition(newPos);
}
