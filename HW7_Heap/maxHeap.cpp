//===============================================
// HW#: HW7P1 maxHeap
// Name: Brian Vargas
// Compiler: g++
// File Type: implementation file maxHeap.cpp
//===============================================

#include "maxHeap.h"

using namespace std;

//begin by defining the private functions

//PURPOSE: Obtains the corresponding index of the parent of this inputted node
//PARAMETER: Index of node we want to get the parent of
int MaxHeap::parent(int i)
{
  //parent location at floor((i-1)/2) through solving
  return (i-1)/2;
}

//PURPOSE: Obtains the corresponding index of the left child of this inputted node
//PARAMETER: Index of node we want to get left child of
int MaxHeap::left(int i)
{
  // left child location
  return 2*i+1;
}

//PURPOSE: Obtains the corresponding index of the right child of this inputted node
//PARAMETER: Index of node we want to get right child of
int MaxHeap::right(int i)
{
  // right child location
  return 2*i+2;
}

//PURPOSE: Swap the value of two integer variables
//PARAMETERS: Integers passed by reference to be swapped
void MaxHeap::swap(int &a, int &b)
{
  int temp = b;
  b = a;
  a = temp;
}

//PURPOSE: Check if the inputted node is a leaf node
//PARAMETERS: Index of node we want to check is a leaf node
bool MaxHeap::isLeaf(int i)
{
  // if node is a leaf, it should have no valid left child
  return (left(i) > size);
  // in ppt, we are given: i >= size/2 are leaves; rest are internal nodes
}

//PURPOSE: Sift the inputted index up the tree until it matches maxHeap properties
//PARAMETER: Index of node we want to sift up; swaps will be made
void MaxHeap::siftup(int i)
{
  //make sure the parent node is always larger than its children
  while(i>0 && arr[parent(i)] < arr[i])
  {
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  } //end while
}

//PURPOSE: Sift the inputted index down the tree until it matches maxHeap properties
//PARAMETER: Index of node we want to sift down; swaps will be made
void MaxHeap::siftdown(int i)
{
  int l,r,larger;
  //keep moving until we reach the leaf - worst case scenario
  while(!isLeaf(i))
  {
    //extract the left and right children indices
    l = left(i);
    r = right(i);
    //establish which index corresponds to the larger value
    if(arr[l] >= arr[r])
      larger = l;
    else
      larger = r;
    //if current node value is larger than the larger child, we are finished
    if(arr[i] >= arr[larger])
      break;
    //otherwise, swap the current node with the larger child
    swap(arr[i], arr[larger]);
    //keep going with this larger node
    i = larger;
  } //end while
}

//now we define the public methods

//PURPOSE: Explicit constructor for the maxHeap
//PARAMETER: Capacity of maxHeap; used to initialize array
MaxHeap::MaxHeap(int cap)
{
  capacity = cap;
  size = 0;
  arr = new int[capacity];
}

//PURPOSE: Obtains the size of the maxHeap - returns number of elements
int MaxHeap::getSize()
{
  return size;
}

//PURPOSE: Obtains the root node of the maxHeap - returns the largest element
int MaxHeap::getMax()
{
  // since it's a max heap, largest value will be at the root
  return arr[0];
}

//PURPOSE: Inserts a new value into the maxHeap
//PARAMATER: The value to be inserted
void MaxHeap::insert(int k)
{
  //throw overflow when there are more elements than capacity
  if(size >= capacity)
    throw Overflow();

  //insert into next available spot in array
  arr[size] = k;
  //sift up until it's smaller than its parent or reaches the root node
  //adjust size too since we just added a new element
  siftup(size++);
}

//PURPOSE: Returns and removes the root node of the maxHeap then adjusts tree
int MaxHeap::extractMax()
{
  //throw underflow when too few elements
  if(size <= 0)
    throw Underflow();
  //if single element, return it and decrease size
  else if(size == 1)
    return arr[--size];
  //get the root node to be returned at the end
  int out = arr[0];
  //move the last node to the root and update the size of the heap since we just removed one
  arr[0] = arr[--size];
  //sift the new root down so the new max is revealed
  siftdown(0);
  //after tree has been adjusted, we can return the extracted max value
  return out;
}

//PURPOSE: Removes an element based on index number
//PARAMATER: Index value from which to remove element from maxHeap
int MaxHeap::removeAt(int i)
{
  //throw underflow when too few elements
  if(i<0 || size<=i)
    throw Underflow();
  //if single element, return it and decrease size
  else if(size == 1)
    return arr[--size];
  //get the ith node to be returned at the end
  int out = arr[i];
  //replace this node with the last node
  arr[i] = arr[--size];
  //sift the node down or up, whatever is necessary
  if(arr[i] < out)
    siftdown(i);
  else
    siftup(i);
  //after the tree has been adjusted accordingly, we can return the removed value
  return out;
}

//PURPOSE: Converts inputted array into a maxHeap by iterating on the internal nodes
//PARAMETERS: array to be heapified and the length of the array
void MaxHeap::heapify(int *array, int len)
{
  //take the heap array to be the inputted array
  arr = array;
  //fix capacity and size so it matches the length of the array
  capacity = size = len;
  //obtain the index of the last internal node; this is where our work takes place
  int half = size/2-1;
  //sift each internal node down in order to turn array into maxHeap
  for(int i=half; i>=0; i--)
    siftdown(i);
}

//PURPOSE: Prints the contents of the array to check what is in the tree
void MaxHeap::print() const
{
  for(int i=0; i<size; i++)
    cout << arr[i] << ", ";
  cout << endl;
}
