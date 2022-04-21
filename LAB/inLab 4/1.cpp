#include <iostream>
using namespace std;

class ClockType
{
public:
    void setTime(int, int, int);
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    ClockType(int, int, int);
    ClockType();

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

// TODO
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
// void ClockType::printTime() const;
void ClockType::incrementHours()
{
    this->hr++;
    if (this->hr >= 24)
    {
        this->hr = 0;
    }
}
void ClockType::incrementSeconds()
{
    this->sec++;

    if (this->sec >= 60)
    {
        this->sec = 0;
        this->incrementMinutes();
    }
}
void ClockType::incrementMinutes()
{
    this->min++;
    if (this->min >= 60)
    {
        this->min = 0;
        this->sec = 0;
        this->incrementHours();
    }
}

ClockType::ClockType(int h, int m, int s)
{
    hr = (h >= 0 && h < 24) ? h : 0;
    min = (m >= 0 && m < 60) ? m : 0;
    sec = (s >= 0 && s < 60) ? s : 0;
}
ClockType::ClockType()
{
    hr = min = sec = 0;
}
int main()
{

    ClockType myClock(5, 2, 30);
    myClock.incrementSeconds();
    myClock.printTime();
}