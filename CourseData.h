#ifndef WET2_COURSE_DATA_H
#define WET2_COURSE_DATA_H

const int inititial_classes_array_size = 4;

class CourseData
{
private:  
    int array_size;
    int top;
    
public:
    int* classes_array;

    CourseData();
    CourseData(const CourseData& to_copy);
    ~CourseData();
    void AddClass();
    int size() const;

private:
    void resize(const int new_array_size);
};

#endif //WET2_COURSE_DATA_H