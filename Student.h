#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    public:
        Student();
        Student(int windTime, int toa);
        ~Student();

        bool nextTickWind();//bool to return false when time needed runs out
        void nextTickWait();
        int getWaitTime();
        int getWindTime();
        int getTOA();

    private:
        int waitTime;
        int windowTime; //time needed at window
        int timeArrival;

};

#endif
