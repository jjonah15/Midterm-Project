#include <iostream>
using namespace std;

#include "Time.h"
#include "Course.h"
#include "Date.h"
#include "Semester.h"
int main()
{

	//Testing course
	/*
    //Time t(4,30);
	//Time y(5, 30);
	Time t;
	cin >> t;
	Time y;
	cin >> y;

	Date d(1,15,1992);
	Date f(2,15,1992);
	//12/11/2017-01/11/2017
	/*Date d;
	cin >> d;
	Date f;
	cin >> f;

	Course fall("CS 112", "Java", "TTH", 3, d, f, t, y);
	cout << fall << endl;

	cout << t - y << endl;

	cout << fall.getStartDate() << endl << fall.getEndDate() << endl << fall.getStartTime() << endl << fall.getEndTime();
	cout << fall.calcDailyDuration();
	*/

	//Testing Semester
	//input formatting 

	Date d(1, 15, 1992);
	Date f(2, 15, 1992);

	Semester sem("fall" ,d,f);
	//cin >> sem;
	cout << sem;
	sem.setStartDate(sem.getEndDate());
	cout << sem;
	//cout << sem.getEndDate() << endl << sem.getStartDate();
	


	system("PAUSE");
    return 0;

}