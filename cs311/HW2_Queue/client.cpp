//=========================================================
//HW#: HW1P1 queue
//Your name: Brian Vargas
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include "queue.h"

//Purpose of the program: Overload queue with strings "A B C AA AB ..." 
//Algorithm: Start with [A B C] and take the element in the front, put him in the back
//brken into 3 parts - with A, with B, with C
int main()
{
   queue myQueue;   //string stack
   string x;        // placeholder for element in the front

   myQueue.add("A");
   myQueue.add("B");
   myQueue.add("C");

   while(true){
      try{
         myQueue.remove(x);
         myQueue.add(x+"A");
         myQueue.add(x+"B");
         myQueue.add(x+"C");
      }
      catch(queue::Overflow){
         break;
      }
   }

   myQueue.displayAll();
   return 0;
}

