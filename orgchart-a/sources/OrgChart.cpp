
#include "OrgChart.hpp"
using namespace std;

namespace ariel{

    OrgChart &OrgChart::add_root(string name){
        return *this;
    }
    OrgChart &OrgChart::add_sub(string father, string sob){
        return *this;
    }
    string *OrgChart::begin_level_order(){
        return &_levelOrder[0];
    }
    string *OrgChart::begin_preorder(){
        return &_preOrder[0];
    }
    string *OrgChart::begin_reverse_order(){
        return &_reverseOrder[0];
    }
    string *OrgChart::end_level_order(){
        return &_levelOrder[0];
    }
    string *OrgChart::end_preorder(){
        return &_preOrder[0];
    }
    string *OrgChart::reverse_order(){
        return &_reverseOrder[0];
    }
    ostream &operator<<(ostream &out, const OrgChart &root){
        out << " ";
        return out;
    }
}