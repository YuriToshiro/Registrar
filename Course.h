#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct DateTime
{
    string date;
    string hour;
    string min;
};

class Course
{
private:
    string mName;
    string mID;
    vector<string> mRoster;
    DateTime mDate;

public:
    // constructor, destructor
    Course();
    Course(string name, string id, vector<string> roster, DateTime date);
    Course(const Course &c);
    ~Course();
    // getters
    friend istream &operator>>(istream &in, Course &course);
    void addStudent(string id);
    string getName();
    string getID();
    vector<string> getRoster();
    DateTime getDate();
    void removeStudent(string id);
};

#endif // COURSE_H