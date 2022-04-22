#ifndef REGISTRAR_H
#define REGISTRAR_H
#include "Student.h"
#include "Course.h"

class Registrar
{
private:
    vector<Student> mStudents;
    vector<Course> mCourses;

public:
    void addStudent(ifstream &in);
    void addCourse(ifstream &in);
    void enrollment();
    Student *findStudent(string id);
    Course *findCourse(string id);
    friend ostream &operator<<(ostream &out, Student &student);
    friend ostream &operator<<(ostream &out, Course &course);
    void ExportStudents(ofstream &out);
    void ExportCourses(ofstream &out);
};

#endif // REGISTRAR_H