//
// Created by tal on 15/03/2021.
//

#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"
#include <algorithm>

using namespace std;
namespace ariel {
    void ariel::Board::post(const unsigned int row, const unsigned int col, const ariel::Direction dir, string msg) {
        unsigned int lng = msg.size();
        this->minrow = minrow < row ? minrow : row;
        this->mincol = mincol < col ? mincol : col;
        switch (dir) {
            case Direction::Horizontal:
                for (unsigned int i = col; i < col + lng; i++) {
                    this->map[make_pair(row, i)] = msg[i - col];
                }
                this->maxcol = maxcol > lng + col ? maxcol : lng + col;
                break;
            case Direction::Vertical:
                this->maxrow = maxrow > lng + row ? maxrow : lng + row;
                for (unsigned int j = row; j < row + lng; j++) {
                    this->map[make_pair(j, col)] = msg[j - row];
                }
                break;
        }
    }

    string ariel::Board::read(const unsigned int row, const unsigned int col, const ariel::Direction dir,
                              unsigned int length) {
        string ans;
        switch (dir) {
            case Direction::Horizontal:
                for (unsigned int i = col; i < col + length; i++) {
                    if (this->map.find(make_pair(row, i)) == this->map.end()) {
                        ans += '_';
                    } else {
                        ans += this->map[make_pair(row, i)];
                    }
                }
                break;
            case Direction::Vertical:
                for (unsigned int j = row; j < row + length; j++) {
                    if (this->map.find(make_pair(j, col)) == this->map.end()) {
                        ans += '_';
                    } else {
                        ans += this->map[make_pair(j, col)];
                    }
                }
                break;
        }
        return ans;
    }

    void ariel::Board::show() {
        minrow = minrow == 0 ? 1 : minrow;
        mincol = mincol == 0 ? 2 : mincol;
        mincol = mincol == 1 ? 3 : mincol;
        for (unsigned int i = minrow - 1; i < maxrow + 1; ++i) {
            cout << "row " << i << ": ";
            for (unsigned int j = mincol - 2; j < maxcol + 3; ++j) {
                cout << read(i, j, Direction::Horizontal, 1);
            }
            cout << endl;
        }

    }
}