#ifndef WET2_COURSE_DATA_H
#define WET2_COURSE_DATA_H

class CourseData
{
private:
    static constexpr int inititial_array_size = 4;
    
    int array_size;
    int top;
    
public:
    int* classes_array;

    CourseData();
    ~CourseData();
    void AddClass();
    int size() const;

private:
    void resize(const int new_array_size);
};

#endif //WET2_COURSE_DATA_H