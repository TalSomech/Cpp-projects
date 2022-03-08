//
// Created by tal on 30/04/2021.
//

#pragma once
#include <string>

#include "Board.hpp"
#include <string>
#include <iostream>
#include "City.hpp"
#include <set>
#include <map>
namespace pandemic{
    class Player{
    protected:
        Board& _game;
        std::set<City> _cards;
        City _cur_city;
        void remove_card(Color _clr);
        int count_cards(Color _clr);
        Player& discover_cure(Color _clr,int cards);
    public:

        Player(Board &game,City start):_game(game), _cur_city(start){}
        void remove_cards();
        virtual Player& drive(City _cty);

        virtual Player& fly_direct(City _cty);
        std::string cur_cty(){
            return _game.get_city(_cur_city).getName();
        }

        virtual Player& fly_charter(City _cty);

        virtual Player& fly_shuttle(City _cty);

        virtual Player& build();

        virtual Player& discover_cure(Color _clr);

        virtual Player& treat(City _cty);

        virtual std::string role(){
            return "Woop Woop";
        };

        Player& take_card(City _cty);
        ~Player()= default;
    };
}