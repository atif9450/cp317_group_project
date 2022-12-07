#include "NameFileReader.h"

void NameFileReader::read_file(StudentList* s) {
    int good;
    int id;
    std::string name;
    std::string line;
    std::ifstream ReadFile(this->file_name);

    if (!ReadFile.is_open()) {
        std::cout << "NameFile.txt failed to open." << std::endl;
        exit(EXIT_FAILURE);
    }

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
        s->add_student(id, name);
    }

    ReadFile.close();
}

void NameFileReader::VerifyLine(std::string line) {
    //check ID
    char* p;
    long converted = strtol(line.substr(0, IDLEN).c_str(), &p, 10);
    if (*p != 0) {
        // failed
        std::cout << line << std::endl;
        throw std::invalid_argument("Error in student ID: not numeric");
        std::cout << "NameFile Reader: Incorrect student ID\n";
    }

    //check middle part
    if (line.substr(9, 2).compare(", ") != 0) {
        std::cout << line << std::endl;
        throw std::invalid_argument("Error in formatting");
        std::cout << "NameFile Reader: Incorrect formatting\n";
    }
    
    //check name
    int i = 11;
    while(line[i]) {
        if ((isalpha(line[i]) == 0) && (isspace(line[i]) == 0)) {
            std::cout << line << std::endl;
            throw std::invalid_argument("Error in student name: not alphabetical");
            std::cout << "NameFile Reader: Incorrect student name\n";
        }
        i++;
    }
}