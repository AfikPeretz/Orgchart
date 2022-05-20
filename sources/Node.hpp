#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{
    class Node{
        string name;
        Node* parent;
        std::vector<Node*> children;

        // Needed so these classes will be able to use the private fields above
        friend class OrgChart;
        friend class IteratorLevelOrder;

        public:
            Node(string name, Node* parent) : name(name), parent(parent)
            {}

            ~Node() {
                for (Node* c : children) {
                    delete c;
                }
            }

            bool add_sub(string parent_name, string sub_name) {
                if (parent_name == name) {
                    children.push_back(new Node(sub_name, this));
                    return true;
                }

                for (Node* c : children) {
                    if (c->add_sub(parent_name, sub_name)) {
                        return true;
                    }
                }
                return false;
            }
    };
}