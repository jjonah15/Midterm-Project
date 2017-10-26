#include <iostream>
#include <iomanip>
#include <string>
#include "Course.h"
#include "Date.h"
using namespace std;

ostream& operator<<(ostream& output,const Course& arg)
{
	output << "Course Info:     " << arg.courseNum << "--" << arg.courseName << endl
		<< "# of Units:  " << arg.units << endl << "Course Dates:      " << arg.startDate << " - "
		<< arg.endDate << endl << "Meeting Days: " << arg.meetDays << endl << "Meeting Time:    "
		<< arg.startTime << " - " << arg.endTime << endl << "Daily Duration:   "
		<< arg.endTime - arg.startTime << " hours" << endl;
	return output;
}
Course::Course(string cNum, string cName, string meetD, double numUnits, Date startD, Date endD, Time startT, Time endT)
	:courseNum(cNum), courseName(cName), meetDays(meetD),units(numUnits),startDate(startD),endDate(endD),startTime(startT),
	endTime(endT)
{

}
string Course::getCourseNum() const
{
	return courseNum;
}
string Course::getCourseName()const
{
	return courseName;
}
string Course::getMeetDays()const
{
	return meetDays;
}
double Course::getUnits()const
{
	return units;
}
void Course::getStartDate()const
{
	cout << startDate;
}
void Course::getEndDate()const
{
	cout << endDate;
}
void Course::getStartTime()const
{
	this->startTime.printStandard();
}
void Course::getEndTime()const
{

	this->endTime.printStandard();
}
Course& Course::setCourseNum(string cNum)
{
	courseNum = cNum;
	return *this;
}
Course& Course::setCourseName(string cName)
{
	courseName = cName;
	return *this;
}
Course& Course::setMeetDays(string mDays)
{
	meetDays = mDays;
	return *this;
}
Course& Course::setUnits(double amt)
{
	units = amt;
	return *this;
}

void Course::setStartDate(Date sDate)
{
	startDate = sDate;
}
void Course::setEndDate(Date eDate)
{
	endDate = eDate;
}

void Course::setStartTime(Time sTime)
{
	startTime = sTime;
}
void Course::setEndTime(Time eTime)
{
	endTime = eTime;

}
Course::~Course()
{
	cout << courseName << " has been deleted." << endl;
}