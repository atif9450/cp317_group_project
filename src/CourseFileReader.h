#ifndef COURSE_FILE_READER_H_
#define COURSE_FILE_READER_H_

#include "FileReader.h"

class CourseFileReader : public FileReader {
    public:
        using FileReader::FileReader;
        void read_file(StudentList s);
};

#endif