//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
namespace pandemic {

    class FieldDoctor : public Player {
    public:
        FieldDoctor(Board &_game, City _cty) : Player(_game, _cty) {};

        FieldDoctor &treat(City _cty) override;

        std::string role() override {
            return "FieldDoctor";
        }
    };

}