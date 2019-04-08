#ifndef STUDENT_C
#define STUDENT_C

#include <iostream>
#include "Student.h"

using namespace std;

inline Student::Student()
{
    waitTime = 0;
    windowTime = 1;
}

inline Student::Student(int windTime, int toa)
{
    waitTime = 0;
    windowTime = windTime;
    timeArrival = toa;
}

inline Student::~Student()
{
    waitTime = 0;
    windowTime = 0;
}

inline bool Student::nextTickWind()
{
    windowTime--;

    if(windowTime == 0)
        return false;
    else
        return true;
}

inline void Student::nextTickWait()
{
    waitTime++;
}

inline int Student::getWaitTime()
{
    return waitTime;
}

inline int Student::getTOA()
{
    return (timeArrival);
}

#endif
