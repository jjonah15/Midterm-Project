//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project
//Step 5
#pragma once
#define COURSESCHEDULE_H
#include "Course.h"
#include "Semester.h"
#include "Date.h"
#include <iostream>
using namespace std;

class CourseSchedule
{
	friend ostream& operator<<(ostream&, const CourseSchedule&);

private:
	Course *array;  //Jonah, we only need one Course pointer right?
	Semester semTerm;
	string studentName;
	int maxSize;
	int numCourses;

public:
	CourseSchedule(string, Semester, int);  //Please double check this one for me!!!
	void setStudentName(string);
	void setNumCourses(int);
	string getStudentName() const;
	int getNumCourses() const;
	Semester& getSemesterName()const;
	bool checkDates(Semester, Date, Date);
	void AddCourse(Course);
	~CourseSchedule();
};
