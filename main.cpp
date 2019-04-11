//first line = number of windows open
//second line = time at which students arrive
//third line = number of students that arrive
//next lines coorespond to the amount of time they need


// cpp check checks for buffer overloads
// find something to look for memory leaks

#include <iostream>
#include "Room.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    Room* registrar = new Room(argv[1]);

    registrar->sim();


    return 0;
}
