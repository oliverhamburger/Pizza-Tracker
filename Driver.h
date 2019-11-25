//--------------------------------------------------------------------
//
//  CS120 Final Project                                       Driver.h
// 
//  Class declaration for the Driver class
//
//  Author: Angelo Williams
//  Date:	4/28/19
//
//--------------------------------------------------------------------

#ifndef DRIVER_H
#define DRIVER_H

#include <string.h>
#include "Order.h"
#include "Time.h"

using namespace std;

class Driver {
	public:
		Driver(string driverName = "");
			// Pre: driverName, a string of the driver's name
			// Post: Creates a new Driver object

		void login() throw (logic_error);
			// Pre: Driver is not logged in
			// Post: Logs in the driver
		void logout() throw (logic_error);
			// Pre: Driver is not logged out
			// Post: Logs out the driver

		void depart(Time time, Order* order) throw (logic_error);
			// Pre: Driver is logged in 
			//		Driver is at the restaurant
			// Post: Sets a driver as out for delivery
			//		 Records departure time
		void deliver(Time time, float tip) throw (logic_error);
			// Pre: Driver is deliverying
			//		Tip must be non-negative
			// Post: Sets a driver as returning from delivery
			//		 Updates driver's stats
		void arrive(Time time) throw (logic_error);
			// Pre: Driver is returning from delivery
			// Post: Sets a driver as back at the restaurant
			//		 Updates driver's stats

		string getName();
			// Pre: 
			// Post: Returns the driver's name
		void setName(string newName);
			// Pre: newName, a string
			// Post: Sets the driver's name to newName

		bool isLoggedIn();
			// Pre:
			// Post: Returns true if the driver is logged in, false otherwise
		int getTotalDeliveries();
			// Pre:
			// Post: Returns the total amount of deliveries
		int getTotalMinDelivering();
			// Pre:
			// Post: Returns the total time spent deliverying
		int getTotalMinDriving();
			// Pre:
			// Post: Returns the total amount of time driving
		float getTotalTips();
			// Pre:
			// Post: Returns the total amount of tips earned

		Order* getOrder() throw (logic_error);
			// Pre: Driver is out for delivery
			// Post: Returns the order being delivered
		string toString();
			// Pre: 
			// Post: Returns a string containing the driver's name, login status, and delivery status

	private:
		string name;				// Name of the driver
		bool loggedIn;				// Keeps track of if the driver is logged in
		Order* currentOrder;			// Current order that the driver is delivering
		Time departureTime;			// Time that the driver left for delivery

		int totalDeliveries;		// Total amount of deliveries
		int totalMinDelivering;		// Total amount of time spent delivering
		int totalMinDriving;		// Total amount of time spent driving
		float totalTips;			// Total amount of tips earned

		int driverStatus;			// Keeps track of the driver's current status
									// 0: at restaurant, 1: delivering, 2: driving back to restaurant
};

#endif
