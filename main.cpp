#include "OrgChart.hpp"
#include "Node.hpp"
#include "iterator.hpp"
using namespace std;
using namespace ariel;




int main() {
	OrgChart organization;
	organization.add_root("University");
	organization.add_sub("University", "lecturer1");
	organization.add_sub("lecturer1", "student1");
	organization.add_sub("lecturer1", "student2");
	organization.add_sub("University", "lecturer2");
	organization.add_sub("University", "erelSegal");
	organization.add_sub("erelSegal", "ivgeni");
	organization.add_sub("erelSegal", "or");
	organization.add_sub("erelSegal", "liron");
	organization.add_sub("liron", "rami");
	organization.add_sub("liron", "dani");
	organization.add_sub("liron", "afik");
	organization.add_root("Ariel");
	
	
	cout << organization << endl;

	for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
		cout << (*it) << " " ;
	}
	cout << endl;

	for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
		cout << (*it) << " " ;
	}
	cout << endl;

	for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
		cout << (*it) << " " ;
	}
	cout << endl;

	for (string element : organization) {
		cout << element << " " ;
	}
	cout << endl;

	for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
		cout << it->size() << " " ;
	}
	cout << endl;

	return 0;
}