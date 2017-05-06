//===============================================
// HW#: HW8P1 Hashing
// Name: Brian Vargas
// Compiler: g++
// File Type: header file hash.h
//===============================================

#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

//Entry class for holding the information in the hash table
//Holds information for name, phone umber, and salary
class Entry {
		string name;
		string phone;
		float salary;
  public:
		//explciit constructor - set attributes to input parameters
		Entry(string name, string phone, float salary) {
			//use this to distinguish attributes vs parameters
			this->name = name;
			this->phone = phone;
			this->salary = salary;
		}
		//set and get functions for necessary attributes
		string getKey() { return name; }
		string getPhone() {  return phone; }
		float getSalary() { return salary; }
		void setKey(string str) { name = str; }
};

//hashmap class - makes us of entry class above to orgaize hash table
//closed hashing, open addressing technique using linear probing
class HashMap {
  public:      
        //overflow is thrown when the hash table is filled up
	//note: no underflow needed because we can just claim key doesnt exist
	class Overflow{};
	//explicit constructor: initalize hashmap with size entries - all null
	HashMap(int size);
	//destructor: delete all non-null entries then delete the hashmap itself
	~HashMap();

	//PURPOSE: Applies the hash function to the input to create an index for table
	//PARAMETER: The key to be hashed into an index
	unsigned long hash(string str);

	//PURPOSE: Insert an entry into the hash table
	//PARAMETER: Entry to be inserted
	void put(Entry *e);

	//PURPOSE: Extract an entry from the hash table based on key
	//PARAMETER: Key to be searched for within hash table
	Entry* get(string key);
	
	//PURPOSE: Remove an entry from the hash table based on key
	//PARAMETER: Key to be deleted within hash table
	Entry* remove(string key);
  protected:
  	Entry **table; //hash table holding entries
	int size; //size of the hash table
};
#endif
