//
// Created by tal on 30/04/2021.
//
#pragma once
#include "Player.hpp"
namespace pandemic {

    class GeneSplicer : public Player {
    public:
        GeneSplicer(Board &_game, City _cty) : Player(_game, _cty) {};

        GeneSplicer &discover_cure(Color _clr) override;

        std::string role() override {
            return "GeneSplicer";
        }
    };

}