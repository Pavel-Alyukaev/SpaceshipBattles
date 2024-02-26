#pragma once
#include <optional>
#include "quaternion.h"


class IGameObject{
public:
	virtual ~IGameObject() = default;
	virtual void SetOrientation(quaternion::Quaternion<double>&) = 0;
    [[nodiscard]] virtual quaternion::Quaternion<double> GetOrientation() const = 0;
    virtual void SetPosition(std::tuple<double,double,double>&) = 0;
    [[nodiscard]] virtual std::tuple<double,double,double> GetPosition() const = 0;
};