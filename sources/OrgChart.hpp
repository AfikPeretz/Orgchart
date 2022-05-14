#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;


namespace ariel{

    enum Iterators {
        levelorder,
        reverselevelorder,
        preorder
    };

    struct Node {
        string name;
        int depth;
        vector <Node> children;
    };



    class OrgChart{

        private:
            int element;
            Node Root;


        public:
            OrgChart (){}
            OrgChart add_root(string){
                return *this;
            }
            OrgChart add_sub(string, string){
                return *this;
            }
            friend ostream &operator<<(ostream &a, OrgChart &){
                return a;
            }
            string *begin_level_order(){
                return NULL;
            }
            void *end_level_order(){
                return NULL;
            }
            string *begin_reverse_order(){
                return NULL;
            }
            void *reverse_order(){
                return NULL;
            }
            string *begin_preorder(){
                return NULL;
            }
            void *end_preorder(){
                return NULL;
            }
            int* begin(){
                return NULL;
            }
            int* end(){
                return NULL;
            }
            

    };
}