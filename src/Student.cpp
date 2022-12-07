#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void Student::create_student(int ID, std::string name) {
    this->student_ID = ID;
    this->student_name = name;
}

void Student::write_grades(std::ofstream& file) {
    for (final_grade_type f : grades) {
        std::string s = student_name;
        s.append(50 - s.length(), ' ');
        file << student_ID << "\t" << s << "\t" << f.course << "\t" << std::fixed << std::setprecision(1) << f.grade << endl;
    }
}

void Student::add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4) {
    float grade = (0.2*Test_1) + (0.2*Test_2)+(0.2*Test_3)+(0.4*Test_4);
    float final_grade = (grade * 10.0) / 10.0;
    final_grade_type f;
    f.course = course;
    f.grade = final_grade;
    grades.push_back(f);
}

int Student::get_student_ID() {
    return student_ID;
}