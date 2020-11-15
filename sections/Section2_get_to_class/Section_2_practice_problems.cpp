#include <iostream>
#include <iomanip>

class Time {
 public:
 void Init(int h, int m, int s);
 void DisplayTwelveHourFormat();
 void DisplayTwentyFourHourFormat();

 private:
  int _hours;
  int _minutes;
  int _seconds;
};

void Time::Init(int h, int m, int s) {
  _hours = h;
  _minutes = m;
  _seconds = s;
}

void Time::DisplayTwelveHourFormat() {
  std::string amOrPm = " am";

  if (_hours > 12) {
    _hours -= 12;
    amOrPm = " pm";
  }
  std::cout << std::setw(2) << std::setfill('0') << _hours << ":"
            << std::setw(2) << std::setfill('0') << _minutes << ":"
            << std::setw(2) << std::setfill('0') << _seconds << amOrPm
            << std::endl;
}

void Time::DisplayTwentyFourHourFormat() {
  if ((_hours < 0 || _hours > 24) && (_minutes < 0 || _minutes > 60) &&
      (_seconds < 0 || _seconds > 60)) {
    std::cout << "Invalid time" << std::endl;
  } else {
    std::cout << std::setw(2) << std::setfill('0') << _hours << ":"
              << std::setw(2) << std::setfill('0') << _minutes << ":"
              << std::setw(2) << std::setfill('0') << _seconds << std::endl;
  }
}

int main() {
  Time time;
  time.Init(12, 10, 01);
  time.DisplayTwentyFourHourFormat();
  time.DisplayTwelveHourFormat();

  Time time2;
  time2.Init(22, 10, 05);
  time2.DisplayTwentyFourHourFormat();
  time2.DisplayTwelveHourFormat();
  return 0;
}