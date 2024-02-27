#include "Teleportation.h"

#include "IMovable.h"

Teleportation::Teleportation(IGameObject* obj) :
m_object(obj),
m_position(NAN, NAN, NAN) {}

Teleportation::~Teleportation() = default;

Teleportation* Teleportation::SetPosition(std::tuple<double, double, double>& pos)
{
    m_position = pos;
	return this;
}

void Teleportation::Execute()
{

	IMovable* Obj = dynamic_cast<IMovable*>(m_object);
	if(Obj == nullptr)
		throw std::runtime_error("unmovable object");

    m_object->SetPosition(m_position);

}
