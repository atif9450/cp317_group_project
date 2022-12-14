#ifndef COURSE_FILE_READER_H_
#define COURSE_FILE_READER_H_

#include "FileReader.h"
#include <regex>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

class CourseFileReader : public FileReader {
    void VerifyLine(std::string);
    
    public:
        using FileReader::FileReader;
        void read_file(StudentList* s);
};

#endif