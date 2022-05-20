#pragma once
#include <iostream>
#include <string>
#include "OrgChart.hpp"
#include "Node.hpp"
#include <queue>
using namespace std;

namespace ariel{
    
    class IteratorLevelOrder{
        
        queue<Node*> queue;
        Node* current;

        public:
            // For the start
            IteratorLevelOrder(Node* root) : current(nullptr) {
                queue.push(root);
                ++(*this);
            }

            // For the end
            IteratorLevelOrder() : current(nullptr)
            {}

            IteratorLevelOrder& operator++() {
                if (queue.empty()) {
                    current = nullptr;
                }
                else {
                    current = queue.front();
                    queue.pop();
                    for (Node* c : current->children) {
                        queue.push(c);
                    }
                }
                
                return *this;
            }

            bool operator!=(const IteratorLevelOrder& other) {
                return current != other.current;
            }

            std::string operator*() {
                return current->name;
            }
        };


}