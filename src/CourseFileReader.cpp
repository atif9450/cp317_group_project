#include <iostream>
#include <sstream>
#include <string>
#include "CourseFileReader.h"

using namespace std;

void CourseFileReader:: read_file(StudentList s) {
    string line;
    stringstream ss;

    try {
        VerifyLine(line);
    }
    catch (invalid_argument & e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream ReadFile(file_name);
    string tempid;
    int id;
    string name;
    int test1;
    int test2;
    int test3;
    int finaltest;
    string temp;


    while (getline(ReadFile, line)){
        // add each student
        stringstream ss(line);

        getline(ss, tempid, ',');
        id = stoi(tempid);

        getline(ss, name, ',');

        getline(ss, temp, ',');
        test1 = stoi(temp);

        getline(ss, temp, ',');
        test2 = stoi(temp);

        getline(ss, temp, ',');
        test3 = stoi(temp);

        getline(ss, temp, ',');
        finaltest = stoi(temp);

        s.add_student(id, name, test1, test2, test3, finaltest);

    }

    ReadFile.close();

}
