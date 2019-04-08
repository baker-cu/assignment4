#ifndef ROOM_C
#define ROOM_C

#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"

Room::Room()
{
    GenQueue<Student> *line = new GenQueue<Student>();
    DoublyLinkedList<Window> *openWindows = new DoublyLinkedList<Window>();

    numWindows = 0;
    time = 0;
}

Room::Room(string filepath)
{
    time = 0;

    GenQueue<Student> *line = new GenQueue<Student>();
    DoublyLinkedList<Window> *openWindows = new DoublyLinkedList<Window>();

    ifstream file(filepath);
    string l;

    getline(file, l);//first line of the file
    int s = stoi(l);
    numWindows = s;
    //add windows to openWindows list
    for(int i = 0; i < numWindows; i++)
    {
        openWindows->insertFront(Window());
    }

    //fills line with students and their times of arrival
    while(getline(file, l))
    {
        s = stoi(l);
        int toa = s; //time of arrival

        getline(file, l);
        s = stoi(l);
        int numStu = s; //number of students at that time

        for(int i = numStu; i > 0; i--)//iterates through time needed
        {
            getline(file, l);//get each time need for the studens in this first group
            s = stoi(l);
            Student tempStu = Student(s,toa);
            *line->insert(tempStu);//inserts that student into the queue with their time needed
        }
    }





}

#endif
