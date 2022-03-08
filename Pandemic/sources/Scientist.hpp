//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
namespace pandemic {

    class Scientist : public Player {
    private:
        int _cure_cards;
    public:
        Scientist(Board &_game, City _cty, int num_mk) : Player(_game, _cty), _cure_cards(num_mk) {};

        Scientist &discover_cure(Color _clr) override;

        std::string role() override {
            return "Scientist";
        }
    };
}
