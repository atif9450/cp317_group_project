#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

// void Student::create_student(int ID, std::string name) {
Student Student::create_student(int ID, std::string name) {
    Student student;
    student.student_ID = ID;
    student.student_name = name;

//     std:: cout << student.student_ID << "\n";
//     std:: cout << student.student_name;
    
    return student;
}

void Student::write_final_grades(std::string file_name) {
    fstream File(file_name);

    map<string,float>::iterator count;
    for (count = grades.begin(); count != grades.end(); ++count) {
        File << student_name << '\t'<< student_ID << '\t'<< count->first<< '\t' << count->second << '\n';
        // outdata << num[i] << endl;
    }

    File.close();
}

void Student::add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4) {
    float grade = (0.2*Test_1) + (0.2*Test_2)+(0.2*Test_3)+(0.4*Test_4);
    float final_grade = (grade * 10.0) / 10.0;

    grades.insert(pair<string, float>(course, final_grade));
}

