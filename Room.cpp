#ifndef ROOM_C
#define ROOM_C

#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"

inline Room::Room()
{
    GenQueue<Student> *line = new GenQueue<Student>();
    DoublyLinkedList<Window> *openWindows = new DoublyLinkedList<Window>();
    Stats* stats = new Stats();

    numWindows = 0;
    time = 0;
}

inline Room::Room(string filepath)
{
    time = 0;

    GenQueue<Student> *line = new GenQueue<Student>();
    DoublyLinkedList<Window> *openWindows = new DoublyLinkedList<Window>();
    Stats* stats = new Stats();

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
    //

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
            line->insert(tempStu);//inserts that student into the queue with their time needed
        }
    }
}

inline Room::~Room()
{
    delete line;
    delete openWindows;

    numWindows = 0;
    time = 0;
}

inline bool Room::fillWind() //returns false if no windows are open
{
    //iterate through list of windows and look for empty window
    for(int i = 0; i<openWindows->getSize(); i++)
    {
        if((openWindows->getPos(i)).isEmpty())
        {
            (openWindows->getPos(i)).oc(line->remove());
            return true;
        }
    }
    return false;
}

inline bool Room::nextTick()
{
    //code to check if line and all windows are empty
            //return false;
    time++;
    //check through occupied windows
    for(int i = 0; i<openWindows->getSize(); i++)
    {
        openWindows->getPos(i).getStu()->nextTickWind();//next tick the student at the window
        //check if student is done at window
        //if student arival time + time needed = current time
        if(openWindows->getPos(i).getStu()->getWindTime() == time - openWindows->getPos(i).getStu()->getTOA())
        {
            stats->addStuTime(openWindows->getPos(i).getStu()->getWaitTime());//add students stats before deleting
            openWindows->getPos(i).oc(line->remove());
        }
    }
    return true;
}

#endif
