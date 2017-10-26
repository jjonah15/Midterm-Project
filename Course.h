#ifndef COURSE_H
#define COURSE_H
#include "Date.h"
#include "Time.h"
#include <string>
using namespace std;

class Course
{
	friend ostream& operator<<(ostream&, const Course&);
	private:
		string courseNum;
		string courseName;
		string meetDays;
		double units;
		Date startDate;
		Date endDate;
		Time startTime;
		Time endTime;

	public:
		Course(string = "",string = "", string = "", double = 0, Date = Date(), Date = Date(), Time = Time(), Time = Time());
		~Course();
		string getCourseNum() const;
		string getCourseName()const;
		string getMeetDays()const;
		double getUnits()const;
		void getStartDate()const;
		void getEndDate()const;
		void getStartTime()const;
		void getEndTime()const;
		Course& setCourseNum(string);
		Course& setCourseName(string);
		Course& setMeetDays(string);
		Course& setUnits(double);
		void setStartDate(Date);
		void setEndDate(Date);
		void setStartTime(Time);
		void setEndTime(Time);


};
#endif