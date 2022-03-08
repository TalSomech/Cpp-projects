//
// Created by tal on 07/03/2021.
//

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good snowman code") {
            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n (.,.) \n ( : ) \n ( : ) "));
            CHECK(nospaces(snowman(21421321)) == nospaces("  ___ \n .....\n (-,o) \n<(] [)\\\n ( : ) "));
            CHECK(nospaces(snowman(11412231)) == nospaces(" _===_\n\\(-,.)/\n (> <) \n ( : ) "));
            CHECK(nospaces(snowman(12412311)) == nospaces(" _===_\n\\(-..) \n ( : )\\\n( : ) "));
            CHECK(nospaces(snowman(22222222)) == nospaces("  ___ \n .....\n\\(o.o)/\n (] [) \n (\" \") "));
            CHECK(nospaces(snowman(21212121)) == nospaces("___ \n .....\n\\(o,.) \n (] [)>\n ( : ) "));
            CHECK(nospaces(snowman(21213444)) == nospaces("  ___ \n .....\n (o,.) \n/(   ) \n (   ) "));
            CHECK(nospaces(snowman(12141112)) == nospaces(" _===_\n (..-) \n<( : )>\n (\" \") "));
            CHECK(nospaces(snowman(44444444)) == nospaces("  ___ \n (_*_)\n (- -) \n (   ) \n (   ) "));
            CHECK(nospaces(snowman(33333333)) == nospaces("   _  \n  /_\\ \n (0_0) \n/(> <)\\\n (___) "));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    //CHECK_THROWS(snowman(555));//there isent an option to add string or something like that
    // <0 tests
    CHECK_THROWS(snowman(-14211123));
    CHECK_THROWS(snowman(-425125411));
    CHECK_THROWS(snowman(-789454511));
    CHECK_THROWS(snowman(-572));
    CHECK_THROWS(snowman(-16));
    // #<8 || #>8
    CHECK_THROWS(snowman(145555555));
    CHECK_THROWS(snowman(425125411));
    CHECK_THROWS(snowman(789511));
    CHECK_THROWS(snowman(572));
    CHECK_THROWS(snowman(16));
    // (!int)
//    CHECK_THROWS(snowman("dsf"));
//    CHECK_THROWS(snowman("425125411"));
//    CHECK_THROWS(snowman("789511"));
//    CHECK_THROWS(snowman("572"));
    /* Add more checks here */
}


/* Add more test cases here */
