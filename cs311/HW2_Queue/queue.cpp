//=========================================================
//HW#: HW1P1 queue
//Your name: Brian Vargas
//Complier:  g++
//File type: Queue implementation file queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// PURPOSE: Constructor must initialize count,front,rear to 0 to indicate
//          that our array is empty with the same front and rear
queue::queue()
{
   count = 0;
   front = 0;
   rear = 0;
}

// PURPOSE: Destructor does not have to do anything since this is a static array
queue::~queue()
{
 //nothing to do
}

// PURPOSE: returns true if queue is empty, otherwise false
//          based upon count - the number of elements in queue
bool queue::isEmpty()
{
   if(count==0)
      return true;
   else
      return false;
}

// PURPOSE: returns true if queue is full, otherwise false
// Full is defined as having a count equal to the max allowed in array
bool queue::isFull()
{
   if(count==MAX_SIZE)
      return true;
   else
      return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
   if(isFull())
      throw Overflow();
   else{
      //add 1 to the count, place element in rear spot, and move rear to next
      //position in a cyclical fashion
      count++;
      el[rear] = newElem;
      rear = (rear+1)%MAX_SIZE;
   }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
   if(isEmpty())
      throw Underflow();
   else{
      //subtract 1 from the count, take element in front spot, and move front to
      //next position in a cyclical fashion
      removedElem = el[front];
      count--;
      front = (front+1)%MAX_SIZE;
   }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
   if(isEmpty())
      throw Underflow();
   else{
      theElem = el[front];
   }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
   return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
   if(isEmpty())
      cout << "[ empty ]" << endl;
   else{
      cout << "[ ";
      for(int i=0; i<count; i++)
         cout << el[(front+i)%MAX_SIZE] << " ";
      cout << "]" << endl;
   }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
   el_t temp; //dummy variable used as a placeholder to move front to back

   if(isEmpty())
      throw Underflow();
   else if(count==1)
      return;
   else{
      remove(temp);
      add(temp);
   }
}
