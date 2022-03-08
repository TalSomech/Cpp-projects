//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
namespace pandemic {
    class Virologist : public Player {
    public:
        Virologist(Board &_game, City _cty) : Player(_game, _cty) {};

        Virologist &treat(City _cty) override;

        std::string role() override {
            return "Virologist";
        }
    };
}