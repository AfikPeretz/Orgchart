#pragma once
#include <iostream>
#include <string>
#include "OrgChart.hpp"
#include "Node.hpp"
#include <queue>
#include <stack>
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

            //bfs
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

            string operator*() {
                return current->name;
            }

            std::string* operator->() {
		        return &(current->name);
	        }

    };

    class IteratorLevelReverse{
        std::stack<Node*> stack;
        Node* current;



        void bfs_reverse(Node* root) {
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* n = q.front();
                q.pop();
                stack.push(n);
                //push in the children from the end to the begin for right order in the end.
                for (unsigned int i = 0; i < n->children.size(); i++) {
                    q.push(n->children[n->children.size() - i - 1]);
                }
            }
        }

        public:
            // For the start
            IteratorLevelReverse(Node* root) : current(nullptr) {
                bfs_reverse(root);
                ++(*this);
            }

            // For the end
            IteratorLevelReverse() : current(nullptr)
            {}

            IteratorLevelReverse& operator++() {
                if (stack.empty()) {
                    current = nullptr;
                }
                else {
                    current = stack.top();
                    stack.pop();
                }
                return *this;
            }

            bool operator!=(const IteratorLevelReverse& other) {
                return current != other.current;
            }

            std::string operator*() {
                return current->name;
            }

            std::string* operator->() {
                return &(current->name);
            }
    };



    class IteratorPreOrder{
        std::queue<Node*> stack;
        Node* current;

        void preorder(Node* root) {
            stack.push(root);
            for (Node* n : root->children) {
                preorder(n);
            }
        }

        public:
            // For the start, current = null for not having garbich in the field
            IteratorPreOrder(Node* root) : current(nullptr) {
                preorder(root);
                ++(*this);
            }

            // For the end
            IteratorPreOrder() : current(nullptr)
            {}

            IteratorPreOrder& operator++() {
                if (stack.empty()) {
                    current = nullptr;
                }
                else {
                    current = stack.front();
                    stack.pop();
                }

                return *this;
            }

            bool operator!=(const IteratorPreOrder& other) {
                return current != other.current;
            }

            std::string operator*() {
                return current->name;
            }

            std::string* operator->() {
		        return &(current->name);
	        }
    };


}