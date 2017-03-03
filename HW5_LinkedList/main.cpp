#include <iostream>
#include "llist.h"

using namespace std;

int main()
{
  llist x;
  int dummy;

  //test printing empty list
  x.displayAll();

  //test adding 2 values to the end then printing
  cout << "Now adding 5 and 6..." << endl;
  x.addRear(5);
  x.addRear(6);
  cout << "Adding 5 and 6 successful" << endl;
  x.displayAll();

  //test adding 2 values to the front then printing
  cout << "Now inserting 3 and 4 to the front..." << endl;
  x.addFront(4);
  x.addFront(3);
  cout << "Adding 3 and 4 successful" << endl;
  x.displayAll();

  //test removing a value from the front
  cout << "Now removing from the front..." << endl;
  x.deleteFront(dummy);
  cout << "Removing " << dummy << " from the front successful" << endl;
  x.displayAll();

  //test removing a value from the rear
  cout << "Now removing from the rear..." << endl;
  x.deleteRear(dummy);
  cout << "Removing " << dummy << " from the rear successful" << endl;
  x.displayAll();

  //test removing ith entry
  x.addFront(2); //to avoid problem
  x.displayAll();
  cout << "Now removing ith entry, i=2" << endl;
  x.deleteIth(2,dummy);
  cout << "Removing " << dummy << " from i=2 successful" << endl;
  x.displayAll();

  //test inserting into ith entry
  cout << "Now inserting 8 into ith entry, i=2" << endl;
  x.addbeforeIth(2,8);
  x.addbeforeIth(3,9);
  cout << "Adding 8 successful" << endl;
  x.displayAll();

  return 0;
}
