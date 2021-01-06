#ifndef WET2_COURSES_MANAGER_H
#define WET2_COURSES_MANAGER_H

#include "Hash_Table.h"
#include "CourseData.h"

class CoursesManager
{
private:
    Hash_Table<CourseData> course_map;

public:
    CoursesManager() = default;
    ~CoursesManager() = default;
    void AddCourse(int courseID);
    void RemoveCourse(int courseID);
    int AddClass(int courseID); //returns the inserted class id
    void WatchClass(int courseID, int classID, int time);
    int TimeViewed(int courseID, int classID);
};


#endif //WET2_COURSES_MANAGER_H