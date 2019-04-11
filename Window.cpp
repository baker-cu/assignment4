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
    timeUnoc = 1;
    stu = NULL;
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
    timeUnoc = 0;
    stu = &s;
    open = false;
}

inline Student* Window::getStu()
{
    return stu;
}

inline void Window::unoc()
{
    stu == NULL;
    open == true;
}

inline void Window::nextTickUnoc()
{
    timeUnoc++;
}

#endif
