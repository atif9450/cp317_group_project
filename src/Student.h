#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <map>
#include <fstream>

class Student {
    std::string name;
    int student_ID;
    std::map<std::string, float> grades;

    public:
        void create_student(int student_ID, std::string student_name);
        void write_final_grades(std::string file_name);
        void add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4);
};

#endif