//
// Created by tal on 30/04/2021.
//
#pragma once
#include "Player.hpp"
namespace pandemic {

    class OperationsExpert : public Player {
    public:
        OperationsExpert(Board &_game, City cty) : Player(_game, cty) {}

        OperationsExpert &build() override;

        std::string role() override {
            return "OperationsExpert";
        }
    };

}