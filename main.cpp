#include "Registrar.h"

void findStudByID(string id, Registrar &r)
{
    Student *s = r.findStudent(id);
    if (s == nullptr)
    {
        cout << "Khong tim thay sinh vien " << id << endl;
        return;
    }
    cout << "Ho va ten: " << s->getName() << endl;
    cout << "MSSV: " << s->getID() << endl;
    cout << "Khoa hoc da dang ky: " << endl;
    for (int i = 0; i < s->getSchedule().size(); i++)
    {
        Course *c = r.findCourse(s->getSchedule()[i]);
        if (c != nullptr)
        {
            cout << c->getDate().date << "-" << c->getDate().hour << ":" << c->getDate().min << ": ";
            cout << c->getName() << endl;
        }
    }
}

void findCourseByID(string id, Registrar &r)
{
    Course *c = r.findCourse(id);
    if (c == nullptr)
    {
        cout << "Khong tim thay khoa hoc " << id << endl;
        return;
    }
    cout << "Ten khoa hoc: " << c->getName() << endl;
    cout << "Ma khoa hoc: " << c->getID() << endl;
    cout << "Danh sach sinh vien dang ky: " << endl;
    for (int i = 0; i < c->getRoster().size(); i++)
    {
        Student *s = r.findStudent(c->getRoster()[i]);
        if (s != nullptr)
        {
            cout << s->getID() << "-" << s->getName() << endl;
        }
    }
}

int main()
{
    Registrar r;
    // Input
    ifstream in("student.txt");
    if (!in.fail())
    {
        r.addStudentFromFile(in); // doc tu file sinh vien
    }
    else
    {
        cout << "File student.txt khong ton tai!\n";
    }
    in.close();
    in.open("course.txt");
    if (!in.fail())
    {
        r.addCourseFromFile(in); // doc tu file khoa hoc
    }
    else
    {
        cout << "File course.txt khong ton tai!\n";
    }
    in.close();

    // Enrollment
    int option = 1;
    ofstream out;
    string id;
    do
    {
        cout << "******************************" << endl;
        cout << "*1. Dang ky khoa hoc         *" << endl;
        cout << "*2. Xoa mot SV khoi he thong *" << endl;
        cout << "*3. Xoa mot KH khoi he thong *" << endl;
        cout << "*4. Tim 1 SV theo MSSV       *" << endl;
        cout << "*5. Tim 1 KH theo ma KH      *" << endl;
        cout << "*6. Xuat danh sach sinh vien *" << endl;
        cout << "*7. Xuat danh sach khoa hoc  *" << endl;
        cout << "*0. Ket thuc                 *" << endl;
        cout << "******************************" << endl;
        cout << "Nhap lua chon: ";
        cin >> option;
        switch (option)
        {
        case 1:
            char c;
            do
            {
                r.enrollment();
                cout << "Hoan thanh. Tiep tuc dang ky? (Y/N): ";
                cin >> c;
                system("cls");

            } while (c == 'Y' || c == 'y');
            break;
        case 2:
            cout << "Nhap MSSV can xoa: ";
            cin >> id;
            r.removeStudent(id);
            system("cls");
            break;
        case 3:
            cout << "Nhap ma khoa hoc can xoa: ";
            cin >> id;
            r.removeCourse(id);
            system("cls");
            break;
        case 4:
            cout << "Nhap MSSV can tim: ";
            cin >> id;
            findStudByID(id, r);
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Nhap ma khoa hoc can tim: ";
            cin >> id;
            findCourseByID(id, r);
            system("pause");
            system("cls");
            break;
        case 6:
            out.open("StudentList.txt");
            r.ExportStudents(out);
            out.close();
            system("cls");
            break;
        case 7:
            out.open("CourseList.txt");
            r.ExportCourses(out);
            out.close();
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le" << endl;
            system("cls");
            break;
        }

    } while (option != 0);
    return 0;
}