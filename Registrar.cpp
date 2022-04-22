#include "Registrar.h"

void Registrar::addStudent(ifstream &in) // them (tang dan theo MSSV) SV tu file vao mang SV
{
    while (!in.eof())
    {
        Student s;
        in >> s;
        if (mStudents.empty() || mStudents.back().getID() < s.getID())
        {
            mStudents.push_back(s);
        }
        else
        {
            int i = mStudents.size() - 1;
            while (i >= 0 && s.getID() < mStudents[i].getID())
            {
                i--;
            }
            mStudents.emplace(mStudents.begin() + (i + 1), s);
        }
    }
}

void Registrar::addCourse(ifstream &in) // them (tang dan theo ma KH) khoa hoc tu file vao mang khoa hoc
{
    while (!in.eof())
    {
        Course c;
        in >> c;
        if (mCourses.empty() || mCourses.back().getID() < c.getID())
        {
            mCourses.push_back(c);
        }
        else
        {
            int i = mCourses.size() - 1;
            while (i >= 0 && c.getID() < mCourses[i].getID())
            {
                i--;
            }
            mCourses.emplace(mCourses.begin() + (i + 1), c);
        }
    }
}
Student *Registrar::findStudent(string id) // tim SV theo MSSV bang Binary Search
{
    int l = 0;
    int r = mStudents.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mStudents[mid].getID() == id)
        {
            return &mStudents[mid];
        }
        else if (mStudents[mid].getID() > id)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return nullptr;
}

Course *Registrar::findCourse(string id) // tim khoa hoc theo ma khoa hoc bang Binary Search
{
    int l = 0;
    int r = mCourses.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mCourses[mid].getID() == id)
        {
            return &mCourses[mid];
        }
        else if (mCourses[mid].getID() > id)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return nullptr;
}

void Registrar::enrollment() // dang ki khoa hoc cho 1 SV
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

ostream &operator<<(ostream &out, Student &student) // Xuat thong tin 1 SV
{
    out << "Ho va ten: " << student.getName() << endl;
    out << "MSSV: " << student.getID() << endl;
    return out;
}

ostream &operator<<(ostream &out, Course &course) // Xuat thong tin 1 khoa hoc
{
    out << "Ten khoa hoc: " << course.getName() << endl;
    out << "Ma khoa hoc: " << course.getID() << endl;
    return out;
}

void Registrar::ExportStudents(ofstream &out) // Xuat danh sach SV ra file .txt
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

void Registrar::ExportCourses(ofstream &out) // Xuat danh sach khoa hoc ra file .txt
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

void Registrar::removeStudent(string id) // Xoa 1 SV khoi danh sach SV
{
    if (findStudent(id) == nullptr)
    {
        cout << "Khong tim thay sinh vien " << id << endl;
        return;
    }
    for (int i = 0; i < mStudents.size(); i++)
    {
        if (mStudents[i].getID() == id)
        {
            mStudents.erase(mStudents.begin() + i);
            break;
        }
    }
    for (int i = 0; i < mCourses.size(); i++)
    {
        mCourses[i].removeStudent(id);
    }
}

void Registrar::removeCourse(string id) // Xoa 1 khoa hoc khoi danh sach khoa hoc
{
    if (findCourse(id) == nullptr)
    {
        cout << "Khong tim thay khoa hoc " << id << endl;
        return;
    }
    for (int i = 0; i < mCourses.size(); i++)
    {
        if (mCourses[i].getID() == id)
        {
            mCourses.erase(mCourses.begin() + i);
            break;
        }
    }
    for (int i = 0; i < mStudents.size(); i++)
    {
        mStudents[i].removeCourse(id);
    }
}