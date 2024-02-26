#include "MoveSpaseSheepXY.h"
#include <optional>

namespace common
{

    MoveSpaseSheepXY::MoveSpaseSheepXY(std::shared_ptr<IGameObject> obj) :m_obj(obj){}

    void MoveSpaseSheepXY::SetVelocity(std::tuple<double,double,double>velocity )
    {
        if(velocity != std::tuple(NAN,NAN,NAN))
        {
            m_obj->SetVelocity(velocity);
        }
        auto curPos  = m_obj->GetPosition();
        auto curVelocity  = m_obj->GetVelocity();
        if(curPos == std::nullopt)
        {
            trow new rumtime_error("incorrect position");
        }
        if(curVelocity == std::nullopt)
        {
            trow new rumtime_error("incorrect velocity");
        }

        auto& [x,y,z ]  = curPos;
        auto& [vx,vy,vz ]  =curVelocity;

        m_obj->SetPosition({x+vx, y+vy, z+vz});
    }
    void MoveSpaseSheepXY::MoveTo(std::tuple<double,double,double> pos)
    {
        if(pos != std::tuple(NAN,NAN,NAN))
        {
            m_obj->SetPosition(pos);
        }

        auto curPos  = m_obj->GetPosition();
        if(curPos == std::nullopt)
        {
            trow new rumtime_error("incorrect position");
        }
    }
}