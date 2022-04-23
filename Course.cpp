#include "Course.h"

Course::Course()
{
    // ctor
}

Course::Course(string name, string id, vector<string> roster, DateTime date)
{
    mName = name;
    mID = id;
    mRoster = roster;
    mDate = date;
}

Course::Course(const Course &c)
{
    mName = c.mName;
    mID = c.mID;
    mRoster = c.mRoster;
    mDate = c.mDate;
}

Course::~Course()
{
    // dtor
}

// kiem tra thu trong tuan
bool isDateOfWeek(string Date)
{
    vector<string> date = {"T2", "T3", "T4", "T5", "T6", "T7", "CN"};
    auto it = find(date.begin(), date.end(), Date);
    if (it != date.end())
    {
        return true;
    }
    return false;
}

istream &operator>>(istream &in, Course &course) // nhap thong tin khoa hoc
{
    getline(in, course.mName);
    in >> course.mID;
    in >> course.mDate.date;
    if (!isDateOfWeek(course.mDate.date))
    {
        course.mDate.date = "NA";
    }
    if (in >> course.mDate.hour && atoi(course.mDate.hour.c_str()) < 0 || atoi(course.mDate.hour.c_str()) > 23)
    {
        course.mDate.hour = "NA";
    }
    if (in >> course.mDate.min && atoi(course.mDate.min.c_str()) < 0 || atoi(course.mDate.min.c_str()) > 59)
    {
        course.mDate.min = "NA";
    }
    in.ignore();
    return in;
}

void Course::addStudent(string id) // them mot sinh vien vao danh sach hoc vien
{
    auto it = find(mRoster.begin(), mRoster.end(), id);
    if (mRoster.size() < 40 && it == mRoster.end())
    {
        mRoster.push_back(id);
    }
    else
    {
        cout << "Mon " << mName << " da day hoac sinh vien dang ki da ton tai!\n";
    }
}

vector<string> Course::getRoster() // lay danh sach hoc vien
{
    return mRoster;
}

string Course::getName() // lay ten khoa hoc
{
    return mName;
}

string Course::getID() // lay ma khoa hoc
{
    return mID;
}

DateTime Course::getDate() // lay thoi gian hoc khoa hoc trong tuan
{
    return mDate;
}

void Course::removeStudent(string id) // xoa mot sinh vien khoi danh sach hoc vien
{
    auto it = find(mRoster.begin(), mRoster.end(), id);
    if (it != mRoster.end())
    {
        mRoster.erase(it);
    }
}