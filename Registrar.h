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
    void addStudentFromFile(ifstream &in);
    void addCourseFromFile(ifstream &in);
    void enrollment();
    Student *findStudent(string id);
    Course *findCourse(string id);
    friend ostream &operator<<(ostream &out, Student &student);
    friend ostream &operator<<(ostream &out, Course &course);
    void ExportStudents(ofstream &out);
    void ExportCourses(ofstream &out);
    void removeStudent(string id);
    void removeCourse(string id);
};

#endif // REGISTRAR_H