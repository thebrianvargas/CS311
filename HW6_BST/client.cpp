//===============================================
// HW#: HW#6P1 bst
// Name: Brian Vargas
// Compiler: g++
// File type: client file (client.cpp)
//===============================================

#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
   //create binary search tree object - uses default constructor!
   BST bst;
   //insert a bunch of values into the binary search tree
   bst.insert(50);
   bst.insert(30);
   bst.insert(20);
   bst.insert(40);
   bst.insert(70);
   bst.insert(60);
   bst.insert(80);
   //print the binary search tree using inorder traversal
   bst.inorder();
   //search for the value 50 - print whether or not it was found
   // -it should be found since we just inserted it
   cout << (bst.search(50) == NULL ? "Element not found." : "Element found.");
   cout << endl;
   //remove the values 40 and 50 from the binary search tree
   bst.remove(40);
   bst.remove(50);
   //print the updated binary search tree using inorder traversal
   bst.inorder();
   //search for the value 50 - print wheter or not it was found
   // -it should not be found since we just removed it
   cout << (bst.search(50) == NULL ? "Element not found." : "Element found.");
   cout << endl;
   return 0;
} //end main
