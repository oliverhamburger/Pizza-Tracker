#include <sstream>
#include <string>
#include <vector>

#include "Restaurant.h"
#include "Order.h"
#include "Driver.h"
#include "Time.h"

void help();
void login(Driver* driver, Restaurant &restaurant);
void logout(string name, Restaurant &restaurant);
void order(Time &time, Restaurant &restaurant, string info);
void serve(Restaurant &restaurant);
void depart(Time &time, Restaurant &restaurant, string name);
void deliver(Time &time, Restaurant &restaurant, string name, float tip);
void arrive(Time &time, Restaurant &restaurant, string name);
void status(Restaurant &restaurant);
void summary(Restaurant &restaurant);

int main(){
	help();

    string cmd;                 // Input command
    Restaurant restaurant;
    int maxWords = 10;
    bool done = false;
    do
    {
        // Reads command an puts string of words into vector to be analysed
        char temp[100] = {0};
        vector<string> words;

		cout << "Enter a command: ";
        cin.getline(temp, 100);
        string in(temp);

        char *token = strtok(temp, " ");
        while (token != NULL)
        {
            words.push_back(token);
            token = strtok(NULL, " ");
        }

        //analyse commands
		if (words[0] == "login") {
			Driver* driver = new Driver;
			driver->setName(words[1]);
			login(driver, restaurant);
		}
		else if (words[0] == "logout") {
			logout(words[1], restaurant);
		}
		else if (words[0] == "order")
		{
			string T = words[1];
			int i = T.find(":");

			string hour = T.substr(0, i);
			string min = T.substr(i + 1, 2);
			int H = stoi(hour);
			int M = stoi(min);
			Time time(H, M);

			string infoString = "";
			vector<string>::iterator it = words.begin();
			it += 2;
			infoString += *it;
			it++;
			while (it != words.end()) {
				infoString += " " + *it;
				it++;
			}

			order(time, restaurant, infoString);
		}
		else if (words[0] == "serve") {
			serve(restaurant);
		}
		else if (words[0] == "depart") {
			string T = words[1];
			int i = T.find(":");

			string hour = T.substr(0, i);
			string min = T.substr(i + 1, 2);
			int H = stoi(hour);
			int M = stoi(min);
			Time time(H, M);

			depart(time, restaurant, words[2]);
		}
		else if (words[0] == "deliver") {
			string T = words[1];
			int i = T.find(":");

			string hour = T.substr(0, i);
			string min = T.substr(i+1, 2);
			int H = stoi(hour);
			int M = stoi(min);
			Time time(H, M);

			deliver(time, restaurant, words[2], stof(words[3]));
		}
		else if (words[0] == "arrive") {
			string T = words[1];
			int i = T.find(":");

			string hour = T.substr(0, i);
			string min = T.substr(i + 1, 2);
			int H = stoi(hour);
			int M = stoi(min);
			Time time(H, M);

			arrive(time, restaurant, words[2]);
		}
		else if (words[0] == "status") {
			status(restaurant);
		}
		else if (words[0] == "summary") {
			summary(restaurant);
		}else if(words[0] == "help"){
			help();
		}else if (words[0] == "quit"){
			done = true;
		}else{
            cout << "Unknown command" << endl;
		}



    }
    while ( !done);

    if( !cin ) {
        cout << "Unknown command" << endl;
    }

    return 0;
}

void help() {
	cout << endl << "   LIST OF COMMANDS" << endl;
	cout << "   ================" << endl;
	cout << "   login DRIVER			  logs in a driver with name DRIVER" << endl;
	cout << "   logout DRIVER		  logs out a driver with name DRIVER" << endl;
	cout << "   order TIME INFO		  adds a new order at time TIME with order info INFO" << endl;
	cout << "   serve TIME			  puts an order to the oven" << endl;
	cout << "   depart TIME DRIVER		  assigns a cooked pizza to DRIVER to leave at TIME" << endl;
	cout << "   deliver TIME DRIVER TIP	  completes DRIVER's delivery at TIME with TIP" << endl;
	cout << "   arrive TIME DRIVER		  marks DRIVER as returning to the restaurant at TIME" << endl;
	cout << "   status			  prints the status of the restaurant" << endl;
	cout << "   summary			  prints a summary of the restaurant" << endl;
	cout << "   help				  prints this list of commands" << endl;
	cout << "   quit				  quits this program" << endl << endl;
}

void login(Driver* driver, Restaurant &restaurant){
	driver->login();
	restaurant.addDriver(driver);
}

void logout(string name, Restaurant &restaurant){
	restaurant.removeDriver(name);
}

void order(Time &time, Restaurant &restaurant, string info){
	Order* order = new Order;
	order->setOrderTime(time);
	order->setInfo(info);

    restaurant.addOrder(order);
}

void serve(Restaurant &restaurant){
    restaurant.cookOrder();
}

void depart(Time &time, Restaurant &restaurant, string name){
    restaurant.assignDriver(time, name);
}

void deliver(Time &time, Restaurant &restaurant, string name, float tip){
    restaurant.deliver(name, time, tip);
}

void arrive(Time &time, Restaurant &restaurant, string name){
    restaurant.arriveDriver(time, name);
}

void status(Restaurant &restaurant){
    restaurant.status();
}

void summary(Restaurant &restaurant){
    restaurant.summary();
}


/*
login Bev
order 18:00 1 mushroom to 123 Holden Hall
order 18:02 4 spinach to 100 Liberty St
login Abe
serve 18:20
depart 18:20 Abe
serve 18:28
deliver 18:30 Abe 2.00
order 18:30 1 cheese 1 sausage to 1000 Beall Ave
depart 18:31 Bev
arrive 18:40 Abe
logout Abe
status
summary
quit

*/
