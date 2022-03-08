//
// Created by tal on 15/03/2021.
//


#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good message code") {
ariel::Board board;
board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3)=="_b_");
// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6)=="abcd__");
board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6)=="abyd__");
board.post(99,50,Direction::Horizontal,"i dont fucking believe it");
CHECK(board.read(/*row=*/99, /*column=*/50, Direction::Horizontal, /*length=*/6)=="i dont");
CHECK(board.read(/*row=*/98, /*column=*/50, Direction::Vertical, /*length=*/6)=="_i____");
CHECK(board.read(99,50,Direction::Horizontal,157)=="i dont fucking believe it_______________________________________________________________________________________________________________________________x____");
CHECK(board.read(99,50,Direction::Vertical,4)=="i___");
ariel::Board board2;
board2.post(0,0,Direction::Horizontal,"hi,my name is Tal Somech");
CHECK(board2.read(0,0,Direction::Horizontal,24)=="hi,my name is Tal Somech");
CHECK(board2.read(0,0,Direction::Vertical,3)=="h__");
board2.post(1,0,Direction::Vertical,"what");
CHECK(board2.read(0,0,Direction::Vertical,5)=="hwhat");
CHECK(board2.read(1,0,Direction::Horizontal,4)=="w___");
board2.post(5,3,Direction::Horizontal,"can you see?");
CHECK(board2.read(5,3,Direction::Horizontal,12)=="can you see?");
CHECK(board2.read(5,0,Direction::Horizontal,23)=="___can you see?________");
board2.post(2,1,Direction::Horizontal,"what about now");
CHECK(board2.read(0,1,Direction::Vertical,5)=="i_w__");
CHECK(board2.read(2,1,Direction::Horizontal,14)=="what about now");
CHECK(board2.read(0,9,Direction::Vertical,6)=="e_u__u");
CHECK(board2.read(0,19,ariel::Direction::Vertical,5)=="o____");
board2.post(3,5,Direction::Horizontal,"can you see me now?");
CHECK(board2.read(3,5,Direction::Horizontal,19)=="can you see me now?");
CHECK(board2.read(0,9,Direction::Vertical,6)=="e_uy_u");
CHECK(board2.read(0,24,Direction::Vertical,5)=="_____");



}

