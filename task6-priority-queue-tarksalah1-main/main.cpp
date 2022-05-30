#include <iostream>

#include "my_pq.h"
using namespace std;
int main(){
	PriorityQueue queue;
	int size, number_of_operations, elements, operation;
	int priority, new_priority;

	cin >> size >> number_of_operations;
	cout << endl;
	for (int element_num = 0;element_num < size;element_num++) {
		cin >> elements;
		queue.insert(elements);
	}

	cout << endl;
	for (int operations_num = 0;operations_num < number_of_operations;operations_num++) {
		cin >> operation;

		switch (operation)
		{
		case 1:
			cin >> elements;
			queue.insert(elements);
			break;

		case 2:
			cin >> priority;
			cin >> new_priority;
			queue.changePriority(priority, new_priority);
			cout << endl;
			break;

		case 3:
			cin >> elements;
			queue.remove(elements);
			break;

		case 4:
			queue.extractMax();
			break;

		case 5:

			cout << queue.getMax()<<" ";
			cout << endl;
			break;

		case 6:
			queue.extractMax2();
			cout << endl;
			break;

		case 7:
			cout << queue.size() << " ";
			cout << endl;
			break;

		default:
			break;
		}
	}

	return 0;
}
