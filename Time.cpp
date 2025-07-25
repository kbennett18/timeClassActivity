#include "Time.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Default Constructor
Time::Time() : Time(0, 0, 0, 0) {}

//Constructor1
Time::Time(int d, int h, int m, int s) :
	day(d), hour(h), min(m), sec(s) {

}
//Constructor2
Time::Time(int h, int m, int s) : Time(0, h, m, s) {}

//Constructor3
Time::Time(int h, int m) : Time(0, h, m, 0) {}


//Simplify function takes a time and formats it correctly
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

//
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
//Prefix operator 
Time Time::operator++()
{
	sec++;
	simplify();
	return *this;
}

//Postfix operator adds 1 second ater the call
Time Time::operator++(int)
{
	Time oldTime = *this;
	sec++;
	simplify();
	return oldTime;
}

//Prefix operator subtracts 1 second
Time Time::operator--()
{
	sec--;
	simplify();
	return *this;
}

//Postfix operator subtracts 1 second
Time Time::operator--(int)
{
	Time oldTime = *this;
	sec--;
	simplify();
	return oldTime;
}

//Compares the time attributes
bool Time::operator>(Time& right)
{
	if (this->day > right.day)
		return true;
	else if (this->day == right.day)
		if (this->hour > right.hour)
			return true;
		else if (this->hour == right.hour)
			if (this->min > right.min)
				return true;
			else if (this->min == right.min)
				if (this->sec > right.sec)
					return true;
	return false;

}

bool Time::operator<(Time& right)
{
	if (this->day < right.day)
		return true;
	else if (this->day == right.day)
		if (this->hour < right.hour)
			return true;
		else if (this->hour == right.hour)
			if (this->min < right.min)
				return true;
			else if (this->min == right.min)
				if (this->sec < right.sec)
					return true;
	return false;
}

//Returns a stream object to place the time in the correct format when displayed
std::ostream& operator<<(std::ostream& strm, const Time& obj)
{
	strm << obj.getDay() << " "
		<< obj.getHour() << " : "
		<< obj.getMin() << " "
		<< obj.getSec() << " "
		<< endl;
	return strm;
}

//Returns the time in seconds
Time::operator int()
{
	int totalSeconds = 0;
	totalSeconds =
		sec +
		60 * (min +
			60 * (hour +
				24 * day));
	return totalSeconds;
}

//Getters
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
