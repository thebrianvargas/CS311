//===============================================
// HW#: HW8P1 Hashing
// Name: Brian Vargas
// Compiler: g++
// File type: client file client.cpp
//===============================================

#include <iostream>
#include "hash.h"

using namespace std;

int main() {
	//create hashmap object - initialize to size 128
	HashMap table(128);
        //create 3 enties: sam, mary, jim with corresponding phone numbers and salaries
	Entry *e1 = new Entry("Sam", "760-750-4567", 100000);
	Entry *e2 = new Entry("Mary", "760-750-1234", 120000);
	Entry *e3 = new Entry("Jim", "760-750-0000", 70000);
     	//insert the 3 entries we created into the hashmap
	table.put(e1);
	table.put(e2);
	table.put(e3);
	
	//have the user search for a particular key within the hashmap
	string key;
	cout << "Type in the search key (use 'q' for quit): ";
	cin >> key;
	//keep asking until the user inserts q
	while(key != "q") {
		//extract the entry with the particular key
		Entry *e = table.get(key); 
		//if entry isn't null, print out information
		if(e != NULL)
			cout << e->getKey() << "'s phone number is " << e->getPhone() << ", and salary is " << e->getSalary() << endl;
		//if entry is null, state that the particular key is not in the table
		else
			cout << "The key '" << key << "' is not in the table." << endl;
		//ask the user to search for another key
		cout << "Type in the search key (use 'q' for quit): ";
		cin >> key;
	}
	return 0;
}
