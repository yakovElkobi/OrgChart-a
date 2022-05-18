/**
 * OrgChart file for the exercise on iterators
 *
 * @author yakov elkobi
 * @since 2022-05
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace ariel{
    struct Node{
        std::string _name;
        std::vector<Node> _children;
    };
    class OrgChart{
        
    private:
        Node _root;
        Node _end; // for end iterator
        std::vector<std::string> _levelOrder;
        std::vector<std::string> _preOrder;
        std::vector<std::string> _reverseOrder;
    public:

        OrgChart &add_root(std::string name);
        OrgChart &add_sub(std::string father, std::string son);
        std::string *begin_level_order();
        std::string *end_level_order();
        std::string *begin_reverse_order();
        std::string *reverse_order();
        std::string *begin_preorder();
        std::string *end_preorder();
        std::string *begin(){ return begin_level_order();}
        std::string *end(){ return end_level_order();}

        friend std::ostream &operator <<(std::ostream &out, const OrgChart &root);
    };
}