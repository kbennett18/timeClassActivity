#ifndef Time_h
#define Time_h
#include <iostream>
using namespace std;


class Time
{
private:
	int day;
	int hour;
	int min;
	int sec;
public:
	Time();
	Time(int d, int h, int m, int s);
	Time(int h, int m, int s);
	Time(int h, int m);
	int getDay() const;
	int getHour() const;
	int getMin() const;
	int getSec() const;
	void simplify();
	Time operator+(Time& right);
	Time operator-(Time& right);
	Time operator++();
	Time operator++(int);
	Time operator--();
	Time operator--(int);
};
#endif


