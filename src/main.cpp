#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "NameFileReader.h"
#include "CourseFileReader.h"

int main(int argc, char *argv[]) {
    std::string nameFile, courseFile;
    std::string outFile = "final_grades.txt";
    StudentList sl;

    if (argc != 3) {
        std::cout << "Please run program like so: gen_final_grades <PATH_TO_NAMEFILE> <PATH_TO_COURSEFILE>" << std::endl;
        return 0;
    }

    nameFile = argv[1];
    courseFile = argv[2];

    NameFileReader f1(nameFile);
    CourseFileReader f2(courseFile);

    f1.read_file(&sl);
    std::cout << "Read NameFile" << std::endl;
    f2.read_file(&sl);
    std::cout << "Read CourseFile" << std::endl;
    sl.write_final_grades(outFile);
    std::cout << "Made output file: " << outFile << std::endl;
    std::cout << "\nPress any key to exit..";

    getchar();

    return 0;
}