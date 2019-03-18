#ifndef CCC_TIME_H
#define CCC_TIME_H

/****************************************************************************
 ** COPYRIGHT (C):    1995 Cay S. Horstmann. All Rights Reserved.
 **
 ** NOTE TO STUDENTS: This file makes use of the functions defined in
 ** the standard header file time.h. It is not important that you understand
 ** these functions.
 **
 ** PROJECT:          Computing Concepts with C++
 ** FILE:             ccc_time.h
 ** PURPOSE:          defines the Time class
 ** VERSION           1.0
 ** PROGRAMMER:       Cay Horstmann (CSH)
 ** START DATE:       4-24-96
 ** UPDATE HISTORY:
 **
 ****************************************************************************/

#line 20 "CCC_TIME.CPP"

#include <time.h>

#line 27 "CCC_TIME.CPP"


class Time
{
public:
	Time(int year, int month, int day, int hour, int min, int sec);
	Time();
    
	int get_year() const;
	int get_month() const;
	int get_day() const;
	int get_hours() const;
	int get_minutes() const;
	int get_seconds() const;
    
	float seconds_from(Time t) const;
	void add_seconds(float);
    
private:
	time_t _time;
};


#endif
