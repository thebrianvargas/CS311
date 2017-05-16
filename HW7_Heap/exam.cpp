#include <iostream>
#include "maxHeap.h"

using namespace std;

int main()
{
  int prob[] = {77,11,62,10,4,48,2,7,8,1,2,3,33,-5,1};
  MaxHeap heap(20);

  for(int i=0; i<15; i++)
    heap.insert(prob[i]);

  heap.insert(76);
  heap.print();

  heap.removeAt(13);
  heap.print();

  heap.removeAt(2);
  heap.print();

  return 0;
}
