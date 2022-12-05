#include "CourseFileReader.h"

using namespace std;

void CourseFileReader::read_file(StudentList* s) {
    string line;
    stringstream ss;

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
        try {
        VerifyLine(line);
        }
        catch (invalid_argument & e) {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
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

        Student* st = s->get_student(id);
        st->add_course(name, test1, test2, test3, finaltest);
    }

    ReadFile.close();

}

void CourseFileReader::VerifyLine(std::string line) {
    regex p("(\\d{9}), ([A-Z]{2}\\d{3}), (\\d{2}), (\\d{2}), (\\d{2}), (\\d{2})");
    smatch m;
    bool valid = regex_search(line, m, p);
    if (!valid || line.size() != 32) {
        std::cout << "CourseFileReader: incorrectly formatted line: " << line << std::endl;
        std::cout << "Please format line as such: STUDENT_ID, COURSE_CODE, GRADE1, GRADE2, GRADE3, GRADE4\n" << std::endl;
        throw std::invalid_argument(NULL);
    }
}
