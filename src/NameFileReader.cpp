#include "NameFileReader.h"

void VerifyLine(std::string line);

void NameFileReader::read_file(StudentList s) {
    int good;
    int id;
    std::string name;
    std::string line;
    std::ifstream ReadFile(file_name);

    while (std::getline(ReadFile, line)) {
        //verify line to make sure input is correct
        try {
            VerifyLine(line);
        }
        catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        //add student to studnet list
        id = std::stoi(line.substr(0, IDLEN));
        name.assign(line.substr(IDLEN + 2, NAMELEN));
        s.add_student(id, name);
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