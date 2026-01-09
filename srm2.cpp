#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

// Structure to hold student details
struct Student {
    string name;
    int age;
    string grade;
};

// Global database using a Map (Key: ID, Value: Student object)
map<int, Student> studentDB;

void addStudent() {
    int id;
    Student s;
    
    cout << "\n--- Add New Student ---\n";
    cout << "Enter Student ID: ";
    cin >> id;

    if (studentDB.find(id) != studentDB.end()) {
        cout << "Error: Student ID already exists!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Grade: ";
    cin >> s.grade;

    studentDB[id] = s;
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (studentDB.empty()) {
        cout << "\nNo records found.\n";
        return;
    }
    cout << "\n--------------------------------------------------\n";
    for (auto const& pair : studentDB) {
        int id = pair.first;            
        Student info = pair.second;      
        cout << id << "\t" << info.name << "\t\t" << info.age << "\t" << info.grade << endl;
    }      
}

void updateStudent() {
    int id;
    cout << "\nEnter ID to update: ";
    cin >> id;

    if (studentDB.find(id) == studentDB.end()) {
        cout << "Student not found.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter New Name: ";
    getline(cin, studentDB[id].name);
    cout << "Enter New Age: ";
    cin >> studentDB[id].age;
    cout << "Enter New Grade: ";
    cin >> studentDB[id].grade;

    cout << "Record updated successfully!\n";
}

void deleteStudent() {
    int id;
    cout << "\nEnter ID to delete: ";
    cin >> id;

    if (studentDB.erase(id)) {
        cout << "Record deleted.\n";
    } else {
        cout << "Student ID not found.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== STUDENT RECORD SYSTEM (C++) =====";
        cout << "\n1. Add Student\n2. View Students\n3. Update Student\n4. Delete Student\n5. Exit";
        cout << "\nSelect choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: cout << "Invalid choice!\n";
        }    }
}