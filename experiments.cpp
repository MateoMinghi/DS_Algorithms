#include <iostream>
using namespace std;

struct Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(): head(nullptr){}  

    int push(int data){
        head = nullptr;
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};


int main(){
    LinkedList List1;
    List1.push(4);
    List1.push(5);
    List1.printList();

    return 0;
}