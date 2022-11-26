#include "StudentList.h"
#include <iostream>

Student* StudentList::get_student(int student_ID) {
    Student* obj;
    for (int i = 0; i<list.size(); i++){
        if(list[i].get_student_ID() == student_ID){
            obj = &(list[i]);
        }
    }
    return obj;
    }

void StudentList::add_student(int student_ID, std::string name) {
    Student obj;
    obj.create_student(student_ID, name);
    list.push_back(obj);
}

void StudentList::write_final_grades(std::string filename) {
    std::ofstream file(filename);

    for (Student s : list) {
        s.write_grades(file);
    }

    file.close();

    return;
}
