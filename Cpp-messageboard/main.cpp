//
// Created by tal on 03/04/2021.
//
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <iostream>
using namespace std;
#define MAX_CHAR 256
int main() {
    int k = 1;
    ariel::Board board;
    int choice;
    int row;
    int col;
    int dir;
    char *msg=new char[MAX_CHAR];
    Direction dirc;
    while (k) {
        cout << "1) Write To Board \n"
                "2) Read From Board\n"
                "3) Show Board\n"
                "4) Exit Program\n"
                "Please Enter a Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Choose Row: ";
                cin >> row;
                cout << "Choose Col: ";
                cin >> col;
                do {
                    cout << "Choose Direction:\n"
                            "0 for Horizontal\n"
                            "1 for Vertical ";
                    cin >> dir;
                    dirc = dir == 0 ? Direction::Horizontal : Direction::Vertical;
                } while (dir != 0 && dir != 1);
                cout << "What is your message? : " << endl;
                cin >> msg;
                board.post(row, col, dirc, msg);
                break;
            }
            case 2: {
                int lng = 0;
                cout << "Choose Row: ";
                cin >> row;
                cout << "Choose Col: ";
                cin >> col;
                do {
                    cout << "Choose Direction:\n"
                            "0 for Horizontal\n"
                            "1 for Vertical: ";
                    cin >> dir;
                    dirc = dir == 0 ? Direction::Horizontal : Direction::Vertical;
                } while (dir != 0 && dir != 1);
                cout << "Choose length to read: ";
                cin >> lng;
                cout<<board.read(row, col, dirc, lng)<<endl;
                break;
            }
            case 3: {
                board.show();
                break;
            }
            case 4: {
                k = 0;
                break;
            }
            default: {
                cout << "wrong choice,try again";
            }
        }

    }
    free(msg);
}
