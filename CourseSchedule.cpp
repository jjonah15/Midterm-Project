//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project
//Step 5

#include "CourseSchedule.h"
#include <iostream>
using namespace std;


CourseSchedule::CourseSchedule(string name, Semester s, int maxNum) : semTerm(s)
{
	setStudentName(name);
	s.setSemesterName(" ");
	maxSize = maxNum;
	setNumCourses(0);
	array = new Course[maxSize];
}

void CourseSchedule::setStudentName(string name)
{
	studentName = name;
}

void CourseSchedule::setNumCourses(int num)
{
	numCourses = num;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}

//changed this to return semester& then u can just cout << courseSchedule.getSemesterName()
Semester& CourseSchedule::getSemesterName() const
{
	Semester* ptr = new Semester(semTerm);
	return *ptr;
}
bool CourseSchedule::checkDates(Semester s, Date start, Date end)
{
	return false;
}

void CourseSchedule::AddCourse(Course c)
{

}

ostream& operator<<(ostream& output, const CourseSchedule& info)
{
	return output;
}

CourseSchedule::~CourseSchedule()
{
	delete[] array;
}
