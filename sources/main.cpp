#include "OrgChart.hpp"
#include "Node.hpp"
#include "iterator.hpp"
using namespace std;
using namespace ariel;




int main() {
	OrgChart organization;
	organization.add_root("a");
	organization.add_sub("a", "b");
	organization.add_sub("a", "c");
	organization.add_sub("b", "e");
	
	cout << organization << endl;
	cout << "-\n";

	for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
	{
		cout << (*it) << " ";
	}

	cout << endl;
}