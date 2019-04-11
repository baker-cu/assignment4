#ifndef STATS_H
#define STATS_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class Stats
{
    public:
        Stats();
        ~Stats();

        int getOverTen();
        int getMedianStu();//need to sort for this to work
        float getMeanStu();
        int getLongestStu();

        float getMeanWind();
        int getLongestWind();
        int getOverFive();

        void addStuTime(int t);
        void addWindTime(int t);


    private:

        DoublyLinkedList<int>* stuWaitTimes;
        DoublyLinkedList<int>* windIdleTimes;

};

#endif
