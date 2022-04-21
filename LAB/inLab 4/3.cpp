#include <bits/stdc++.h>
using namespace std;

class ClockType
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType &) const;
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};
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
bool ClockType::equalTime(const ClockType &clk) const
{
    if (hr == clk.hr && min == clk.min && sec == clk.sec)
    {
        return true;
    }
    return false;
}

int main()
{
    ClockType yourClock;
    ClockType myClock(5, 2, 30);
    if (myClock.equalTime(yourClock))
        cout << "Both times are equal." << endl;
    else
        cout << "The two times are not equal." << endl;
    return 0;
}