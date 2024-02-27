#include <tuple>
#include "SpaceSheep.h"

namespace common {
    SpaceSheep::SpaceSheep() = default;

    SpaceSheep::~SpaceSheep() = default;

void SpaceSheep::SetVelocity(std::tuple<double,double,double>& velocity)
    {
        m_velocity = velocity;
    }

std::tuple<double, double, double> SpaceSheep::GetVelocity() const
{
    if (m_velocity == std::nullopt)
        throw std::runtime_error("unknown velocity");

    return m_velocity.value();
}
} // common