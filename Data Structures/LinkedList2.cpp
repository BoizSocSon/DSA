#include <iostream>
using namespace std;

// Node class to represent each node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
    private:
        Node* head;

    public:
        // Constructor to initialize an empty list
        LinkedList() {
            head = nullptr;
        }

        // Function to insert a node at the end of the list
        void insert(int val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // Function to display the linked list
        void display() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        // Function to delete a node by value
        void deleteNode(int val) {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }

            if (head->data == val) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr && temp->next->data != val) {
                temp = temp->next;
            }

            if (temp->next == nullptr) {
                cout << "Node with value " << val << " not found" << endl;
                return;
            }

            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();  // Output: 10 -> 20 -> 30 -> NULL

    list.deleteNode(20);
    list.display();  // Output: 10 -> 30 -> NULL

    return 0;
}
