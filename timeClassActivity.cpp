#include "Time.h"
#include <iostream>
using namespace std;

void testTimeAssignment();
void testTimeSimplify();
void timeTestAdd();
void timeTestSubtract();

int main()
{
	//testTimeAssignment();
	//testTimeSimplify();
	//timeTestAdd();
	//timeTestSubtract();
}

void testTimeAssignment()
 {
	Time now(10, 22);
	Time classStart(9, 40);

	cout << now.getHour() << " : " << now.getMin() << endl;
	now = classStart;
	cout << now.getHour() << " : " << now.getMin() << endl;

}

void testTimeSimplify()
{
	Time myTime(36, 61, 61);
	Time myOtherTime(-1, -1, -1);

	cout << myTime.getDay() << " " << myTime.getHour() << 
		" : " << myTime.getMin() << " " << myTime.getSec() << endl;

	myTime.simplify();

	cout << myTime.getDay() << " " << myTime.getHour() <<
		" : " << myTime.getMin() << " " << myTime.getSec() << endl << endl << endl;

	cout << myOtherTime.getDay() << " " << myOtherTime.getHour() <<
		" : " << myOtherTime.getMin() << " " << myOtherTime.getSec() << endl;

	myOtherTime.simplify();

	cout << myOtherTime.getDay() << " " << myOtherTime.getHour() <<
		" : " << myOtherTime.getMin() << " " << myOtherTime.getSec() << endl;



}

void timeTestAdd()
{
	Time now(11, 05);
	Time dinner(18, 30);
	Time later = now + dinner;
	cout << later.getDay() << " " << later.getHour() <<
		" : " << later.getMin() << " " << later.getSec() << endl;
}

void timeTestSubtract()
{
	Time now(11, 05);
	Time dinner(18, 30);
	Time later = dinner - now;
	cout << later.getDay() << " " << later.getHour() <<
		" : " << later.getMin() << " " << later.getSec() << endl;
}

Time Time::operator++()
{
	sec++;
	simplify();
	return *this;
}

Time Time::operator++(int)
{
	Time oldTime = *this;
	sec++;
	simplify();
	return oldTime;
}

Time Time::operator--()
{
	sec--;
	simplify();
	return *this;
}

Time Time::operator--(int)
{
	Time oldTime = *this;
	sec--;
	simplify();
	return oldTime;
}