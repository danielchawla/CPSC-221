Project Num: 1
StudentID: 174-141-46 (Worked on project by myself).
Ugrad login: x8q0b

Description: 

Implemented 2 functions in LQueue.C and created runway simulation in their entirety as instructed. Code compiles and works as expected on ugrad servers. 

To compile LQueue_driver:
$ make
To run:
$ ./LQueue_driver

To compile Runway:
$ make runway
To run:
./runway

Notes: 

Code is best read with Tab Width set to 2.

Test cases are run by default for LQueue.C in LQueue_driver. 
To test runway.C, uncomment test cases in runway.C’s main function and comment out normal operations section.

For fun, I added functionality to handle emergency situation where plane crash occurs on nearby runway and nearby runway requests to redirect their plane landings to this runway. User can select number of planes to allow to land. Those plans will then merge to this runways landing queue using “merge_two_queues()”. To disable this, set const bool receiveEmergencyCall = false in runway.H.

Assumptions:
1. Inputs are nonempty.
2. Inputs are nonnegative integers for ./runway

File descriptions:
LQueue.h - header for LQueue.
LQueue.C - contains LQueue implementation.
LQueue_driver.C - driver with main function. contains test cases.
Makefile - makefile for runway and LQueue.
runway.h - runway simulation header.
runway.C - runway simulation implementation. contains main function and test cases.

