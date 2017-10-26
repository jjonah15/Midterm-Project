#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


#include "Time.h"

ostream& operator<<(ostream& output, const Time& arg)
{
	output << ((arg.hour == 0 || arg.hour == 12) ? 12 : arg.hour % 12) << ":"
		<< setfill('0') << setw(2) << arg.minute << (arg.hour < 12 ? " AM" : " PM");
	return output;
}
istream& operator>>(istream& input, Time& arg)
{
	char setting;
	//HH:MM PM
	input >> setw(2)>> arg.hour;
	if (arg.hour < 0 || arg.hour > 12)
	{
		arg.hour = 0;
	}
	input.ignore();
	input >>setw(2)>> arg.minute;
	if (arg.minute < 0 || arg.minute > 60)
	{
		arg.minute = 0;
	}
	input.ignore();
	input >> setw(1) >> setting;
	if (setting == 'P' || setting == 'p')
	{
		if (arg.hour != 12)
		{
			arg.hour += 12;
		}
	}
	if (setting == 'A' || setting == 'a')
	{
		if (arg.hour == 12)
		{
			arg.hour -= 12;
		}
	}
	input.ignore(2);

	return input;
}
//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
 setTime(hour, minute);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
 setHour(hour);
 setMinute(minute);
 return *this; 
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
  return *this;
}  

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
  minute = (m >= 0 && m < 24) ? m : 0;  //validates minute, if valid set to m, else set to 0
  return *this;
} 


/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
     cout << setfill('0') << setw(2) << hour << ":" 
          << setw(2) << minute << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" 
          << setfill ('0') << setw(2) << minute << (hour < 12 ? "AM" : "PM" )<< endl;
}
double Time::operator-(const Time& arg) const
{
	double hour,minute,difference;
	string diff;
	if (this->hour > arg.hour)
	{
		hour = this->hour - arg.hour;
		minute = this->minute - arg.hour;
	}
	else
	{
		hour = arg.hour - this->hour;
		minute = arg.minute - this->minute;
	}
	difference = hour + (minute / 60);
	return difference;
	
}
Time::~Time()
{

}