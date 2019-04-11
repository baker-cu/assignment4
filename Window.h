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
        void unoc();
        Student* getStu();

        int getTimeOc();
        int getTimeUnoc();

        void nextTickUnoc();


    private:
        bool open;
        int timeOc;
        int timeUnoc;
        Student* stu;

};

#endif
