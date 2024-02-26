#include "Teleportation.h"

#include "IMovable.h"

Teleportation::Teleportation() :
m_object(nullptr)
, m_position(NAN, NAN, NAN)
{}

Teleportation::Teleportation(IGameObject* obj) :
m_object(obj)
, m_position(NAN, NAN, NAN) {}

Teleportation::~Teleportation() = default;

Teleportation* Teleportation::SetObject(IGameObject* obj)
{
	m_object = obj;
	return this;
}

Teleportation* Teleportation::SetPosition(std::tuple<double, double, double>&)
{
	return nullptr;
}

void Teleportation::Execute()
{
	if (m_object == nullptr)
		throw std::runtime_error("unknown object");

	IMovable* Obj = dynamic_cast<IMovable*>(m_object);
	if(Obj == nullptr)
		throw std::runtime_error("unmovable object");

	auto v = std::tuple(0., 0., 0.);
	Obj->SetVelocity(v);

}
