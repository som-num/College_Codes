#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    string address;
    int math_grade;
    int english_grade;
    int filipino_grade;
    int mapeh_grade;
    int science_grade;

public:
    void input() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student address: ";
        getline(cin, address);
    }

    void edit() {
        cout << "Enter new address: ";
        getline(cin, address);
    }

    void input_grade() {
        cout << "Enter math grade: ";
        cin >> math_grade;
        cout << "Enter English grade: ";
        cin >> english_grade;
        cout << "Enter Filipino grade: ";
        cin >> filipino_grade;
        cout << "Enter MAPEH grade: ";
        cin >> mapeh_grade;
        cout << "Enter Science grade: ";
        cin >> science_grade;
    }

    string get_name() const {
        return name;
    }

    int get_math_grade() const {
        return math_grade;
    }

    int get_english_grade() const {
        return english_grade;
    }

    int get_filipino_grade() const {
        return filipino_grade;
    }

    int get_mapeh_grade() const {
        return mapeh_grade;
    }

    int get_science_grade() const {
        return science_grade;
    }
};

class ClassRecord {
private:
    int num_students;
    Student students[50];

public:
    ClassRecord() {
        num_students = 0;
    }

    void add_student() {
        if (num_students >= 50) {
            cout << "Maximum number of students reached." << endl;
            return;
        }
        students[num_students].input();
        students[num_students].input_grade();
        num_students++;
    }

    void edit_student() {
        string name;
        cout << "Enter student name to edit: ";
        getline(cin, name);

        int index = -1;
        for (int i = 0; i < num_students; i++) {
            if (students[i].get_name() == name) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Student not found." << endl;
            return;
        }

        students[index].edit();
    }

