#include "CoursesManager.h"

void CoursesManager::AddCourse(int courseID)
{
    //handle exep...
    assert(courseID > 0 && !course_map.contains(courseID));

    course_map.insert(courseID);
}

void CoursesManager::RemoveCourse(int courseID)
{
    //handle exep...
    assert(courseID > 0 && course_map.contains(courseID));

    //remove classes from time tree
    for(int curr_classID = 0; curr_classID < course_map[courseID].size();curr_classID++)
    {
        int curr_class_time = course_map[courseID].classes_array[curr_classID];
        //remove curr_class from time tree
    }
    //remove course from course_map
    course_map.erase(courseID);
}

int CoursesManager::AddClass(int courseID)
{
    //handle exep...
    assert(courseID > 0 && course_map.contains(courseID));

    course_map[courseID].AddClass();
    return (course_map[courseID].size() - 1);
}

void CoursesManager::WatchClass(int courseID, int classID, int time)
{
    //handle exep...
    assert(courseID > 0 && course_map.contains(courseID) && classID >= 0 && time > 0 && classID < course_map[courseID].size());

    //update in course_map
    course_map[courseID].classes_array[classID] += time;

    //update in time tree
}

int CoursesManager::TimeViewed(int courseID, int classID)
{
    //handle exep...
    assert(courseID > 0 && course_map.contains(courseID) && classID >= 0 && classID < course_map[courseID].size());

    return course_map[courseID].classes_array[classID];
}