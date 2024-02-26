#pragma once
#include <optional>

#include "IGameObject.h"

class GameObjectBase : public IGameObject
{
public:
    ~GameObjectBase() override;
    void SetOrientation(quaternion::Quaternion<double>&) override;
    [[nodiscard]] quaternion::Quaternion<double> GetOrientation() const override;
    void SetPosition(std::tuple<double, double, double>&) override;
    [[nodiscard]] std::tuple<double, double, double> GetPosition() const override;

private:
    std::optional<quaternion::Quaternion<double>> m_quaternion;
    std::optional<std::tuple<double, double, double>> m_position;
};
