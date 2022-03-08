//
// Created by tal on 18/05/2021.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sources/BinaryTree.hpp"
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace ariel;
using namespace std;
using namespace doctest;
TEST_CASE ("add root") {
    BinaryTree<int> tree;
    auto t=tree.begin_inorder();
    for (int i = 0; i < 20; i++) {
        tree.add_root(i);
        t=tree.begin_inorder();
        CHECK(*(t) != i);
    }
}

TEST_CASE ("add left&&CHECK order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 10; i++) {
        tree.add_left(i, i + 1);
    }
    int k = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); ++t,++k) {
                CHECK((*t) == k);
      //  k++;
    }
    k = 10;
    for (auto t = tree.begin_inorder(); t != tree.end_inorder(); t++,k--) {
                CHECK((*t) == k);
    }
    k = 10;
    for (auto t = tree.begin_postorder(); t != tree.end_postorder(); t++,k--) {
                CHECK((*t) == k);
    }

}

TEST_CASE ("add right&&CHECK order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 10; i++) {
        tree.add_right(i, i + 1);
    }
    int k = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); t++,k++) {
                CHECK((*t) == k);
    }
    k = 0;
    for (auto t = tree.begin_inorder(); t != tree.end_inorder(); t++,k++) {
                CHECK((*t) == k);
    }
    k = 10;
    for (auto t = tree.begin_postorder(); t != tree.end_postorder(); t++,k--) {
                CHECK((*t) == k);
    }
}
///**
 /** left kids are odd , right kids are even
 * **/
TEST_CASE ("Check normality") {
    BinaryTree<int> tree;
    tree.add_root(0);
    tree.add_left(0, 10);
    tree.add_right(0, 20);
    for (int i = 0; i < 2; ++i) {
        if (i % 2) {
            tree.add_left(i + 10, i + 12);
            tree.add_right(i + 10, i + 11);
        } else {
            tree.add_left(i + 20, i + 21);
            tree.add_right(i + 20, i + 20);
        }
    }
    auto i = tree.begin_preorder();
    auto j = tree.begin_inorder();
    auto t = tree.begin_postorder();
    //CHECK((*i)==0&&(*j)==12&&(*t)==12);
            CHECK((*i++) == 0);
            CHECK((*j++) == 12);
            CHECK((*t++) == 12);
            CHECK((*i++) == 10);
            CHECK((*j++) == 10);
            CHECK((*t++) == 11);
            CHECK((*i++) == 12);
            CHECK((*j++) == 11);
            CHECK((*t++) == 10);
            CHECK((*i++) == 11);
            CHECK((*j++) == 0);
            CHECK((*t++) == 22);
            CHECK((*i++) == 20);
            CHECK((*j++) == 22);
            CHECK((*t++) == 21);
            CHECK((*i++) == 22);
            CHECK((*j++) == 20);
            CHECK((*t++) == 20);
            CHECK((*i++) == 21);
            CHECK((*j++) == 21);
            CHECK((*t++) == 0);


//
//    CHECK((*i++)==10&&(*j++)==10&&(*t++)==11);
//    CHECK((*i++)==12&&(*j++)==11&&(*t++)==10);
//    CHECK((*i++)==11&&(*j++)==0&&(*t++)==22);
//    CHECK((*i++)==20&&(*j++)==22&&(*t++)==21);
//    CHECK((*i++)==22&&(*j++)==20&&(*t++)==20);
//    CHECK((*i++)==21&&(*j++)==21&&(*t++)==0);
    //CHECK((*i++)==12&&(*j++)==&&(*t++)==11);


    //    for (auto i = tree.begin_preorder(); i !=tree.end_preorder() ; ++i) {
//    if(k%2){
//        CHECK((*i)==)
//    }
//    }
//    for (auto i = tree.begin_inorder(); i !=tree.end_inorder() ; ++i) {
//
//    }
//    for (auto i = tree.begin_postorder(); i !=tree.end_postorder() ; ++i) {
//
//    }
}

