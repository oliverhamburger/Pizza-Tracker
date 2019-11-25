// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <stdexcept>

using namespace std;


class Time {
	public:
		/******** Function Members ********/
		/***** Class constructor *****/
		Time();
		/*----------------------------------------------------------------------
		 Constructs a Timer

		 Precondition:  None
		 Postcondition: Creates a time with default values for data members
		 -----------------------------------------------------------------------*/

		Time(int h, int m) throw (logic_error);
		/*----------------------------------------------------------------------


		 Precondition:  0 <= hour <= 23 and 0 <= min <= 59
		 Postcondition: Creates a time with the given hour and minute
		 -----------------------------------------------------------------------*/

		static int elapsedMin(Time t1, Time t2);
		/*----------------------------------------------------------------------


		 Precondition:  None
		 Postcondition: Returns the difference in minutes between t1 and t2
						Assumes t2 is between 00:00 and 23:59 hours after t1
						Returns time in minutes
		 -----------------------------------------------------------------------*/

		int getTime() const;
		/*----------------------------------------------------------------------


		 Precondition:  None
		 Postcondition: Returns the time in minutes
		 -----------------------------------------------------------------------*/

		string toString();
		/*----------------------------------------------------------------------


		 Precondition:  None
		 Postcondition: Returns a string containing the hour and minute
						(e.g., “13:01”)
		 -----------------------------------------------------------------------*/

	private:
		/******** Data Members ********/
		int min;
};

#endif	// ifndef TIMER_H
