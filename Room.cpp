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
    done = false;
}

inline Room::Room(string filepath)
{
    time = 0;
    done = false;

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
            stats->addWindTime(openWindows->getPos(i).getTimeUnoc());
            return true;
        }
    }
    return false;
}

inline bool Room::nextTick()
{
    //check if line and all windows are empty
    int fullWindows = 0;
    if(line->isEmpty())
    {
        for(int i = 0; i<openWindows->getSize(); i++)
        {
            if(!openWindows->getPos(i).isEmpty())
                fullWindows++;
        }
        if(fullWindows == 0)
            done = true;
            return false;
    }

    time++;
    //check through occupied windows
    for(int i = 0; i<openWindows->getSize(); i++)//iterate through windows
    {
        if(!openWindows->getPos(i).isEmpty())//checks if window is full (not empty)
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
        if(openWindows->getPos(i).isEmpty())
        {
            if(line->front().getTOA() >= time)//if student has "arrived"
            {
                //first must get stats from empty window and student
                stats->addStuTime(time - (line->front().getTOA()));
                stats->addWindTime(openWindows->getPos(i).getTimeUnoc());
                //add student to window
                openWindows->getPos(i).oc(line->remove());
            }
            else//no student to put into window
            {
                openWindows->getPos(i).nextTickUnoc(); //adds idle time to window
            }
        }
    }
    done = false;
    return true;







    //what needs to happen in next tick
    //the tick of the room increases by one

    //if all windows are open and the line is empty (done)
        //return false to stop sim (done)

    //go through each window (done)

        //if the window is not empty(done)
            //if student.nextTickWind == true they stay in window (done)
            //if false they leave window (else) (done)

        //if it is empty...look at the student in the front of the line (done)
            //if that students arrival time is equal to or greater than the room time they can be put into a window
                //when they are getting put into the window the students wait time and window idle time needs to be put into the stats
}

inline void Room::sim()
{
    //keep doing next tick until there are no more people in the room
    while(done = false)
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
