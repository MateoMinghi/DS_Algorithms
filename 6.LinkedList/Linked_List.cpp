#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Method to insert a new node at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Method to insert a new node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Method to print the elements of the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Example usage of the LinkedList class
int main() {
    LinkedList myList;

    // Inserting elements into the linked list
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtEnd(15);
    myList.insertAtEnd(20);

    // Printing the linked list
    std::cout << "Linked List: ";
    myList.printList();

    return 0;
}




/* 
This will eventually go inside the markdown file but just in case anything happens ill put it here

The line Node* newNode = new Node(); combines dynamic memory allocation (new) with object initialization
using the default constructor (Node()). It creates a new Node object on the heap and assigns its address
to the pointer variable newNode. This syntax is commonly used in C++ for creating objects dynamically
when the exact size or number of objects needed is not known at compile time, or when objects need to
persist beyond the scope of the current function.
*/