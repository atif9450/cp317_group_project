#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <map>
#include <vector>
#include <fstream>

typedef struct {
    std::string course;
    float grade;
} final_grade_type;

class Student {
    std::string student_name;
    int student_ID;
    // string name;
    std::vector<final_grade_type> grades;

    public:
        // void create_student(int student_ID, std::string student_name);
        void create_student(int student_ID, std::string student_name);
        void write_grades(std::ofstream& file);
        void add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4);
        int get_student_ID();
};

#endif
