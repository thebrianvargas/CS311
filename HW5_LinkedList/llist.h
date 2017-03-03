// =======================================================
// HW#: HW3P1 llist
// Your name: Brian Vargas
// Compiler:  g++ 
// File type: header file (llist.h) 
//========================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // empty constructor to create a list object
  ~llist();     // destructor to destroy all nodes - called at end automatically
  
  //PURPOSE: Determines if the linked list is empty
  bool isEmpty();
    
  //PURPOSE: Prints all elements in linked list beginning from front node
  // all the way until to the rear node
  void displayAll();

  //PURPOSE: Inserts new element into the front of linked list
  //PARAMETER: New value to be inserted
  void addFront(el_t);
    
  //PURPOSE: Inserts new element into the rear of linked list
  //PARAMETER: New value to be inserted
  void addRear(el_t);

  //PURPOSE: Deletes element in the front of linked list
  //PARAMTER: Value that is being deleted passed by reference
  void deleteFront(el_t&);
    
  //PURPOSE: Deletes element in the rear of linked list
  //PARAMETER: Value that is being deleted passed by reference
  void deleteRear(el_t&);
    
  //PURPOSE: Deletes element in the ith slot of the linked list
  //PARAMETER: Value that is being deleted passed by reference
  void deleteIth(int, el_t&);

  //PURPOSE: Inserts new element into the linked list, making the new ith entry
  //PARAMETER: New value to be inserted
  void addbeforeIth(int, el_t);
    
};
