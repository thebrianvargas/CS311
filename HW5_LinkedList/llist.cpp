// ====================================================
//HW#: HW3P1 llist
//Your name: Brian Vargas
//Complier:  g++
//File type: llist implementation file (llist.cpp)
//=====================================================

#include <iostream>
#include <string>
#include "llist.h" 

using namespace std;

//Constructor - initialize front, rear to null and count to 0
// this does not create any node. new list is empty.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
} //end constructor

//PURPOSE: Removes all nodes of linked list to destruct it
//Destructor - while list not empty, call deleteFront to delete all nodes
llist::~llist()
{
  int dummy; //dummy variable to take in what is deleted from the front
  //cout by request, tells us we have called the destructor
//  cout << "Calling the llist destructor" << endl;
  //cout is redundant information; Professor allowed me to not cout it
  while(Count != 0){
    deleteFront(dummy);
  } //end while
} //end destructor

//PURPOSE: Determines if Linked List is empty
//Returns true if the following 3 conditions are met:
// front and rear both point to NULL, count is 0
bool llist::isEmpty()
{
  //definition of empty: front,rear point null and count is 0
  if(Front==NULL && Rear==NULL && Count==0)
    return true;
  return false;
} //end isEmpty
  
//PURPOSE: Displays all the elements in the linked list beginning from front
void llist::displayAll()
{
  if(isEmpty()) //if empty, display [ empty ]
    cout << "[ empty ]" << endl;
  else{ //loop until our pointer gets to the rear
    Node *box = Front; //create traversal node; this is how we move through it
    for(int i=0; i<Count; i++){
      cout << box->Elem << " ";
      box = box->Next;
    } //end for(i)
    cout << endl;
  } //end else
} //end displayAll

//PURPOSE: Add an element to the front of the linked list
//PARAMETER: Elemnent to be added
void llist::addFront(el_t newNum)
{
  //create new node to add to the front; fill it as needed
  Node *x;
  x = new Node;
  x->Elem = newNum;
  x->Next = NULL;

  //if the linked list is empty, this will be our very first entry
  // thus, make the rear point to it
  if(isEmpty())
    Rear = x;
  //if the linked list has elements, make the new node point to the front instead
  else
    x->Next = Front;

  //now make the front point to this new node to finalize that it's the front
  Front = x;
  //update counter to show we have 1 more element in the linked list
  Count++;
}

//PURPOSE: Add an element to the rear of the linked list
//PARAMTER: Element to be added  
void llist::addRear(el_t newNum) 
{
  //create new node to add to the rear; fill it as needed
  Node *x;
  x = new Node;
  x->Elem = newNum;
  x->Next = NULL;

  //if the linked list is empty, this will be our very first entry
  // thus, make the front point to it
  if(isEmpty())
    Front = x;
  //if the linked list has elements, make the old rear point to this new node
  else
    Rear->Next = x;

  //now make the rear point to this new node to finalize that it's the rear
  Rear = x;
  //update the counter to show we have 1 more element in the linked list
  Count++;
} //end addRear

//PURPOSE: Deletes the entry in the front of the linked list
//PARAMETER: Holds the value that used to be in front prior to deletion
void llist::deleteFront(el_t &oldNum)
{
  //error case - empty list gives us underflow; can't delete what isn't there!
  if(isEmpty())
    throw Underflow();
  //special case - currently one node
  //give back element through oldNum, make front,rear Null and update count
  else if(Count == 1){
    oldNum = Front->Elem;
    Front = NULL;
    Rear = NULL;
    Count = 0;
  }
  //regular case
  //give back front element through oldNum, remove front node, and update count
  else{
    oldNum = Front->Elem;
    Node *newFront; //placeholder for new front; must delete old front first
    newFront = Front->Next;
    delete Front;
    Front = newFront; //reassign front to the new front after deletion
    Count--;
  } //end else: regular case
} //end deleteFront

//PURPOSE: Deletes the entry in the rear of the linked list
//PARAMETER: Holds the value that used to be in the rear prior to deletion
void llist::deleteRear(el_t &oldNum)
{
  //error case - empty list gives us underflow; can't delete what isn't there!
  if(isEmpty())
    throw Underflow();
  //special case - currently one node
  //give back element through oldNum, make front,rear Null and update count
  else if(Count == 1){
    oldNum = Rear->Elem;
    Front = NULL;
    Rear = NULL;
    Count = 0;
  }
  //regular case
  //give back rear element through oldNum, remove rear node, and update count
  else{
    oldNum = Rear->Elem;
    Node *newRear; //placeholder for new rear; must delete old rear first
    newRear = Front;
    while(newRear->Next != Rear) //find the place right before the rear
      newRear = newRear->Next; //to be our new rear
    delete Rear;
    Rear = newRear; //reassign rear to the new rear after deletion
    Count--;
  } //end else: regular case
}


//PURPOSE: Deletes the ith entry in the linked list where i index begins at 1
//PARAMETER: Holds the value that used to be in the ith slot prior to deletion
void llist::deleteIth(int i, el_t &oldNum)
{
  //error case - i is an illegal value: >Count or <1 - throw outofrange
  if(i>Count || i<1)
    throw OutOfRange();
  //special cases - call other functions we already made for i=1 or i=Count
  else if(i==1)
    deleteFront(oldNum);
  else if(i==Count)
    deleteRear(oldNum);
  //regular case
  //delete ith node where i begins at 1 and update count
  //make it so i-1 entry now has i+1 entry as its next
  else{
    Node *iNode,*priorNode; //pointers that will hold i-1,i entries after traversal
    priorNode = Front;
    for(int j=1; j<i-1; j++)
      priorNode = priorNode->Next; //obtain i-1 entry
    iNode = priorNode->Next; //obtain i entry to be removed
    oldNum = iNode->Elem; //value being removed in ith position
    priorNode->Next = iNode->Next; //have i-1 be followed by i+1 entry by changing next
    delete iNode;
    Count--;
  } //end else: regular case
}

//PURPOSE: Inserts new node into linked list making it the new ith node
//PARAMETER: Element to be added
void llist::addbeforeIth(int i, el_t newNum)
{
  //error case - i is an illegal value: >Count+1 or <1 - throw outofrange
  if(i>Count+1 || i<1)
    throw OutOfRange();
  //special cases - call other functions we already made for i=1 or i=Count+1
  else if(i==1)
    addFront(newNum);
  else if(i==Count+1)
    addRear(newNum);
  //regular case
  //add right before ith node where i begins at 1 and update count
  else{
    Node *iNode,*priorNode,*newNode; //pointers that will hold i-1,i,i+1 entries after traversal
    newNode = new Node;
    priorNode = Front;
    for(int j=1; j<i-1; j++)
      priorNode = priorNode->Next; //obtain i-1 entry
    iNode = priorNode->Next; //obtain i entry - will become i+1 entry after insertion
    priorNode->Next = newNode; //place new node in i spot
    newNode->Next = iNode; //have old i entry follow this new node - making it the i+1
    newNode->Elem = newNum; //insert value into new ith entry of linked list
    Count++;
  } //end else: regular case
}
