#include "GameObjectBase.h"

GameObjectBase::~GameObjectBase() = default;

void GameObjectBase::SetOrientation(quaternion::Quaternion<double>& quat)
{
    m_quaternion = quat;
}

quaternion::Quaternion<double> GameObjectBase::GetOrientation() const
{
	if (m_quaternion == std::nullopt)
		throw std::runtime_error("unknown orientation");

	return m_quaternion.value();
}

void GameObjectBase::SetPosition(std::tuple<double, double, double>& pos)
{
    m_position = pos;
}

std::tuple<double, double, double> GameObjectBase::GetPosition() const
{
	if (m_position == std::nullopt)
		throw std::runtime_error("unknown position");

	return m_position.value();
}