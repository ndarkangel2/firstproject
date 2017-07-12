#include <iostream> 
#include <stdio.h>      
#include <stdlib.h>      
#include <string> 
#include <time.h>
#include "Elevator.h"
using namespace std;

void Elevator::Simulate()
{	
	Generate_passenger();

	bool is_highest = false;
	cout << endl;
	cout << "The elevator started operating......" << endl;

	// Operation loop of the elevator ( run until there is no passenger left to serve )
	while (passenger_num > 0) {
		drop_off();
		pick_up();
		
		// Base Cases
		if (current_Lv == 1) { is_highest = false; }
		if (current_Lv == 5) { is_highest = true; }

		// Elevator operation
		if (current_Lv < 5 && is_highest == false) { go_up(); }
		else { go_down(); }
	}
}

// Generate passengers and push them into different queue based on where they request the elevator
void Elevator::Generate_passenger()
{
	passenger_num = (rand() % 15) + 1; // Generate passengers ( full capacity: 15 people)
	char name = 'A';
	cout << "NUMBER OF PASSENGER: " << passenger_num << endl;
	for (int i = 1; i <= passenger_num; i++) {
		People p;
		p.set_name(name);
		p.print_info();
		name++;
		switch (p.get_start_Lv()) {
		case 1:
			Lv1.push(p);
			break;
		case 2:
			Lv2.push(p);
			break;
		case 3:
			Lv3.push(p);
			break;
		case 4:
			Lv4.push(p);
			break;
		default:
			Lv5.push(p);
		}
	}
}

// Get current queue of current level
queue<People> Elevator::get_Lv()
{
	switch (current_Lv){
		case 1:
			return Lv1;
			break;
		case 2:
			return Lv2;
			break;
		case 3:
			return Lv3;
			break;
		case 4:
			return Lv4;
			break;
		default:
			return Lv5;
	}
}

void Elevator::go_up()
{
	Ttotal += 30; // It takes 30 sec to go through each level
	current_Lv += 1;
}

void Elevator::go_down()
{
	Ttotal += 30; // It takes 30 sec to go through each level
	current_Lv -= 1;
}

void Elevator::pick_up()
{
	queue <People> Lv = get_Lv();
	if (!Lv.empty()) {
		queue<People> temp; // Used to store passenger who hasn't requested ( still stay in the queue)
		int Tdrop = 0;
		while (!Lv.empty()) {
			// Check request time to pick up passenger ( passenger will not be picked up if the 
			// request time is bigger than the total time (they heaven't come yet))
			if (Lv.front().get_Trequest() <= Ttotal) { 
				cout << endl;
				cout << "        Current level: " << current_Lv << endl;
				cout << "Picked up passenger " << Lv.front().get_name() << " at time: " << Ttotal + Tdrop << endl;
				Lv.front().set_Twaited(Ttotal - Lv.front().get_Trequest()); // Set passenger's waited time ( How long he/she waited )
				cout << "Passenger " << Lv.front().get_name() << " waited: " << Lv.front().get_Twaited() << " sec" << endl;
				elevator.push(Lv.front());
				Lv.pop();
				set_data(Lv);
				//cout << "Num of passenger still in Lv" << current_Lv << ": " << Lv.size() << endl;
				cout << "Number of passenger in elevator: " << elevator.size() << endl;
				cout << endl;
				Tdrop += 5; // Add 5 second per picked up passenger
			}
			else {
				temp.push(Lv.front());
				Lv.pop();
			}
		}
		if (!temp.empty()) { // // Return passengers that still stay in the queue
			Lv = temp;
			set_data(Lv);
		}
		Ttotal += Tdrop;
	}
}

void Elevator::drop_off()
{
	if (!elevator.empty()) {
		queue<People> temp; // Used to store passenger who does not go to this level ( still stay in elevator)
		int Tdrop = 0;
		while (!elevator.empty()) {
			if (elevator.front().get_end_Lv() == current_Lv) { // Check end level to drop passengers
				cout << endl;
				cout << "        Current level: " << current_Lv << endl;
				cout << "Dropped off passenger " << elevator.front().get_name() << " at time: " << Ttotal + Tdrop << endl;
				elevator.pop();
				cout << "Number of passenger in elevator" << ": " << elevator.size() << endl;
				cout << endl;
				passenger_num --;
				Tdrop += 5; // Add 5 second per dropped off passenger
			}
			else {
				temp.push(elevator.front());
				elevator.pop();
			}
		}
		if (!temp.empty()) { elevator = temp; } // Return passengers that still stay in the elevator
		Ttotal += Tdrop;
	}
}

// Set new data from queue t to the current level queue
void Elevator::set_data(queue<People> t)
{
	switch (current_Lv) {
	case 1:
		Lv1 = t;
		break;
	case 2:
		Lv2 = t;
		break;
	case 3:
		Lv3 = t;
		break;
	case 4:
		Lv4 = t;
		break;
	default:
		Lv5 = t;
	}

}

