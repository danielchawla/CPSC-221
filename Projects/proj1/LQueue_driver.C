/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;

   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2=q1 (via print):\n";
   print(q2); 
   cout << endl;
   
   // custom queues for testing
   Queue q3;
   q3.enqueue(5);
   q3.enqueue(250);
   q3.enqueue(1000);
   cout << "Contents of queue q3 (via print):\n";
   print(q3); 
   cout << endl;

   Queue q4;
   q4.enqueue(1);
   cout << "Contents of queue q4 (via print):\n";
   print(q4); 
   cout << endl;

   Queue q5;
   q5.enqueue(1);
   q5.enqueue(2);
   q5.enqueue(3);
   q5.enqueue(99);
   q5.enqueue(100);
   q5.enqueue(101);
   q5.enqueue(101);
   q5.enqueue(101);
   q5.enqueue(10000);
   cout << "Contents of queue q5 (via print):\n";
   print(q5); 
   cout << endl;

   Queue q6;
   cout << "Contents of queue q6 (should be NULL):\n";
   print(q6); 
   cout << endl;

   Queue q7;
   q7.enqueue(2);
   cout << "Contents of queue q7:\n";
   print(q6); 
   cout << endl;
   
   // testing merging 
   cout << "Contents after merging 7 into 4:\n";
   q4.merge_two_queues(q7);
   print(q4); 
   cout << endl;

   cout << "Contents after merging 5 into 6:\n";
   q6.merge_two_queues(q5);
   print(q6); 
   cout << endl;

   cout << "Contents after merging 3 into 4:\n";
   q4.merge_two_queues(q3);
   print(q4); 
   cout << endl;

   cout << "Contents after merging 4 into 2:\n";
   q2.merge_two_queues(q4);
   print(q2); 
   cout << endl;

   cout << "Contents after merging 6 into 2:\n";
   q2.merge_two_queues(q6);
   print(q2); 
   cout << endl;

   // testing move_to_front 	 
   q2.move_to_front(10000);
   cout << "Contents of queue q2 after moving 10000 to front:\n";
   print(q2); 
   cout << endl;

   q2.move_to_front(49);
   cout << "Contents of queue q2 after moving 49 to front (nothing should happen):\n";
   print(q2); 
   cout << endl;

   q2.move_to_front(10000);
   cout << "Contents of queue q2 after moving 10000 to front again:\n";
   print(q2); 
   cout << endl;

   q2.move_to_front(0);
   cout << "Contents of queue q2 after moving 0 to front (nothing should happen):\n";
   print(q2); 
   cout << endl;

   q2.move_to_front(101);
   cout << "Contents of queue q2 after moving 101 to front:\n";
   print(q2); 
   cout << endl;

   q2.move_to_front(101);
   cout << "Contents of queue q2 after moving 101 to front again (nothing should happen):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2: " << q2.front() << endl;

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();
   //system("PAUSE");
   return 0;
}
