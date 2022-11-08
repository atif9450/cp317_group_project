#include "NameFileReader.h"

void NameFileReader::read_file(StudentList s) {
    int good;
    std::string line;
    std::ifstream ReadFile(file_name);

    while (std::getline(ReadFile, line)) {
        if ((good = VerifyLine(line)) <= -1) {
            //throw std::invalid_argument("Error in input file");
            //exit(EXIT_FAILURE);
        }
        /*
        std::cout << line.substr(0, IDLEN) << "\n";
        std::cout << line.substr(11, NAMELEN) << "\n";
        std::cout << "-------------------------- \n";
        */

    }
    ReadFile.close();
}

void VerifyLine(std::string line) {
    //check ID
    char* p;
    long converted = strtol(line.substr(0, IDLEN).c_str(), &p, 10);
    if (*p != 0) {
        // failed
        throw std::invalid_argument("Error in student ID: not numeric");
        //cout << "---wrong id---";
    }
    //check middle part
    if (line.substr(9, 2).compare(", ") != 0) {
        throw std::invalid_argument("Error in formatting");
        //cout << "---wrong middle---";
    }
    //check name
    int i = 11;
    while(line[i]) {
        if ((isalpha(line[i]) == 0) && (isspace(line[i]) == 0)) {
            throw std::invalid_argument("Error in student name: not alphabetical");
            //cout << "---wrong name---";
        }
        i++;
    }
}