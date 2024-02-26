#pragma once
#include <iostream>
#include "SpaceSheep.h"
#include "quaternion.h"
#include "quaternion_io.h"

double GetRad(double degrees)
{
    static const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    return radians;
}

int main() {



    return 0;
}