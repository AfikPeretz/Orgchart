#include "doctest.h"
#include <string>
#include <vector>
using namespace std;
#include "OrgChart.hpp"
using namespace ariel;

TEST_CASE("not throw"){
    OrgChart organization1;
    OrgChart organization2;
    CHECK_THROWS(organization1.add_sub("afik","Benny")); 
    CHECK_THROWS(organization2.add_sub("afik","gidi"));
    CHECK_THROWS(organization2.add_sub("afik","avi"));
    CHECK_THROWS(organization1.add_sub("afik","elad"));
    CHECK_THROWS(organization1.add_sub("afik","shmuel"));
    CHECK_THROWS(organization2.add_sub("afik","CEO"));
    CHECK_THROWS(organization2.add_sub("afik","CTO"));
    CHECK_THROWS(organization1.add_sub("afik","yoel"));
    CHECK_THROWS(organization1.add_sub("afik","nono"));
    CHECK_THROWS(organization2.add_sub("hadar","CEO"));
    CHECK_THROWS(organization2.add_sub("hadar","CTO"));
    CHECK_THROWS(organization1.add_sub("afik","ori"));
    CHECK_THROWS(organization1.add_sub("afik","hadar"));
    CHECK_THROWS(organization2.add_sub("afik","halel"));
    CHECK_THROWS(organization2.add_sub("afik","hod"));
    CHECK_THROWS(organization1.add_sub("afik","eden"));
    CHECK_THROWS(organization1.add_sub("afik","shilat"));
    CHECK_THROWS(organization2.add_sub("afik","osher"));
    CHECK_THROWS(organization2.add_sub("afik","sahar"));
    CHECK_THROWS(organization1.add_sub("afik","avichay"));
    CHECK_THROWS(organization1.add_sub("afik","lidor"));
    CHECK_THROWS(organization2.add_sub("nono","CEO"));
    CHECK_THROWS(organization2.add_sub("nono","CTO"));
    CHECK_THROWS(organization1.add_sub("afik","david"));

}