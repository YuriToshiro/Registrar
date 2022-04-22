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
    string Date;
    int hour;
    int min;
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
};

#endif // COURSE_H