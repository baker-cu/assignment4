#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "GenQueue.h"

using namespace std;

class room
{
    public:
        Room();
        Room(int numWind);
        ~Room();
    private:
        GenQueue *line; //queue for the line of students
        

        int numWindows;


}

#endif
