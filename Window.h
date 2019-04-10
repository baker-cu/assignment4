#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

using namespace std;

class Window
{
    public:
        Window();
        ~Window();

        bool isEmpty();

        bool oc(Student s);//RITE THIS

        int getTimeOc();
        int getTimeUnoc();


    private:
        bool open;
        int timeOc;
        int timeUnoc;
        Student* stu;

};

#endif
