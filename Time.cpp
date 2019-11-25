#include "Time.h"

using namespace std;


/*-------------------------------Implementation of Timer member functions.------------------------------------------*/

Time::Time()
/*----------------------------------------------------------------------
Constructs a Timer
Precondition:  None
Postcondition: Creates a time with default values for data members
-----------------------------------------------------------------------*/
{
	min = 0;
}

Time::Time(int h, int m) throw (logic_error)
/*----------------------------------------------------------------------
Precondition:  0 <= hour <= 23 and 0 <= min <= 59
Postcondition: Creates a time with the given hour and minute
-----------------------------------------------------------------------*/
{
	if (h > 24 || h < 0 || m < 0 || m > 60) {
		throw logic_error("Invalid time");
	}

	min = (h * 60) + m;
}

int Time::elapsedMin(Time t1, Time t2)
/*----------------------------------------------------------------------
Precondition:  None
Postcondition: Returns the difference in minutes between t1 and t2
Assumes t2 is between 00:00 and 23:59 hours after t1
Returns time in minutes
-----------------------------------------------------------------------*/
{
	return (t2.min - t1.min);
}

int Time::getTime() const
/*----------------------------------------------------------------------
Precondition:  None
Postcondition: Returns the time in minutes
-----------------------------------------------------------------------*/
{
	return min;
}

string Time::toString()
/*----------------------------------------------------------------------
Precondition:  None
Postcondition: Returns a string containing the hour and minute
(e.g., “13:01”)
-----------------------------------------------------------------------*/
{
	int finalHour = min / 60;
	int finalMin = min % 60;

	string minStr;
	if (finalMin < 10)
		minStr = "0" + to_string(finalMin);
	else
		minStr = to_string(finalMin);

	string hour = to_string(finalHour) + ":" + minStr;
	return hour;
}