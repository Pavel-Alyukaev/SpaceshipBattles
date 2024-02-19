#include <tuple>
#include "GameObject.h"

namespace common {
    GameObject::GameObject(){
        m_quaternion = {0.,0.,1.,0.};
    }

    void GameObject::SetOrientation(quaternion::Quaternion<double>& quat) {
        m_quaternion = quat;
    }
    quaternion::Quaternion<double> GameObject::GetOrientation() {
        return m_quaternion;
    }
    void GameObject::SetPosition(std::tuple<double,double,double>& pos)
    {
        m_position = pos;
    }
    std::tuple<double,double,double> GameObject::GetPosition()
    {
        return m_position;
    }
    


    void GameObject::Rotate(quaternion::Quaternion<double>& quat){
        auto q = quat;
        q *= m_quaternion;
        q *= quaternion::conj(quat);
        m_quaternion = q;
    }


} // common