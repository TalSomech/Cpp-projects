

#include "snowman.hpp"
#include <array>
#include <iostream>
#include <stdexcept>

namespace ariel {
    const int min_input = 11111111, min_dig = 1, max_dig = 4, length = 8, hex_base = 10, up = 0, down = 1, left = 2, middle = 3, right = 4, body_lng = 2;
    const int head = 7, nose = 6, left_eye = 5, right_eye = 4, left_arm = 3, right_arm = 2, vest = 1, feet = 0;
    const int n = 7, lf = 1, rg = 5;

    std::array<int, length> Check(int key) {
        std::array<int, length> inp = {};
        if (key < min_dig) {
            throw std::out_of_range{"Invalid code"};
        }
        for (int i = 0; i < length; i++) {
            inp.at(i) = key % hex_base;
            if (inp.at(i) > max_dig || inp.at(i) < min_dig) {
                throw std::out_of_range{"Invalid code"};
            }
            key = key / hex_base;
        }
        if (key != 0) {
            throw std::out_of_range{"Invalid code"};
        }
        return inp;
    }

    std::string get_head(int inp) {
        switch (inp) {
            case 1:
                return " _===_\n";
            case 2:
                return "  ___ \n"
                       " .....\n";
            case 3:
                return "   _  \n"
                       "  /_\\ \n";
            case 4:
                return "  ___ \n"
                       " (_*_)\n";
            default:
                return " ";
        }
    }

    char get_eye(int eye) {
        switch (eye) {
            case 1:
                return '.';
            case 2:
                return 'o';
            case 3:
                return 'O';
            case 4:
                return '-';
            default:
                return ' ';
        }
    }

    char get_nose(int key) {
        switch (key) {
            case 1:
                return ',';
            case 2:
                return '.';
            case 3:
                return '_';
            default:
                return ' ';
        }
    }

    void get_left_arm(std::array <std::array<char, body_lng>, length> &body, int key) {
        const int left = 0;
        switch (key) {
            case 1:
                body.at(left).at(down) = '<';
                break;
            case 2:
                body.at(left).at(up) = '\\';
                break;
            case 3:
                body.at(left).at(down) = '/';
                break;
            default:
                break;
        }
    }

    void get_right_arm(std::array <std::array<char, body_lng>, length> &body, int key) {
        const int right = 6;
        switch (key) {
            case 1:
                body.at(right).at(down) = '>';
                break;
            case 2:
                body.at(right).at(up) = '/';
                break;
            case 3:
                body.at(right).at(down) = '\\';
                break;
            case 4:
                body.at(right).at(up) = ' ';
                break;
            default:
                break;
        }
    }

    void get_vest(std::array <std::array<char, body_lng>, length> &body, int key) {
        switch (key) {
            case 1:
                body.at(middle).at(down) = ':';
                break;
            case 2:
                body.at(left).at(down) = ']';
                body.at(right).at(down) = '[';
                break;
            case 3:
                body.at(left).at(down) = '>';
                body.at(right).at(down) = '<';
                break;
            default:
                break;
        }
    }

    std::string get_feet(int key) {
        switch (key) {
            case 1:
                return " ( : ) \n";
            case 2:
                return " (\" \") \n";
            case 3:
                return " (___) \n";
            case 4:
                return " (   ) \n";
            default:
                return " ";

        }
    }

    void fill_space(std::array <std::array<char, body_lng>, length> &arr) {
        for (int i = 0; i < body_lng; ++i) {
            for (int j = 0; j < length; ++j) {
                arr.at(j).at(i) = ' ';
            }
        }
    }

    std::string snowman(int key) {
        std::array<int, length> inp = Check(key);
        std::string ans;
        ans += get_head(inp[head]);
        std::array <std::array<char, body_lng>, length> body = {{}};
        fill_space(body);
        body.at(n).at(up) = body.at(n).at(down) = '\n';
        body.at(lf).at(up) = body.at(lf).at(down) = '(';
        body.at(rg).at(up) = body.at(rg).at(down) = ')';
        body.at(middle).at(up) = get_nose(inp[nose]);
        body.at(left).at(up) = get_eye(inp[left_eye]);
        body.at(right).at(up) = get_eye(inp[right_eye]);
        get_left_arm(body, inp[left_arm]);
        get_right_arm(body, inp[right_arm]);
        get_vest(body, inp[vest]);
        for (int i = 0; i < body_lng; i++) {
            for (int j = 0; j < length; j++) {
                ans += body.at(j).at(i);
            }
        }
        ans += get_feet(inp[feet]);
        return ans;
    }
}
