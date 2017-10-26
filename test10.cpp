#include <iostream>
using namespace std;

#include "Time.h"
#include "Course.h"
#include "Date.h"
int main()
{
    Time t;
	cin >> t;
	Time y;
	cin >> y;
	Date d;
	//Wint2018 12/11/2017-01/11/2017
	cin >> d;
	Date f;
	cin >> f;
	Course fall("CS 112", "Java", "TTH", 3, d, f, t, y);

	cout << fall;



	system("PAUSE");
    return 0;
}