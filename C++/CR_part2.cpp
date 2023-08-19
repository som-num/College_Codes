#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

class Student
{
private:
    string studentName = "";
    string studentId = "";
    string studentBirthday = "";
    string studentAddress = "";
    int math_grade, english_grade, filipino_grade, mapeh_grade, science_grade;

public:
    void inputInfo()
    {
        cout << "Enter Student Name: ";
        getline(cin, this->studentName);

        cout << "Enter Student ID: ";
        getline(cin, this->studentId);
      

        cout << "Enter Student Birthday (MM/DD/YY): ";
        getline(cin, this->studentBirthday);
       

        cout << "Enter Student Address: ";
        getline(cin, this->studentAddress);
       
    }

    void editInfo()
    {
        int ans;
        cout << setw(25)<<left<<"(1) Student Name" << setw(20) << left<<studentName <<endl;
        cout << setw(25)<<left<<"(2) Student Birthday\t" << setw(20)<<left<<studentBirthday<< endl;
        cout << setw(25)<<left<<"(3) Student Address\t" << setw(20)<<left<<studentAddress<< endl;
        cout << "Select which to edit: ";
        cin >> ans;
        cin.ignore();

        switch (ans)
        {
        case 1:
            // cout << "Old Name: " << studentName << endl;
            cout << "Enter New Name: ";
            getline(cin, studentName);
            break;
        case 2:
            // cout << "Old Birthday: " << studentBirthday << endl;
            cout << "Enter New Birthday: ";
            getline(cin, studentBirthday);
            break;
        case 3:
            // cout << "Old Address: " << studentAddress << endl;
            cout << "Enter New Address: ";
            getline(cin, studentAddress);
            break;
        default:
            cout<<"Invalid input please try again...."<<endl;
        }
    }
    void inputGrade()
    {
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

    void editGrade()
    {
        int ans;
        cout << "(1) Math\t" <<  math_grade << endl;
        cout << "(2) English\t" <<  english_grade << endl;
        cout << "(3) Filipino\t" <<  filipino_grade << endl;
        cout << "(4) MAPEH\t" <<  mapeh_grade << endl;
        cout << "(5) Science\t" <<  science_grade <<endl;
        cout << "Select which grade to edit: ";
        cin >> ans;
        cin.ignore();
        switch (ans)
        {
        case 1:
            // cout << "Old Grade: " << math_grade << endl;
            cout << "Enter New Grade: ";
            cin >> math_grade;
            break;
        case 2:
            // cout << "Old Grade: " << english_grade << endl;
            cout << "Enter New Grade: ";
            cin >> english_grade;
            break;
        case 3:
            // cout << "Old Grade: " << filipino_grade << endl;
            cout << "Enter New Grade: ";
            cin >> filipino_grade;
            break;
        case 4:
            // cout << "Old Grade: " << mapeh_grade << endl;
            cout << "Enter New Grade: ";
            cin >> mapeh_grade;
            break;
        case 5:
            // cout << "Old Grade: " << science_grade << endl;
            cout << "Enter New Grade: ";
            cin >> science_grade;
            break;
        default: 
            cout << "Invalid input please try again...."<<endl;
        }
    }

    string get_name() const
    {
        return studentName;
    }

    string get_studentId()const
    {
        return studentId;
    }

    string get_Birthday() const
    {
        return studentBirthday;
    }

    string get_Address() const
    {
        return studentAddress;
    }

    int get_math_grade() const
    {
        return math_grade;
    }

    int get_english_grade() const
    {
        return english_grade;
    }

    int get_filipino_grade() const
    {
        return filipino_grade;
    }

    int get_mapeh_grade() const
    {
        return mapeh_grade;
    }

    int get_science_grade() const
    {
        return science_grade;
    }

    double get_average_grade() const
    {
        double avg = ((science_grade+mapeh_grade+english_grade+math_grade+filipino_grade)/5);
        return avg;

    }
};

bool compareNames(const Student &s1, const Student &s2){
    string s1lastName = s1.get_name().substr(s1.get_name().find_last_of(" ")+1);
    string s2lastName = s2.get_name().substr(s2.get_name().find_last_of(" ")+1);
    return s1lastName < s2lastName;
}

class ClassRecords
{
private:
    int num_students;
    Student students[50];

public:
    ClassRecords()    
    {
        num_students = 0;
    }

   int find_student_index(const string& id) const {
    for (int i = 0; i < num_students; i++) {
        if (students[i].get_studentId() == id) {
            return i;
        }
    }
    return -1;
}

