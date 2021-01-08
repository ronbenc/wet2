#include "Lecture.h"

std::ostream& operator<<(std::ostream& os, Lecture a)
{
    os << "<" << a.courseID << "," << a.classID << ">" << std::endl;
    return os;
}

bool operator<(Lecture a, Lecture b)
{
    if(a.view_time != b.view_time)
    {
        return (a.view_time < b.view_time);
    }
    else if(a.courseID != b.courseID)
    {
        return (a.courseID < b.courseID);
    }
    else
    {
        return (a.classID < b.classID);
    }
}

bool operator>(Lecture a, Lecture b)
{
    return !(a < b);
}

bool operator<=(Lecture a, Lecture b)
{
    if(a.view_time != b.view_time)
    {
        return (a.view_time <= b.view_time);
    }
    else if(a.courseID != b.courseID)
    {
        return (a.courseID <= b.courseID);
    }
    else
    {
        return (a.classID <= b.classID);
    }
}

bool operator>=(Lecture a, Lecture b)
{
    return !(a <= b);
}

bool operator==(Lecture a, Lecture b)
{
    return ((a.courseID == b.courseID) && (a.classID == b.classID));
}

bool operator!=(Lecture a, Lecture b)
{
    return !(a == b);
}