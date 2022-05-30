#include <iostream>
#include "my_tree.h"
#include <vector>

using namespace std;

int main(int argc, char** argv){
	vector<int> Vector;
	int size, number_of_operations, elements,operation;
	cin >> size >> number_of_operations;
	cout << endl;
	for (int element_num = 0;element_num < size;element_num++) {
		cin >> elements;
		Vector.push_back(elements);
	}
	MyTree<int> t(Vector);

	cout << endl;
	for (int operations_num = 0;operations_num < number_of_operations;operations_num++) {
		cin >> operation;
		
		switch (operation)
		{
		case 1:
			cin >> elements;
			t.insert(elements);
			break;

		case 2:
			cin >> elements;
			cout << t.search(elements)<<" ";
			cout << endl;
			break;

		case 3:
			cin >> elements;
			if (elements == 1) {
				t.inorder_rec();
			}
			else t.inorder_it();
			cout << endl;
			break;

		case 4:
			cin >> elements;
			if (elements == 1) {
				t.preorder_rec();
			}
			else t.preorder_it();
			cout << endl;
			break;

		case 5:
			cin >> elements;
			if (elements == 1) {
				t.postorder_rec();
			}
			else t.postorder_it();
			cout << endl;
			break;

		case 6:
			t.breadth_traversal();
			cout << endl;
			break;

		case 7:
			cout<<t.size()<<" ";
			cout << endl;
			break;

		case 8:
			cin >> elements;
			cout << t.deleteNode(elements);
			cout << endl;
			break;

		default:
			break;
		}
	}
}

