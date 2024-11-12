#include <iostream>
#include <string>
using namespace std;

// Define a structure to represent each student node in a linked list
struct Student {
    int ID;
    string name;
    string studentClass;
    Student* next; // Pointer to the next student in the chain

    // Constructor to initialize a student
    Student(int id, string n, string c) : ID(id), name(n), studentClass(c), next(nullptr) {}
};

// Hash table constants
const int BUCKET_COUNT = 10; // Number of buckets in the hash table

// Array of pointers to represent the hash table with separate chaining
Student* hashTable[BUCKET_COUNT] = { nullptr };

// Hash function to map an ID to a bucket index
int hashFunction(int ID) {
    return ID % BUCKET_COUNT;
}

// Insert a student into the hash table
void insert(int ID, string name, string studentClass) {
    int index = hashFunction(ID);

    // Check if the student ID already exists in the list
    Student* current = hashTable[index];
    while (current != nullptr) {
        if (current->ID == ID) {
            // If the ID already exists, update the student's name and class
            current->name = name;
            current->studentClass = studentClass;
            return;
        }
        current = current->next;
    }

    // If ID does not exist, insert a new student node at the beginning of the list
    Student* newStudent = new Student(ID, name, studentClass);
    newStudent->next = hashTable[index];
    hashTable[index] = newStudent;
}

// Delete a student by ID from the hash table
void deleteStudent(int ID) {
    int index = hashFunction(ID);
    Student* current = hashTable[index];
    Student* prev = nullptr;

    while (current != nullptr) {
        if (current->ID == ID) {
            // If the student is found, remove it from the linked list
            if (prev == nullptr) {
                // If it's the first node in the list
                hashTable[index] = current->next;
            } else {
                // If it's in the middle or end of the list
                prev->next = current->next;
            }
            delete current; // Free memory of the deleted student
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Retrieve student information by ID
string infor(int ID) {
    int index = hashFunction(ID);
    Student* current = hashTable[index];

    while (current != nullptr) {
        if (current->ID == ID) {
            return current->name + "," + current->studentClass;
        }
        current = current->next;
    }
    return "NA,NA"; // If student not found
}

int main() {
    string command;

    while (cin >> command) {
        if (command == "Insert") {
            int ID;
            string name, studentClass;
            cin >> ID >> name >> studentClass;
            insert(ID, name, studentClass);
        } else if (command == "Delete") {
            int ID;
            cin >> ID;
            deleteStudent(ID);
        } else if (command == "Infor") {
            int ID;
            cin >> ID;
            cout << infor(ID) << endl;
        } else if (command == "Exit"){
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
