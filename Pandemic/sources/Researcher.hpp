//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
namespace pandemic {

    class Researcher : public pandemic::Player {
    public:
        Researcher(Board &_game, City _cty) : Player(_game, _cty) {};

        Researcher &discover_cure(Color _clr) override;

        std::string role() override {
            return "Researcher";
        }
    };
}

