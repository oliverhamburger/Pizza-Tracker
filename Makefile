CC = g++

objects = Driver.o Order.o Restaurant.o Time.o
leftovers = Driver.h.gch Order.h.gch Restaurant.h.gch Time.h.gch

all: PizzaDeliveryTracker clean

tests: TestTracker clean

PizzaDeliveryTracker: interface.o Driver.o Restaurant.o Order.o Time.o
	$(CC) interface.o Driver.o Restaurant.o Order.o Time.o -o PizzaDeliveryTracker
	rm -f interface.o

interface.o: interface.cpp
	$(CC) -c interface.cpp

Driver.o: Driver.cpp Driver.h
	$(CC) -c Driver.cpp Driver.h

Order.o: Order.cpp Order.h
	$(CC) -c Order.cpp Order.h

Restaurant.o: Restaurant.cpp Restaurant.h
	$(CC) -c Restaurant.cpp Restaurant.h

Time.o: Time.cpp Time.h
	$(CC) -c Time.cpp Time.h

TestTracker: unitTests.cpp Driver.o Restaurant.o Order.o Time.o
	$(CC) unitTests.cpp Driver.o Restaurant.o Order.o Time.o -o TestTracker

clean:
	rm -f ${objects}
	rm -f *.h.gch
