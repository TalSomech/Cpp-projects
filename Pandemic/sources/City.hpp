//
// Created by tal on 30/04/2021.
//
#pragma once

#include "vector"
#include "Color.hpp"
#include <set>
#include <utility>
namespace pandemic {
    enum City {
        Atlanta ,
        Chicago, //=1
        Essen, //=2
        London, //=3
        Madrid, //=4
        Milan, //=5
        Montreal, //=6
        NewYork, //=7
        Paris, //=8
        SanFrancisco, //=9
        StPetersburg, //=10
        Washington, //=11
        Bogota, //=12
        BuenosAires, //=13
        Johannesburg, //=14
        Khartoum, //=15
        Kinshasa, //=16
        Lagos, //=17
        Lima, //=18
        LosAngeles,
        MexicoCity,
        Miami,
        Santiago,
        SaoPaulo,
        Algiers,
        Baghdad,
        Cairo,
        Chennai,
        Delhi,
        Istanbul,
        Karachi,
        Kolkata,
        Moscow,
        Mumbai,
        Riyadh,
        Tehran,
        Bangkok,
        Beijing,
        HoChiMinhCity,
        HongKong,
        Jakarta,
        Manila,
        Osaka,
        Seoul,
        Shanghai,
        Sydney,
        Taipei,
        Tokyo,
    };
    class CityC {
    private:
        Color _city_color;
        std::string _name;
        std::set<City> _neighbs;

    public:
        bool rsc_station;
        int infection_lvl;
        CityC(): rsc_station(false), _city_color(Black), infection_lvl(0){};
        CityC(std::string name,std::set<City> friends, Color _clr): _name(name) , _city_color(_clr), infection_lvl(0), rsc_station(false), _neighbs(std::move(friends)) {
        }

        const std::set<City> &getNeighbs() const {
            return _neighbs;
        }
//        unsigned int get_cube_num() const{
//            return infection_lvl;
//        }
        std::string getName() const {
            return _name;
        }
        Color getCityColor() const {
            return _city_color;
        }
    };
}