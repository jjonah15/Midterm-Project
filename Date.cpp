//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project
//Step 2

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;

//initialize the static member
const int Date::days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };


//global friend function (overloaded <<)
ostream& operator<<(ostream &output, const Date &d)
{
	/*static string monthName[13] = { "", "January", "February",
		"March", "April", "May",
		"June", "July", "August",
		"September", "October", "November", "December" }; */

	output << /*monthName[*/d.month/*]*/ << "/" << d.day << "/" << d.year;

	return output;  //allows for cascading calls
}

istream& operator>>(istream &input, Date &d)
{

	input >> setw(2) >> d.month;
	input.ignore();
	input >> setw(2) >> d.day;
	input.ignore();
	input >> setw(4) >> d.year;
	return input;
}

//constructor - default args allow to be default constructor
Date::Date(int m, int d, int y)
{
	setDate(m, d, y);  //don't repeat code
}

void Date::setDate(int mm, int dd, int yy)
{
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

	if (month == 2 && leapYear(year))
	{
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	}
	else
	{
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
	}
}

Date &Date::operator ++()  //overloaded PREFIX increment operator
{
	helpIncrement();  //call private utility function to increment the date
	return *this;  //return reference to CHANGED date object that can be on the left of assignment op
}

//overloaded postfix increment operator
//note dummy integer parameter does not have a name
Date Date::operator ++(int)
{
	Date temp = *this;  //only exists in this function so MUST return a copy
	helpIncrement();  //increment original passed in
	return temp;  //return a copy of original before changes
}

//overloaded += operator to add a specified number of days to the date
const Date &Date::operator +=(int addDays)
{
	for (int i = 0; i < addDays; i++)
	{
		helpIncrement();
	}

	return *this;
}

bool Date::leapYear(int testYear)
{
	if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Date::endOfMonth(int testDay) const
{
	if (month == 2 && leapYear(year))
	{
		if (testDay == 29)
			return true;
		else
			return false;
	}

	else
	{
		if (testDay == days[month])
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}

//this is the private helper function that actually increments the date
void Date::helpIncrement()
{
	//if day is not the end of a month
	if (!endOfMonth(day))
	{
		day++;
	}

	else
	{
		if (month < 12)  //if we're at the end of the month and it's not December (month 12)
		{
			month++;  //go to the first day of the next month
			day = 1;
		}

		else  //it's the last day of december, need to go to january 1 of next year
		{
			year++;
			month = 1;
			day = 1;
		}
	}
}

/*  Need the TIME_H to complete below:

bool Date::operator==(const Date& d) const
{

}

bool Date::operator!=(const Date& d) const
{

}

bool Date::operator<(const Date& d) const
{

}

bool Date::operator>(const Date& d) const
{

}

bool Date::operator<=(const Date& d) const
{

}

bool Date::operator>=(const Date& number) const
{

}

*/