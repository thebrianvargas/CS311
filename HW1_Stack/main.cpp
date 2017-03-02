//=========================================================
//HW#: HW1P1 stack
//Your name: Brian Vargas
//Complier:  g++
//File type: client program main.cpp
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: To compute postfix single-digit integer arithmetic
//Algorithm: Push single-digits into stack, pop 2 digits when we reach an operator,
//           and calculate the result with the operator.
//           In the end, we get final result of expression or a corresponding error.
//Potential errors: overflow, underflow, too many operands, invalid item
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: ";
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result; //result from operations
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
          //48 is the ASCII code for 0; 57 is the ASCII code for 9
          //transform from ASCII code to integer by subtracting 48
          if(item>=48 && item<=57)
            postfixstack.push((int)item-48);
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
                result = box2-box1;
              else if(item == '+')
                result = box2+box1;
              else if(item =='*')
                result = box2*box1;
              postfixstack.push(result);
	    }
	  else throw "invalid item";
	} // end try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow){ // for stack full and still trying to push
        cout << "Stack overflow!" << endl; //note: Rika implementation is vector so I changed the output
        return 0;
      }
      catch (stack::Underflow){ // for too few operands
        cout << "Not enough operands!" << endl;
        return 0;
      }
      catch (char const* errorcode){ // for invalid item
        cout << "invalid item in expression!" << endl;
        return 0;
      }

      //display entire stack after each iteration to match provided output
      postfixstack.displayAll();
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(result);
  cout << "result: " << result << endl;
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if(!postfixstack.isEmpty())
    cout << "Incomplete expression!" << endl;

  //leave the program at the very end
  return 0;
}// end of the program
