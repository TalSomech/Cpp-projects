//
// Created by tal on 30/04/2021.
//

#pragma once

#include <ostream>
#include <unordered_map>
#include "City.hpp"
#include <set>

namespace pandemic {
    class Board{
    private:
        std::unordered_map <City,CityC> cities;
        std::set<Color> _cures;
        void load_game();
    public:
        Board(){
            load_game();
        };
        int& operator[](City _cty);
        friend std::ostream& operator<<(std::ostream& out,Board &brd);
        bool is_clean();
        CityC& get_city(City _cty){
            return cities[_cty];
        }
        const std::set<Color> &getCures() const {
            return _cures;
        }
        void add_cure(Color _clr);
        bool are_connected(City from,City to);
        void remove_cures();
        void remove_stations();
        bool city_curedMedc(City _cty);

    };
}