    void add_Student()
    {
        char ans;
        if (num_students >= 50)
        {
            cout << "Class Record already full" << endl;
        }
        students[num_students].inputInfo();
        // cin.ignore();

        cout<< "Do you want to input Grades? y/n  ";
        cin>>ans;
        cin.ignore();
        if (ans == 'y' || ans == 'Y'){
            students[num_students].inputGrade();
        }       
        num_students++;
        cout << "Student added successfully." << endl;
    }


   void edit_student() {
    string studentId;
    cout << "\t\t Edit Student Info" << endl;
    cout << "Enter student ID  to edit: ";
    getline(cin, studentId);

    int index = find_student_index(studentId);
    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    students[index].editInfo();
}

void add_grade() {
    string studentId;
    cout << "\t\t Add Grade:" << endl;
    cout << "Enter student ID to add grade: ";
    getline(cin, studentId);

    int index = find_student_index(studentId);
    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    students[index].inputGrade();
}

    void edit_grade(){
        string studentId;

        cout<<"\t\t Grade edit"<<endl;
        cout << "\nEnter student ID to edit grade: ";
        getline(cin, studentId);

        int index = find_student_index(studentId);
         if (index == -1) {
        cout << "Student not found." << endl;
        return;
        }

        students[index].editGrade();

    }
   

    void viewClassRecord()  {
        cout<<string(100,'-')<<endl;
        cout<<"\t\t View Class Record"<<endl;

        cout << setw(20) << left << "Name" 
        << setw(20) << left << "Address" 
        << setw(20) << left << "Birthday"<< endl;
        cout << setfill(' ') << setw(40) << " " << setfill(' ') << endl;

       // Sort the students array alphabetically by name
       sort(students, students + num_students, [](const Student& a, const Student& b) {
        return a.get_name() < b.get_name();
    });
        for (int i = 0; i < num_students; i++) {
            cout << setw(20) << left << students[i].get_name() 
            << setw(20) << left << students[i].get_Address() 
            << setw(20) << left << students[i].get_Birthday() << endl;
        }

        cout<<string(100,'-')<<endl;
    }

    void viewBestIn(){
        int mathHighest = 0;
        int mapehHighest = 0;
        int englishHighest = 0;
        int filipinoHighest = 0;
        int scienceHighest = 0;
        string mathHighestName,mapehHighestName,englishHighestName,filipinoHighestName,scienceHighestName;
        int choice;

        for(int i = 0; i< num_students; i++){
            if(students[i].get_math_grade() > mathHighest){
                mathHighest = students[i].get_math_grade();
                mathHighestName = students[i].get_name();
            }
            if(students[i].get_mapeh_grade() > mapehHighest){
                mapehHighest = students[i].get_mapeh_grade();
                mapehHighestName = students[i].get_name();
            }
            if(students[i].get_english_grade() > englishHighest){
                englishHighest = students[i].get_english_grade();
                englishHighestName = students[i].get_name();
            }
            if(students[i].get_filipino_grade() > filipinoHighest){
                filipinoHighest = students[i].get_filipino_grade();
                filipinoHighestName = students[i].get_name();
            }
            if(students[i].get_science_grade() > scienceHighest){
                scienceHighest = students[i].get_science_grade();
                scienceHighestName = students[i].get_name();
            }

            cout<<string(100,'-')<<endl;            
            }
            cout<<"\t\t View Best In"<<endl;

            cout<<"(1) Math"<<endl;
            cout<<"(2) MAPEH" << endl;
            cout<<"(3) English" << endl;
            cout<<"(4) Filipino" << endl;
            cout<<"(5) Science" << endl;
            cout<<"Select which subject: ";
            cin >> choice;

            switch(choice){
                case 1:
                    cout<< "Best in Math: "<< mathHighestName<< " " << mathHighest <<endl;
                    break;
                case 2:
                    cout<< "Best in MAPEH: "<< mapehHighestName << " " << mapehHighest <<endl;
                    break;
                case 3:
                    cout<< "Best in English: "<< englishHighestName << " " << englishHighest <<endl;
                    break;
                case 4:
                    cout << "Best in Filipino: " << filipinoHighestName << " " << filipinoHighest <<endl;
                    break;
                case 5:
                    cout << "Best in Science: " << scienceHighestName  << " " << scienceHighest <<endl;
                    break;
                default:
                    cout<< "Invalid input please try again...." <<endl;

            cout<<string(100,'-')<<endl;

        }
    }

