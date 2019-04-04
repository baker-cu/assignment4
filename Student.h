#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    public:
        Student();
        Stuent(int windTime);
        ~Student();

    private:
        int waitTime;
        int windowTime;

};

#endif
