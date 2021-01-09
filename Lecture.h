#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>

class Lecture
{
    public:
    int view_time;
    int courseID;
    int classID;

    Lecture() = default;
    explicit Lecture(int courseID, int classID, int view_time = 0) : courseID(courseID), classID(classID), view_time(view_time) {}
    Lecture(const Lecture& to_copy) = default;
    Lecture& operator=(const Lecture& other) = default;
    ~Lecture() = default;    
};

std::ostream& operator<<(std::ostream& os, const Lecture& a);
bool operator<(Lecture a, Lecture b);
bool operator>(Lecture a, Lecture b);
bool operator<=(Lecture a, Lecture b);
bool operator>=(Lecture a, Lecture b);
bool operator==(Lecture a, Lecture b);
bool operator!=(Lecture a, Lecture b);

#endif //LECTURE_H