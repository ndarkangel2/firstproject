#ifndef PEOPLE_H
#define PEOPLE_H

#include <stdlib.h>      
#include <string> 
#include <time.h>
using namespace std;

class People
{
	private:
		int start_Lv = 0;
		int end_Lv = 0;
		int Trequest = 0; // The time people request the elevator 
		int Twaited = 0;
		char name;

	public:
		// Constructor
		People() {
			start_Lv = (rand() % 5) + 1;
			end_Lv = (rand() % 5) + 1;
			while (start_Lv == end_Lv) { end_Lv = (rand() % 5) + 1; } // Error check: start level cannot be the same as end level
			if (start_Lv > 1) { Trequest = (rand() % 300) + 1; } // Request time is within 300 sec ( full cycle of the elevator 30 sec/level)
			
		}

		// Functions
		void set_name(char n) { name = n; }
		char get_name() { return name; };
		int get_Trequest() { return Trequest; }
		void set_Twaited(int i) { Twaited += i; }
		int get_Twaited() { return Twaited; }
		int get_start_Lv() { return start_Lv; }
		int get_end_Lv() { return end_Lv; }
		void print_info() {
			cout << "Name: " << name << " " << " Start level: " << start_Lv << " " << " End level: " <<
				end_Lv << " " << " Request time: " << Trequest << endl;
		}

};

#endif

