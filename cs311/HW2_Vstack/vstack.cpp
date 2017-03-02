//=========================================================
//HW#: HW2P2 vstack
//Your name: Brian Vargas
//Complier:  g++
//File type: stack implementation file vstack.cpp
//=========================================================

using namespace std;  
#include <iostream>
#include "vstack.h"

//PURPOSE:  Constructor - doesn't do anything since vectr already intialized
stack::stack()
{ 
  //nothing to do
} // indicate an empty stack 

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{
  //--steps taken to make sure there are no extra cells 
  clearIt();
}

//PURPOSE:  checks size and returns true if 0; false otherwise
bool stack::isEmpty()
{ 
  if(el.size() == 0)
    return true;
  else
    return false; 
}

//PURPOSE: false - dynamic arrays are never full
bool stack::isFull()
{ 
  return false; 
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el by pushing back
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
  if (isFull()) 
    throw Overflow();
  else 
    el.push_back(elem);
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  if (isEmpty()) 
    throw Underflow(); 
  else{ 
    elem = el[el.size()-1];
    el.pop_back();
  }
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
  if (isEmpty()) 
    throw Underflow();
  else{ 
    elem = el[el.size()-1]; 
  } 
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
  if (isEmpty()) 
    cout << "[ empty ]" << endl;
  else 
    for (int i=el.size()-1; i>=0; i--)
      cout << el[i] << endl; 
  cout << "-------------------" << endl;
}


//PURPOSE: pops all elements from the stack to make it empty if it's not already empty
void stack::clearIt()
{
  if (!isEmpty()){
    for(int i=el.size()-1; i>=0; i--)
      el.pop_back();
  }
}
