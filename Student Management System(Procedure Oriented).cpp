#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
const int MAX_STUDENTS = 100; // Maximum number of students the system can handle
struct Student {
    string name;
    int roll_no;
    string subject;
    string section;
    string address;
};
// Function prototypes
void insert(Student students[], int& num_students);
void search(const Student students[], int num_students);
void display(const Student students[], int num_students);
void deleteRecord(Student students[], int& num_students, int roll_no);
int main() {
	system ("color f0");
    Student students[MAX_STUDENTS];
    int num_students = 0;
    char choice;
    do {
        cout << "---------------------------" << endl;
        cout << "Student Management System" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Search Record" << endl;
        cout << "3. Display All Records" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                insert(students, num_students);
                break;
            case '2':
                search(students, num_students);
                break;
            case '3':
                display(students, num_students);
                break;
            case '4':
                int roll_to_delete;
                cout << "Enter Roll Number to delete: ";
                cin >> roll_to_delete;
                deleteRecord(students, num_students, roll_to_delete);
                break;
            case '5':
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != '5');

    return 0;
}

void insert(Student students[], int& num_students) {
    if (num_students >= MAX_STUDENTS) {
        cout << "Maximum number of students reached. Cannot insert more records." << endl;
        return;
    }
    Student new_student;
    cout << "Enter Student Name: ";
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    getline(cin, new_student.name);
    cout << "Enter Roll Number: ";
    cin >> new_student.roll_no;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, new_student.subject);
    cout << "Enter Section: ";
    getline(cin, new_student.section);
    cout << "Enter Address: ";
    getline(cin, new_student.address);

    students[num_students] = new_student;
    num_students++;

    cout << "Record inserted successfully!" << endl;
}

void search(const Student students[], int num_students) {
    int roll_to_search;
    cout << "Enter Roll Number to search: ";
    cin >> roll_to_search;

    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_to_search) {
            cout << "Record found:" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll Number: " << students[i].roll_no << endl;
            cout << "Subject: " << students[i].subject << endl;
            cout << "Section: " << students[i].section << endl;
            cout << "Address: " << students[i].address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found for Roll Number: " << roll_to_search << endl;
    }
}

void display(const Student students[], int num_students) {
    if (num_students == 0) {
        cout << "No records found." << endl;
    } else {
        cout << "----- Student Records -----" << endl;
        for (int i = 0; i < num_students; i++) {
            cout << "Record " << (i + 1) << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll Number: " << students[i].roll_no << endl;
            cout << "Subject: " << students[i].subject << endl;
            cout << "Section: " << students[i].section << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "---------------------------" << endl;
        }
    }
}

void deleteRecord(Student students[], int& num_students, int roll_no) {
    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no) {
            // Move the last record to the position of the record to be deleted
            students[i] = students[num_students - 1];
            num_students--;
            found = true;
            cout << "Record with Roll Number " << roll_no << " deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Record not found for Roll Number: " << roll_no << ". Deletion failed." << endl;
    }
}

