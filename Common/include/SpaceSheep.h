#pragma once
#include <optional>

#include "GameObjectBase.h"
#include "IMovable.h"

namespace common {

    class SpaceSheep : public GameObjectBase, public IMovable{
    public:
        SpaceSheep();
        ~SpaceSheep() override;

        void SetVelocity(std::tuple<double, double, double>&) override;
        [[nodiscard]] std::tuple<double, double, double> GetVelocity() const override;

    private:
        std::optional<std::tuple<double,double,double>> m_velocity;
    };

} // common


