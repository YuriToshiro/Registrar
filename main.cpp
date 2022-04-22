#include "Registrar.h"

int main()
{
    Registrar r;
    // Input
    ifstream in("student.txt");
    if (!in.fail())
    {
        r.addStudent(in); // doc tu file sinh vien
    }
    else
    {
        cout << "File sinhvien.txt khong ton tai!\n";
    }
    in.close();
    in.open("course.txt");
    if (!in.fail())
    {
        r.addCourse(in); // doc tu file khoa hoc
    }
    else
    {
        cout << "File khoahoc.txt khong ton tai!\n";
    }
    in.close();

    // Enrollment
    int option = 1;
    ofstream out;
    do
    {
        cout << "******************************" << endl;
        cout << "*1. Dang ky khoa hoc         *" << endl;
        cout << "*2. Xuat danh sach sinh vien *" << endl;
        cout << "*3. Xuat danh sach khoa hoc  *" << endl;
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
                cout << "Dang ki thanh cong. Tiep tuc? (Y/N): ";
                cin >> c;
                system("cls");

            } while (c == 'Y' || c == 'y');
            break;
        case 2:
            out.open("StudentList.txt");
            r.ExportStudents(out);
            out.close();
            system("cls");
            break;
        case 3:
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