    void view_class_record() {
        sort(students, students + num_students, [](const Student& a, const Student& b) {
            return a.get_name() < b.get_name();
        });

        cout << left << setw(20) << "Name"
            << right << setw(10) << "Math"
            << setw(10) << "English"
            << setw(10) << "Filipino"
            << setw(10) << "MAPEH"
            << setw(10) << "Science" << endl;

        for (int i = 0; i < num_students; i++) {
            cout << left << setw(20) << students[i].get_name()
                << right << setw(10) << students[i].get_math_grade()
                << setw(10) << students[i].get_english_grade()
                << setw(10) << students[i].get_filipino_grade()
                << setw(10) << students[i].get_mapeh_grade()
                << setw(10) << students[i].get_science_grade() << endl;
        }
    }
void view_best_in() {
    int choice;
    cout << "Select subject:\n"
        << "1. Math\n"
        << "2. English\n"
        << "3. Filipino\n"
        << "4. MAPEH\n"
        << "5. Science\n"
        << "Enter choice: ";
    cin >> choice;

    int best_grade = -1;
    string best_student_name;
    for (int i = 0; i < num_students; i++) {
        int grade = 0;
        switch (choice) {
            case 1:
                grade = students[i].get_math_grade();
                break;
            case 2:
                grade = students[i].get_english_grade();
                break;
            case 3:
                grade = students[i].get_filipino_grade();
                break;
            case 4:
                grade = students[i].get_mapeh_grade();
                break;
            case 5:
                grade = students[i].get_science_grade();
                break;
            default:
                cout << "Invalid choice." << endl;
                return;
        }

        if (grade > best_grade) {
            best_grade = grade;
            best_student_name = students[i].get_name();
        }
    }

    cout << "Best in ";
    switch (choice) {
        case 1:
            cout << "Math";
            break;
        case 2:
            cout << "English";
            break;
        case 3:
            cout << "Filipino";
            break;
        case 4:
            cout << "MAPEH";
            break;
        case 5:
            cout << "Science";
            break;
    }
    cout << ": " << best_student_name << endl;
}

void view_grade_book() {
    sort(students, students + num_students, [](const Student& a, const Student& b) {
        double avg_a = (a.get_math_grade() + a.get_english_grade() + a.get_filipino_grade() + a.get_mapeh_grade() + a.get_science_grade()) / 5.0;
        double avg_b = (b.get_math_grade() + b.get_english_grade() + b.get_filipino_grade() + b.get_mapeh_grade() + b.get_science_grade()) / 5.0;
        return avg_a > avg_b;
    });

    cout << left << setw(20) << "Name"
        << right << setw(10) << "Math"
        << setw(10) << "English"
        << setw(10) << "Filipino"
        << setw(10) << "MAPEH"
        << setw(10) << "Science"
        << setw(10) << "Average" << endl;

    for (int i = 0; i < num_students; i++) {
        double avg = (students[i].get_math_grade() + students[i].get_english_grade() + students[i].get_filipino_grade() + students[i].get_mapeh_grade() + students[i].get_science_grade()) / 5.0;
        cout << left << setw(20) << students[i].get_name()
            << right << setw(10) << students[i].get_math_grade()
            << setw(10) << students[i].get_english_grade()
            << setw(10) << students[i].get_filipino_grade()
            << setw(10) << students[i].get_mapeh_grade()
            << setw(10) << students[i].get_science_grade()
            << setw(10) << fixed << setprecision(2) << avg << endl;
   
}

void print_student_record() {
    string student_name;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student_name);

    for (int i = 0; i < num_students; i++) {
        if (students[i].get_name() == student_name) {
            ofstream fout(student_name + ".txt");
            fout << "Name: " << students[i].get_name() << endl;
            fout << "Address: " << students[i].get_address() << endl;
            fout << "Math Grade: " << students[i].get_math_grade() << endl;
            fout << "English Grade: " << students[i].get_english_grade() << endl;
            fout << "Filipino Grade: " << students[i].get_filipino_grade() << endl;
            fout << "MAPEH Grade: " << students[i].get_mapeh_grade() << endl;
            fout << "Science Grade: " << students[i].get_science_grade() << endl;
            fout.close();
            cout << "Student record saved to " << student_name << ".txt" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void print_class_record() {
    sort(students, students + num_students, [](const Student& a, const Student& b) {
        double avg_a = (a.get_math_grade() + a.get_english_grade() + a.get_filipino_grade() + a.get_mapeh_grade() + a.get_science_grade()) / 5.0;
        double avg_b = (b.get_math_grade() + b.get_english_grade() + b.get_filipino_grade() + b.get_mapeh_grade() + b.get_science_grade()) / 5.0;
        return avg_a > avg_b;
    });

    ofstream fout("Class Record.txt");
    fout << left << setw(20) << "Name"
        << right << setw(10) << "Math"
        << setw(10) << "English"
        << setw(10) << "Filipino"
        << setw(10) << "MAPEH"
        << setw(10) << "Science"
        << setw(10) << "Average" << endl;

    for (int i = 0; i < num_students; i++) {
        double avg = (students[i].get_math_grade() + students[i].get_english_grade() + students[i].get_filipino_grade() + students[i].get_mapeh_grade() + students[i].get_science_grade()) / 5.0;
        fout << left << setw(20) << students[i].get_name()
            << right << setw(10) << students[i].get_math_grade()
            << setw(10) << students[i].get_english_grade()
            << setw(10) << students[i].get_filipino_grade()
            << setw(10) << students[i].get_mapeh_grade()
            << setw(10) << students[i].get_science_grade()
            << setw(10) << fixed << setprecision(2) << avg << endl;
    }
    fout.close();
    cout << "Class record saved to Class Record.txt" << endl;
}
public:
void run() {
int choice;
do {
display_menu();
cin >> choice;
switch (choice) {
case 1:
add_student();
break;
case 2:
edit_student_records();
break;
case 3:
input_edit_grades();
break;
case 4:
view_class_record();
            case 5:
                view_best_subject();
                break;
            case 6:
                view_grade_book();
                break;
            case 7:
                print_student_record();
                break;
            case 8:
                print_class_record();
                break;
            case 9:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
}
};

int main() {
ClassRecord program;
program.run();
return 0;
}



   
