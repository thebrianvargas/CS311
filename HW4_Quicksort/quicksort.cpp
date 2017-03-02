//=========================================================
//HW#: HW4P1 quicksort
//Name: Brian Vargas
//Compiler: g++
//File type: implementation file quicksort.cpp
//=========================================================

#include<iostream>
using namespace std;

//PURPOSE: swap array entries a and b using a temporary variable
//PARAMETERS: array entries a,b to be swapped
void swap(int* a, int* b)
{
    int t = *a; //temporary variable to hold swapped entry
    *a = *b; //reassign variable - half of swap
    *b = t; //complete swap
}
 
//PURPOSE: partitions the inputted array into two subarrays and
//         swaps accordingly using pivot
//PARAMETERS: (sub)array to be worked on; low and high are the indices
//            for the smaller and larger endpoints
int partition (int arr[], int low, int high)
{
   int pivot, i, j; //initialize variables for iterating and for holding pivot

   pivot = arr[high]; //pivot set at larger endpoint
   i = low-1; //i begins below smaller endpoint
   for(j=low; j<high; j++){ //iterate through subarray
      if(arr[j] <= pivot){ //if current entry in subarray smaller than pivot,
        swap(arr[++i], arr[j]); //increment index and swap to sort
      }
   } //end for(j)
   swap(arr[++i],arr[high]); //swap at the end and return final i index
   return i;
}
 
//PURPOSE: recursively sorts array of numbers by partitioning
//         according to the different values
//PARAMETERS: array (or subarray after recursion) to be sorted,
//	   indices low and high for the smaller and larger endpoints of array
void quickSort(int arr[], int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high); //partition (sub)array
        quickSort(arr, low, pi - 1); //quicksort the smaller array
        quickSort(arr, pi + 1, high); //quicksort the larger array
    }
}
 
//PURPOSE: prints out the entry in the array in order of index
//PARAMETERS: array to be printed and size of the array
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
//PURPOSE: main driver function - contains test case for quicksort
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}
