#ifndef WET2_COURSES_MANAGER_H
#define WET2_COURSES_MANAGER_H

#include "Hash_Table.h"
#include "CourseData.h"
#include "AVL_Tree.h"
#include "AVL_Tree_iterator.h"
#include "Pair.h"
#include "Lecture.h"
#include "Exceptions.h"

class CoursesManager
{
private:
    Hash_Table<CourseData> course_map;
    AVL_Tree<Lecture> view_tree;
    
    public:
    
    CoursesManager() = default;
    ~CoursesManager() = default;
    void AddCourse(int courseID);
    void RemoveCourse(int courseID);
    int AddClass(int courseID); //returns the inserted class id
    void WatchClass(int courseID, int classID, int time);
    int TimeViewed(int courseID, int classID);
    void GetIthWatchedClass(int i, int* courseID, int* classID);
};


#endif //WET2_COURSES_MANAGER_H