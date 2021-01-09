// #include "linked_int.h"


// bool operator<(const linked_int& a, const linked_int& b)
// {
//     if(a.view_time != b.view_time)
//     {
//         return (a.view_time < b.view_time);
//     }
//     else if(a.courseID != b.courseID)
//     {
//         return (a.courseID < b.courseID);
//     }
//     else
//     {
//         return (a.classID < b.classID);
//     }
// }

// bool operator>(const linked_int& a, const linked_int& b)
// {
//     if(a.view_time != b.view_time)
//     {
//         return (a.view_time > b.view_time);
//     }
//     else if(a.courseID != b.courseID)
//     {
//         return (a.courseID > b.courseID);
//     }
//     else
//     {
//         return (a.classID > b.classID);
//     }
// }

// bool operator<=(const linked_int& a, const linked_int& b)
// {
//     return !(a > b);
// }

// bool operator>=(const linked_int& a, const linked_int& b)
// {
//     return !(a < b);
// }

// bool operator==(const linked_int& a, const linked_int& b)
// {
//     return ((a.view_time == b.view_time) && (a.courseID == b.courseID) && (a.classID && b.classID));
// }

// bool operator!=(const linked_int& a, const linked_int& b)
// {
//     return !(a == b);
// }