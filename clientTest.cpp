//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project
#include <iostream>
#include <string>
#include "Course.h"
#include "CourseSchedule.h"
#include "Date.h"

using namespace std;

int main()
{
	string userName;
	Semester semName;
	int maxNum;
	char selection = 0;

	cout << "Welcome to Course Schedule program!" << endl << "Please enter your name, the semester, "
		<< "the start date,\nend date, and maximum number of classes you are taking. \nIn the following format "
		<< "John, Fall 09/15/1990-12/16/1990, 3. Press enter after every comma." << endl;
	cin >> userName >> semName >> maxNum;
	CourseSchedule sched(userName, semName, maxNum);

	while (selection != 'q')
	{
		cout << "COURSE ENTRY MENU FOR:   " << sched.getSemesterName() << endl
			<< "-----------------------------------------------" << endl
			<< "1) Enter a new course" << endl
			<< "2) Remove a course" << endl
			<< "3) Print semester schedule" << endl
			<< "q) Quit the program " << endl;
		cin >> selection;
		tolower(selection);
		if (selection == 1)
		{
			Time startT,endT;
			Date startD,endD;
			string cNum, cName, meetDays;
			double units;
			cout << "Please enter the course number, course name, meeting days, \nand number of "
				<< "units the course is worth. Press enter after each input." << endl;
			cin >> cNum >> cName >> meetDays >> units;
			cout << "Please enter the starting time of the class. " << endl;
			cin >> startT;
			cout << "Please enter the ending time of the class." << endl;
			cin >> endT;
			cout << "Please enter the starting date of the class." << endl;
			cin >> startD;
			cout << "Please enter the ending date of the class." << endl;
			cin >> endD;
			Course newCourse(cNum, cName, meetDays, units,startD,endD,startT, endT);
			// wait until add course is done thne add
		}
		else if (selection == 2)
		{

		}
		else if (selection == 3)
		{

		}
	}
	system("PAUSE");
	return 0;
}