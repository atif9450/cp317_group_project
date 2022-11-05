#ifndef NAME_FILE_READER_H_
#define NAME_FILE_READER_H_

#include "FileReader.h"

class NameFileReader : public FileReader {
    public:
        using FileReader::FileReader;
        void read_file(StudentList s);
};

#endif