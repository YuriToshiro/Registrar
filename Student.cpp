#include "Student.h"

Student::Student()
{
    // ctor
}

Student::Student(string name, string id)
{
    mName = name;
    mID = id;
}

Student::Student(const Student &s)
{
    mName = s.mName;
    mID = s.mID;
    mSchedule = s.mSchedule;
}

Student::~Student()
{
    // dtor
}

void Student::registerCourse(string courseID)
{
    auto it = find(mSchedule.begin(), mSchedule.end(), courseID);
    if (mSchedule.size() < 5 && it == mSchedule.end())
    {
        mSchedule.push_back(courseID);
    }
    else
    {
        cout << "Sinh vien " << mName << " da dang ky toi da 5 khoa hoc hoac dang ki trung!\n";
    }
}

istream &operator>>(istream &in, Student &student)
{
    string s;
    getline(in, s);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            student.mName = s.substr(0, i);
            student.mID = s.substr(i + 1, s.size());
            break;
        }
    }
    return in;
}

string Student::getName()
{
    return mName;
}

string Student::getID()
{
    return mID;
}

vector<string> Student::getSchedule()
{
    return mSchedule;
}