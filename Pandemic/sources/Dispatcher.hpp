//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
#include "Board.hpp"
namespace pandemic {
    class Dispatcher : public Player{
    public:
        Dispatcher(Board &_game, City cty) : Player(_game, cty) {};

        Dispatcher &fly_direct(City _cty) override;

        std::string role() override {
            return "Dispatcher";
        }
    };
}

