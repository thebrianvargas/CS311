// =======================================================
// HW#: HW2P2 vstack
// Your name: Brian Vargas
// Compiler:  g++ 
// File type: header file vstack.h
//=======================================================

#include<vector>

//----- Globally setting up the aliases ----------------

//MAX is not needed for vector since dynamic array

typedef int el_t;      // the el_t type is int for assignment
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  vector<el_t> el;	  //el is a dynamic array of el_t's
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide variable to receive the top element (pass by ref)
  void topElem(el_t&);
  
  //PURPOSE: checks top and returns true if stack is empty, false otherwise.
  bool isEmpty();
  //PURPOSE: checks top and returns true if stack is full, false otherwise.
  bool isFull();
  //PURPOSE: displays stack elements vertically if nonempty
  //         or displays [ empty ] otherwise.
  void displayAll();
  //PURPOSE: pops all elements from the stack to make it empty if it's not already empty
  void clearIt();
  
};  
