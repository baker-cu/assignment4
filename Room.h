#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
#include "Student.cpp"
#include "Window.cpp"

using namespace std;

class Room
{
    public:
        Room();
        Room(string filepath);
        ~Room();

        bool fillWind(Student s);//trys to fill windows in
        void nextTick();//moves time forward by one

        bool isLineEmpty();
        bool isWindowEmpty();

        void sim();

    private:
        GenQueue<Student> *line; //queue for the line of students
        DoublyLinkedList<Window> *openWindows; //list of all of the open windows to iterate through

        int numWindows;
        int time;
};

#endif
