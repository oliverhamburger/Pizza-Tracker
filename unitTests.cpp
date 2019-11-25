//--------------------------------------------------------------------
//
//  CS120 Final Project                                  unitTests.cpp
// 
//  Unit tests for the Restaurant ADT
//
//  Author: Angelo Williams
//  Date:	4/30/19
//
//--------------------------------------------------------------------

#include "catch.h"

#include "Restaurant.h"
#include "Order.h"
#include "Driver.h"
#include "Time.h"

//--------------------------------------------------------------------
//
//	Set up test variables
//
//--------------------------------------------------------------------

Time t1;
Time t2 = Time(2, 0);
Time t3 = Time(20, 45);

Order* o1 = new Order;
Order* o2 = new Order;
Order* o3 = new Order;

Driver* d1 = new Driver;
Driver* d2 = new Driver;

Restaurant r1;

//--------------------------------------------------------------------
//
//	Testing for Time class
//
//--------------------------------------------------------------------

TEST_CASE("Time.elapsedMin") {
	o2->setOrderTime(t2);
	o2->setInfo("more info");

	o3->setOrderTime(t2);
	o3->setInfo("more info");

	d1->setName("Foo");
	d2->setName("Bar");

	REQUIRE(t1.elapsedMin(t1, t2) == 120);
	REQUIRE(t1.elapsedMin(t1, t3) == 1245);
	REQUIRE(t1.elapsedMin(t2, t3) == 1125);
}

TEST_CASE("Time.toString") {
	REQUIRE(t1.toString() == "0:00");
	REQUIRE(t2.toString() == "2:00");
	REQUIRE(t3.toString() == "20:45");
}

TEST_CASE("Time.getTime") {
	REQUIRE(t1.getTime() == 0);
	REQUIRE(t2.getTime() == 120);
	REQUIRE(t3.getTime() == 1245);
}

//--------------------------------------------------------------------
//
//	Testing for Order class
//
//--------------------------------------------------------------------

TEST_CASE("Order.getMinToDelivery") {
	o1->depart();
	o1->deliver(t2);

	REQUIRE(o1->getMinToDelivery() == 120);
}

TEST_CASE("Order.toString") {
	REQUIRE(o2->toString() == "Order 2:00 more info");
}

//--------------------------------------------------------------------
//
//	Testing for Driver class
//
//--------------------------------------------------------------------

TEST_CASE("Driver.getName") {
	REQUIRE(d1->getName() == "Foo");
}

TEST_CASE("Driver.isLoggedIn") {
	d1->login();
	REQUIRE(d1->isLoggedIn() == true);
	REQUIRE(d2->isLoggedIn() == false);
}

TEST_CASE("Driver.getTotalDeliveries") {
	d1->depart(t1, o2);
	d1->deliver(t2, 2);
	d1->arrive(Time(3, 0));

	REQUIRE(d1->getTotalDeliveries() == 1);
	REQUIRE(d2->getTotalDeliveries() == 0);
}

TEST_CASE("Driver.getTotalMinDelivering") {
	REQUIRE(d1->getTotalMinDelivering() == 120);
	REQUIRE(d2->getTotalMinDelivering() == 0);
}

TEST_CASE("Driver.getTotalMinDriving") {
	REQUIRE(d1->getTotalMinDriving() == 180);
	REQUIRE(d2->getTotalMinDriving() == 0);
}

TEST_CASE("Driver.getTotalTips") {
	REQUIRE((int)d1->getTotalTips() == 2);
	REQUIRE((int)d2->getTotalTips() == 0);
}

TEST_CASE("Driver.getOrder") {
	d1->depart(Time(4, 0), o3);
	REQUIRE(d1->getOrder()->toString() == o3->toString());
}

//--------------------------------------------------------------------
//
//	Testing for Restaurant class
//
//--------------------------------------------------------------------

// N/A
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Other test cases are based on terminal output, so they must be checked manually.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
