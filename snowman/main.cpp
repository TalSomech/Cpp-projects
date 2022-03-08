//
// Created by tal on 15/03/2021.
//
#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
int main() {
    int t=1;
    int inp=0;
    while(t) {
        cout << "enter a 8-digit number to build the snowman: "<<endl;
        try{
            cin >> inp;
            cout << ariel::snowman(inp)<<endl;
            t=0;
        }
        catch(exception& ex){
            cout << "Wrong input,try again" << endl;
        }
    }
}
