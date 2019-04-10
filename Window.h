#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Student.cpp"

using namespace std;

class Window
{
    public:
        Window();
        ~Window();

        bool isEmpty();

        void oc(Student s);
        Student* getStu();

        int getTimeOc();
        int getTimeUnoc();


    private:
        bool open;
        int timeOc;
        int timeUnoc;
        Student* stu;

};

#endif
