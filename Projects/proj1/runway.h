#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "LQueue.h"

using namespace std;

#ifndef Runway_h
#define Runway_h

class Runway{
	public:
		
		/* Constructors */
		Runway();
    /*-----------------------------------------------------------------------
     Constructs Runway object with params set to default vals.
     
     Precondition:  None.
     Postcondition: Variables for landing time, takeoff time, landing rate, takeoff
						rate, and duration during are initialized to default val of -1.
     -----------------------------------------------------------------------*/
		
		Runway(int landTime, int takeoffTime, int landRate, int takeoffRate, int duration);
		/*-----------------------------------------------------------------------
     Constructs Runway with given params.
     
     Precondition:  Nonnegative integers are inputted for landTime (time it takes
						to land), takeoffTime (time it takes to take off), landRate (num of 
						planes landing per hour), takeoffRate (num of planes taking off per
						hour), and duration (number of minutes to run simulation).
     Postcondition: Runway object is created with properties equal to the
						passed in parameters. 
    -----------------------------------------------------------------------*/

		void simulate();
    /*-----------------------------------------------------------------------
     Starts runway simulation.
     
     Precondition: None.
     Postcondition: Starts simulation. Asks for starting parameters if needed.
     -----------------------------------------------------------------------*/ 
	private:
		// constants
		const bool receiveEmergencyCall = true; // set to false to disable emergency call
		const int minPerHour = 60; 
		
		int landTime;
		int takeoffTime;
		int landRate;
		int takeoffRate;
		int duration;
			
		int landQSize = 0;
		int takeoffQSize = 0;
		int maxLandQ = 0;
		int maxTakeoffQ = 0;
		int totalLand = 0;
		int totalTakeoff = 0;	
		int totalLandWait = 0;
		int totalTakeoffWait = 0;
		int aircraftNum = 1000; // first aircraft has number 1000 
		int runwayBusy = 0; // timer to keep track of runway status. 0 = runway free. 
		

		int emergencyCallTime = 0; // time at which runway receives emergency call
		
		Queue landQ;
		Queue takeoffQ;

		void getParams();
    /*-----------------------------------------------------------------------
     Gets landing time, takeoff time, landing rate, takeoff rate, and duration
		 params from user. 
     
     Precondition:  Runway object created. User inputs nonnegative values. 
     Postcondition: Object's params are set according user input.
     -----------------------------------------------------------------------*/ 


		void generateRequests();
    /*-----------------------------------------------------------------------
     Generates landing request and takeoff request if random number mod 60 is
		 less than runway's respective landing and takeoff rates. 
     
     Precondition:  Landing and takeoff rates, and aircraftNum are nonnegative. 
					Object has valid LQueues landQ and takeoffQ.landQSize and takeoffQSize
					values are accurate for corresponding queues.  
     Postcondition: A plane with different airplane number is added to landing
					and takeoff queue if random number mod 60 is less than respective 
					landing and take off rates. Object counter variables are updated.
					Result printed to screen. Aircraft num increases with each enqueuing.
     -----------------------------------------------------------------------*/ 

		void nextAction();
    /*-----------------------------------------------------------------------
     If runway is free, checks for planes in landQ. If nonempty, lets plane
		 land. If empty, checks for planes in takeoffQ and lets those take off. 
     
     Precondition:  runwayBusy counter is nonnegative. landQ and
					takeoffQ exist. landQSize and takeoffQSize accurately represent 
					corresponding queue size. 
     Postcondition: If runway is free, lets plane land if landQ is nonempty.
					If landQ empty and runway free, lets plane takeoff if takeoffQ is
					nonempty. Action represented by dequeues planes and printing results
					to screen. Increments runwayBusy according to landTime or takeoffTime.
     -----------------------------------------------------------------------*/

		void updateTimers();
    /*-----------------------------------------------------------------------
     Updates total waiting time in queues and updates runwayBusy counter.
     
     Precondition:  runwayBusy, totalLandWait, totalTakeoffWait are nonnegative. 
     Postcondition: If runwayBusy > 0, decrements counter. If landQ and takeoffQ
					are nonempty, increments corresponding counter.
     -----------------------------------------------------------------------*/

		void printStats();
    /*-----------------------------------------------------------------------
     Prints out max lengths of landQ and takeoffQ. Also displays avg wait
		 times in each queues.
     
     Precondition:  None.
     Postcondition: Prints out max lengths of landQ and takeoffQ. Displays avg
					wait times in each queue to 2 decimal places. If total number of
					landings in takeoff are 0, then displays 0 for avg times. 
     -----------------------------------------------------------------------*/

		void emergencyCall();
    /*-----------------------------------------------------------------------
     Notifies user of request from neighboring runway to divest plane landings
		 to simulation's runway. Receives input on number of planes runway can take.
		 Merges that number of planes into takeoffQ. 
     
     Precondition:  Simulation duration greater than 1. 
     Postcondition: Prints emergency request. Ask for users input on number. 
		 			Merges that number of planes into takeoffQ. 
     -----------------------------------------------------------------------*/

		
}; // end of class declarations

#endif
