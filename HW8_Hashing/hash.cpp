//===============================================
// HW#: HW8P1 Hashing
// Name: Brian Vargas
// Compiler: g++
// File type: implementation file hash.cpp
//===============================================


#include "hash.h"

using namespace std;

//explicit constructor for hash map - makes use of entry class
//creates hash table with a particular size
HashMap::HashMap(int size)
{
  //set the size of our hash map to the specified size
  this->size = size;
  //initialize the hash map with null entries with particular size
  table = new Entry*[size];
  for(int i=0; i<size; i++)
    table[i] = NULL;
} //end: constructor

//destructor for hash map - delete all non-null entries then delete table
HashMap::~HashMap()
{
  //loop through the hash map and delete each entry if not null
  for(int i=0; i<size; i++)
  {
    if(table[i] != NULL)
      delete table[i];
  } //end for(i)
  delete table; //delete[]
} //end: destructor

//PURPOSE: Applies the hash function to the input to create an index for table
//PARAMETER: The key to be hashed into an index
unsigned long HashMap::hash(string str)
{
  //based off of DJB2 hashing algorithm from the powerpoint
  const char* cstr = str.c_str(); //convert key into c string
  unsigned long hash = 5381; //initialize output value at 5381
  int c;
  while((c = *cstr++)) //iterate through all chars in c string
    hash = hash*33+c; //multiply previous hash by 33 and add next char value
  return hash; //return the finalized hash value
  //creates a powerful hash based on all characters as opposed to just using the length
} //end: hash

//PURPOSE: Inserts an entry into the hash table
//PARAMETER: Entry to be inserted
void HashMap::put(Entry *e)
{
  //extract the key for the entry we are trying to add
  string key = e->getKey();
  //obtain the index from the hash table - this is where we'll insert
  int index = hash(key)%size;
  int index2 = index; //remember where we started
  //we need to find the index to insert the new entry
  //iterate until we reach an empty/available slot
  while(table[index] != NULL && table[index]->getKey() != key //CAN USE FOR LOOP WITH BREAK INSTEAD
	&& table[index]->getKey() != "empty")
  {
    //move to next spot; mod to loop to beginning if at the end
    index = (index+1)%size;
    //if we loop around to where we started, our hash map is filled up
    //and we cannot insert any more values; throw overflow
    if(index == index2)
      throw Overflow();
  } //end while
  //we exit the while loop once we found the right index to insert; insert entry
  table[index] = e;
} //end: put

//PURPOSE: Extract an entry from the hash tabled based on key
//PARAMETER: Key to be searched for within hash table
Entry* HashMap::get(string key)
{
  //obtain the index it should belong to in the hash map
  int index = hash(key)%size;
  int index2 = index; //remember where we started
  //we need to find the index at which this particular key is at
  while(table[index] != NULL && table[index]->getKey() != key)
  {
    //move to next spot; mod to loop to beginning if at the end
    index = (index+1)%size;
    //if we loop around to where we started, then our key was never found
    //that means this entry we are looking for is not in our hash map
    if(index == index2)
      return NULL;
  } //end while
  //we exit the while loop once we found the right index; extract entry
  return table[index];
} //end: get

//PURPOSE: Remove an entry from the hash tabled based on key
//PARAMETER: Key to be deleted within hash table
Entry* HashMap::remove(string key)
{
  //obtain the index it should belong to in the hash map
  int index = hash(key)%size;
  int index2 = index; //remember where we started
  //we need to find the index at which this particular key is at
  while(table[index] != NULL && table[index]->getKey() != key)
  {
    //move to next spot; mod to loop to beginning if at the end
    index = (index+1)%size;
    //if we loop around to where we started, then our key was never found
    //that means this entry we are looking for is not in our hash map
    if(index == index2)
      return NULL;
  } //end while
  //we exit the while loop once we found the right index; remove entry
  //save the entry we are about to delete 
  Entry *e = table[index];
  //deallocate it from our memory
  delete e;
  //tag the index it was on with a new entry indicating empty
  table[index] = new Entry("empty","",0);
  //return the deleted entry
  return e;
} //end: remove
