//Jonah Moon and April Shin
//CSIS 137 Wed Night Class
//Midterm Project
//Step 4
#pragma once
#define SEMESTER_H
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

class Semester
{
	friend ostream& operator<<(ostream&, const Semester&);
	friend istream& operator>>(istream&, Semester&);

	private:
		string semesterName;
		Date startDate;
		Date endDate;

	public:
		Semester(string, Date, Date);
		void setSemesterName(string);
		string getSemesterName() const;

};
