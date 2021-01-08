cmake_minimum_required(VERSION 3.0.0)
project(wet1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(wet2 main.cpp CourseData.cpp CoursesManager.cpp library2.cpp Lecture.cpp) 
# add_executable(wet2 main2.cpp AVL_Tree.cpp AVL_Tree_iterator.h library2.cpp) 


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
