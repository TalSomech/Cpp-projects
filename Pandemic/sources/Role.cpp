//
// Created by tal on 09/05/2021.
//

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace std;
constexpr int CURE_CARDS =5;
pandemic::Virologist &pandemic::Virologist::treat(City _cty) {
    if(_game[_cty]==0){
        throw invalid_argument("Already Cured");
    }
    if(_cty==_cur_city){
        Player::treat(_cty);
    }
    else {
        if (_cards.find(_cty) != _cards.end()) {
            if (_game[_cty] > 0) {
                _game[_cty]--;
                _cards.erase(_cty);
            }
        } else {
            throw invalid_argument("You do not have the corresponding card!");
        }
    }
    return *this;
}

pandemic::Scientist &pandemic::Scientist::discover_cure(Color _clr) {
    return dynamic_cast<Scientist &>(pandemic::Player::discover_cure(_clr, _cure_cards));
}

pandemic::Researcher &pandemic::Researcher::discover_cure(Color _clr) {

    if (_game.getCures().find(_clr) != _game.getCures().end()) {
        return *this;
    }
    if (count_cards(_clr) >= CURE_CARDS) {
        remove_card(_clr);
        _game.add_cure(_clr);
    } else {
        throw invalid_argument("Cannot discover cure.");
    }
    return *this;
}

pandemic::Medic &pandemic::Medic::drive(City _cty) {
    Player::drive(_cty);
    if(!_game.city_curedMedc(_cty)){
        _game[_cty]=0;
    }
    return *this;
}

pandemic::Medic &pandemic::Medic::treat(City _cty) {
    if(_game[_cty]==0|| _cty!=_cur_city){
        throw invalid_argument("Cannot Cure");
    }
    _game[_cty]=0;
    return *this;
}

pandemic::Medic &pandemic::Medic::fly_direct(City _cty) {
    _cty=(pandemic::City)_cty;
    Player::fly_direct(_cty);
    if(!_game.city_curedMedc(_cty)){
        _game[_cty]=0;
    }
    return *this;
}

pandemic::Medic &pandemic::Medic::fly_charter(City _cty) {
    Player::fly_charter(_cty);
    if(!_game.city_curedMedc(_cty)){
        _game[_cty]=0;
    }
    return *this;
}

pandemic::Medic &pandemic::Medic::fly_shuttle(City _cty) {
    Player::fly_shuttle(_cty);
    if(!_game.city_curedMedc(_cty)){
        _game[_cty]=0;
    }
    return *this;
}
pandemic::GeneSplicer &pandemic::GeneSplicer::discover_cure(pandemic::Color _clr) {
    if (_game.getCures().find(_clr) != _game.getCures().end()) {
        return *this;
    }
    if ((_game.get_city(_cur_city).rsc_station) && (_cards.size() >= CURE_CARDS)) {
        int counter =0;
        auto  it = _cards.begin();
        while(it != _cards.end())
        {
            it = _cards.erase(it);
            counter++;
            if(counter==CURE_CARDS){break;}
        }
        _game.add_cure(_clr);
    } else {
        throw invalid_argument("Cannot discover cure.");
    }
    return *this;
}

pandemic::FieldDoctor &pandemic::FieldDoctor::treat(pandemic::City _cty) {
    if(_game[_cty]==0){
        throw invalid_argument("Already cured");
    }
    if(_cty==_cur_city){
       Player::treat(_cty);
    }
    else {
        if (_game.are_connected(_cur_city, _cty)&&_game[_cty]>0) {
                _game[_cty]--;
        } else {
            string err = "Cannot treat";
            throw invalid_argument(err);
        }
    }
    return *this;
}

pandemic::Dispatcher &pandemic::Dispatcher::fly_direct(pandemic::City _cty) {
    if(_cur_city==_cty){
        throw invalid_argument("already in this city");
    }
    if(_game.get_city(_cur_city).rsc_station){
        _cur_city=_cty;
    }
    else{
       Player::fly_direct(_cty);
    }
    return *this;
}

pandemic::OperationsExpert &pandemic::OperationsExpert::build() {
    _game.get_city(_cur_city).rsc_station= true;
    return *this;
}
