//
// Created by oham2 on 4/24/2019.
//

#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"

using namespace std;


class Order {
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    Order();
    /*----------------------------------------------------------------------
     Constructs an order.

     Precondition:  None
     Postcondition: Creates an order with default values for data members
     -----------------------------------------------------------------------*/

    Order(const Order& source);
    /*----------------------------------------------------------------------
     Constructs a copy of the order source.

     Precondition:  None
     Postcondition: Creates an order equal to the Order source
     -----------------------------------------------------------------------*/

    Order(Time time, string info);
    /*----------------------------------------------------------------------


     Precondition:  None
     Postcondition: Creates an order with the given order time and information
     -----------------------------------------------------------------------*/

    void depart() throw (logic_error);
    /*----------------------------------------------------------------------


     Precondition:  Order is at the restaurant
     Postcondition: Order is out for delivery
     -----------------------------------------------------------------------*/

    void deliver(Time time) throw (logic_error);
    /*----------------------------------------------------------------------


     Precondition:  Order is out for delivery
     Postcondition: Order is delivered. Time to delivery is recorded
     -----------------------------------------------------------------------*/

    int getMinToDelivery() throw (logic_error);
    /*----------------------------------------------------------------------


     Precondition:  Order is delivered
     Postcondition: Returns the minutes until the order is delivered
                    (i.e., between “order” and “deliver” commands)
     -----------------------------------------------------------------------*/

    string toString();
    /*----------------------------------------------------------------------


     Precondition:  None
     Postcondition: Returns a string containing the order time and info
     -----------------------------------------------------------------------*/

	void setOrderTime(Time t);
		// Pre: t, a Time object representing the time at which the order was placed
		// Post: Sets orderPlaced to t
	void setInfo(string info);
		// Pre: info, a string representing the order info
		// Post: Sets orderInfo to info

private:
    /******** Data Members ********/
    bool atResturant;			// true if the order is at the restaurant, false otherwise
    bool outForDelivery;		// true if the order is out for delivery, false otherwise
    bool delivered;				// true if the order is delivered, false otherwise
    string orderInfo;			// string containing the order's info
    Time orderPlaced;			// Time object representing when the order was placed
    Time takentoDeliver;		// Time object representing the amount of time taken to deliver
};

#endif //ORDER_H
