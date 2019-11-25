//--------------------------------------------------------------------
//
//  CS120 Final Project                                     Driver.cpp
// 
//  Class definitions for the Driver class
//
//  Author: Angelo Williams
//  Date:	4/28/19
//
//--------------------------------------------------------------------

#include "Driver.h"

using namespace std;

Driver::Driver(string driverName) 
// Pre: driverName, a string of the driver's name
// Post: Creates a new Driver object
{
	name = driverName;
	loggedIn = false;

	totalDeliveries = 0;
	totalMinDelivering = 0;
	totalMinDriving = 0;
	totalTips = 0;

	driverStatus = 0;
}

void Driver::login() throw (logic_error)
// Pre: Driver is not logged in
// Post: Logs in the driver
{
	if (loggedIn)
		throw logic_error("Cannot log in an already logged in user.\n");

	loggedIn = true;
}

void Driver::logout() throw (logic_error) 
// Pre: Driver is not logged out
// Post: Logs out the driver
{
	if (!loggedIn)
		throw logic_error("Cannot log out an already logged out user.\n");

	loggedIn = false;
}

void Driver::depart(Time time, Order* order) throw (logic_error) 
// Pre: Driver is logged in 
//		Driver is at the restaurant
// Post: Sets a driver as out for delivery
//		 Records departure time
{
	if (!loggedIn)
		throw logic_error("A driver that is not logged in cannot make a delivery.\n");

	if (driverStatus) 
		throw logic_error("A driver that is not at the restaurant cannot make a delivery.\n");

	departureTime = time;
	currentOrder = order;

	currentOrder->depart();

	driverStatus = 1;
}

void Driver::deliver(Time time, float tip) throw (logic_error) 
// Pre: Driver is deliverying
//		Tip must be non-negative
// Post: Sets a driver as returning from delivery
//		 Updates driver's stats
{
	if (driverStatus != 1)
		throw logic_error("A driver that is not out on a delivery cannot complete a delivery.\n");

	if (tip < 0)
		throw logic_error("A tip cannot be negative.\n");

	totalTips += tip;
	totalDeliveries += 1;
	totalMinDelivering += time.elapsedMin(departureTime, time);
	totalMinDriving += time.elapsedMin(departureTime, time);

	departureTime = time;

	currentOrder->deliver(time);
	currentOrder = nullptr;

	driverStatus = 2;
}	

void Driver::arrive(Time time) throw (logic_error) 
// Pre: Driver is returning from delivery
// Post: Sets a driver as back at the restaurant
//		 Updates driver's stats
{
	if (driverStatus != 2)
		throw logic_error("A driver that is not returning from a delivery cannot arrive at the restaurant.\n");

	totalMinDriving += time.elapsedMin(departureTime, time);
	
	driverStatus = 0;
}

string Driver::getName() 
// Pre: 
// Post: Returns the driver's name
{
	return name;
}

void Driver::setName(string newName)
// Pre: newName, a string
// Post: Sets the driver's name to newName
{
	name = newName;
}

bool Driver::isLoggedIn() 
// Pre:
// Post: Returns true if the driver is logged in, false otherwise
{
	return loggedIn;
}

int Driver::getTotalDeliveries()
// Pre:
// Post: Returns the total amount of deliveries
{
	return totalDeliveries;
}

int Driver::getTotalMinDelivering()
// Pre:
// Post: Returns the total time spent deliverying
{
	return totalMinDelivering;
}

int Driver::getTotalMinDriving()
// Pre:
// Post: Returns the total amount of time driving
{
	return totalMinDriving;
}	

float Driver::getTotalTips() 
// Pre:
// Post: Returns the total amount of tips earned
{
	return totalTips;
}

Order* Driver::getOrder() throw (logic_error) 
// Pre: Driver is out for delivery
// Post: Returns the order being delivered
{
	if (driverStatus == 0)
		throw logic_error("A driver that is not out on a delivery cannot have an order.\n");

	return currentOrder;
}

string Driver::toString() 
// Pre: 
// Post: Returns a string containing the driver's name, login status, and delivery status
{
	string loginStr = (loggedIn ? "Logged in" : "Logged out");

	string driverStatusStr;
	if (driverStatus == 0)
		driverStatusStr = "Currently at the restaurant";
	else if (driverStatus == 1)
		driverStatusStr = "Currently on a delivery. Left at " + departureTime.toString() + "\n" + "    Current order: " + currentOrder->toString();
	else if (driverStatus == 2)
		driverStatusStr = "Currently returning to the restaurant";

	return ("  " + name + "\n    " + loginStr + "\n    " + driverStatusStr);
}
