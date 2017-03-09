
#include "runway.h"

int main(void){
	//normal runway operations
	Runway runway;
	runway.simulate();
	
	//Test cases. Uncomment to run.  
	//Runway runway1(0,0,0,0,0);
	//runway1.simulate();
	//Runway runway2(0,1,40,40,0);
	//runway2.simulate();
	//Runway runway3(10,0,0,40,10);
	//runway3.simulate();
	//Runway runway4(10,10,5,0,30);
	//runway4.simulate();
 	//Runway runway5(4,3,15,60,10);
	//runway5.simulate();
 	//Runway runway6(14,3,80,100,10);
	//runway6.simulate();

}

// Constructor 
Runway::Runway(){
	landTime = takeoffTime = landRate = takeoffRate = duration = -1; // default value
}

// Constructor that accepts parameters
Runway::Runway(int landTime, int takeoffTime, int landRate, int takeoffRate, int duration){
	this->landTime = landTime;
	this->takeoffTime = takeoffTime;
	this->landRate = landRate;
	this->takeoffRate = takeoffRate;
	this->duration = duration;
}

// run simulation
void Runway::simulate(){
	srand (time(NULL));
	cout << "\nBEGINNING SIMULATION \n" << endl;	
	if(duration == -1) getParams(); 

	emergencyCallTime = duration / 2; // emergency call received halfway through simulation
	
	// Main loops. Executes when time < simulation duration or plane queues are not empty or the runway is busy.
	for(int time = 0; time < duration || ! landQ.empty() || ! takeoffQ.empty() || runwayBusy; time++){
		cout << "Time = " << time+1 << endl; // starting at time = 1
		if(time == emergencyCallTime && receiveEmergencyCall){
			emergencyCall();
		}
		if (time == duration){
			cout <<	"\n *** SIMULATION TIME REACHED. NO NEW TAKEOFFS OR LANDINGS GENERATED *** \n" << endl;	
		} 
		updateTimers();					
		if (time < duration ) generateRequests();
		nextAction();
	} // end for loop

	printStats();
	cout << "END OF SIMULATION" << endl;
}



// Get parameters from user
void Runway::getParams(){
	cout << "Time for a plane to land (in minutes): "; 
	cin >> landTime;
	cout << "Time for a plane to takeoff (in minutes): ";
	cin >> takeoffTime;
	cout << "Landing rate (planes per hour): ";
	cin >> landRate;
	cout << "Takeoff rate (planes per hour): ";
	cin >> takeoffRate;
  	cout << "How long to run the simulation (in minutes): ";
	cin >> duration;
}

// generates landing and takeoff request
void Runway::generateRequests(){

	if( ( rand() % minPerHour ) < landRate){
		landQ.enqueue(aircraftNum);
		landQSize++;
		cout << "Plane " << aircraftNum << " wants to land. Added to landing queue. " << landQSize << " in queue." << endl;
		totalLand++; // since all these planes will land before program terminates
		aircraftNum+= 1; 
		
		if(landQSize > maxLandQ) maxLandQ = landQSize;
	}
	if( ( rand() % minPerHour ) < takeoffRate){
		takeoffQ.enqueue(aircraftNum);
		takeoffQSize++;
		cout << "Plane " << aircraftNum << " wants to take off. Added to takeoff queue. " << takeoffQSize << " in queue." << endl;
		totalTakeoff++; // since all these planes will takeoff before program terminates 
		aircraftNum+= 1; 
		
		if(takeoffQSize > maxTakeoffQ) maxTakeoffQ = takeoffQSize;
	}
}


// processes next landing and take off requests
void Runway::nextAction(){
	if(!runwayBusy){ // runway is free
		if(! landQ.empty() ){
			int planeNum = landQ.front();
			landQ.dequeue();
			landQSize--;
			cout << "Landing: Plane " << planeNum << ". Total in queue: " << landQSize << endl;  
			runwayBusy = landTime;		
		} else if (! takeoffQ.empty() ) {
			int planeNum = takeoffQ.front();
			takeoffQ.dequeue();
			takeoffQSize--;
			cout << "Taking off: Plane " << planeNum << ". Total in queue: " << takeoffQSize << endl; 
			runwayBusy = takeoffTime;
		}
	}
}

// updates timers
void Runway::updateTimers(){
	if(runwayBusy > 0) runwayBusy --;
	if(runwayBusy == 0) cout << "Runway clear!" << endl;		
	if(! landQ.empty() ) totalLandWait++;
	if(! takeoffQ.empty() ) totalTakeoffWait++;
}


// prints out stats
void Runway::printStats(){
	double avgLandTime = 0;
	double avgTakeoffTime = 0;
	if (totalLand) avgLandTime = (double) totalLandWait / totalLand;
	if (totalTakeoff) avgTakeoffTime = (double) totalTakeoffWait / totalTakeoff;
	cout << "\nRUNWAY STATS\n" << endl;	
	cout << "Maximum number of planes in landing queue was: " << maxLandQ << endl;
	cout << "Maximum number of planes in takeoff queue was: " << maxTakeoffQ << endl;
	// print avg times to 2 decimal places
	cout << "Average minutes spent waiting to land: " << setprecision(2) << fixed << avgLandTime << endl;
	cout << "Average minutes spent waiting to takeoff: " << setprecision(2) << fixed << avgTakeoffTime << endl;
}


// extra functionality simulating emergency call
void Runway::emergencyCall(){
	int emergencyPlaneLandings = 0;
	Queue emergencyLandings;
	cout << "\n *** Airplane crash on neighboring runway. Received request to land their planes on this runway." << endl;
	cout << "*** How many planes can they redirect to this runway? Enter number: " << endl;
	cin >> emergencyPlaneLandings; 
	landQSize += emergencyPlaneLandings;
	while (emergencyPlaneLandings > 0) {
		emergencyLandings.enqueue(aircraftNum);
		aircraftNum++;
		emergencyPlaneLandings--;
	}
	landQ.merge_two_queues(emergencyLandings);
	cout << "Merge complete. " << landQSize << " in landing queue. Resuming operations." << endl;
}



