#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    setTime(int hour, int minute, int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;  
    }
}