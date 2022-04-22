#include "Registrar.h"

void Registrar::addStudent(ifstream &in)
{
    while (!in.eof())
    {
        Student s;
        in >> s;
        mStudents.push_back(s);
    }
}

void Registrar::addCourse(ifstream &in)
{
    while (!in.eof())
    {
        Course c;
        in >> c;
        mCourses.push_back(c);
    }
}
Student *Registrar::findStudent(string id)
{
    for (int i = 0; i < mStudents.size(); i++)
    {
        if (mStudents[i].getID() == id)
        {
            return &mStudents[i];
        }
    }
    return nullptr;
}

Course *Registrar::findCourse(string id)
{
    for (int i = 0; i < mCourses.size(); i++)
    {
        if (mCourses[i].getID() == id)
        {
            return &mCourses[i];
        }
    }
    return nullptr;
}

void Registrar::enrollment()
{
    string id;
    cout << "Nhap MSSV can dang ky khoa hoc: ";
    cin >> id;
    Student *s = findStudent(id);
    if (s == nullptr)
    {
        cout << "Khong tim thay sinh vien " << id << endl;
        return;
    }
    string courseID;
    cout << "Nhap ma khoa hoc (Q de ket thuc): ";
    while (cin >> courseID && courseID != "Q" && courseID != "q")
    {
        Course *c = findCourse(courseID);
        if (c != nullptr)
        {
            c->addStudent(id);
            s->registerCourse(courseID);
        }
        else
        {
            cout << "Khong tim thay khoa hoc " << courseID << endl;
        }
        cout << "Nhap ma khoa hoc (Q de ket thuc): ";
    }
}

ostream &operator<<(ostream &out, Student &student)
{
    out << "Ho va ten: " << student.getName() << endl;
    out << "MSSV: " << student.getID() << endl;
    return out;
}

ostream &operator<<(ostream &out, Course &course)
{
    out << "Ten khoa hoc: " << course.getName() << endl;
    out << "Ma khoa hoc: " << course.getID() << endl;
    return out;
}

void Registrar::ExportStudents(ofstream &out)
{
    for (int i = 0; i < mStudents.size(); i++)
    {
        out << i + 1 << "." << endl;
        out << mStudents[i];
        out << "Khoa hoc dang ky: " << endl;
        for (int j = 0; j < mStudents[i].getSchedule().size(); j++)
        {
            Course *c = findCourse(mStudents[i].getSchedule()[j]);
            out << c->getDate().Date << "-" << c->getDate().hour << ":" << c->getDate().min << ": ";
            out << c->getName() << endl;
        }
        out << "------------------------------" << endl;
    }
}

void Registrar::ExportCourses(ofstream &out)
{
    for (int i = 0; i < mCourses.size(); i++)
    {
        out << i + 1 << "." << endl;
        out << mCourses[i];
        out << "Danh sach sinh vien dang ky: " << endl;
        for (int j = 0; j < mCourses[i].getRoster().size(); j++)
        {
            Student *s = findStudent(mCourses[i].getRoster()[j]);
            out << s->getID() << "-" << s->getName() << endl;
        }
        out << "------------------------------" << endl;
    }
}