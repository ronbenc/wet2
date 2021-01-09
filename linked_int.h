// #ifndef WET2_LINKED_INT_H
// #define WET2_LINKED_INT_H

// #include "TreeNode.h"
// #include "Pair.h"
// #include "Exceptions.h"
// #include "linked_pair.h"

// class linked_int
// {
//     public:

//     int view_time;
//     int courseID;
//     int classID;
//     TreeNode<linked_pair>* lecture;
    
//     linked_int()
//     {
//         view_time = courseID = classID = 0;
//         lecture = nullptr;
//     }
//     ~linked_int() = default;
//     linked_int& operator=(const linked_int& other) = default;
//     linked_int(int view_time, int courseID, int classID, TreeNode<linked_pair>* lecture = nullptr) : 
//                         view_time(view_time), courseID(courseID), classID(classID), lecture(lecture) {}
//     linked_int(const linked_int& to_copy) = default;    
// };

// std::ostream& operator<<(std::ostream os, const linked_int& a);
// bool operator<(const linked_int& a, const linked_int& b);
// bool operator>(const linked_int& a, const linked_int& b);
// bool operator<=(const linked_int& a, const linked_int& b);
// bool operator>=(const linked_int& a, const linked_int& b);
// bool operator==(const linked_int& a, const linked_int& b);
// bool operator!=(const linked_int& a, const linked_int& b);



// #endif //WET2_LINKED_INT_H