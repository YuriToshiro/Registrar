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

istream &operator>>(istream &in, Course &course)
{
    getline(in, course.mName);
    in >> course.mID >> course.mDate.Date >> course.mDate.hour >> course.mDate.min;
    in.ignore();
    return in;
}

void Course::addStudent(string id)
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

vector<string> Course::getRoster()
{
    return mRoster;
}

string Course::getName()
{
    return mName;
}

string Course::getID()
{
    return mID;
}

DateTime Course::getDate()
{
    return mDate;
}