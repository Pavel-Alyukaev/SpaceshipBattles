pragma once
#include <tuple>
class IRotatable{
public:
	virtual ~IRotatable() = default;
	virtual void TurnByAngle(std::tuple<double,double,double>&) = 0;
};
