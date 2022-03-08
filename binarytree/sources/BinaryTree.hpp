//
// Created by tal on 18/05/2021.
//

#pragma once

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>
#include <queue>

namespace ariel {
    template<typename T>

    class BinaryTree {

    private:
        struct Node {
            Node *left, *right, *father;
            T value;

            explicit Node(const T &val, Node *dad = nullptr,
                          Node *lef = nullptr, Node *righ = nullptr) : father(dad), value(val), left(lef),
                                                                       right(righ) {

            };

            Node *add_left(const T &val) {
                if(left!=nullptr){
                    left->value=val;
                    return left;
                }
                left = new Node(val, this);
                return left;
            }

            Node *add_right(const T &val) {
                if(right!= nullptr){
                    right->value=val;
                    return right;
                }
                right = new Node(val, this);
                return right;
            }
            friend std::ostream &operator<<(std::ostream &os, const Node &node) {
                os << node.value;
                return os;
            };
//            ~Node(){
//                father= nullptr;
//                right= nullptr;
//                left= nullptr;
//                //delete value;
//            }
        };

        std::multimap<T, Node *> tree;
        Node *root;

        void copy(Node *first, const Node *other);

        void destructor(Node *node);

    public:
        BinaryTree() : root(nullptr) {};

        BinaryTree(const BinaryTree &other) {
            if (other.root != nullptr) {
                root = new Node(other.root->value);
                copy(root, other.root);
            }
        }

        BinaryTree(BinaryTree &&other)  noexcept {
            root = other.root;
            other.root= nullptr;
            // copy(root, other.root);
            tree=move(other.tree);
            //other.tree=nullptr;
        }
        /***************************************************************************************************
 * ************************************************************************************************
 * */


        BinaryTree &add_root(const T val) {
            if (root == nullptr) {

                tree.emplace(val, new Node(val));
                root = tree.find(val)->second;
            } else {
                tree.erase(root->value);
                root->value = val;
                tree.emplace(val, root);
            }
            return *this;
        };

        BinaryTree &add_left(const T &father, const T &son) {
            if(root== nullptr){throw std::invalid_argument("No root");}
            if (tree.find(father) == tree.end()) {
                throw std::invalid_argument("Father doesn't exist");
            }
            auto range = tree.equal_range(father);
            for (auto i = range.first; i != range.second; i++) {
                if (i->second->left == nullptr) {
                    tree.emplace(son, i->second->add_left(son));
                    return *this;
                }
            }
            auto k=range.first->second;
            tree.erase(k->left->value);
            tree.emplace(son,k->add_left(son));
//            tree.find(son)->second->value=son;
//            k->second->left
//            tree.emplace(son,)
            //tree.erase(son);
            //  tree.find(son)->first=
            //root->value = val;
            // tree.emplace(val, root);
            //tree.emplace(son,tree.find(father)->second->left);
            //tree.find(father)->second->left->value = son;

            // }
            return *this;
        };

        BinaryTree &add_right(const T &father, const T &son) {
            if(root== nullptr){throw std::invalid_argument("No root");}
            if (tree.find(father) == tree.end()) {
                throw std::invalid_argument("Father doesn't exist");
            }
            auto range = tree.equal_range(father);
            for (auto i = range.first; i != range.second; i++) {
                if (i->second->right == nullptr) {
                    tree.emplace(son, i->second->add_right(son));
                    return *this;
                }

            }
            auto k=range.first->second;
            tree.erase(k->right->value);
            tree.emplace(son,k->add_right(son));
            // }
            return *this;
        };
/***************************************************************************************************
 * ************************************************************************************************
 * */


        class iterator {
        private:
            Node *curr;
            std::queue<Node *> it;
        public:
            explicit iterator(Node *ptr = nullptr) : curr(ptr) {};


            /**
             * pre order iterative , took from geeksforgeeks although it isn't that hard
             * to implement , but i already did that in data structures course
             * */
            void pre_order() {
                if (curr == NULL) { return; }
                std::stack<Node *> st;
                Node *nd = curr;
                while (!st.empty() || nd != NULL) {
                    while (nd != NULL) {
                        it.push(nd);
                        if (nd->right) { st.push(nd->right); }

                        nd = nd->left;
                    }

                    if (!st.empty()) {
                        nd = st.top();
                        st.pop();
                    }
                }
                curr=it.front();
                it.pop();
            };

