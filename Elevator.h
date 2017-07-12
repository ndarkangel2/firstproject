#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream> 
#include <queue> 
#include <vector>
#include <stdio.h>      
#include <stdlib.h>      
#include <time.h>   
#include <string> 
#include "People.h"
using namespace std;

class Elevator
{
	private:
		// This queue has passenger who are in the elevator
		queue<People> elevator; 
	
		// These queues have passenger who are waiting on each level
		queue<People> Lv1;
		queue<People> Lv2;
		queue<People> Lv3;
		queue<People> Lv4;
		queue<People> Lv5;
	
		int Ttotal = 0;
		int current_Lv = 1;
		int passenger_num = 0;

	public:
		// Constructor
		Elevator() {}

		// Functions
		void Simulate(); // Display the result
		void Generate_passenger();//create randomly people
		queue <People> get_Lv();// Priority
		void go_up();// command to go up
		void go_down();// command to go down
		void pick_up();// function picking up
		void drop_off();// function for drop off 
		void set_data(queue<People> t);// temp queue for people's data
};

#endif
