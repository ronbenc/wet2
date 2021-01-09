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

    //update in time tree - itay
    int prev_time = course_map[courseID].classes_array[classID];
    if(view_tree.contains(Lecture(courseID, classID, prev_time)))
    {
        TreeNode<Lecture>* prev_node = view_tree.find(Lecture(courseID, classID, prev_time));
        view_tree.removeNode(prev_node->getData());
        std::cout << view_tree << std::endl;//debug
    }
    int curr_time = prev_time + time;
    view_tree.insertNode(Lecture(courseID, classID, curr_time));

    //update in course_map
    course_map[courseID].classes_array[classID] += time;

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
    if(false) //if time tree size < i
    {

    }
    // if(i > this->times_map.getSize()) //if time tree size < i
    // {
    //     throw Failure();
    // }
    // Lecture ith = times_map.Select(times_map.getSize() - i);
    
    //for testing
    *courseID = -1;
    *classID = -1;
}