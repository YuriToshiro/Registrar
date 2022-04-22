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

void Student::registerCourse(string courseID) // dang ki mot khoa hoc va them vao lich bieu
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

istream &operator>>(istream &in, Student &student) // nhap thong tin sinh vien
{
    string s;
    getline(in, s);
    for (int i = s.size() - 1; i >= 0; i--) // lay tu cuoi chuoi, cat lay mssv, con lai la ten
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

string Student::getName() // lay ten SV
{
    return mName;
}

string Student::getID() // lay MSSV
{
    return mID;
}

vector<string> Student::getSchedule() // lay lich bieu
{
    return mSchedule;
}

void Student::removeCourse(string courseID) // xoa mot khoa hoc khoi lich bieu
{
    auto it = find(mSchedule.begin(), mSchedule.end(), courseID);
    if (it != mSchedule.end())
    {
        mSchedule.erase(it);
    }
}