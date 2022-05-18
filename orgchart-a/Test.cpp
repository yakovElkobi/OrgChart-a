#include "doctest.h"
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test OrgChart"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));   // Now the CTO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));   // Now the CFO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));   // Now the COO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));  // Now the VP_BI is subordinate to the COO
    CHECK_THROWS(organization.add_sub("MEO", "MTO"));
    CHECK_THROWS(organization.add_sub("REO", "RTO"));
        /*
        CEO
        |--------|--------|
        CTO      CFO      COO
        |                 |
        VP_SW             VP_BI
    */

    vector<string> vec = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    size_t  i = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order() && i < vec.size(); ++it){
        CHECK_EQ(*it, vec[i++]);
    }
    i = 0;
    vec.clear();
    vec = {"VP_SW", "VP_BI", "CTO", "CFO", "COO", "CEO"};
    for(auto it = organization.begin_reverse_order(); it != organization.reverse_order() && i < vec.size(); ++it){
        CHECK_EQ(*it, vec[i++]);
    }
    i = 0;
    vec.clear();
    vec = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    for(auto it=organization.begin_preorder(); it!=organization.end_preorder() && i < vec.size(); ++it) {
        CHECK_EQ(*it, vec[i++]);
    }
    i = 0;
    vec.clear();
    vec = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    for(auto element : organization){ // this should work like level order
        CHECK_EQ(element, vec[i++]);
    }
}
TEST_CASE("BAD INPUT"){
    OrgChart organization;
    CHECK_THROWS(organization.add_sub("CEO", "CTO"));    // IS EMPTEY
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));   // Now the CTO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));   // Now the CFO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));   // Now the COO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));  // Now the VP_BI is subordinate to the COO
    CHECK_THROWS(organization.add_sub("MEO", "MTO")); // not 
    CHECK_THROWS(organization.add_sub("REO", "RTO"));
    CHECK_THROWS(organization.add_sub("WEO", "WTO"));
    CHECK_THROWS(organization.add_sub("LEO", "LTO"));
    CHECK_THROWS(organization.add_sub("SEO", "STO"));
    CHECK_THROWS(organization.add_sub("DEO", "DTO"));
    CHECK_THROWS(organization.add_sub("FEO", "FTO"));
}