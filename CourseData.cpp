#include "CourseData.h"

CourseData::CourseData() : array_size(inititial_classes_array_size), top(0), classes_array(new int[array_size])
{
}

CourseData::CourseData(const CourseData& to_copy) : array_size(to_copy.array_size), top(to_copy.top), classes_array(new int[array_size])
{
    for(int i = 0; i < array_size; i++)
    {
        classes_array[i] = to_copy.classes_array[i];
    }
}

CourseData::~CourseData()
{
    delete[] classes_array;
}

void CourseData::AddClass()
{
    classes_array[top] = 0;
    top++;
    
    if(top >= array_size)
    {
        resize(2 * array_size);
    }
}

int CourseData::size() const
{
    return top;
}

void CourseData::resize(const int new_array_size)
{
    int* new_classes_array = new int[new_array_size];

    for(int i = 0; i < top; i++)
    {
        new_classes_array[i] = classes_array[i];
    }

    delete[]  classes_array;
    classes_array = new_classes_array;
    array_size = new_array_size;
}