    void viewGradeBook(){

        
        cout << string(110,'-') <<endl;
        cout << setw(10) << left << "Name" 
        << setw(10) << left << "Math" 
        << setw(10) << left << "Science"
        << setw(10) << left << "English" 
        << setw(10) << left << "Filipino"
         << setw(10) << left << "MAPEH" 
         << setw(10) << left << "Average" << endl;
        // cout << setfill(' ') << setw(40) << " " << setfill(' ') << endl;
         // Sort the students array in descending order of average grades
        sort(students, students + num_students, compareNames);


          for (int i = 0; i < num_students; i++) {
            

            // cout << string(110,'-') <<endl;
            cout << setw(10) << left << students[i].get_name() 
            << setw(10) << left << students[i].get_math_grade() 
            << setw(10) << left << students[i].get_science_grade()
            << setw(10) << left << students[i].get_english_grade() 
            << setw(10) << left << students[i].get_filipino_grade() 
            << setw(10) << left << students[i].get_mapeh_grade() 
            << setw(10) << left << students[i].get_average_grade() << endl;
            
            }
            cout << string(110,'-') <<endl;

    }

    void printStudentToDocument(){
        string studentId;
        ofstream studentInfo;

        studentInfo.open("StudentRecord.txt", ios::out | ios::trunc);
        cout << "Enter student Id to edit: ";
        getline(cin, studentId);

        int index = -1;
        for (int i = 0; i < num_students; i++)
        {
            if (students[i].get_studentId() == studentId)
            {
                index = i;
                studentInfo << "Name: " << students[index].get_name() <<endl;
                studentInfo << "Birthday: " << students[index].get_Birthday() <<endl;
                studentInfo << "Address: " << students[index].get_Address() <<endl;
                studentInfo << "Math Grade: " << students[index].get_math_grade() <<endl;
                studentInfo << "Science Grade: " << students[index].get_science_grade() <<endl;
                studentInfo << "English Grade: " << students[index].get_english_grade() <<endl;
                studentInfo << "Filipino Grade: " << students[index].get_filipino_grade() <<endl;
                studentInfo << "MAPEH Grade: " << students[index].get_math_grade() <<endl;
                break;
            }
        }
        studentInfo.close();

        if (index == -1)
        {
            cout << "Student not found." << endl;
            return;
        }         

    }

    void printAllToDocument(){

        ofstream classInfo;

        classInfo.open("ClassRecord.doc", ios::out | ios::trunc);

        
        classInfo << string(110,'-') <<endl;
        classInfo << setw(10) << left << "Name" 
        << setw(10) << left << "Math" 
        << setw(10) << left << "Science"
        << setw(10) << left << "English" 
        << setw(10) << left << "Filipino"
         << setw(10) << left << "MAPEH" 
         << setw(10) << left << "Average" << endl;
        // cout << setfill(' ') << setw(40) << " " << setfill(' ') << endl;
         // Sort the students array in descending order of average grades
            sort(students, students + num_students, 
                [](const Student &s1, const Student &s2) { 
                    return s1.get_average_grade() > s2.get_average_grade(); 
                });


          for (int i = 0; i < num_students; i++) {
            

            // cout << string(110,'-') <<endl;
            classInfo << setw(10) << left << students[i].get_name() 
            << setw(10) << left << students[i].get_math_grade() 
            << setw(10) << left << students[i].get_science_grade()
            << setw(10) << left << students[i].get_english_grade() 
            << setw(10) << left << students[i].get_filipino_grade() 
            << setw(10) << left << students[i].get_mapeh_grade() 
            << setw(10) << left << students[i].get_average_grade() << endl;
            
            }
            classInfo << string(110,'-') <<endl;

            classInfo.close();

        
    }


};

void run()
{
    ClassRecords records;
    int choice;
    do
    {
        cout<<"\t\t Class Record"<<endl;
        cout << " (1) Add a student \n (2) Edit student records \n (3) Input Grades \n (4) Edit Grades \n (5) View class record \n (6) View best in \n (7) View grade book \n (8) Print All to document \n (9) Print Student to document \n (10) If you're tired \n Select number: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            system("clear");
            records.add_Student();
            system("clear");
            break;
        case 2:      
            system("clear");
            records.viewClassRecord();
            records.edit_student();
            system("clear");            
            break;
        case 3:
            system("clear");
            records.viewClassRecord();
            records.add_grade();
            system("clear");
            break;
        case 4:
            system("clear");
            records.viewClassRecord();
            records.edit_grade();
            system("clear");
            break;
        case 5:
            system("clear");
            records.viewClassRecord();
            // system("clear");
            break;
        case 6:
            system("clear");
            records.viewClassRecord();
            records.viewBestIn();
            // system("clear");
            break;
        case 7:
            system("clear");
            records.viewClassRecord();
            records.viewGradeBook();
            // system("clear");            
            break;
        case 8:
            system("clear");
            records.viewClassRecord();
            records.printAllToDocument();
            break;
        case 9:
            system("clear");
            records.viewClassRecord();
            records.printStudentToDocument();
            system("clear");
            break;

        case 10:
            cout << "Goodnight" << endl;
            system("pokemon-colorscripts -r");
            system("shutdown -r now");
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);
}

int main()
{
    run();
}
