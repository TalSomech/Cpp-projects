//
// Created by tal on 15/03/2021.
//

#ifndef MESSAGEBOARD_A_BOARD_H
#define MESSAGEBOARD_A_BOARD_H

#include "Direction.hpp"
#include <unordered_map>
#include <limits>

using namespace std;

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair <T1, T2> &p) const {
        auto hash1 = hash < T1 > {}(p.first);
        auto hash2 = hash < T2 > {}(p.second);
        return hash1 ^ hash2;
    }
};
namespace ariel {
    class Board {
    private:
        unsigned int mincol = std::numeric_limits<int>::max();
        unsigned int maxcol = 0;
        unsigned int maxrow = 0;
        unsigned int minrow = std::numeric_limits<int>::max();
        unordered_map<pair<int, int>, char, hash_pair> map;
    public:
        void post(unsigned int row, unsigned int col, const ariel::Direction dir, string msg);

        string read(unsigned int row, unsigned int col, ariel::Direction dir, unsigned int length);
        //string read(const unsigned int row, int col,const ariel::Direction dir,const unsigned int length);
//        string ariel::Board::read(const unsigned int row, const unsigned int col, const ariel::Direction dir,
//                                  unsigned int length);
        void show();
    };
}
#endif //MESSAGEBOARD_A_BOARD_H
