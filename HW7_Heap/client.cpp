//===============================================
// HW#: HW7P1 maxHeap
// Name: Brian Vargas
// Compiler: g++
// File type: client file client.cpp
//===============================================

#include <iostream>
#include "maxHeap.h"

using namespace std;

int main()
{
    //create maxHeap object - has capacity 11 by explicit constructor
    MaxHeap h(11);
    //insert a bunch of values to the maxHeap
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    //remove the value at index 2
    h.removeAt(2);
    //extract the max and print it
    cout << h.extractMax() << " ";
    //print the current max 
    cout << h.getMax() << endl;
	
    //create new array for heapify
    int a[7] = {2, 3, 4, 5, 6, 7, 1};
    //create maxHeap object - has capacity 7, same as array a
    MaxHeap h2(7);
    //let the maxHeap take in the array and heapify it
    h2.heapify(a, 7);
    //extract the max and print it
    cout << h2.extractMax() << " ";
    //print the current max
    cout << h2.getMax() << " " << endl;
    return 0;
} //end main
