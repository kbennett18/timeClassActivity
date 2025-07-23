#include "Time.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Time::Time() : Time(0, 0, 0, 0) {}

Time::Time(int d, int h, int m, int s) :
	day(d), hour(h), min(m), sec(s) {

}

Time::Time(int h, int m, int s) : Time(0, h, m, s) {}

Time::Time(int h, int m) : Time(0, h, m, 0) {}

void Time::simplify()
{
	if (sec >= 60)
	{
		min += sec / 60;
		sec = sec % 60;
	}
	if (sec < 0)
	{
		min -= ((abs(sec) / 60) + 1);
		sec = 60 - (abs(sec)) % 60;
	}
	if (min >= 60)
	{
		hour += min / 60;
		min = min % 60;
	}
	if (min < 0)
	{
		hour -= ((abs(min) / 60) + 1);
		min = 60 - (abs(min)) % 60;
	}
	if (hour >= 24)
	{
		day += hour / 24;
		hour = hour % 24;
	}
	if (hour < 0)
	{
		day -= ((abs(hour) / 24) + 1);
		hour = 24 - (abs(hour)) % 24;
	}
}

Time Time::operator+(Time& right)
{
	Time tempTime;
	tempTime.day = this->day + right.day;
	tempTime.hour = this->hour + right.hour;
	tempTime.min = this->min + right.min;
	tempTime.sec = this->sec + right.sec;
	tempTime.simplify();
	return tempTime;
}

Time Time::operator-(Time& right)
{
	Time tempTime;
	tempTime.day = this->day - right.day;
	tempTime.hour = this->hour - right.hour;
	tempTime.min = this->min - right.min;
	tempTime.sec = this->sec - right.sec;
	tempTime.simplify();
	return tempTime;
}

int Time::getDay() const
{
	return day;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMin() const
{
	return min;
}

int Time::getSec() const
{
	return sec;
}
