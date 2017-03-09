/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 

/*
* Deletes the text_item with max freq value in a max_heap
* Precondition: numItems is correct, heap not empty
* Postcondition: if empty, throws error. otherwise decrements numItems
*     and removes text_item with max freq
* Returns: text_item with max freq
*/
text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
	  text_item max = top();
	  data[0] = data[numItems-1];
	  numItems--;
	  // maintains the heap-order property required for a max-heap
	  swap_down(0);
		return max;
	}
}

/*
* Swaps down integer at current index if necessary to preserve
* maximum heap invariant
* Params: i - integer index
*/
void max_heap::swap_down(int i) {	
	// implementation based on Unit 2 notes
  int swap = i;
  int left_child = i*2+1;
  int right_child = left_child+1;
  if( left_child < numItems && data[left_child].freq > data[swap].freq){
    swap = left_child;
  }
  if( right_child < numItems && data[right_child].freq > data[swap].freq){
    swap = right_child;
  }
  if(swap != i){
    text_item tmp = data[i];
    data[i] = data[swap];
    data[swap] = tmp;
    swap_down(swap);
  }
}

/*
* Inserts a text_item into a max_heap
* Precondition: numItems is correct, heap not full
* Postcondition: if full, throws error. otherwise increments numItems
*     and inserts text_item
* Params: text_item with max freq
*/
void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {	
		data[numItems++] = item;
		// maintains the heap-order property required for a max-heap
		swap_up(numItems-1);
	}
}

/*
* Swaps up integer at current index if necessary to preserve
* maximum heap invariant
* Params: i - integer index
*/
void max_heap::swap_up(int i) { 
  // implementation based on Unit 2 notes
  if(i == 0) return;
  int parent = (i-1)/2;
  if(data[i].freq > data[parent].freq){
    text_item tmp = data[i];
    data[i] = data[parent];
    data[parent] = tmp;
    swap_up(parent);
  }
	
}
