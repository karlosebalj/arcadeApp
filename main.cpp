#include <iostream>
#include <string>
#include <iomanip>

class Time
{
public:
	void Init(int hrs, int min, int sec);
	void displayTime12();
	void displayTime24();

private:
	int _hrs;
	int _min;
	int _sec;
	std::string _timeOfDay;
	std::string _ampm;

};

void Time::Init(int hrs, int min, int sec)
{
	_hrs = hrs;
	_min = min;
	_sec = sec;

}

void Time::displayTime12()
{

	int hrs12 = _hrs;
	if (hrs12 < 12)
	{
		hrs12 += 12;
		_ampm = "am";
		_timeOfDay = "morning";
	}
	else
	{
		hrs12 += -12;
		_ampm = "pm";
		_timeOfDay = "evening";
	}

	std::string _timesOfSeconds;
	if (_sec <= 1)
	{
		_timesOfSeconds = " second";
	}
	else
	{
		_timesOfSeconds = " seconds";
	}
	std::cout << "Display time in 12 hour format: " << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << hrs12 << ":"
		<< std::setw(2) << std::setfill('0') << _min << ":"
		<< std::setw(2) << std::setfill('0') << _sec << " " << _ampm
		<< " - " << hrs12 << " hours, " << _min << " minutes and " << _sec << _timesOfSeconds << " in the " << _timeOfDay << std::endl;
	std::cout << std::endl;
}

void Time::displayTime24()
{
	std::cout << "Display time in 24 hour format: " << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << _hrs << ":"
		<< std::setw(2) << std::setfill('0') << _min << ":"
		<< std::setw(2) << std::setfill('0') << _sec << std::endl;
	std::cout << std::endl;
}


int main()
{

	Time time;
	time.Init(00, 10, 01);
	time.displayTime12();
	time.displayTime24();

	time.Init(22, 10, 05);
	time.displayTime12();
	time.displayTime24();
	system("pause");
}

