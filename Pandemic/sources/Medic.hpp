//
// Created by tal on 30/04/2021.
//

#pragma once
#include "Player.hpp"
namespace pandemic {

    class Medic : public Player {
    public:
        Medic(Board &_game, City _cty) : Player(_game, _cty) {
            if (_game.getCures().find(_game.get_city(_cty).getCityColor()) != _game.getCures().end()) {
                _game[_cty]=0;
            }
        };

        Medic &drive(City _cty) override;

        Medic &treat(City _cty) override;

        Medic &fly_direct(City _cty) override;

        Medic &fly_charter(City _cty) override;

        Medic &fly_shuttle(City _cty) override;

        std::string role() override {
            return "Medic";
        }
    };

}