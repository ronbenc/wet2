// #ifndef WET2_LINKED_PAIR_H
// #define WET2_LINKED_PAIR_H

// #include "TreeNode.h"
// #include "Pair.h"
// #include "Exceptions.h"
// #include "linked_int.h"

// class linked_pair
// {
//     public:

//     Pair<int,int> pair;
//     TreeNode<linked_int>* time;
    
//     linked_pair()
//     {
//         pair = Pair<int,int>();
//         time = nullptr;
//     }
//     ~linked_pair() = default;
//     linked_pair& operator=(const linked_pair& other) = default;
//     linked_pair(int courseID, int classID, TreeNode<linked_int>* time = nullptr) : time(time)
//     {
//         pair = Pair<int,int>(courseID, classID);
//     }
//     linked_pair(const linked_pair& to_copy) = default;    
// };

// std::ostream& operator<<(std::ostream os, const linked_pair& a);
// bool operator<(const linked_pair& a, const linked_pair& b);
// bool operator>(const linked_pair& a, const linked_pair& b);
// bool operator<=(const linked_pair& a, const linked_pair& b);
// bool operator>=(const linked_pair& a, const linked_pair& b);
// bool operator==(const linked_pair& a, const linked_pair& b);
// bool operator!=(const linked_pair& a, const linked_pair& b);



// #endif //WET2_LINKED_PAIR_H