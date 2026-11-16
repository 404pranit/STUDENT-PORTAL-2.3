
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int marks;

    void display() {
        cout << id << " " << name
             << " " << marks << endl;
    }
};

int main() {

    vector<Student> students;
    int choice;

    do {
        cout << "\n--- STUDENT PORTAL ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Calculate Grade\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;

            cout << "Enter ID: ";
            cin >> s.id;

            cout << "Enter Name: ";
            cin >> s.name;

            cout << "Enter Marks: ";
            cin >> s.marks;

            if (s.marks < 0 || s.marks > 100) {
                cout << "Invalid Marks\n";
            }
            else {
                students.push_back(s);

                ofstream file("students.txt", ios::app);
                file << s.id << " "
                     << s.name << " "
                     << s.marks << endl;
                file.close();

                cout << "Student Added!\n";
            }
        }

        else if (choice == 2) {
            for (Student s : students) {
                s.display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            for (Student s : students) {
                if (s.id == id) {
                    s.display();
                }
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            for (Student s : students) {
                if (s.id == id) {
                    if (s.marks >= 75)
                        cout << "Grade A\n";
                    else if (s.marks >= 60)
                        cout << "Grade B\n";
                    else if (s.marks >= 40)
                        cout << "Grade C\n";
                    else
                        cout << "Fail\n";
                }
            }
        }

    } while (choice != 5);

    return 0;
}
