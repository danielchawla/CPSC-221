/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of move_to_front()
void Queue::move_to_front(const QueueElement & key){
  if (myFront->data == key) return;
	
	Queue::NodePointer pPrev = myFront;
	Queue::NodePointer ptr;

	for (ptr = myFront; ptr != 0; ptr = ptr->next){
	  if(ptr->data == key){
			pPrev->next = ptr->next;
			ptr->next = myFront;
	    myFront = ptr; 
			if(ptr == myBack) myBack = pPrev;

      return;
	  } else {
	    pPrev = ptr;
    }   
	}
}

//--- Definition of merge_two_queues()
void Queue::merge_two_queues( Queue & queue2){

	Queue::NodePointer p1 = myFront;
	Queue::NodePointer p2 = queue2.myFront;

	// cases to handle empty queues
	if ( queue2.empty() ) return; 
	if ( empty() ) {
		myFront = queue2.myFront;
		myBack = queue2.myBack;
		p2 = p2->next;
	} // selecting start point of merged queue
	else if (p1->data >= p2->data){
		myFront = queue2.myFront;	
		p2 = p2->next;
	} else {
		p1 = p1->next;
	}

	Queue::NodePointer pPrev = myFront;
	
	// merges two queues
	while(p2 != 0){
		if(p1 != 0 && p1->data < p2->data){
			pPrev->next = p1;
			pPrev = p1;				
			p1 = p1->next;
		} else {
			pPrev->next = p2;
			pPrev = p2;
			if (p2->next == 0) myBack = p2;
			p2 = p2->next;
		} 	
	}	// end while
	
	//making queue2 empty
	queue2.myFront = 0;
	queue2.myBack = 0;
}










