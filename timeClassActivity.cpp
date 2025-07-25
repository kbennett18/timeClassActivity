#include "Time.h"
#include <iostream>
using namespace std;

void testTimeAssignment();
void testTimeSimplify();
void timeTestAdd();
void timeTestSubtract();
void timeTestPlusPlus();
void timeTestRelationalOperator();
void timeTestExtractionOperator();
void timeTestIntegerConversion();

int main()
{
	//testTimeAssignment();
	//testTimeSimplify();
	//timeTestAdd();
	//timeTestSubtract();
	//timeTestPlusPlus();
	//timeTestRelationalOperator();
	//timeTestExtractionOperator();
	//timeTestIntegerConversion();

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

void timeTestPlusPlus()
{
	Time now(11, 24, 59);

	for (int i = 0; i < 100; i++)
	{
		now++;
		cout << now.getDay() << " " << now.getHour() <<
			" : " << now.getMin() << " " << now.getSec() << endl;
	}
}

void timeTestRelationalOperator()
{
	Time now(11, 59);
	Time later(1, 1, 1, 1);

	cout << (now < later) << endl;
	cout << (now > later) << endl;
}

void timeTestExtractionOperator()
{
	Time now(0, 12, 17, 32);
	cout << now;
}

void timeTestIntegerConversion()
{
	Time tomorrowsClass(1, 9, 40, 0);
	cout << static_cast<int>(tomorrowsClass) << endl;
}

