#ifndef ROOM_C
#define ROOM_C

#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"

inline Room::Room()
{
    line = new GenQueue<Student>();
    openWindows = new DoublyLinkedList<Window>();
    stats = new Stats();

    numWindows = 0;
    time = 0;
    done = false;
}

inline Room::Room(string filepath)
{
    time = 0;
    done = false;

    line = new GenQueue<Student>();
    openWindows = new DoublyLinkedList<Window>();
    stats = new Stats();


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
            //Student tempStu = Student(s,toa);
            line->insert(Student(s,toa));//inserts that student into the queue with their time needed
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

inline bool Room::nextTick()
{
    //check if line and all windows are empty
    int fullWindows = 0;
    if(line->getSize() == 0) //seg fault right here for some reason
    {
        for(int i = 0; i<openWindows->getSize(); i++)
        {
            if(openWindows->getPos(i).isEmpty() == false)
                fullWindows++;
        }
        if(fullWindows == 0)
        {
            done = true;
            return false;
        }
    }

    time++;
    //check through occupied windows
    for(int i = 0; i<openWindows->getSize(); i++)//iterate through windows
    {
        if(openWindows->getPos(i).isEmpty() == false)//checks if window is full (not empty)
        {
            if(openWindows->getPos(i).getStu()->nextTickWind() == false)//next tick the student at the window
            {//if false then their time is up
                openWindows->getPos(i).unoc();//unoccupies window
            }
        }
    }
    for(int i = 0; i<openWindows->getSize(); i++)//iterate through windows
    {
        //if window is empty
        if(openWindows->getPos(i).isEmpty() == true)
        {
            if(line->isEmpty() == false)
            {
                if(line->front().getTOA() <= time)//if student has "arrived"
                {
                    //first must get stats from empty window and student
                    stats->addStuTime(time-(line->front().getTOA()));
                    stats->addWindTime(openWindows->getPos(i).getTimeUnoc());
                    //add student to window
                    Student temp = line->remove();
                    Window tempW = openWindows->getPos(i);
                    tempW.oc(temp);
                }

                else//no student to put into window
                {
                    openWindows->getPos(i).nextTickUnoc(); //adds idle time to window
                }
            }
        }
    }
    done = false;
    return true;
}

inline void Room::sim()
{
    //keep doing next tick until there are no more people in the room
    while(done == false)
    {
        nextTick();
    }

    //print out all of the stats
    cout<<"Average student wait time: "<<stats->getMeanStu()<<endl;
    //cout meadian student wait time
    cout<<"Longest student wait time: "<<stats->getLongestStu()<<endl;
    cout<<"Number of students waiting over 10 mins: "<<stats->getOverTen()<<endl;

    cout<<"Average window idle time: "<<stats->getMeanWind()<<endl;
    cout<<"Longest window idle time: "<<stats->getLongestWind()<<endl;
    cout<<"Number of windows idling over 5 mins: "<<stats->getOverFive()<<endl;

}

#endif
