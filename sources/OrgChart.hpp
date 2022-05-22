#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Node.hpp"
#include "iterator.hpp"
using namespace std;


namespace ariel{
    class OrgChart{
        Node* root;

        void print(std::ostream& os, Node* node) {
            os << node->name;
            if (!node->children.empty()) {
                os << "->(";
                bool first = true;
                for (Node* c : node->children) {
                    if (first) {
                        first = false;
                    }
                    else {
                        os << ",";
                    }
                    print(os, c);
                }
                os << ")";
            }
        }

        public:
            OrgChart() : root(nullptr){}
            ~OrgChart() {
                if (root != nullptr) {
                    delete root;
                }
            }

            OrgChart& add_root(string name) {
                if (root) {
                    root->name = name;
                }
                else {
                    root = new Node(name, nullptr);
                }
                return *this;
            }

            OrgChart& add_sub(string parent, string name) {
                if (root == nullptr) {
                    throw std::exception();
                }

                if (!root->add_sub(parent, name)) {
                    throw std::exception();
                }

                return *this;
            }

            friend std::ostream& operator<<(std::ostream& os, OrgChart& org) {
                if (org.root == nullptr) {
                    return os;
                }

                org.print(os, org.root);

                os << endl;

                return os;
            }

            IteratorLevelOrder begin_level_order() {
                if (root == nullptr) throw std::exception();
                return IteratorLevelOrder(root);
            }

            IteratorLevelOrder end_level_order() {
                if (root == nullptr) throw std::exception();
                return IteratorLevelOrder();
            }

            IteratorLevelReverse begin_reverse_order() {
                if (root == nullptr) throw std::exception();
                return IteratorLevelReverse(root);
            }

            IteratorLevelReverse end_reverse_order() {
                if (root == nullptr) throw std::exception();
                return IteratorLevelReverse();
            }

            IteratorLevelReverse reverse_order() {
                if (root == nullptr) throw std::exception();
                return IteratorLevelReverse();
            }

            IteratorPreOrder begin_preorder() {
                if (root == nullptr) throw std::exception();
		        return IteratorPreOrder(root);
	        }

            IteratorPreOrder end_preorder() {
                if (root == nullptr) throw std::exception();
                return IteratorPreOrder();
            }


            //for : operator, same order as levelorder
            IteratorLevelOrder begin() {
                return begin_level_order();
            }

            IteratorLevelOrder end() {
                return end_level_order();
            }
    };
}