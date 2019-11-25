//
// Created by oham2 on 4/24/2019.
//

#include "Order.h"

using namespace std;

/*-------------------------------Implementation of Order member functions.------------------------------------------*/

//--Definition of Class Constructor
Order::Order()
/*----------------------------------------------------------------------
Constructs an order.

Precondition:  None
Postcondition: Creates an order with default values for data members
-----------------------------------------------------------------------*/
{
	Time placed;
	atResturant = true;
	outForDelivery = false;
	delivered = false;
	orderInfo = "";
	orderPlaced = placed;
}

Order::Order(const Order &source)
/*----------------------------------------------------------------------
Constructs a copy of the order source.

Precondition:  None
Postcondition: Creates an order equal to the Order source
-----------------------------------------------------------------------*/
{
	atResturant = source.atResturant;
	outForDelivery = source.outForDelivery;
	delivered = source.delivered;
	orderInfo = source.orderInfo;
	orderPlaced = source.orderPlaced;
}

Order::Order(Time time, string info)
/*----------------------------------------------------------------------
Precondition:  None
Postcondition: Creates an order with the given order time and information
-----------------------------------------------------------------------*/
{
	atResturant = true;
	outForDelivery = false;
	delivered = false;
	orderInfo = info;
	orderPlaced = time;

}

void Order::depart() throw (logic_error)
/*----------------------------------------------------------------------
Precondition:  Order is at the restaurant
Postcondition: Order is out for delivery
-----------------------------------------------------------------------*/
{
	if (!atResturant) {
		throw logic_error("Order not at resturant");
	}

	atResturant = false;
	outForDelivery = true;
}

void Order::deliver(Time time) throw (logic_error)
/*----------------------------------------------------------------------
Precondition:  Order is out for delivery
Postcondition: Order is delivered. Time to delivery is recorded
-----------------------------------------------------------------------*/
{
	if (!outForDelivery) {
		throw logic_error("Order not out for delivery");
	}

	outForDelivery = false;
	delivered = true;
	takentoDeliver = time;

}

int Order::getMinToDelivery() throw (logic_error)
/*----------------------------------------------------------------------
Precondition:  Order is delivered
Postcondition: Returns the minutes until the order is delivered
(i.e., between “order” and “deliver” commands)
-----------------------------------------------------------------------*/
{
	if (!delivered) {
		throw logic_error("Order not delivered");
	}

	return (takentoDeliver.getTime() - orderPlaced.getTime());
}

string Order::toString()
/*----------------------------------------------------------------------
Precondition:  None
Postcondition: Returns a string containing the order time and info
-----------------------------------------------------------------------*/
{
	string result = "Order " + orderPlaced.toString() + " " + orderInfo;
	return result;

}

void Order::setOrderTime(Time t)
// Pre: t, a Time object representing the time at which the order was placed
// Post: Sets orderPlaced to t
{
	orderPlaced = t;
}

void Order::setInfo(string info)
// Pre: info, a string representing the order info
// Post: Sets orderInfo to info
{
	orderInfo = info;
}