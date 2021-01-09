#include "CoursesManager.h"


void CoursesManager::AddCourse(int courseID)
{
    if(courseID <= 0)
    {
        throw InvalidInput();
    }
    if(course_map.contains(courseID))
    {
        throw Failure();
    }
    assert(courseID > 0 && !course_map.contains(courseID));

    course_map.insert(courseID);
}

void CoursesManager::RemoveCourse(int courseID)
{
    if(courseID <= 0)
    {
        throw InvalidInput();
    }
    if(!course_map.contains(courseID))
    {
        throw Failure();
    }
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
    if(courseID <= 0)
    {
        throw InvalidInput();
    }
    if(!course_map.contains(courseID))
    {
        throw Failure();
    }
    assert(courseID > 0 && course_map.contains(courseID));

    course_map[courseID].AddClass();
    return (course_map[courseID].size() - 1);
}

void CoursesManager::WatchClass(int courseID, int classID, int time)
{
    if(courseID <= 0 || classID < 0 || time <= 0 || classID+1 > course_map[courseID].size())
    {
        throw InvalidInput();
    }
    if(!course_map.contains(courseID))
    {
        throw Failure();
    }
    assert(courseID > 0 && course_map.contains(courseID) && classID >= 0 && time > 0 && classID < course_map[courseID].size());

    //update in course_map
    course_map[courseID].classes_array[classID] += time;

    
    //update in time tree
    
    Lecture tmp = Lecture(0, courseID, classID);
    int prev_time = 0;
    
    //if the class already has been watched, save previous view time and remove from tree
    if(times_map.contains(tmp))
    {
        TreeNode<Lecture>* prev_node = this->times_map.find(courseID, classID);
        prev_time = prev_node->getData().view_time;
        times_map.removeNode(Lecture(0, courseID, classID));
    }    

    //insert with correct data
    times_map.insertNode(Lecture(prev_time + time, courseID, classID));
}

int CoursesManager::TimeViewed(int courseID, int classID)
{
    if(courseID <= 0 || classID < 0 || classID+1 > course_map[courseID].size())
    {
        throw InvalidInput();
    }
    if(!course_map.contains(courseID))
    {
        throw Failure();
    }
    assert(courseID > 0 && course_map.contains(courseID) && classID >= 0 && classID < course_map[courseID].size());

    return course_map[courseID].classes_array[classID];
}

void CoursesManager::GetIthWatchedClass(int i, int* courseID, int* classID)
{
    if(i <= 0)
    {
        throw InvalidInput();
    }
    if(i > this->times_map.getSize()) //if time tree size < i
    {
        throw Failure();
    }
    Lecture ith = times_map.Select(times_map.getSize() - i);
    
    //for testing
    *courseID = ith.courseID;
    *classID = ith.classID;
}