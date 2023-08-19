#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class ClassRecord {
private:
    string name;
    string studentId;
    string birthday;
    string address;
    double mathGrade;
    double englishGrade;
    double filipinoGrade;
    double mapehGrade;
    double scienceGrade;

public:
    // Constructor
    ClassRecord(string name) {
        this->name = name;
        cout << "Enter Student ID: ";
        getline(cin, this->studentId);
        cout << "Enter Birthday: ";
        getline(cin, this->birthday);
        cout << "Enter Address: ";
        getline(cin, this->address);
        
    }
    ClassRecord(){
        cout << "Enter math grade: ";
        cin >> mathGrade;
        cout << "Enter English grade: ";
        cin >> englishGrade;
        cout << "Enter Filipino grade: ";
        cin >> filipinoGrade;
        cout << "Enter MAPEH grade: ";
        cin >> mapehGrade;
        cout << "Enter Science grade: ";
        cin >> scienceGrade;
    }

    // Getter methods
    string getName() const {
        return name;
    }
    string getBirthday() const {
        return birthday;
    }
    string getaddress() const {
        return address;
    }
    string getStudentId() const {
        return studentId;
    }

    double getMathGrade() const {
        return mathGrade;
    }

    double getEnglishGrade() const {
        return englishGrade;
    }

    double getFilipinoGrade() const {
        return filipinoGrade;
    }

    double getMapehGrade() const {
        return mapehGrade;
    }

    double getScienceGrade() const {
        return scienceGrade;
    }
};

void addStudent(vector<ClassRecord>& students){
    // int numStudent;
    // cout<<"Enter number of Students: ";
    // cin >>numStudent;
    // cin.ignore();

    // for(int i=0;i<numStudent;i++)
    // {
        string name;
        cout << "Enter student name: ";
        getline(cin, name);
        students.push_back(ClassRecord(name));
    // }
}
void editStudentRecord(vector<ClassRecord>& students){
    string name;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    

    for (auto& student : students) {
      

        if (student.getName() == name) {
            // Edit the student record here
            int ans;
            cout<<"(1) Student id"<<endl;
            cout<<"(2) Birthday"<<endl;
            cout<<"(3) Address"<<endl;
            cout<<"Select which to edit: ";
            cin>> ans;
            

            switch (ans){
                case 1:
                cout<<student.getStudentId();
                // student.studentId = "hello";
                break;
            }
            break;
        }
    }

    // If the function hasn't returned yet, the student was not found
    cout << "Student not found\n";
}


int main(){
    vector<ClassRecord> students;

    int ans;
    cout<< " (1) Add a student \n (2) Edit student records \n (3) Input/Edit Grades \n (4) View class record \n (5) View best in \n (6) View grade book \n (7) Print All to document \n (8) Print Student to document \n";
    cout<<"Select Number: ";
    cin>>ans;

 
    switch(ans){
        case 1:
            addStudent(students);
            break;
        case 2:
            editStudentRecord(students);
            break;
        // case 3:
        //     inputGrade();
        //     break;
        // case 4:
        //     viewClassRecord();
        //     break;
        // case 5:
        //     viewBestIn();
        //     break;
        // case 6:
        //     viewGradeBook();
        //     break;
        // case 7:
        //     printAllToDocs();
        //     break;
        // case 8:
        //     printStudentToDocs();
        //     break;
        

    }
    char letter;
    cout<<"do you wish to continue? y/n";cin>>letter;
    if (letter == 'y' || letter == 'Y'){
        return(main());
    }
    
}



