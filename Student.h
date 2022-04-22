#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
private:
    string mName;
    string mID;
    vector<string> mSchedule;

public:
    // constructor, destructor
    Student();
    Student(string name, string id);
    Student(const Student &);
    ~Student();
    // getters
    friend istream &operator>>(istream &in, Student &student);
    void registerCourse(string courseID);
    vector<string> getSchedule();
    string getName();
    string getID();
};

#endif // STUDENT_H