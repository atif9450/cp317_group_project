#ifndef NAME_FILE_READER_H_
#define NAME_FILE_READER_H_

#include "FileReader.h"
#include <iostream>

#define IDLEN 9
#define NAMELEN 32


class NameFileReader : public FileReader {
    void VerifyLine(std::string line);
    public:
        using FileReader::FileReader;
        void read_file(StudentList s);
};

#endif