#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <string>
#include <fstream>
#include "StudentList.h"

class FileReader {
    public:
        std::string file_name;
        FileReader(std::string file_name);
        virtual void read_file(StudentList* s)=0;
};

#endif