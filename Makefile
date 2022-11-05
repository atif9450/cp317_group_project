build: bin/coursefilereader.o bin/filereader.o bin/main.o bin/namefilereader.o bin/student.o bin/studentlist.o
	g++ bin/coursefilereader.o bin/filereader.o bin/main.o bin/namefilereader.o bin/student.o bin/studentlist.o

bin/coursefilereader.o: src/CourseFileReader.cpp
	g++ src/CourseFileReader.cpp -c -o bin/coursefilereader.o

bin/filereader.o: src/FileReader.cpp
	g++ src/FileReader.cpp -c -o bin/filereader.o

bin/main.o: src/main.cpp
	g++ src/main.cpp -c -o bin/main.o

bin/namefilereader.o: src/NameFileReader.cpp
	g++ src/NameFileReader.cpp -c -o bin/namefilereader.o

bin/student.o: src/Student.cpp
	g++ src/Student.cpp -c -o bin/student.o

bin/studentlist.o: src/StudentList.cpp
	g++ src/StudentList.cpp -c -o bin/studentlist.o

clean:
	del bin\*.o
	del a.exe