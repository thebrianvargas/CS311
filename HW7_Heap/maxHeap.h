//===============================================
// HW#: HW7P1 maxHeap
// Name: Brian Vargas
// Compiler: g++
// File Type: header file maxHeap.h
//===============================================

#ifndef HEAP_H
#define HEAP_H

#include <iostream>

//maxHeap class - tree structure that can be stored as an array organized by max values
//holds information for the array, array capacity, and current size of tree
class MaxHeap
{
    int *arr;		// pointer to array of elements in heap
    int capacity;	// maximum possible size of max heap
    int size;		// Current number of elements in max heap

    //PURPOSE: Obtains the corresponding index of the parent of this inputted node
    //PARAMETER: Index of node we want to get the parent of
    int parent(int i);

    //PURPOSE: Obtains the corresponding index of the left child of this inputted node
    //PARAMETER: Index of node we want to get left child of
    int left(int i);

    //PURPOSE: Obtains the corresponding index of the right child of this inputted node
    //PARAMETER: Index of node we want to get right child of
    int right(int i);

    //PURPOSE: Swap the value of two integer variables
    //PARAMETERS: Integers passed by reference to be swapped
    void swap(int &a, int &b);

    //PURPOSE: Check if the inputted node is a leaf node
    //PARAMETERS: Index of node we want to check is a leaf node
    bool isLeaf(int i);

    //PURPOSE: Sift the inputted index up the tree until it matches maxHeap properties
    //PARAMETER: Index of node we want to sift up; swaps will be made
    void siftup(int i);

    //PURPOSE: Sift the inputted index down the tree until it matches maxHeap properties
    //PARAMETER: Index of node we want to sift down; swaps will be made
    void siftdown(int i);
public:
    //PURPOSE: Thrown when the heap gets filled up and we still try to insert more elements
    class Overflow{};

    //PURPOSE: Thrown when trying to access indices smaller than the size of the heap
    class Underflow{};

    //PURPOSE: Explicit constructor for the maxHeap
    //PARAMETER: Capacity of maxHeap; used to initialize array
    MaxHeap(int capacity);

    //PURPOSE: Obtains the size of the maxHeap - returns number of elements
    int getSize();

    //PURPOSE: Obtains the root node of the maxHeap - returns the largest element
    int getMax();

    //PURPOSE: Inserts a new value into the maxHeap
    //PARAMATER: The value to be inserted
    void insert(int k);

    //PURPOSE: Returns and removes the root node of the maxHeap then adjusts tree
    int extractMax();

    //PURPOSE: Removes an element based on index number
    //PARAMATER: Index value from which to remove element from maxHeap
    int removeAt(int i);

    //PURPOSE: Converts inputted array into a maxHeap by iterating on the internal nodes
    //PARAMETERS: array to be heapified and the length of the array
    void heapify(int *array, int len);

    //PURPOSE: Prints the contents of the array to check what is in the tree
    void print() const;
};
#endif