            /**
             * inorder iterative , took from geeksforgeeks although it isn't that hard
             * to implement , but i already did that in data structures course
             * */
            void in_order() {
                if(curr==nullptr){return;}
                std::stack<Node *> s;
                Node *nd = curr;
                while (nd != NULL || !s.empty()) {
                    /* Reach the left most Node of the
                       curr Node */
                    while (nd != NULL) {
                        /* place pointer to a tree node on
                           the stack before traversing
                          the node's left subtree */
                        s.push(nd);
                        nd = nd->left;
                    }

                    /* Current must be NULL at this point */
                    nd = s.top();
                    s.pop();
                    it.push(nd);
                    /* we have visited the node and its
                       left subtree.  Now, it's right
                       subtree's turn */
                    nd = nd->right;
                }
                curr=it.front();
                it.pop();
            };

            /**
            * post order iterative , took from geeksforgeeks although it isn't that hard
            * to implement , but i already did that in data structures course
            * */
            void post_order() {
                if (curr == NULL) { return; }
                // Create two stacks
                std::stack<Node *> s1;
                std::stack<Node *> s2;
                // push root to first stack
                s1.push(curr);
                Node *nd=nullptr;
                // Run while first stack is not empty
                while (!s1.empty()) {
                    // Pop an item from s1 and push it to s2
                    nd = s1.top();
                    s1.pop();
                    s2.push(nd);

                    // Push left and right children
                    // of removed item to s1
                    if (nd->left) { s1.push(nd->left); }
                    if (nd->right) { s1.push(nd->right); }
                }
                // Print all elements of second stack
                while (!s2.empty()) {
                    nd = s2.top();
                    s2.pop();
                    it.push(nd);
                }
                curr=it.front();
                it.pop();

            };

            T &operator*() const {
                //return (int)0;
                return curr->value;
            };

            T *operator->() const {
                return &(curr->value);
            };

            // ++i;
            iterator &operator++() {
                if (it.empty()) {
                    curr = nullptr;
                }
                else {
                    curr = it.front();
                    it.pop();
                }
                return *this;
            };
            iterator operator++(int) {
                iterator tmp=*this;
                if (it.empty()) {
                    curr = nullptr;
                }
                else {
                    curr = it.front();
                    it.pop();
                }
                return tmp;
            };

            bool operator==(const iterator &rhs) const {
                return curr == rhs.curr;
                //return pointer_to_current_node == rhs.pointer_to_current_node;
            };

            bool operator!=(const iterator &rhs) const {
                return curr != rhs.curr;
            };

            friend std::ostream &operator<<(std::ostream &os, const iterator &it) {
                os << it.curr->value;
                return os;
            };
        };

        iterator begin_preorder() {
            // return &(m_first->m_value);
            iterator it{root};
            it.pre_order();
            return it;
            // , *(iterator::pre_order)};
        };

        iterator end_preorder() {
            return iterator();
        };

        iterator begin_inorder() {
            iterator it{root};
            it.in_order();
            return it;            //a.func = iterator::in_order();

        };

        iterator end_inorder() { return iterator(); };

        iterator begin_postorder() {
            iterator it{root};
            it.post_order();
            return it;
        };

        iterator end_postorder() { return iterator(); };

        iterator begin() { return begin_inorder(); };

        iterator end() { return iterator(); };

/***************************************************************************************************
 * ************************************************************************************************
 * */

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree) {
            return os;
        };
        BinaryTree &operator=(BinaryTree &&other) noexcept {
            if (root) {
                destructor(root);
            }
            root = other.root;
            tree=move(other.tree);
            other.root=nullptr;
        }

        BinaryTree<T> &operator=(const BinaryTree<T>  &other) {
            if (this == &other) {
                return *this;
            }
            if(root!= nullptr) {
                destructor(root);
                tree.clear();
            }
            if(other.root!=nullptr){
                root=new Node(other.root->value);
                copy(root, other.root);
            }
            return *this;
        }



        ~BinaryTree() {
            destructor(root);
            tree.clear();
        };

    };

/***************************************************************************************************
 * ************************************************************************************************
 * */
    template<typename T>
    void BinaryTree<T>::copy(BinaryTree::Node *first, const BinaryTree::Node *other) {

        if (other->left != nullptr) {
            tree.emplace(other->left->value, first->add_left(other->left->value));
            copy(first->left, other->left);
        }
        if (other->right != nullptr) {
            // this->add_right(other->right->value)
            // first->right = new Node(other->right->value);
            tree.emplace(other->right->value, first->add_right(other->right->value));
            copy(first->right, other->right);
        }
    }
    template<typename T>
    void BinaryTree<T>::destructor(BinaryTree::Node *node) {
        if (node) {
            destructor(node->left);
            destructor(node->right);
            delete node;
        }
    }
}

