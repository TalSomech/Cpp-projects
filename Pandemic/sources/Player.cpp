//
// Created by tal on 30/04/2021.
//
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace std;
using namespace pandemic;
constexpr int CURE_CARDS=5;
Player &Player::drive(City _cty) {
    if (_cur_city == _cty) {
        return *this;
    }
    if (_game.are_connected(_cur_city, _cty)) {
        this->_cur_city = _cty;

    }
    else {
        string err = "Those cities aren't connected!";
        throw invalid_argument(err);
    }
    return *this;
}

Player &Player::fly_direct(City _cty) {
    if (_cur_city == _cty) {
        throw invalid_argument("already in this city");
    }
    if (_cards.find(_cty) != _cards.end()) {
        _cards.erase(_cty);
        this->_cur_city = _cty;
    } else {
        throw invalid_argument("You do not have the corresponding card!");
    }
    return *this;

}

Player &Player::fly_charter(City _cty) {
    if (_cur_city == _cty) {
      throw invalid_argument("Already in this city");
    }
    if (_cards.find(_cur_city) != _cards.end()) {
        _cards.erase(_cur_city);
        this->_cur_city = _cty;
    } else {
        throw invalid_argument("You do not have the corresponding card!");
    }
    return *this;

}

Player &Player::fly_shuttle(City _cty) {
    if (_cur_city == _cty) {
        throw invalid_argument("Same City");
        return *this;
    }
    if ((!_game.get_city(_cty).rsc_station) || (!_game.get_city(_cur_city).rsc_station)) {
        throw invalid_argument("One of those cities does not have a research station built!");
    }
    this->_cur_city = _cty;
    return *this;
}

Player &Player::build() {
    if (_game.get_city(_cur_city).rsc_station) {
        return *this;
    }
    if (_cards.find(_cur_city) != _cards.end()) {

        _game.get_city(_cur_city).rsc_station = true;
        _cards.erase(_cur_city);
    } else {
        throw invalid_argument("You do not have the corresponding card!");

    }
    return *this;
}

Player &Player::discover_cure(Color _clr) {
    return discover_cure(_clr, CURE_CARDS);
}

Player &Player::treat(City _cty) {
    CityC &_city = _game.get_city(_cty);
    if (_game[_cty] == 0 || _cty != _cur_city) {
        throw invalid_argument("Cannot Cure");
    }
    if (_game.getCures().find(_city.getCityColor()) != _game.getCures().end()) {
        _game[_cty] = 0;
    } else {
        if (_game[_cty] > 0) { _game[_cty]--; }
    }
    return *this;
}

Player &Player::take_card(City _cty) {
    _cards.insert(_cty);
    return *this;
}


void Player::remove_card(Color _clr) {
    auto it = _cards.begin();
    while (it != _cards.end()) {
        if (_game.get_city(*it).getCityColor() == _clr) {
            it = _cards.erase(it);
        } else { it++; }
    }
}

int Player::count_cards(Color _clr) {
    int counter = 0;
    for (const auto &_cty :_cards) {
        if (_game.get_city(_cty).getCityColor() == _clr) {
            counter++;
        }
    }
    return counter;
}

Player &Player::discover_cure(Color _clr, int cards) {
    if (_game.getCures().find(_clr) != _game.getCures().end()) {
        return *this;
    }
    if ((!_game.get_city(_cur_city).rsc_station)) {
        throw invalid_argument("No research station");
    }
    if ((count_cards(_clr) >= cards)) {

        remove_card(_clr);
        _game.add_cure(_clr);
    } else {
        throw invalid_argument("Cannot discover cure.");

    }
    return *this;
}

void Player::remove_cards() {
    _cards.clear();
}
