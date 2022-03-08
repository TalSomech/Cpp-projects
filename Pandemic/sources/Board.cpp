//
// Created by tal on 30/04/2021.
//

#include "Board.hpp"
#include <istream>
#include <iostream>
#include "City.hpp"
#include <algorithm>
using namespace std;
using namespace pandemic;

void Board::load_game() {
    cities[Algiers] = CityC("Algiers", {Madrid, Paris, Istanbul, Cairo}, Black);
    cities[Atlanta] = CityC("Atlanta", {Chicago, Miami, Washington}, Blue);
    cities[Baghdad] = CityC("Baghdad", {Tehran, Istanbul, Cairo, Riyadh, Karachi}, Black);
    cities[Bangkok] = CityC("Bangkok", {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}, Red);
    cities[Beijing] = CityC("Beijing", {Shanghai, Seoul}, Red);
    cities[Bogota] = CityC("Bogota", {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}, Yellow);
    cities[BuenosAires] = CityC("BuenosAires", {Bogota, SaoPaulo}, Yellow);
    cities[Cairo] = CityC("Cairo", {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}, Black);
    cities[Chennai] = CityC("Chennai", {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}, Black);
    cities[Chicago] = CityC("Chicago", {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}, Blue);
    cities[Delhi] = CityC("Delhi", {Tehran, Karachi, Mumbai, Chennai, Kolkata}, Black);
    cities[Essen] = CityC("Essen", {London, Paris, Milan, StPetersburg}, Blue);
    cities[HoChiMinhCity] = CityC("HoChiMinhCity",{Jakarta, Bangkok, HongKong, Manila}, Red);
    cities[HongKong] = CityC("HongKong", {Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei,Bangkok}, Red);
    cities[Istanbul] = CityC("Istanbul", {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}, Black);
    cities[Jakarta] = CityC("Jakarta", {Chennai, Bangkok, HoChiMinhCity, Sydney}, Red);
    cities[Johannesburg] = CityC("Johannesburg", {Kinshasa, Khartoum}, Yellow);
    cities[Karachi] = CityC("Karachi", {Tehran, Baghdad, Riyadh, Mumbai, Delhi}, Black);
    cities[Khartoum] = CityC("Khartoum", {Cairo, Lagos, Kinshasa, Johannesburg}, Yellow);
    cities[Kinshasa] = CityC("Kinshasa",{Lagos, Khartoum, Johannesburg}, Yellow);
    cities[Kolkata] = CityC("Kolkata", {Delhi, Chennai, Bangkok, HongKong}, Black);
    cities[Lagos] = CityC("Lagos", {SaoPaulo, Khartoum, Kinshasa}, Yellow);
    cities[Lima] = CityC("Lima", {MexicoCity, Bogota, Santiago}, Yellow);
    cities[London] = CityC("London", {NewYork, Madrid, Essen, Paris}, Blue);
    cities[LosAngeles] = CityC("LosAngeles", {SanFrancisco, Chicago, MexicoCity, Sydney}, Yellow);
    cities[Madrid] = CityC("Madrid", {London, NewYork, Paris, SaoPaulo, Algiers}, Blue);
    cities[Manila] = CityC("Manila", {Taipei, SanFrancisco, HoChiMinhCity, Sydney,HongKong}, Red);
    cities[Miami] = CityC("Miami", {Atlanta, MexicoCity, Washington, Bogota}, Yellow);
    cities[MexicoCity] = CityC("MexicoCity", {LosAngeles, Chicago, Miami, Lima, Bogota}, Yellow);
    cities[Milan] = CityC("Milan", {Essen, Paris, Istanbul}, Blue);
    cities[Montreal] = CityC("Montreal", {Chicago, Washington, NewYork}, Blue);
    cities[Moscow] = CityC("Moscow", {StPetersburg, Istanbul, Tehran}, Black);
    cities[Mumbai] = CityC("Mumbai", {Karachi, Delhi, Chennai}, Black);
    cities[NewYork] = CityC("NewYork", {Montreal, Washington, London, Madrid}, Blue);
    cities[Osaka] = CityC("Osaka", {Taipei, Tokyo}, Red);
    cities[Paris] = CityC("Paris", {Algiers, Essen, Madrid, Milan, London}, Blue);
    cities[Riyadh] = CityC("Riyadh", {Baghdad, Cairo, Karachi}, Black);
    cities[SanFrancisco] = CityC("SanFrancisco", {LosAngeles, Chicago, Tokyo, Manila}, Blue);
    cities[Santiago] = CityC("Santiago", {Lima}, Yellow);
    cities[SaoPaulo] = CityC("SaoPaulo", {Bogota, BuenosAires, Lagos, Madrid}, Yellow);
    cities[Seoul] = CityC("Seoul", {Beijing, Shanghai, Tokyo}, Red);
    cities[Shanghai] = CityC("Shanghai", {Beijing, HongKong, Taipei, Seoul, Tokyo}, Red);
    cities[StPetersburg] = CityC("StPetersburg", {Essen, Istanbul, Moscow}, Blue);
    cities[Sydney] = CityC("Sydney", {Jakarta, Manila, LosAngeles}, Red);
    cities[Taipei] = CityC("Taipei", {Shanghai, HongKong, Osaka, Manila}, Red);
    cities[Tehran] = CityC("Tehran", {Baghdad, Moscow, Karachi, Delhi}, Black);
    cities[Tokyo] = CityC("Tokyo", {Seoul, Shanghai, Osaka, SanFrancisco}, Red);
    cities[Washington] = CityC("Washington", {Atlanta, NewYork, Montreal, Miami}, Blue);
}

int &Board::operator[](City _cty) {
    return (cities[_cty].infection_lvl);
}


bool Board::is_clean(){
    return all_of(cities.begin(),cities.end(),[](auto const & p){return !(p.second.infection_lvl>0);});
}

std::ostream &pandemic::operator<<(ostream &out, Board &brd) {
    for(auto & _cty:brd.cities){
        cout<<boolalpha;
        cout<<_cty.second.getName()<<": "<<_cty.second.infection_lvl<<endl;
    }
    cout<<"Built research stations: "<<endl;
    for(auto & _cty:brd.cities){
        if(_cty.second.rsc_station){
            cout<<_cty.second.getName()<<endl;
        }
    }
    cout<<"Discovered cures: ";
    if(brd._cures.find(Blue)!=brd._cures.end()){
        cout<<"Blue,";
    }
    if(brd._cures.find(Yellow)!=brd._cures.end()){
        cout<<"Yellow,";
    }
    if(brd._cures.find(Black)!=brd._cures.end()){
        cout<<"Black,";
    }
    if(brd._cures.find(Red)!=brd._cures.end()){
        cout<<"Red,";
    }
    return out;
}

bool Board::are_connected(City from, City to) {
    return (this->cities[from].getNeighbs().find(to) != this->cities[from].getNeighbs().end());
}

bool Board::city_curedMedc(City _cty) {
    return _cures.find(cities[_cty].getCityColor()) == _cures.end();
}

void Board::remove_cures() {
    _cures.clear();
}

void Board::remove_stations() {
    for (auto &city : cities) {
        city.second.rsc_station=false;
    }
}

void Board::add_cure(Color _clr) {
    if (_cures.find(_clr) != _cures.end()) {
        return;
    }
    _cures.insert(_clr);
}
