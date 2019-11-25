//
// Created by mhosl on 4/24/2019.
//

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>
#include <queue>
#include <stdexcept>
#include "Order.h"
#include "Driver.h"
#include "Time.h"

using namespace std;

class Restaurant {
    private:
        deque<Order*> cooking;				// Queue containing order to be cooked
        deque<Order*> departure;				// Queue containing orders to be delivered
        vector<Driver*> driverList;			// Vector containing the drivers

		int totalOrderTime;

        int getDriverIndex( string name );
			// Pre: name, a string containing the name of a driver
			// Post: returns the index of the driver in driverList, returns -1 if not found

    public:
        Restaurant();
			// Pre: 
			// Post: Creates a new Restaurant object

        void addDriver(Driver* driver);
			// Pre: driver, a pointer to a Driver object to be added to the system
			// Post: Adds driver to the system
		void removeDriver(string name);
			// Pre: name, a string identifying to a Driver object to be removed to the system
			// Post: Removes the driver with name from the system
        void addOrder(Order* order);
			// Pre: order, a pointer to an Order object to be added to the system
			// Post: Adds order to the system

        void cookOrder() throw (logic_error);
			// Pre: There must be orders to be cooked
			// Post: Pops the oldest order in the cooking queue and adds it to the departure queue
        void assignDriver( Time t, string name) throw (logic_error);
			// Pre: t, a Time object representing the current time
			//		name, the name of the driver to assign to the order
			//		The departure queue must not be empty
			//		The assigned driver cannot be already on a delivery
			// Post: Pops the oldest order from the departure queue and assigns it to a driver

        void status();
			// Pre:
			// Post: Prints the status of the orders and logged-in drivers
        void summary();
			// Pre: 
			// Post: Prints summary statistics on the restaurant

		void deliver(string name, Time t, float tip);
			// Pre: name, a string containing the name of a driver
			//		t, a Time object containing the time at which the order was delivered
			//		tip, a float representing the tip given to the driver
			// Post: The order being delivered by the driver is delivered and the driver receives a tip

		void arriveDriver(Time t, string name);
			// Pre: t, a Time object representing the current time
			//		name, the name of the driver arriving back at the restaurant
			// Post: returns the driver back to restaurant
};


#endif //RESTAURANT_H
