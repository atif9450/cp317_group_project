#include "Student.h"

// void Student::create_student(int ID, std::string name) {
Student::create_student(int ID, std::string name) {
    Student student;
    student.student_ID = ID;
    student.student_name = name;

    return student;
}

void Student::write_final_grades(std::string file_name) {
    ofstream File(file_name);

    for (count = grades.begin(); count != grades.end(); ++count) {
        File << student_name << '\t'<< student_ID << '\t'<< count->first<< '\t' << count->second << '\n';
        // outdata << num[i] << endl;
    }

    File.close();
}

void Student::add_course(std::string course, float Test_1, float Test_2, float Test_3, float Test_4) {
    grade = (Test_1+Test_2+Test_3Test_4)/4;
    float final_grade = floor(grade * 100.0) / 100.0;

    grades.insert(pair<string, float>(course, final_grade));
}
