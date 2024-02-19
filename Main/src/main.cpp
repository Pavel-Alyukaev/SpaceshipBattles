#pragma once
#include <iostream>
#include "GameObject.h"
#include "quaternion.h"
#include "quaternion_io.h"

double GetRad(double degrees)
{
    static const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    return radians;
}

int main() {

    quaternion::QuaternionIO::print_style = 1;
    common::GameObject go{};
    double angle  = 30;
    quaternion::Quaternion<double> x1(std::cos(GetRad(angle)), 0., 0., std::sin(GetRad(angle)));

    quaternion::QuaternionIO::print<double>(std::cout, go.GetPosition());
    go.Rotate(x1);
    quaternion::QuaternionIO::print<double>(std::cout, go.GetPosition());
    //lib L;
    //L.Solve(1,0,0);
    return 0;
}