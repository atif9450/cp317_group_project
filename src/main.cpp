#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "NameFileReader.h"
#include "CourseFileReader.h"

int main() {
    std::string nameFile = "C:\\Users\\ehraa\\Documents\\GitHub\\cp317_group_project\\cp317_group_project\\NameFile.txt";
    std::string courseFile = "C:\\Users\\ehraa\\Documents\\GitHub\\cp317_group_project\\cp317_group_project\\CourseFile.txt";
    std::string outFile = "final_grades.txt";
    StudentList sl;

    // std::cout << "Enter path to NameFile.txt: ";
    // std::cin >> nameFile;
    // std::cout << "Enter path to CourseFile.txt: ";
    // std::cin >> courseFile;

    NameFileReader f1(nameFile);
    CourseFileReader f2(courseFile);

    f1.read_file(&sl);
    f2.read_file(&sl);
    sl.write_final_grades(outFile);

    return 0;
}