#include "IGameObject.h"
#include "quaternion.h"
namespace common {

    class GameObject : public IGameObject{


    public:
        GameObject();
        ~GameObject() = default;

        void SetOrientation(quaternion::Quaternion<double>& quat) override;
        quaternion::Quaternion<double> GetOrientation() override;
        void SetPosition(std::tuple<double,double,double>&) override;
        std::tuple<double,double,double> GetPosition() override;

    private:
        quaternion::Quaternion<double> m_quaternion;
        std::tuple<double,double,double> m_position;
    };

} // common


