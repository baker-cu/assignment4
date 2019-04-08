#ifndef ROOM_C
#define ROOM_C

#include <iostream>
#include "Room.h"

Room::Room()
{
    GenQueue<student> *line = new GenQueue<student>();
    DoublyLinkedList<window> *openWindows = new DoublyLinkedList<window>();

    numWindows = 0;
}

Room::Room(string filepath)
{
    GenQueue<student> *line = new GenQueue<student>();
    DoublyLinkedList<window> *openWindows = new DoublyLinkedList<window>();

    ifstream file(filepath);
    int line;

    getline(file, line);//first line of the file
    numWindows = line;

    while(getline(file, line))
    {
        int toa = line; //time of arrival

        getline(file, line));
        int numStu = line; //number of students at that time

        for(int i = x; i > 0; i--)//iterates through time needed
        {
            getline(file, line);//get each time need for the studens in this first group
            *line->insert(Student(line),toa);//inserts that student into the queue with their time needed
        }
    }

}

#endif
