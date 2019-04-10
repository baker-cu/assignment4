#ifndef WINDOW_C
#define WINDOW_C

#include <iostream>
#include "Window.h"

using namespace std;

inline Window::Window()
{
    open = true;
    timeOc = 0;
    timeUnoc = 0;
    stu = NULL;
}

inline Window::~Window()
{
    open = false;
    timeOc = 0;
    timeUnoc = 0;
    delete stu;
}

inline bool Window::isEmpty()
{
    if(open == true)
        return true;
    else
        return false;
}

inline int Window::getTimeOc()
{
    return timeOc;
}

inline int Window::getTimeUnoc()
{
    return timeUnoc;
}

inline void Window::oc(Student s)
{
    stu = &s;
}

inline Student* Window::getStu()
{
    return stu;
}

#endif
