#ifndef STATS_C
#define STATS_C

#include <iostream>
#include "Stats.h"

using namespace std;

inline Stats::Stats()
{
    stuWaitTimes = new DoublyLinkedList<int>;
    windIdleTimes = new DoublyLinkedList<int>;
}

inline Stats::~Stats()
{
    delete stuWaitTimes;
    delete windIdleTimes;
}

inline void Stats::addStuTime(int t)
{
    stuWaitTimes->insertFront(t);
}

inline void Stats::addWindTime(int t)
{
    windIdleTimes->insertFront(t);
}

inline int Stats::getOverTen()
{
    int count;
    for(int i = 0; i<stuWaitTimes->getSize();i++)
    {
        if(stuWaitTimes->getPos(i)>=10)
            count++;
    }
    return count;
}

inline int Stats::getOverFive()
{
    int count;
    for(int i = 0; i<windIdleTimes->getSize();i++)
    {
        if(windIdleTimes->getPos(i)>=5)
            count++;
    }
    return count;
}

inline float Stats::getMeanStu()
{
    int sum;
    for(int i = 0; i<stuWaitTimes->getSize();i++)
    {
        sum+=stuWaitTimes->getPos(i);
    }
    float mean;
    mean = sum/(stuWaitTimes->getSize());

    return mean;
}

inline float Stats::getMeanWind()
{
    int sum;
    for(int i = 0; i<windIdleTimes->getSize();i++)
    {
        sum+=windIdleTimes->getPos(i);
    }
    float mean;
    mean = sum/(windIdleTimes->getSize());

    return mean;
}

inline int Stats::getLongestStu()
{
    int longest = 0;
    for(int i = 0; i<stuWaitTimes->getSize();i++)
    {
        if(stuWaitTimes->getPos(i)>longest)
            longest = stuWaitTimes->getPos(i);
    }
    return longest;
}

inline int Stats::getLongestWind()
{
    int longest = 0;
    for(int i = 0; i<windIdleTimes->getSize();i++)
    {
        if(windIdleTimes->getPos(i)>longest)
            longest = windIdleTimes->getPos(i);
    }
    return longest;
}

inline int Stats::getMedianStu()
{
    DoublyLinkedList<int>* temp = new DoublyLinkedList<int>;
    return 0;
}

#endif
