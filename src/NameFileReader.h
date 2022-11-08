#ifndef NAME_FILE_READER_H_
#define NAME_FILE_READER_H_

#include "FileReader.h"
#include <iostream>
using namespace std;

#define IDLEN 9
#define NAMELEN 32


class NameFileReader : public FileReader {
    int VerifyLine(string line);
    public:
        using FileReader::FileReader;
        void read_file(StudentList s);
};

#endif