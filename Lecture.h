#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>

class Lecture
{
    public:
    int view_time;
    int courseID;
    int classID;

    Lecture(int view_time, int courseID, int classID) : view_time(view_time), courseID(courseID), classID(classID) {}
    Lecture(const Lecture& to_copy) = default;
    Lecture& operator=(const Lecture& other) = default;
    ~Lecture() = default;
    // void viewAdd(int a);    
};

std::ostream& operator<<(std::ostream os, Lecture a);
bool operator<(Lecture a, Lecture b);
bool operator>(Lecture a, Lecture b);
bool operator<=(Lecture a, Lecture b);
bool operator>=(Lecture a, Lecture b);
bool operator==(Lecture a, Lecture b);
bool operator!=(Lecture a, Lecture b);

#endif //LECTURE_H