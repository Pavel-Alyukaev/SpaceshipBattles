#pragma once
#include <tuple>
class IMovable
{
public:
	virtual ~IMovable() = default;
	virtual void SetVelocity(std::tuple<double,double,double>&) = 0;
	[[nodiscard]] virtual std::tuple<double, double, double> GetVelocity() const = 0;
};
