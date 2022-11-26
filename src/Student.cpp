#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

Student Student::create_student(int ID, std::string name) {
    Student student;
    student.student_ID = ID;
    student.student_name = name;

//     std:: cout << student.student_ID << "\n";
//     std:: cout << student.student_name;
    
    return student;
}

void Student::write_grades(std::ofstream& file) {

    std::cout << "test";

    map<string,float>::iterator count;
    for (count = grades.begin(); count != grades.end(); ++count) {
        file << student_name << '\t'<< student_ID << '\t'<< count->first<< '\t' << count->second << '\n';
        // outdata << num[i] << endl;
    }

}

void Student::add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4) {
    float grade = (0.2*Test_1) + (0.2*Test_2)+(0.2*Test_3)+(0.4*Test_4);
    float final_grade = (grade * 10.0) / 10.0;

    grades.insert(pair<string, float>(course, final_grade));
}

int Student::get_student_ID() {
    return student_ID;
}