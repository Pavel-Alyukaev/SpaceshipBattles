
#include "gtest/gtest.h"
#include "SpaceSheep.h"
#include "Teleportation.h"
#include "RotateObjXY.h"
#include <algorithm>

TEST(common, Teleportation)
{
    common::SpaceSheep sh;
    Teleportation tel(&sh);
    std::tuple<double, double, double> newPos = {1.,1.,1.};
    tel.SetPosition(newPos)->Execute();
    auto pos = sh.GetPosition();

    ASSERT_EQ(pos,newPos);
}

TEST(common, Rotation)
{
    common::SpaceSheep sh;
    sh.SetOrientation({0.,0.,1.,0.});
    quaternion::Quaternion<double> newOrient(0.,-1.,0.,0.);
    RotateObjXY rot(&sh);
    double angle = 90;
    rot.SetAngle(angle)->Execute();
    auto pos = sh.GetOrientation();

    ASSERT_EQ(pos,newOrient); 
}
