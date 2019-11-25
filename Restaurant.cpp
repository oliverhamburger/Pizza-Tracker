//
// Created by mhosl on 4/24/2019.
//

#include "Restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant() 
// Pre: 
// Post: Creates a new Restaurant object
{
	totalOrderTime = 0;
}

void Restaurant::addDriver(Driver *driver) 
// Pre: driver, a pointer to a Driver object to be added to the system
// Post: Adds driver to the system
{
    driverList.push_back(driver);
}

void Restaurant::removeDriver(string name)
// Pre: name, a string identifying to a Driver object to be removed to the system
// Post: Removes the driver with name from the system
{
	vector<Driver*>::iterator it = driverList.begin();
	for (; it != driverList.end(); it++) {
		if ((*it)->getName() == name) {
			(*it)->logout();
		}
	}
}

void Restaurant::addOrder(Order *order)
// Pre: order, a pointer to an Order object to be added to the system
// Post: Adds order to the system
{
    cooking.push_back(order);
}

int Restaurant::getDriverIndex(string name) 
// Pre: name, a string containing the name of a driver
// Post: returns the index of the driver in driverList, returns -1 if not found
{
    for(int i = 0; i < driverList.size(); i++)
	{
        if(driverList[i]->getName() == name){
            return i;
        }
    }

    return -1;
}

void Restaurant::cookOrder() throw (logic_error) 
// Pre: There must be orders to be cooked
// Post: Pops the oldest order in the cooking queue and adds it to the departure queue
{
    if(cooking.empty())
		throw logic_error( "No orders to be cooked." );

    departure.push_back( cooking.front() );
    cooking.pop_front();
}

void Restaurant::assignDriver(Time t, string name) throw (logic_error) 
// Pre: t, a Time object representing the current time
//		name, the name of the driver to assign to the order
//		The departure queue must not be empty
// Post: Pops the oldest order from the departure queue and assigns it to a driver
{
	if (departure.empty())
		throw logic_error("No orders to be delivered.");

	Driver* driver = driverList[getDriverIndex(name)];
    Order* toAssign = departure.front();

    departure.pop_front();

    driver->depart( t, toAssign );
}

void Restaurant::status() 
// Pre:
// Post: Prints the status of the orders and logged-in drivers
{

	cout << endl << "RESTAURANT STATUS" << endl;

    cout << "Orders waiting to be cooked:" << endl;
    for(int i = 0; i < cooking.size(); i++){
		cout << "  " << cooking[i]->toString() << endl;
    }

    cout << endl << "Orders waiting to depart:" << endl;
    for(int i = 0; i < departure.size(); i++){
        cout << "  " << departure[i]->toString() << endl;
    }

    cout << endl << "Drivers:" << endl;
    for(int i = 0; i < driverList.size(); i++) {
        if (driverList[i]->isLoggedIn()) {
            cout << driverList[i]->toString() << endl;
        }
    }
    cout << endl;

}

void Restaurant::summary() 
// Pre: 
// Post: Prints summary statistics on the restaurant
{
    int totalDeliveries = 0;
    for(int i = 0; i < driverList.size(); i++){
        totalDeliveries += driverList[i]->getTotalDeliveries();
    }

	cout << endl << "RESTAURANT SUMMARY" << endl;

    cout << "Number of orders completed: " << totalDeliveries << endl;

	cout << "Average time per order: ";
	if (totalDeliveries == 0)
		cout << "N/A" << endl;
	else
		cout << (float)totalOrderTime / (float)totalDeliveries << endl;

    for(int i = 0; i < driverList.size(); i++){
		string averageTimeStr;
		if (driverList[i]->getTotalDeliveries() == 0)
			averageTimeStr = "N/A";
		else
			averageTimeStr = to_string((float)driverList[i]->getTotalMinDelivering() / driverList[i]->getTotalDeliveries());

        cout << "Driver " << driverList[i]->getName() << ":\n";
        cout << "  Number of deliveries completed: " << driverList[i]->getTotalDeliveries() << endl;
		cout << "  Average time per delivery: " << averageTimeStr << endl;
        cout << "  Total driving time: " << driverList[i]->getTotalMinDriving() << endl;
		cout << "  Total tip amount: " << driverList[i]->getTotalTips() << endl;
    }

	cout << endl;
}

void Restaurant::deliver(string name, Time t, float tip)
// Pre: name, a string containing the name of a driver
//		t, a Time object containing the time at which the order was delivered
//		tip, a float representing the tip given to the driver
// Post: The order being delivered by the driver is delivered and the driver receives a tip
{
	Order* currentOrder = driverList[getDriverIndex(name)]->getOrder();
	driverList[ getDriverIndex(name) ]->deliver( t, tip );
	totalOrderTime += currentOrder->getMinToDelivery();
}

void Restaurant::arriveDriver(Time t, string name)
// Pre: t, a Time object representing the current time
//		name, the name of the driver arriving back at the restaurant
// Post: returns the driver back to restaurant
{
	driverList[getDriverIndex(name)]->arrive(t);
}