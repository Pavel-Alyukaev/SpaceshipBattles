#include <tuple>
#include "SpaceSheep.h"
#include "quaternion.h"

namespace common {
    SpaceSheep::SpaceSheep(){
          }

    void SpaceSheep::SetOrientation(quaternion::Quaternion<double>& quat) {
        m_quaternion = quat;
    }
    const std::optional<std::optional<quaternion::Quaternion<double>>> SpaceSheep::GetOrientation() const
    {
        return m_quaternion;
    }
    void SpaceSheep::SetPosition(std::tuple<double,double,double>& pos)
    {
        m_position = pos;
    }
    std::optional<std::tuple<double,double,double>> SpaceSheep::GetPosition() const
    {
        return m_position;
    }

    void SpaceSheep::SetVelocity(std::tuple<double,double,double>& velocity)
    {
        m_velocity = velocity;
    }
    std::optional<std::tuple<double,double,double>> SpaceSheep::GetVelocity() const
    {
        return m_velocity;
    };



    void SpaceSheep::Rotate(quaternion::Quaternion<double>& quat){
        auto q = quat;
        q *= m_quaternion;
        q *= quaternion::conj(quat);
        m_quaternion = q;
    }


} // common