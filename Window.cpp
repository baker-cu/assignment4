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
}

inline Window::~Window()
{
    open = false;
    timeOc = 0;
    timeUnoc = 0;
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

#endif
