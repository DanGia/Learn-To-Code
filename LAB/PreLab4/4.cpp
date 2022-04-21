#include <iostream>
using namespace std;
class ClockType
{
public:
    ClockType()
    {
        hr = min = sec = 0;
    }

    void setTime(int, int, int);
    void printTime() const;

private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";
    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

void ClockType::setTime(int hr, int min, int sec)
{
    if (hr >= 24 or hr < 0)
        hr = 0;
    if (min >= 60 or min < 0)
        min = 0;
    if (sec >= 60 or sec < 0)
        sec = 0;
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}
int main()
{
    ClockType myClock;
    myClock.setTime(5, 4, 30);
    myClock.printTime();
    return 0;
}